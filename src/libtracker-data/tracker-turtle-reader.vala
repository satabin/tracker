/*
 * Copyright (C) 2009, Nokia
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 */

public class Tracker.TurtleReader : Object {
	SparqlScanner scanner;

	// token buffer
	TokenInfo[] tokens;
	// index of current token in buffer
	int index;
	// number of tokens in buffer
	int size;

	const int BUFFER_SIZE = 32;

	struct TokenInfo {
		public SparqlTokenType type;
		public SourceLocation begin;
		public SourceLocation end;
	}

	enum State {
		INITIAL,
		BOS,
		SUBJECT,
		PREDICATE,
		OBJECT
	}

	State state;

	// todo: support non-default graph with ntrig files
	public string graph { get; private set; }

	public string subject { get; private set; }
	public string predicate { get; private set; }
	public string object { get; private set; }
	public bool object_is_uri { get; private set; }

	HashTable<string,string> prefix_map;

	string[] subject_stack;
	string[] predicate_stack;

	int bnodeid = 0;
	// base UUID used for blank nodes
	uchar[] base_uuid;

	MappedFile? mapped_file;

	public TurtleReader (string path) throws FileError {
		mapped_file = new MappedFile (path, false);
		scanner = new SparqlScanner (mapped_file.get_contents (), mapped_file.get_length ());

		base_uuid = new uchar[16];
		uuid_generate (base_uuid);

		tokens = new TokenInfo[BUFFER_SIZE];
		prefix_map = new HashTable<string,string>.full (str_hash, str_equal, g_free, g_free);
	}

	string generate_bnodeid (string? user_bnodeid) {
		// user_bnodeid is NULL for anonymous nodes
		if (user_bnodeid == null) {
			return ":%d".printf (++bnodeid);
		} else {
			var checksum = new Checksum (ChecksumType.SHA1);
			// base UUID, unique per file
			checksum.update (base_uuid, 16);
			// node ID
			checksum.update ((uchar[]) user_bnodeid, -1);

			string sha1 = checksum.get_string ();

			// generate name based uuid
			return "urn:uuid:%.8s-%.4s-%.4s-%.4s-%.12s".printf (
				sha1, sha1.offset (8), sha1.offset (12), sha1.offset (16), sha1.offset (20));
		}
	}

	inline bool next_token () throws SparqlError {
		index = (index + 1) % BUFFER_SIZE;
		size--;
		if (size <= 0) {
			SourceLocation begin, end;
			SparqlTokenType type = scanner.read_token (out begin, out end);
			tokens[index].type = type;
			tokens[index].begin = begin;
			tokens[index].end = end;
			size = 1;
		}
		return (tokens[index].type != SparqlTokenType.EOF);
	}

	inline SparqlTokenType current () {
		return tokens[index].type;
	}

	inline bool accept (SparqlTokenType type) throws SparqlError {
		if (current () == type) {
			next_token ();
			return true;
		}
		return false;
	}

	SparqlError get_error (string msg) {
		return new SparqlError.PARSE ("%d.%d: syntax error, %s".printf (tokens[index].begin.line, tokens[index].begin.column, msg));
	}

	bool expect (SparqlTokenType type) throws SparqlError {
		if (accept (type)) {
			return true;
		}

		throw get_error ("expected %s".printf (type.to_string ()));
	}

	string get_last_string (int strip = 0) {
		int last_index = (index + BUFFER_SIZE - 1) % BUFFER_SIZE;
		return ((string) (tokens[last_index].begin.pos + strip)).ndup ((tokens[last_index].end.pos - tokens[last_index].begin.pos - 2 * strip));
	}

	string resolve_prefixed_name (string prefix, string local_name) throws SparqlError {
		string ns = prefix_map.lookup (prefix);
		if (ns == null) {
			throw get_error ("use of undefined prefix `%s'".printf (prefix));
		}
		return ns + local_name;
	}

	public bool next () throws SparqlError {
		while (true) {
			switch (state) {
			case State.INITIAL:
				next_token ();
				state = State.BOS;
				continue;
			case State.BOS:
				// begin of statement
				if (accept (SparqlTokenType.ATPREFIX)) {
					string ns = "";
					if (accept (SparqlTokenType.PN_PREFIX)) {
					       ns = get_last_string ();
					}
					expect (SparqlTokenType.COLON);
					expect (SparqlTokenType.IRI_REF);
					string uri = get_last_string (1);
					prefix_map.insert (ns, uri);
					expect (SparqlTokenType.DOT);
					continue;
				} else if (accept (SparqlTokenType.ATBASE)) {
					expect (SparqlTokenType.IRI_REF);
					expect (SparqlTokenType.DOT);
					continue;
				} else if (current () == SparqlTokenType.EOF) {
					return false;
				}
				// parse subject
				if (accept (SparqlTokenType.IRI_REF)) {
					subject = get_last_string (1);
					state = State.SUBJECT;
					continue;
				} else if (accept (SparqlTokenType.PN_PREFIX)) {
					// prefixed name with namespace foo:bar
					string ns = get_last_string ();
					expect (SparqlTokenType.COLON);
					subject = resolve_prefixed_name (ns, get_last_string ().substring (1));
					state = State.SUBJECT;
					continue;
				} else if (accept (SparqlTokenType.COLON)) {
					// prefixed name without namespace :bar
					subject = resolve_prefixed_name ("", get_last_string ().substring (1));
					state = State.SUBJECT;
					continue;
				} else if (accept (SparqlTokenType.BLANK_NODE)) {
					// _:foo
					expect (SparqlTokenType.COLON);
					subject = generate_bnodeid (get_last_string ().substring (1));
					state = State.SUBJECT;
					continue;
				} else {
					throw get_error ("expected subject");
				}
			case State.SUBJECT:
				// parse predicate
				if (accept (SparqlTokenType.IRI_REF)) {
					predicate = get_last_string (1);
					state = State.PREDICATE;
					continue;
				} else if (accept (SparqlTokenType.PN_PREFIX)) {
					string ns = get_last_string ();
					expect (SparqlTokenType.COLON);
					predicate = resolve_prefixed_name (ns, get_last_string ().substring (1));
					state = State.PREDICATE;
					continue;
				} else if (accept (SparqlTokenType.COLON)) {
					predicate = resolve_prefixed_name ("", get_last_string ().substring (1));
					state = State.PREDICATE;
					continue;
				} else if (accept (SparqlTokenType.A)) {
					predicate = "http://www.w3.org/1999/02/22-rdf-syntax-ns#type";
					state = State.PREDICATE;
					continue;
				} else {
					throw get_error ("expected predicate");
				}
			case State.PREDICATE:
				// parse object
				if (accept (SparqlTokenType.IRI_REF)) {
					object = get_last_string (1);
					object_is_uri = true;
					state = State.OBJECT;
					return true;
				} else if (accept (SparqlTokenType.PN_PREFIX)) {
					// prefixed name with namespace foo:bar
					string ns = get_last_string ();
					expect (SparqlTokenType.COLON);
					object = resolve_prefixed_name (ns, get_last_string ().substring (1));
					object_is_uri = true;
					state = State.OBJECT;
					return true;
				} else if (accept (SparqlTokenType.COLON)) {
					// prefixed name without namespace :bar
					object = resolve_prefixed_name ("", get_last_string ().substring (1));
					object_is_uri = true;
					state = State.OBJECT;
					return true;
				} else if (accept (SparqlTokenType.BLANK_NODE)) {
					// _:foo
					expect (SparqlTokenType.COLON);
					object = generate_bnodeid (get_last_string ().substring (1));
					object_is_uri = true;
					state = State.OBJECT;
					return true;
				} else if (accept (SparqlTokenType.OPEN_BRACKET)) {
					// begin of anonymous blank node
					subject_stack += subject;
					predicate_stack += predicate;
					subject = generate_bnodeid (null);
					state = State.SUBJECT;
					continue;
				} else if (accept (SparqlTokenType.STRING_LITERAL1) || accept (SparqlTokenType.STRING_LITERAL2)) {
					var sb = new StringBuilder ();

					string s = get_last_string (1);
					string* p = s;
					string* end = p + s.size ();
					while ((long) p < (long) end) {
						string* q = Posix.strchr (p, '\\');
						if (q == null) {
							sb.append_len (p, (long) (end - p));
							p = end;
						} else {
							sb.append_len (p, (long) (q - p));
							p = q + 1;
							switch (((char*) p)[0]) {
							case '\'':
							case '"':
							case '\\':
								sb.append_c (((char*) p)[0]);
								break;
							case 'b':
								sb.append_c ('\b');
								break;
							case 'f':
								sb.append_c ('\f');
								break;
							case 'n':
								sb.append_c ('\n');
								break;
							case 'r':
								sb.append_c ('\r');
								break;
							case 't':
								sb.append_c ('\t');
								break;
							}
							p++;
						}
					}
					object = sb.str;
					object_is_uri = false;
					state = State.OBJECT;

					if (accept (SparqlTokenType.DOUBLE_CIRCUMFLEX)) {
						if (!accept (SparqlTokenType.IRI_REF)) {
							accept (SparqlTokenType.PN_PREFIX);
							expect (SparqlTokenType.COLON);
						}
					}

					return true;
				} else if (accept (SparqlTokenType.STRING_LITERAL_LONG1) || accept (SparqlTokenType.STRING_LITERAL_LONG2)) {
					object = get_last_string (3);
					object_is_uri = false;
					state = State.OBJECT;

					if (accept (SparqlTokenType.DOUBLE_CIRCUMFLEX)) {
						if (!accept (SparqlTokenType.IRI_REF)) {
							accept (SparqlTokenType.PN_PREFIX);
							expect (SparqlTokenType.COLON);
						}
					}

					return true;
				} else if (accept (SparqlTokenType.INTEGER) || accept (SparqlTokenType.DECIMAL) || accept (SparqlTokenType.DOUBLE) || accept (SparqlTokenType.TRUE) || accept (SparqlTokenType.FALSE)) {
					object = get_last_string ();
					object_is_uri = false;
					state = State.OBJECT;
					return true;
				} else {
					throw get_error ("expected object");
				}
			case State.OBJECT:
				if (accept (SparqlTokenType.COMMA)) {
					state = state.PREDICATE;
					continue;
				} else if (accept (SparqlTokenType.SEMICOLON)) {
					if (accept (SparqlTokenType.DOT)) {
						// semicolon before dot is allowed in both, SPARQL and Turtle
						state = State.BOS;
						continue;
					}
					state = state.SUBJECT;
					continue;
				} else if (subject_stack.length > 0) {
					// end of anonymous blank node
					expect (SparqlTokenType.CLOSE_BRACKET);

					object = subject;
					object_is_uri = true;

					subject = subject_stack[subject_stack.length - 1];
					subject_stack.length--;

					predicate = predicate_stack[predicate_stack.length - 1];
					predicate_stack.length--;

					state = State.OBJECT;
					return true;
				} else if (accept (SparqlTokenType.DOT)) {
					state = State.BOS;
					continue;
				} else {
					throw get_error ("expected comma, semicolon, or dot");
				}
			}
		}
	}

	public static void load (string path) throws FileError, SparqlError, DataError, DBInterfaceError {
		try {
			Data.begin_transaction ();

			var reader = new TurtleReader (path);
			while (reader.next ()) {
				if (reader.object_is_uri) {
					Data.insert_statement_with_uri (reader.graph, reader.subject, reader.predicate, reader.object);
				} else {
					Data.insert_statement_with_string (reader.graph, reader.subject, reader.predicate, reader.object);
				}
			}

			Data.commit_transaction ();
		} catch (DataError e) {
			Data.rollback_transaction ();
			throw e;
		} catch (DBInterfaceError e) {
			Data.rollback_transaction ();
			throw e;
		}
	}

	[CCode (cname = "uuid_generate")]
	public extern static void uuid_generate ([CCode (array_length = false)] uchar[] uuid);
}

