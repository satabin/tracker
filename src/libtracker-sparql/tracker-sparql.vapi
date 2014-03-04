/* tracker-sparql.vapi generated by valac 0.22.1, do not modify. */

namespace Tracker {
	namespace Sparql {
		[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
		public class Builder : GLib.Object {
			public enum State {
				UPDATE,
				INSERT,
				DELETE,
				SUBJECT,
				PREDICATE,
				OBJECT,
				BLANK,
				WHERE,
				EMBEDDED_INSERT,
				GRAPH
			}
			public Builder ();
			public void append (string raw);
			public void delete_close ();
			public void delete_open (string? graph);
			public Builder.embedded_insert ();
			public void graph_close ();
			public void graph_open (string graph);
			public void insert_close ();
			public void insert_open (string? graph);
			public void insert_silent_open (string? graph);
			public void object (string s);
			public void object_blank_close ();
			public void object_blank_open ();
			public void object_boolean (bool literal);
			public void object_date (ref time_t literal);
			public void object_double (double literal);
			public void object_int64 (int64 literal);
			public void object_iri (string iri);
			public void object_string (string literal);
			public void object_unvalidated (string value);
			public void object_variable (string var_name);
			public void predicate (string s);
			public void predicate_iri (string iri);
			public void prepend (string raw);
			public void subject (string s);
			public void subject_iri (string iri);
			public void subject_variable (string var_name);
			public Builder.update ();
			public void where_close ();
			public void where_open ();
			public int length { get; private set; }
			public string result { get; }
			public Tracker.Sparql.Builder.State state { get; }
		}
		[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
		public abstract class Connection : GLib.Object {
			public Connection ();
			public static new Tracker.Sparql.Connection @get (GLib.Cancellable? cancellable = null) throws Tracker.Sparql.Error, GLib.IOError, GLib.DBusError, GLib.SpawnError;
			public static new async Tracker.Sparql.Connection get_async (GLib.Cancellable? cancellable = null) throws Tracker.Sparql.Error, GLib.IOError, GLib.DBusError, GLib.SpawnError;
			[Deprecated]
			public static new Tracker.Sparql.Connection get_direct (GLib.Cancellable? cancellable = null) throws Tracker.Sparql.Error, GLib.IOError, GLib.DBusError, GLib.SpawnError;
			[Deprecated]
			public static async Tracker.Sparql.Connection get_direct_async (GLib.Cancellable? cancellable = null) throws Tracker.Sparql.Error, GLib.IOError, GLib.DBusError, GLib.SpawnError;
			public virtual void load (GLib.File file, GLib.Cancellable? cancellable = null) throws Tracker.Sparql.Error, GLib.IOError, GLib.DBusError;
			public virtual async void load_async (GLib.File file, GLib.Cancellable? cancellable = null) throws Tracker.Sparql.Error, GLib.IOError, GLib.DBusError;
			public abstract Tracker.Sparql.Cursor query (string sparql, GLib.Cancellable? cancellable = null) throws Tracker.Sparql.Error, GLib.IOError, GLib.DBusError;
			public abstract async Tracker.Sparql.Cursor query_async (string sparql, GLib.Cancellable? cancellable = null) throws Tracker.Sparql.Error, GLib.IOError, GLib.DBusError;
			public virtual Tracker.Sparql.Cursor? statistics (GLib.Cancellable? cancellable = null) throws Tracker.Sparql.Error, GLib.IOError, GLib.DBusError;
			public virtual async Tracker.Sparql.Cursor? statistics_async (GLib.Cancellable? cancellable = null) throws Tracker.Sparql.Error, GLib.IOError, GLib.DBusError;
			public virtual void update (string sparql, int priority = GLib.Priority.DEFAULT, GLib.Cancellable? cancellable = null) throws Tracker.Sparql.Error, GLib.IOError, GLib.DBusError;
			public virtual async GLib.GenericArray<Tracker.Sparql.Error?>? update_array_async (string[] sparql, int priority = GLib.Priority.DEFAULT, GLib.Cancellable? cancellable = null) throws Tracker.Sparql.Error, GLib.IOError, GLib.DBusError;
			public virtual async void update_async (string sparql, int priority = GLib.Priority.DEFAULT, GLib.Cancellable? cancellable = null) throws Tracker.Sparql.Error, GLib.IOError, GLib.DBusError;
			public virtual GLib.Variant? update_blank (string sparql, int priority = GLib.Priority.DEFAULT, GLib.Cancellable? cancellable = null) throws Tracker.Sparql.Error, GLib.IOError, GLib.DBusError;
			public virtual async GLib.Variant? update_blank_async (string sparql, int priority = GLib.Priority.DEFAULT, GLib.Cancellable? cancellable = null) throws Tracker.Sparql.Error, GLib.IOError, GLib.DBusError;
		}
		[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
		public abstract class Cursor : GLib.Object {
			public Cursor ();
			public virtual void close ();
			public virtual bool get_boolean (int column);
			public virtual double get_double (int column);
			public virtual int64 get_integer (int column);
			public abstract unowned string? get_string (int column, out long length = null);
			public abstract Tracker.Sparql.ValueType get_value_type (int column);
			public abstract unowned string? get_variable_name (int column);
			public virtual bool is_bound (int column);
			public abstract bool next (GLib.Cancellable? cancellable = null) throws GLib.Error;
			public abstract async bool next_async (GLib.Cancellable? cancellable = null) throws GLib.Error;
			public abstract void rewind ();
			public Tracker.Sparql.Connection connection { get; set; }
			public abstract int n_columns { get; }
		}
		[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
		public enum ValueType {
			UNBOUND,
			URI,
			STRING,
			INTEGER,
			DOUBLE,
			DATETIME,
			BLANK_NODE,
			BOOLEAN
		}
		[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
		[DBus (name = "org.freedesktop.Tracker1.SparqlError")]
		public errordomain Error {
			PARSE,
			UNKNOWN_CLASS,
			UNKNOWN_PROPERTY,
			TYPE,
			CONSTRAINT,
			NO_SPACE,
			INTERNAL,
			UNSUPPORTED
		}
		[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
		public static string escape_string (string literal);
		[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
		public static string escape_uri_printf (string format, ...);
		[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
		public static string escape_uri_vprintf (string format, va_list args);
		[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
		public static string get_uuid_urn ();
	}
}
[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
public const string TRACKER_DBUS_SERVICE;
[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
public const string TRACKER_DBUS_INTERFACE_RESOURCES;
[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
public const string TRACKER_DBUS_OBJECT_RESOURCES;
[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
public const string TRACKER_DBUS_INTERFACE_STATISTICS;
[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
public const string TRACKER_DBUS_OBJECT_STATISTICS;
[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
public const string TRACKER_DBUS_INTERFACE_STATUS;
[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
public const string TRACKER_DBUS_OBJECT_STATUS;
[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
public const string TRACKER_DBUS_INTERFACE_STEROIDS;
[CCode (cheader_filename = "libtracker-sparql/tracker-generated-no-checks.h")]
public const string TRACKER_DBUS_OBJECT_STEROIDS;
