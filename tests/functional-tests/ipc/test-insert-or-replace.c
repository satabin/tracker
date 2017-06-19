/* test-insert-or-replace.c generated by valac 0.35.6.22-1f654-dirty, the Vala compiler
 * generated from test-insert-or-replace.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include "libtracker-sparql/tracker-sparql.h"

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_timer_destroy0(var) ((var == NULL) ? NULL : (var = (g_timer_destroy (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))



#define insert_query_replace "\n" \
"DELETE { ?r nao:hasProperty ?property . }\n" \
"WHERE { \n" \
"	?r a nco:PhoneNumber;\n" \
"	   nco:phoneNumber \"02141730585%d\";\n" \
"	   nao:hasProperty ?property .\n" \
"}\n" \
"\n" \
"DELETE {\n" \
"	?r a nco:CarPhoneNumber, nco:BbsNumber, nco:PagerNumber,\n" \
"	     nco:VideoTelephoneNumber, nco:MessagingNumber, nco:VoicePhoneNum" \
"ber,\n" \
"	     nco:CellPhoneNumber, nco:FaxNumber, nco:ModemNumber .\n" \
"} WHERE {\n" \
"	?r a nco:PhoneNumber;\n" \
"	   nco:phoneNumber \"02141730585%d\" .\n" \
"}\n" \
"\n" \
"INSERT {\n" \
"	_:tel a nco:PhoneNumber ;\n" \
"	      nco:phoneNumber \"02141730585%d\" .\n" \
"} WHERE {\n" \
"	OPTIONAL {\n" \
"		?r a nco:PhoneNumber;\n" \
"		   nco:phoneNumber \"02141730585%d\" .\n" \
"	}\n" \
"	FILTER(!bound(?r)) .\n" \
"}\n" \
"\n" \
"INSERT OR REPLACE { <mailto:rhome0@example.com%d> a nco:EmailAddress ;" \
"\n" \
"		nco:emailAddress \"rhome0@example.com%d\" . }\n" \
"\n" \
"DELETE { <contact:r:%d> nco:hasAffiliation ?e . ?e a rdfs:Resource }\n" \
"WHERE { <contact:r:%d> a nco:PersonContact ; nco:hasAffiliation ?e }\n" \
"\n" \
"INSERT OR REPLACE {\n" \
"	_:af1 a nco:Affiliation ;\n" \
"	      rdfs:label \"Work\" ;\n" \
"	      nco:hasEmailAddress <mailto:rhome0@example.com%d> .\n" \
"\n" \
"	_:af2 a nco:Affiliation ;\n" \
"	      rdfs:label \"Other\" ;\n" \
"	      nco:hasPhoneNumber ?tel .\n" \
"\n" \
"	<contact:r:%d> a nco:PersonContact ;\n" \
"	               nco:nameGiven \"First %d\" ;\n" \
"	               nco:nameFamily \"Last %d\" ;\n" \
"	               nco:hasAffiliation _:af1 ;\n" \
"	               nco:hasAffiliation _:af2 ;\n" \
"	               nie:contentCreated \"2011-03-14T13:47:25\" ;\n" \
"	               nco:contactUID \"c1f1b12d-bc75-4d45-9a1f-b1efe934409f\"" \
" .\n" \
"} WHERE {\n" \
"	?tel nco:phoneNumber \"02141730585%d\"\n" \
"}"
#define insert_query_original "\n" \
"DELETE { ?r nao:hasProperty ?property . }\n" \
"WHERE { \n" \
"	?r a nco:PhoneNumber; nco:phoneNumber \"2141730585%d\";\n" \
"	   nao:hasProperty ?property .\n" \
"}\n" \
"\n" \
"DELETE {\n" \
"	?r a nco:CarPhoneNumber, nco:BbsNumber, nco:PagerNumber,\n" \
"	     nco:VideoTelephoneNumber, nco:MessagingNumber, nco:VoicePhoneNum" \
"ber,\n" \
"	     nco:CellPhoneNumber, nco:FaxNumber, nco:ModemNumber .\n" \
"} WHERE {\n" \
"	?r a nco:PhoneNumber;\n" \
"	   nco:phoneNumber \"2141730585%d\" .\n" \
"}\n" \
"\n" \
"INSERT {\n" \
"	_:tel a nco:PhoneNumber ;\n" \
"	      nco:phoneNumber \"2141730585%d\" .\n" \
"} WHERE {\n" \
"	OPTIONAL {\n" \
"		?r a nco:PhoneNumber;\n" \
"		   nco:phoneNumber \"2141730585%d\" .\n" \
"	}\n" \
"	FILTER(!bound(?r)) .\n" \
"}\n" \
"\n" \
"INSERT { <mailto:home0@example.com%d> a nco:EmailAddress ;\n" \
"			nco:emailAddress \"home0@example.com%d\" . }\n" \
"\n" \
"DELETE { <contact:o:%d> nco:hasAffiliation ?e . ?e a rdfs:Resource }\n" \
"WHERE { <contact:o:%d> a nco:PersonContact ; nco:hasAffiliation ?e }\n" \
"\n" \
"DELETE { GRAPH <urn:uuid:08070f5c-a334-4d19-a8b0-12a3071bfab9> {\n" \
"    <contact:o:%d> ?predicate ?object .\n" \
"} } WHERE { GRAPH <urn:uuid:08070f5c-a334-4d19-a8b0-12a3071bfab9> {\n" \
"    <contact:o:%d> ?predicate ?object .\n" \
"    FILTER(?predicate NOT IN (nco:contactLocalUID,nco:contactUID,rdf:t" \
"ype)) .\n" \
"} }\n" \
"\n" \
"INSERT { GRAPH <urn:uuid:08070f5c-a334-4d19-a8b0-12a3071bfab9> {\n" \
"	_:af1 a nco:Affiliation ;\n" \
"	      rdfs:label \"Work\" ;\n" \
"	      nco:hasEmailAddress <mailto:home0@example.com%d> .\n" \
"\n" \
"	_:af2 a nco:Affiliation ;\n" \
"	      rdfs:label \"Other\" ;\n" \
"	      nco:hasPhoneNumber ?tel .\n" \
"\n" \
"	<contact:o:%d> a nco:PersonContact ;\n" \
"	               nco:nameGiven \"First %d\" ;\n" \
"	               nco:nameFamily \"Last %d\" ;\n" \
"	               nco:hasAffiliation _:af1 ;\n" \
"	               nco:hasAffiliation _:af2 ;\n" \
"	               nie:contentCreated \"2011-03-14T13:47:25\" ;\n" \
"	               nco:contactUID \"c1f1b12d-bc75-4d45-9a1f-b1efe934409f\"" \
" .\n" \
"} } WHERE {\n" \
"	?tel nco:phoneNumber \"2141730585%d\"\n" \
"}"
gint _vala_main (gchar** args, int args_length1);


gint _vala_main (gchar** args, int args_length1) {
	gint result = 0;
	GError * _inner_error_ = NULL;
	{
		guint i = 0U;
		guint y;
		GTimer* timer;
		GTimer* _tmp0_;
		TrackerSparqlConnection* c = NULL;
		TrackerSparqlConnection* _tmp1_;
		TrackerSparqlConnection* _tmp2_;
		TrackerSparqlConnection* _tmp3_;
		gchar** _tmp4_;
		gint _tmp4__length1;
		gboolean _tmp8_ = FALSE;
		gchar** _tmp9_;
		gint _tmp9__length1;
		gboolean _tmp37_ = FALSE;
		gchar** _tmp38_;
		gint _tmp38__length1;
#line 122 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		y = (guint) 100;
#line 123 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_tmp0_ = g_timer_new ();
#line 123 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		timer = _tmp0_;
#line 125 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_tmp2_ = tracker_sparql_connection_get (NULL, &_inner_error_);
#line 125 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_tmp1_ = _tmp2_;
#line 125 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 125 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_g_object_unref0 (c);
#line 125 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_g_timer_destroy0 (timer);
#line 60 "test-insert-or-replace.c"
			goto __catch0_g_error;
		}
#line 125 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_tmp3_ = _tmp1_;
#line 125 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_tmp1_ = NULL;
#line 125 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_g_object_unref0 (c);
#line 125 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		c = _tmp3_;
#line 127 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_tmp4_ = args;
#line 127 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_tmp4__length1 = args_length1;
#line 127 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		if (_tmp4__length1 == 3) {
#line 77 "test-insert-or-replace.c"
			gchar** _tmp5_;
			gint _tmp5__length1;
			const gchar* _tmp6_;
			gint _tmp7_;
#line 128 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp5_ = args;
#line 128 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp5__length1 = args_length1;
#line 128 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp6_ = _tmp5_[2];
#line 128 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp7_ = atoi (_tmp6_);
#line 128 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			y = (guint) _tmp7_;
#line 92 "test-insert-or-replace.c"
		}
#line 131 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_tmp9_ = args;
#line 131 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_tmp9__length1 = args_length1;
#line 131 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		if (_tmp9__length1 == 1) {
#line 131 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp8_ = TRUE;
#line 102 "test-insert-or-replace.c"
		} else {
			gchar** _tmp10_;
			gint _tmp10__length1;
			const gchar* _tmp11_;
#line 131 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp10_ = args;
#line 131 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp10__length1 = args_length1;
#line 131 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp11_ = _tmp10_[1];
#line 131 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp8_ = g_strcmp0 (_tmp11_, "replace") == 0;
#line 115 "test-insert-or-replace.c"
		}
#line 131 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		if (_tmp8_) {
#line 119 "test-insert-or-replace.c"
			GTimer* _tmp12_;
			GTimer* _tmp33_;
			guint _tmp34_;
			GTimer* _tmp35_;
			gdouble _tmp36_;
#line 132 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp12_ = timer;
#line 132 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			g_timer_start (_tmp12_);
#line 129 "test-insert-or-replace.c"
			{
				gboolean _tmp13_;
#line 133 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
				i = (guint) 0;
#line 133 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
				_tmp13_ = TRUE;
#line 133 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
				while (TRUE) {
#line 138 "test-insert-or-replace.c"
					guint _tmp15_;
					guint _tmp16_;
					TrackerSparqlConnection* _tmp17_;
					guint _tmp18_;
					guint _tmp19_;
					guint _tmp20_;
					guint _tmp21_;
					guint _tmp22_;
					guint _tmp23_;
					guint _tmp24_;
					guint _tmp25_;
					guint _tmp26_;
					guint _tmp27_;
					guint _tmp28_;
					guint _tmp29_;
					guint _tmp30_;
					gchar* _tmp31_;
					gchar* _tmp32_;
#line 133 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					if (!_tmp13_) {
#line 159 "test-insert-or-replace.c"
						guint _tmp14_;
#line 133 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
						_tmp14_ = i;
#line 133 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
						i = _tmp14_ + 1;
#line 165 "test-insert-or-replace.c"
					}
#line 133 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp13_ = FALSE;
#line 133 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp15_ = i;
#line 133 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp16_ = y;
#line 133 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					if (!(_tmp15_ < _tmp16_)) {
#line 133 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
						break;
#line 177 "test-insert-or-replace.c"
					}
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp17_ = c;
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp18_ = i;
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp19_ = i;
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp20_ = i;
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp21_ = i;
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp22_ = i;
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp23_ = i;
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp24_ = i;
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp25_ = i;
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp26_ = i;
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp27_ = i;
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp28_ = i;
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp29_ = i;
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp30_ = i;
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp31_ = g_strdup_printf (insert_query_replace, _tmp18_, _tmp19_, _tmp20_, _tmp21_, _tmp22_, _tmp23_, _tmp24_, _tmp25_, _tmp26_, _tmp27_, _tmp28_, _tmp29_, _tmp30_);
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp32_ = _tmp31_;
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					tracker_sparql_connection_update (_tmp17_, _tmp32_, G_PRIORITY_DEFAULT, NULL, &_inner_error_);
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_g_free0 (_tmp32_);
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
						_g_object_unref0 (_tmp1_);
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
						_g_object_unref0 (c);
#line 134 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
						_g_timer_destroy0 (timer);
#line 223 "test-insert-or-replace.c"
						goto __catch0_g_error;
					}
				}
			}
#line 136 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp33_ = timer;
#line 136 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			g_timer_stop (_tmp33_);
#line 138 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp34_ = y;
#line 138 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp35_ = timer;
#line 138 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp36_ = g_timer_elapsed (_tmp35_, NULL);
#line 138 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			g_print ("REPLACE  : %u contacts: %f\n", _tmp34_, _tmp36_);
#line 240 "test-insert-or-replace.c"
		}
#line 142 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_tmp38_ = args;
#line 142 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_tmp38__length1 = args_length1;
#line 142 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		if (_tmp38__length1 == 1) {
#line 142 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp37_ = TRUE;
#line 250 "test-insert-or-replace.c"
		} else {
			gchar** _tmp39_;
			gint _tmp39__length1;
			const gchar* _tmp40_;
#line 142 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp39_ = args;
#line 142 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp39__length1 = args_length1;
#line 142 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp40_ = _tmp39_[1];
#line 142 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp37_ = g_strcmp0 (_tmp40_, "original") == 0;
#line 263 "test-insert-or-replace.c"
		}
#line 142 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		if (_tmp37_) {
#line 267 "test-insert-or-replace.c"
			GTimer* _tmp41_;
			GTimer* _tmp64_;
			guint _tmp65_;
			GTimer* _tmp66_;
			gdouble _tmp67_;
#line 143 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp41_ = timer;
#line 143 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			g_timer_start (_tmp41_);
#line 277 "test-insert-or-replace.c"
			{
				gboolean _tmp42_;
#line 144 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
				i = (guint) 0;
#line 144 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
				_tmp42_ = TRUE;
#line 144 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
				while (TRUE) {
#line 286 "test-insert-or-replace.c"
					guint _tmp44_;
					guint _tmp45_;
					TrackerSparqlConnection* _tmp46_;
					guint _tmp47_;
					guint _tmp48_;
					guint _tmp49_;
					guint _tmp50_;
					guint _tmp51_;
					guint _tmp52_;
					guint _tmp53_;
					guint _tmp54_;
					guint _tmp55_;
					guint _tmp56_;
					guint _tmp57_;
					guint _tmp58_;
					guint _tmp59_;
					guint _tmp60_;
					guint _tmp61_;
					gchar* _tmp62_;
					gchar* _tmp63_;
#line 144 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					if (!_tmp42_) {
#line 309 "test-insert-or-replace.c"
						guint _tmp43_;
#line 144 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
						_tmp43_ = i;
#line 144 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
						i = _tmp43_ + 1;
#line 315 "test-insert-or-replace.c"
					}
#line 144 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp42_ = FALSE;
#line 144 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp44_ = i;
#line 144 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp45_ = y;
#line 144 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					if (!(_tmp44_ < _tmp45_)) {
#line 144 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
						break;
#line 327 "test-insert-or-replace.c"
					}
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp46_ = c;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp47_ = i;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp48_ = i;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp49_ = i;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp50_ = i;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp51_ = i;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp52_ = i;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp53_ = i;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp54_ = i;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp55_ = i;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp56_ = i;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp57_ = i;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp58_ = i;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp59_ = i;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp60_ = i;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp61_ = i;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp62_ = g_strdup_printf (insert_query_original, _tmp47_, _tmp48_, _tmp49_, _tmp50_, _tmp51_, _tmp52_, _tmp53_, _tmp54_, _tmp55_, _tmp56_, _tmp57_, _tmp58_, _tmp59_, _tmp60_, _tmp61_);
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_tmp63_ = _tmp62_;
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					tracker_sparql_connection_update (_tmp46_, _tmp63_, G_PRIORITY_DEFAULT, NULL, &_inner_error_);
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					_g_free0 (_tmp63_);
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
					if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
						_g_object_unref0 (_tmp1_);
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
						_g_object_unref0 (c);
#line 145 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
						_g_timer_destroy0 (timer);
#line 377 "test-insert-or-replace.c"
						goto __catch0_g_error;
					}
				}
			}
#line 147 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp64_ = timer;
#line 147 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			g_timer_stop (_tmp64_);
#line 149 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp65_ = y;
#line 149 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp66_ = timer;
#line 149 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			_tmp67_ = g_timer_elapsed (_tmp66_, NULL);
#line 149 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
			g_print ("ORIGINAL : %u contacts: %f\n", _tmp65_, _tmp67_);
#line 394 "test-insert-or-replace.c"
		}
#line 121 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_g_object_unref0 (_tmp1_);
#line 121 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_g_object_unref0 (c);
#line 121 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_g_timer_destroy0 (timer);
#line 402 "test-insert-or-replace.c"
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		GError* _tmp68_;
		const gchar* _tmp69_;
#line 121 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		e = _inner_error_;
#line 121 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_inner_error_ = NULL;
#line 152 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_tmp68_ = e;
#line 152 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_tmp69_ = _tmp68_->message;
#line 152 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		g_critical ("test-insert-or-replace.vala:152: %s", _tmp69_);
#line 121 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		_g_error_free0 (e);
#line 422 "test-insert-or-replace.c"
	}
	__finally0:
#line 121 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
	if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 427 "test-insert-or-replace.c"
		gint _tmp70_ = 0;
#line 121 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 121 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		g_clear_error (&_inner_error_);
#line 121 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
		return _tmp70_;
#line 435 "test-insert-or-replace.c"
	}
#line 155 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
	result = 0;
#line 155 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
	return result;
#line 441 "test-insert-or-replace.c"
}


int main (int argc, char ** argv) {
#if !GLIB_CHECK_VERSION (2,35,0)
	g_type_init ();
#endif
#line 120 "/home/carlos/Source/gnome/tracker/tests/functional-tests/ipc/test-insert-or-replace.vala"
	return _vala_main (argv, argc);
#line 451 "test-insert-or-replace.c"
}



