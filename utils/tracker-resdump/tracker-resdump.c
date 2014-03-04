/* tracker-resdump.c generated by valac 0.22.1, the Vala compiler
 * generated from tracker-resdump.vala, do not modify */

/*
 * Copyright (C) 2010, Nokia
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 */

#include <glib.h>
#include <glib-object.h>
#include "libtracker-sparql/tracker-sparql.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gee.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))


extern TrackerSparqlConnection* conn;
TrackerSparqlConnection* conn = NULL;
extern GeeSet* looked_up_iris;
GeeSet* looked_up_iris = NULL;

void usage (gchar** args, int args_length1);
gboolean dump_resource (const gchar* urn);
gint _vala_main (gchar** args, int args_length1);


void usage (gchar** args, int args_length1) {
	FILE* _tmp0_ = NULL;
	gchar** _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	const gchar* _tmp2_ = NULL;
#line 25 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	_tmp0_ = stderr;
#line 25 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	_tmp1_ = args;
#line 25 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	_tmp1__length1 = args_length1;
#line 25 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	_tmp2_ = _tmp1_[0];
#line 25 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	fprintf (_tmp0_, "Usage: %s urn\n", _tmp2_);
#line 62 "tracker-resdump.c"
}


static gpointer _g_object_ref0 (gpointer self) {
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	return self ? g_object_ref (self) : NULL;
#line 69 "tracker-resdump.c"
}


gboolean dump_resource (const gchar* urn) {
	gboolean result = FALSE;
	GeeList* iris_to_lookup = NULL;
	GeeArrayList* _tmp0_ = NULL;
	GeeSet* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	GError * _inner_error_ = NULL;
#line 30 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	g_return_val_if_fail (urn != NULL, FALSE);
#line 31 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	_tmp0_ = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL, NULL, NULL);
#line 31 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	iris_to_lookup = (GeeList*) _tmp0_;
#line 33 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	_tmp1_ = looked_up_iris;
#line 33 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	_tmp2_ = urn;
#line 33 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	gee_collection_add ((GeeCollection*) _tmp1_, _tmp2_);
#line 92 "tracker-resdump.c"
	{
		TrackerSparqlCursor* cursor = NULL;
		TrackerSparqlConnection* _tmp3_ = NULL;
		const gchar* _tmp4_ = NULL;
		gchar* _tmp5_ = NULL;
		gchar* _tmp6_ = NULL;
		TrackerSparqlCursor* _tmp7_ = NULL;
		TrackerSparqlCursor* _tmp8_ = NULL;
		GeeList* type_statements = NULL;
		GeeArrayList* _tmp9_ = NULL;
		GeeList* statements = NULL;
		GeeArrayList* _tmp10_ = NULL;
#line 36 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp3_ = conn;
#line 36 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp4_ = urn;
#line 36 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp5_ = g_strdup_printf ("SELECT ?p rdfs:range(?p) ?o {<%s> ?p ?o}", _tmp4_);
#line 36 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp6_ = _tmp5_;
#line 36 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp7_ = tracker_sparql_connection_query (_tmp3_, _tmp6_, NULL, &_inner_error_);
#line 36 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp8_ = _tmp7_;
#line 36 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_g_free0 (_tmp6_);
#line 36 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		cursor = _tmp8_;
#line 36 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		if (_inner_error_ != NULL) {
#line 123 "tracker-resdump.c"
			goto __catch0_g_error;
		}
#line 38 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp9_ = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL, NULL, NULL);
#line 38 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		type_statements = (GeeList*) _tmp9_;
#line 39 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp10_ = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL, NULL, NULL);
#line 39 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		statements = (GeeList*) _tmp10_;
#line 41 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		while (TRUE) {
#line 136 "tracker-resdump.c"
			gboolean _tmp11_ = FALSE;
			TrackerSparqlCursor* _tmp12_ = NULL;
			gboolean _tmp13_ = FALSE;
			TrackerSparqlCursor* _tmp14_ = NULL;
			const gchar* _tmp15_ = NULL;
			gboolean _tmp16_ = FALSE;
			gchar* statement = NULL;
			const gchar* _tmp17_ = NULL;
			TrackerSparqlCursor* _tmp18_ = NULL;
			const gchar* _tmp19_ = NULL;
			gchar* _tmp20_ = NULL;
			TrackerSparqlCursor* _tmp21_ = NULL;
			const gchar* _tmp22_ = NULL;
			const gchar* _tmp23_ = NULL;
			GQuark _tmp25_ = 0U;
#line 49 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			static GQuark _tmp24_label0 = 0;
#line 49 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			static GQuark _tmp24_label1 = 0;
#line 49 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			static GQuark _tmp24_label2 = 0;
#line 49 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			static GQuark _tmp24_label3 = 0;
#line 49 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			static GQuark _tmp24_label4 = 0;
#line 162 "tracker-resdump.c"
			TrackerSparqlCursor* _tmp52_ = NULL;
			const gchar* _tmp53_ = NULL;
#line 41 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp12_ = cursor;
#line 41 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp13_ = tracker_sparql_cursor_next (_tmp12_, NULL, &_inner_error_);
#line 41 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp11_ = _tmp13_;
#line 41 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			if (_inner_error_ != NULL) {
#line 41 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_g_object_unref0 (statements);
#line 41 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_g_object_unref0 (type_statements);
#line 41 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_g_object_unref0 (cursor);
#line 179 "tracker-resdump.c"
				goto __catch0_g_error;
			}
#line 41 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			if (!_tmp11_) {
#line 41 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				break;
#line 186 "tracker-resdump.c"
			}
#line 43 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp14_ = cursor;
#line 43 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp15_ = tracker_sparql_cursor_get_string (_tmp14_, 0, NULL);
#line 43 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp16_ = g_str_has_prefix (_tmp15_, "http://www.tracker-project.org/ontologies/tracker#");
#line 43 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			if (_tmp16_) {
#line 44 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				continue;
#line 198 "tracker-resdump.c"
			}
#line 47 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp17_ = urn;
#line 47 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp18_ = cursor;
#line 47 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp19_ = tracker_sparql_cursor_get_string (_tmp18_, 0, NULL);
#line 47 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp20_ = g_strdup_printf ("<%s> <%s> ", _tmp17_, _tmp19_);
#line 47 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			statement = _tmp20_;
#line 49 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp21_ = cursor;
#line 49 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp22_ = tracker_sparql_cursor_get_string (_tmp21_, 1, NULL);
#line 49 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp23_ = _tmp22_;
#line 49 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp25_ = (NULL == _tmp23_) ? 0 : g_quark_from_string (_tmp23_);
#line 49 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			if ((_tmp25_ == ((0 != _tmp24_label0) ? _tmp24_label0 : (_tmp24_label0 = g_quark_from_static_string ("http://www.w3.org/2001/XMLSchema#string")))) || (_tmp25_ == ((0 != _tmp24_label1) ? _tmp24_label1 : (_tmp24_label1 = g_quark_from_static_string ("http://www.w3.org/2001/XMLSchema#dateTime"))))) {
#line 49 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				switch (0) {
#line 222 "tracker-resdump.c"
					default:
					{
						const gchar* _tmp26_ = NULL;
						TrackerSparqlCursor* _tmp27_ = NULL;
						const gchar* _tmp28_ = NULL;
						gchar* _tmp29_ = NULL;
						gchar* _tmp30_ = NULL;
						gchar* _tmp31_ = NULL;
						gchar* _tmp32_ = NULL;
						gchar* _tmp33_ = NULL;
#line 52 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp26_ = statement;
#line 52 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp27_ = cursor;
#line 52 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp28_ = tracker_sparql_cursor_get_string (_tmp27_, 2, NULL);
#line 52 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp29_ = tracker_sparql_escape_string (_tmp28_);
#line 52 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp30_ = _tmp29_;
#line 52 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp31_ = g_strdup_printf ("\"%s\"", _tmp30_);
#line 52 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp32_ = _tmp31_;
#line 52 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp33_ = g_strconcat (_tmp26_, _tmp32_, NULL);
#line 52 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_g_free0 (statement);
#line 52 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						statement = _tmp33_;
#line 52 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_g_free0 (_tmp32_);
#line 52 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_g_free0 (_tmp30_);
#line 53 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						break;
#line 259 "tracker-resdump.c"
					}
				}
			} else if (((_tmp25_ == ((0 != _tmp24_label2) ? _tmp24_label2 : (_tmp24_label2 = g_quark_from_static_string ("http://www.w3.org/2001/XMLSchema#integer")))) || (_tmp25_ == ((0 != _tmp24_label3) ? _tmp24_label3 : (_tmp24_label3 = g_quark_from_static_string ("http://www.w3.org/2001/XMLSchema#double"))))) || (_tmp25_ == ((0 != _tmp24_label4) ? _tmp24_label4 : (_tmp24_label4 = g_quark_from_static_string ("http://www.w3.org/2001/XMLSchema#boolean"))))) {
#line 49 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				switch (0) {
#line 265 "tracker-resdump.c"
					default:
					{
						const gchar* _tmp34_ = NULL;
						TrackerSparqlCursor* _tmp35_ = NULL;
						const gchar* _tmp36_ = NULL;
						gchar* _tmp37_ = NULL;
						gchar* _tmp38_ = NULL;
						gchar* _tmp39_ = NULL;
#line 57 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp34_ = statement;
#line 57 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp35_ = cursor;
#line 57 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp36_ = tracker_sparql_cursor_get_string (_tmp35_, 2, NULL);
#line 57 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp37_ = g_strdup_printf ("%s", _tmp36_);
#line 57 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp38_ = _tmp37_;
#line 57 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp39_ = g_strconcat (_tmp34_, _tmp38_, NULL);
#line 57 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_g_free0 (statement);
#line 57 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						statement = _tmp39_;
#line 57 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_g_free0 (_tmp38_);
#line 58 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						break;
#line 294 "tracker-resdump.c"
					}
				}
			} else {
#line 49 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				switch (0) {
#line 300 "tracker-resdump.c"
					default:
					{
						const gchar* obj = NULL;
						TrackerSparqlCursor* _tmp40_ = NULL;
						const gchar* _tmp41_ = NULL;
						GeeSet* _tmp42_ = NULL;
						const gchar* _tmp43_ = NULL;
						gboolean _tmp44_ = FALSE;
						const gchar* _tmp47_ = NULL;
						const gchar* _tmp48_ = NULL;
						gchar* _tmp49_ = NULL;
						gchar* _tmp50_ = NULL;
						gchar* _tmp51_ = NULL;
#line 61 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp40_ = cursor;
#line 61 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp41_ = tracker_sparql_cursor_get_string (_tmp40_, 2, NULL);
#line 61 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						obj = _tmp41_;
#line 62 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp42_ = looked_up_iris;
#line 62 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp43_ = obj;
#line 62 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp44_ = gee_collection_contains ((GeeCollection*) _tmp42_, _tmp43_);
#line 62 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						if (!_tmp44_) {
#line 328 "tracker-resdump.c"
							GeeList* _tmp45_ = NULL;
							const gchar* _tmp46_ = NULL;
#line 63 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
							_tmp45_ = iris_to_lookup;
#line 63 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
							_tmp46_ = obj;
#line 63 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
							gee_collection_add ((GeeCollection*) _tmp45_, _tmp46_);
#line 337 "tracker-resdump.c"
						}
#line 65 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp47_ = statement;
#line 65 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp48_ = obj;
#line 65 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp49_ = g_strdup_printf ("<%s>", _tmp48_);
#line 65 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp50_ = _tmp49_;
#line 65 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_tmp51_ = g_strconcat (_tmp47_, _tmp50_, NULL);
#line 65 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_g_free0 (statement);
#line 65 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						statement = _tmp51_;
#line 65 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						_g_free0 (_tmp50_);
#line 66 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
						break;
#line 357 "tracker-resdump.c"
					}
				}
			}
#line 69 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp52_ = cursor;
#line 69 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp53_ = tracker_sparql_cursor_get_string (_tmp52_, 0, NULL);
#line 69 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			if (g_strcmp0 (_tmp53_, "http://www.w3.org/1999/02/22-rdf-syntax-ns#type") == 0) {
#line 367 "tracker-resdump.c"
				GeeList* _tmp54_ = NULL;
				const gchar* _tmp55_ = NULL;
#line 70 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp54_ = type_statements;
#line 70 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp55_ = statement;
#line 70 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				gee_collection_add ((GeeCollection*) _tmp54_, _tmp55_);
#line 376 "tracker-resdump.c"
			} else {
				GeeList* _tmp56_ = NULL;
				const gchar* _tmp57_ = NULL;
#line 72 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp56_ = statements;
#line 72 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp57_ = statement;
#line 72 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				gee_collection_add ((GeeCollection*) _tmp56_, _tmp57_);
#line 386 "tracker-resdump.c"
			}
#line 41 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_g_free0 (statement);
#line 390 "tracker-resdump.c"
		}
		{
			GeeList* _s_list = NULL;
			GeeList* _tmp58_ = NULL;
			GeeList* _tmp59_ = NULL;
			gint _s_size = 0;
			GeeList* _tmp60_ = NULL;
			gint _tmp61_ = 0;
			gint _tmp62_ = 0;
			gint _s_index = 0;
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp58_ = type_statements;
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp59_ = _g_object_ref0 (_tmp58_);
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_s_list = _tmp59_;
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp60_ = _s_list;
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp61_ = gee_collection_get_size ((GeeCollection*) _tmp60_);
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp62_ = _tmp61_;
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_s_size = _tmp62_;
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_s_index = -1;
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			while (TRUE) {
#line 419 "tracker-resdump.c"
				gint _tmp63_ = 0;
				gint _tmp64_ = 0;
				gint _tmp65_ = 0;
				gchar* s = NULL;
				GeeList* _tmp66_ = NULL;
				gint _tmp67_ = 0;
				gpointer _tmp68_ = NULL;
				FILE* _tmp69_ = NULL;
				const gchar* _tmp70_ = NULL;
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp63_ = _s_index;
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_s_index = _tmp63_ + 1;
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp64_ = _s_index;
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp65_ = _s_size;
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				if (!(_tmp64_ < _tmp65_)) {
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
					break;
#line 441 "tracker-resdump.c"
				}
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp66_ = _s_list;
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp67_ = _s_index;
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp68_ = gee_list_get (_tmp66_, _tmp67_);
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				s = (gchar*) _tmp68_;
#line 77 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp69_ = stdout;
#line 77 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp70_ = s;
#line 77 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				fprintf (_tmp69_, "%s .\n", _tmp70_);
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_g_free0 (s);
#line 459 "tracker-resdump.c"
			}
#line 76 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_g_object_unref0 (_s_list);
#line 463 "tracker-resdump.c"
		}
		{
			GeeList* _s_list = NULL;
			GeeList* _tmp71_ = NULL;
			GeeList* _tmp72_ = NULL;
			gint _s_size = 0;
			GeeList* _tmp73_ = NULL;
			gint _tmp74_ = 0;
			gint _tmp75_ = 0;
			gint _s_index = 0;
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp71_ = statements;
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp72_ = _g_object_ref0 (_tmp71_);
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_s_list = _tmp72_;
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp73_ = _s_list;
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp74_ = gee_collection_get_size ((GeeCollection*) _tmp73_);
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp75_ = _tmp74_;
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_s_size = _tmp75_;
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_s_index = -1;
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			while (TRUE) {
#line 492 "tracker-resdump.c"
				gint _tmp76_ = 0;
				gint _tmp77_ = 0;
				gint _tmp78_ = 0;
				gchar* s = NULL;
				GeeList* _tmp79_ = NULL;
				gint _tmp80_ = 0;
				gpointer _tmp81_ = NULL;
				FILE* _tmp82_ = NULL;
				const gchar* _tmp83_ = NULL;
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp76_ = _s_index;
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_s_index = _tmp76_ + 1;
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp77_ = _s_index;
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp78_ = _s_size;
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				if (!(_tmp77_ < _tmp78_)) {
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
					break;
#line 514 "tracker-resdump.c"
				}
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp79_ = _s_list;
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp80_ = _s_index;
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp81_ = gee_list_get (_tmp79_, _tmp80_);
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				s = (gchar*) _tmp81_;
#line 81 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp82_ = stdout;
#line 81 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp83_ = s;
#line 81 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				fprintf (_tmp82_, "%s .\n", _tmp83_);
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_g_free0 (s);
#line 532 "tracker-resdump.c"
			}
#line 80 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_g_object_unref0 (_s_list);
#line 536 "tracker-resdump.c"
		}
		{
			GeeList* _s_list = NULL;
			GeeList* _tmp84_ = NULL;
			GeeList* _tmp85_ = NULL;
			gint _s_size = 0;
			GeeList* _tmp86_ = NULL;
			gint _tmp87_ = 0;
			gint _tmp88_ = 0;
			gint _s_index = 0;
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp84_ = iris_to_lookup;
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp85_ = _g_object_ref0 (_tmp84_);
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_s_list = _tmp85_;
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp86_ = _s_list;
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp87_ = gee_collection_get_size ((GeeCollection*) _tmp86_);
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_tmp88_ = _tmp87_;
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_s_size = _tmp88_;
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_s_index = -1;
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			while (TRUE) {
#line 565 "tracker-resdump.c"
				gint _tmp89_ = 0;
				gint _tmp90_ = 0;
				gint _tmp91_ = 0;
				gchar* s = NULL;
				GeeList* _tmp92_ = NULL;
				gint _tmp93_ = 0;
				gpointer _tmp94_ = NULL;
				const gchar* _tmp95_ = NULL;
				gboolean _tmp96_ = FALSE;
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp89_ = _s_index;
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_s_index = _tmp89_ + 1;
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp90_ = _s_index;
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp91_ = _s_size;
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				if (!(_tmp90_ < _tmp91_)) {
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
					break;
#line 587 "tracker-resdump.c"
				}
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp92_ = _s_list;
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp93_ = _s_index;
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp94_ = gee_list_get (_tmp92_, _tmp93_);
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				s = (gchar*) _tmp94_;
#line 85 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp95_ = s;
#line 85 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_tmp96_ = dump_resource (_tmp95_);
#line 85 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				if (!_tmp96_) {
#line 86 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
					result = FALSE;
#line 86 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
					_g_free0 (s);
#line 86 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
					_g_object_unref0 (_s_list);
#line 86 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
					_g_object_unref0 (statements);
#line 86 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
					_g_object_unref0 (type_statements);
#line 86 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
					_g_object_unref0 (cursor);
#line 86 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
					_g_object_unref0 (iris_to_lookup);
#line 86 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
					return result;
#line 619 "tracker-resdump.c"
				}
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
				_g_free0 (s);
#line 623 "tracker-resdump.c"
			}
#line 84 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
			_g_object_unref0 (_s_list);
#line 627 "tracker-resdump.c"
		}
#line 35 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_g_object_unref0 (statements);
#line 35 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_g_object_unref0 (type_statements);
#line 35 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_g_object_unref0 (cursor);
#line 635 "tracker-resdump.c"
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		const gchar* _tmp97_ = NULL;
		GError* _tmp98_ = NULL;
		const gchar* _tmp99_ = NULL;
#line 35 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		e = _inner_error_;
#line 35 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_inner_error_ = NULL;
#line 90 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp97_ = urn;
#line 90 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp98_ = e;
#line 90 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp99_ = _tmp98_->message;
#line 90 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		g_critical ("tracker-resdump.vala:90: Couldn't query info for resource %s: %s", _tmp97_, _tmp99_);
#line 91 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		result = FALSE;
#line 91 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_g_error_free0 (e);
#line 91 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_g_object_unref0 (iris_to_lookup);
#line 91 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		return result;
#line 664 "tracker-resdump.c"
	}
	__finally0:
#line 35 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	if (_inner_error_ != NULL) {
#line 35 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_g_object_unref0 (iris_to_lookup);
#line 35 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 35 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		g_clear_error (&_inner_error_);
#line 35 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		return FALSE;
#line 677 "tracker-resdump.c"
	}
#line 94 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	result = TRUE;
#line 94 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	_g_object_unref0 (iris_to_lookup);
#line 94 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	return result;
#line 685 "tracker-resdump.c"
}


gint _vala_main (gchar** args, int args_length1) {
	gint result = 0;
	gchar** _tmp0_ = NULL;
	gint _tmp0__length1 = 0;
	GeeHashSet* _tmp6_ = NULL;
	gchar** _tmp7_ = NULL;
	gint _tmp7__length1 = 0;
	const gchar* _tmp8_ = NULL;
	gboolean _tmp9_ = FALSE;
	GError * _inner_error_ = NULL;
#line 99 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	_tmp0_ = args;
#line 99 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	_tmp0__length1 = args_length1;
#line 99 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	if (_tmp0__length1 != 2) {
#line 705 "tracker-resdump.c"
		gchar** _tmp1_ = NULL;
		gint _tmp1__length1 = 0;
#line 100 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp1_ = args;
#line 100 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp1__length1 = args_length1;
#line 100 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		usage (_tmp1_, _tmp1__length1);
#line 101 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		result = 1;
#line 101 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		return result;
#line 718 "tracker-resdump.c"
	}
	{
		TrackerSparqlConnection* _tmp2_ = NULL;
		TrackerSparqlConnection* _tmp3_ = NULL;
#line 105 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp3_ = tracker_sparql_connection_get (NULL, &_inner_error_);
#line 105 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp2_ = _tmp3_;
#line 105 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		if (_inner_error_ != NULL) {
#line 729 "tracker-resdump.c"
			goto __catch1_g_error;
		}
#line 105 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_g_object_unref0 (conn);
#line 105 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		conn = _tmp2_;
#line 736 "tracker-resdump.c"
	}
	goto __finally1;
	__catch1_g_error:
	{
		GError* e = NULL;
		GError* _tmp4_ = NULL;
		const gchar* _tmp5_ = NULL;
#line 104 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		e = _inner_error_;
#line 104 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_inner_error_ = NULL;
#line 107 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp4_ = e;
#line 107 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_tmp5_ = _tmp4_->message;
#line 107 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		g_critical ("tracker-resdump.vala:107: Couldn't connect to Tracker: %s", _tmp5_);
#line 108 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		result = 1;
#line 108 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		_g_error_free0 (e);
#line 108 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		return result;
#line 760 "tracker-resdump.c"
	}
	__finally1:
#line 104 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	if (_inner_error_ != NULL) {
#line 104 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 104 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		g_clear_error (&_inner_error_);
#line 104 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		return 0;
#line 771 "tracker-resdump.c"
	}
#line 111 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	_tmp6_ = gee_hash_set_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL, NULL, NULL, NULL, NULL, NULL);
#line 111 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	_g_object_unref0 (looked_up_iris);
#line 111 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	looked_up_iris = (GeeSet*) _tmp6_;
#line 113 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	_tmp7_ = args;
#line 113 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	_tmp7__length1 = args_length1;
#line 113 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	_tmp8_ = _tmp7_[1];
#line 113 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	_tmp9_ = dump_resource (_tmp8_);
#line 113 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	if (_tmp9_) {
#line 114 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		result = 0;
#line 114 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
		return result;
#line 793 "tracker-resdump.c"
	}
#line 117 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	result = 1;
#line 117 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	return result;
#line 799 "tracker-resdump.c"
}


int main (int argc, char ** argv) {
#line 97 "/home/martyn/Source/tracker/utils/tracker-resdump/tracker-resdump.vala"
	return _vala_main (argv, argc);
#line 806 "tracker-resdump.c"
}



