/* test-shared-query.c generated by valac 0.12.0.69-6c49, the Vala compiler
 * generated from test-shared-query.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <libtracker-sparql/tracker-sparql.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>


#define TYPE_TEST_APP (test_app_get_type ())
#define TEST_APP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TEST_APP, TestApp))
#define TEST_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TEST_APP, TestAppClass))
#define IS_TEST_APP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TEST_APP))
#define IS_TEST_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TEST_APP))
#define TEST_APP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TEST_APP, TestAppClass))

typedef struct _TestApp TestApp;
typedef struct _TestAppClass TestAppClass;
typedef struct _TestAppPrivate TestAppPrivate;
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _TestAppTestQueryAsyncData TestAppTestQueryAsyncData;
typedef struct _TestAppDoAsyncTestsData TestAppDoAsyncTestsData;

struct _TestApp {
	GObject parent_instance;
	TestAppPrivate * priv;
};

struct _TestAppClass {
	GObjectClass parent_class;
};

struct _TestAppPrivate {
	GMainLoop* loop;
	TrackerSparqlConnection* con;
	gint res;
};

struct _TestAppTestQueryAsyncData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	TestApp* self;
	TrackerSparqlCursor* cursor;
	TrackerSparqlCursor* _tmp0_;
	TrackerSparqlCursor* _tmp1_;
	GError * e;
	gint _tmp2_;
	gint _tmp3_;
	GError * _inner_error_;
};

struct _TestAppDoAsyncTestsData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	TestApp* self;
};


static gpointer test_app_parent_class = NULL;

GType test_app_get_type (void) G_GNUC_CONST;
#define TEST_APP_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_TEST_APP, TestAppPrivate))
enum  {
	TEST_APP_DUMMY_PROPERTY
};
TestApp* test_app_new (TrackerSparqlConnection* connection);
TestApp* test_app_construct (GType object_type, TrackerSparqlConnection* connection);
static gchar* test_app_type_to_string (TestApp* self, TrackerSparqlValueType type);
static gint test_app_iter_cursor (TestApp* self, TrackerSparqlCursor* cursor);
static void test_app_test_query (TestApp* self);
static void test_app_test_query_async_data_free (gpointer _data);
static void test_app_test_query_async (TestApp* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void test_app_test_query_finish (TestApp* self, GAsyncResult* _res_);
static gboolean test_app_test_query_async_co (TestAppTestQueryAsyncData* data);
static void test_app_test_query_async_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void test_app_do_sync_tests (TestApp* self);
static void test_app_do_async_tests_data_free (gpointer _data);
static void test_app_do_async_tests (TestApp* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void test_app_do_async_tests_finish (TestApp* self, GAsyncResult* _res_);
static gboolean test_app_do_async_tests_co (TestAppDoAsyncTestsData* data);
static void test_app_do_async_tests_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static gboolean test_app_in_mainloop (TestApp* self);
gint test_app_run (TestApp* self);
static gboolean _test_app_in_mainloop_gsource_func (gpointer self);
static void test_app_finalize (GObject* obj);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


TestApp* test_app_construct (GType object_type, TrackerSparqlConnection* connection) {
	TestApp * self = NULL;
	TrackerSparqlConnection* _tmp0_;
	g_return_val_if_fail (connection != NULL, NULL);
	self = (TestApp*) g_object_new (object_type, NULL);
	_tmp0_ = _g_object_ref0 (connection);
	_g_object_unref0 (self->priv->con);
	self->priv->con = _tmp0_;
	return self;
}


TestApp* test_app_new (TrackerSparqlConnection* connection) {
	return test_app_construct (TYPE_TEST_APP, connection);
}


static gchar* test_app_type_to_string (TestApp* self, TrackerSparqlValueType type) {
	gchar* result = NULL;
	gchar* _tmp8_;
	g_return_val_if_fail (self != NULL, NULL);
	switch (type) {
		case TRACKER_SPARQL_VALUE_TYPE_UNBOUND:
		{
			gchar* _tmp0_;
			_tmp0_ = g_strdup ("unbound");
			result = _tmp0_;
			return result;
		}
		case TRACKER_SPARQL_VALUE_TYPE_URI:
		{
			gchar* _tmp1_;
			_tmp1_ = g_strdup ("uri");
			result = _tmp1_;
			return result;
		}
		case TRACKER_SPARQL_VALUE_TYPE_STRING:
		{
			gchar* _tmp2_;
			_tmp2_ = g_strdup ("string");
			result = _tmp2_;
			return result;
		}
		case TRACKER_SPARQL_VALUE_TYPE_INTEGER:
		{
			gchar* _tmp3_;
			_tmp3_ = g_strdup ("integer");
			result = _tmp3_;
			return result;
		}
		case TRACKER_SPARQL_VALUE_TYPE_DOUBLE:
		{
			gchar* _tmp4_;
			_tmp4_ = g_strdup ("double");
			result = _tmp4_;
			return result;
		}
		case TRACKER_SPARQL_VALUE_TYPE_DATETIME:
		{
			gchar* _tmp5_;
			_tmp5_ = g_strdup ("datetime");
			result = _tmp5_;
			return result;
		}
		case TRACKER_SPARQL_VALUE_TYPE_BLANK_NODE:
		{
			gchar* _tmp6_;
			_tmp6_ = g_strdup ("blank-node");
			result = _tmp6_;
			return result;
		}
		case TRACKER_SPARQL_VALUE_TYPE_BOOLEAN:
		{
			gchar* _tmp7_;
			_tmp7_ = g_strdup ("boolean");
			result = _tmp7_;
			return result;
		}
		default:
		{
			break;
		}
	}
	_tmp8_ = g_strdup ("unknown");
	result = _tmp8_;
	return result;
}


static gint test_app_iter_cursor (TestApp* self, TrackerSparqlCursor* cursor) {
	gint result = 0;
	gint i = 0;
	gint _tmp3_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (cursor != NULL, 0);
	{
		gboolean _tmp0_;
		i = 0;
		_tmp0_ = TRUE;
		while (TRUE) {
			gint _tmp1_;
			const gchar* _tmp2_ = NULL;
			if (!_tmp0_) {
				i++;
			}
			_tmp0_ = FALSE;
			_tmp1_ = tracker_sparql_cursor_get_n_columns (cursor);
			if (!(i < _tmp1_)) {
				break;
			}
			_tmp2_ = tracker_sparql_cursor_get_variable_name (cursor, i);
			g_print ("| %s ", _tmp2_);
		}
	}
	_tmp3_ = tracker_sparql_cursor_get_n_columns (cursor);
	g_print ("| -> %d columns\n", _tmp3_);
	while (TRUE) {
		gboolean _tmp4_;
		gboolean _tmp5_;
		_tmp4_ = tracker_sparql_cursor_next (cursor, NULL, &_inner_error_);
		_tmp5_ = _tmp4_;
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
		if (!_tmp5_) {
			break;
		}
		{
			gboolean _tmp6_;
			i = 0;
			_tmp6_ = TRUE;
			while (TRUE) {
				gint _tmp7_;
				const gchar* _tmp8_ = NULL;
				const gchar* _tmp9_ = NULL;
				TrackerSparqlValueType _tmp10_;
				gchar* _tmp11_ = NULL;
				gchar* _tmp12_;
				if (!_tmp6_) {
					i++;
				}
				_tmp6_ = FALSE;
				_tmp7_ = tracker_sparql_cursor_get_n_columns (cursor);
				if (!(i < _tmp7_)) {
					break;
				}
				if (i != 0) {
					_tmp8_ = ",";
				} else {
					_tmp8_ = "";
				}
				_tmp9_ = tracker_sparql_cursor_get_string (cursor, i, NULL);
				_tmp10_ = tracker_sparql_cursor_get_value_type (cursor, i);
				_tmp11_ = test_app_type_to_string (self, _tmp10_);
				_tmp12_ = _tmp11_;
				g_print ("%s%s a %s", _tmp8_, _tmp9_, _tmp12_);
				_g_free0 (_tmp12_);
			}
		}
		g_print ("\n");
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		g_warning ("test-shared-query.vala:56: Couldn't iterate query results: %s", e->message);
		result = -1;
		_g_error_free0 (e);
		return result;
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
	result = 0;
	return result;
}


static void test_app_test_query (TestApp* self) {
	TrackerSparqlCursor* cursor = NULL;
	TrackerSparqlCursor* _tmp0_ = NULL;
	TrackerSparqlCursor* _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	g_print ("Sync test\n");
	_tmp0_ = tracker_sparql_connection_query (self->priv->con, "SELECT ?u WHERE { ?u a rdfs:Class }", NULL, &_inner_error_);
	_tmp1_ = _tmp0_;
	if (_inner_error_ != NULL) {
		goto __catch1_g_error;
	}
	_g_object_unref0 (cursor);
	cursor = _tmp1_;
	goto __finally1;
	__catch1_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		g_warning ("test-shared-query.vala:70: Couldn't perform query: %s", e->message);
		self->priv->res = -1;
		_g_error_free0 (e);
		_g_object_unref0 (cursor);
		return;
	}
	__finally1:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cursor);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp2_ = test_app_iter_cursor (self, cursor);
	self->priv->res = _tmp2_;
	if (self->priv->res == (-1)) {
		_g_object_unref0 (cursor);
		return;
	}
	g_print ("\nRewinding\n");
	tracker_sparql_cursor_rewind (cursor);
	g_print ("\nSecond run\n");
	_tmp3_ = test_app_iter_cursor (self, cursor);
	self->priv->res = _tmp3_;
	_g_object_unref0 (cursor);
}


static void test_app_test_query_async_data_free (gpointer _data) {
	TestAppTestQueryAsyncData* data;
	data = _data;
	_g_object_unref0 (data->self);
	g_slice_free (TestAppTestQueryAsyncData, data);
}


static void test_app_test_query_async (TestApp* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	TestAppTestQueryAsyncData* _data_;
	_data_ = g_slice_new0 (TestAppTestQueryAsyncData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, test_app_test_query_async);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, test_app_test_query_async_data_free);
	_data_->self = _g_object_ref0 (self);
	test_app_test_query_async_co (_data_);
}


static void test_app_test_query_finish (TestApp* self, GAsyncResult* _res_) {
	TestAppTestQueryAsyncData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void test_app_test_query_async_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	TestAppTestQueryAsyncData* data;
	data = _user_data_;
	data->_source_object_ = source_object;
	data->_res_ = _res_;
	test_app_test_query_async_co (data);
}


static gboolean test_app_test_query_async_co (TestAppTestQueryAsyncData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	g_print ("Async test\n");
	data->_state_ = 1;
	tracker_sparql_connection_query_async (data->self->priv->con, "SELECT ?u WHERE { ?u a rdfs:Class }", NULL, test_app_test_query_async_ready, data);
	return FALSE;
	_state_1:
	data->_tmp0_ = NULL;
	data->_tmp0_ = tracker_sparql_connection_query_finish (data->self->priv->con, data->_res_, &data->_inner_error_);
	data->_tmp1_ = data->_tmp0_;
	if (data->_inner_error_ != NULL) {
		goto __catch2_g_error;
	}
	_g_object_unref0 (data->cursor);
	data->cursor = data->_tmp1_;
	goto __finally2;
	__catch2_g_error:
	{
		data->e = data->_inner_error_;
		data->_inner_error_ = NULL;
		g_warning ("test-shared-query.vala:94: Couldn't perform query: %s", data->e->message);
		data->self->priv->res = -1;
		_g_error_free0 (data->e);
		_g_object_unref0 (data->cursor);
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
	__finally2:
	if (data->_inner_error_ != NULL) {
		_g_object_unref0 (data->cursor);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
		g_clear_error (&data->_inner_error_);
		return FALSE;
	}
	data->_tmp2_ = test_app_iter_cursor (data->self, data->cursor);
	data->self->priv->res = data->_tmp2_;
	if (data->self->priv->res == (-1)) {
		_g_object_unref0 (data->cursor);
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
	g_print ("\nRewinding\n");
	tracker_sparql_cursor_rewind (data->cursor);
	g_print ("\nSecond run\n");
	data->_tmp3_ = test_app_iter_cursor (data->self, data->cursor);
	data->self->priv->res = data->_tmp3_;
	_g_object_unref0 (data->cursor);
	if (data->_state_ == 0) {
		g_simple_async_result_complete_in_idle (data->_async_result);
	} else {
		g_simple_async_result_complete (data->_async_result);
	}
	g_object_unref (data->_async_result);
	return FALSE;
}


static void test_app_do_sync_tests (TestApp* self) {
	g_return_if_fail (self != NULL);
	test_app_test_query (self);
}


static void test_app_do_async_tests_data_free (gpointer _data) {
	TestAppDoAsyncTestsData* data;
	data = _data;
	_g_object_unref0 (data->self);
	g_slice_free (TestAppDoAsyncTestsData, data);
}


static void test_app_do_async_tests (TestApp* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	TestAppDoAsyncTestsData* _data_;
	_data_ = g_slice_new0 (TestAppDoAsyncTestsData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, test_app_do_async_tests);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, test_app_do_async_tests_data_free);
	_data_->self = _g_object_ref0 (self);
	test_app_do_async_tests_co (_data_);
}


static void test_app_do_async_tests_finish (TestApp* self, GAsyncResult* _res_) {
	TestAppDoAsyncTestsData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void test_app_do_async_tests_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	TestAppDoAsyncTestsData* data;
	data = _user_data_;
	data->_source_object_ = source_object;
	data->_res_ = _res_;
	test_app_do_async_tests_co (data);
}


static gboolean test_app_do_async_tests_co (TestAppDoAsyncTestsData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	data->_state_ = 1;
	test_app_test_query_async (data->self, test_app_do_async_tests_ready, data);
	return FALSE;
	_state_1:
	test_app_test_query_finish (data->self, data->_res_);
	g_print ("Async tests done, now I can quit the mainloop\n");
	g_main_loop_quit (data->self->priv->loop);
	if (data->_state_ == 0) {
		g_simple_async_result_complete_in_idle (data->_async_result);
	} else {
		g_simple_async_result_complete (data->_async_result);
	}
	g_object_unref (data->_async_result);
	return FALSE;
}


static gboolean test_app_in_mainloop (TestApp* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	test_app_do_sync_tests (self);
	test_app_do_async_tests (self, NULL, NULL);
	result = FALSE;
	return result;
}


static gboolean _test_app_in_mainloop_gsource_func (gpointer self) {
	gboolean result;
	result = test_app_in_mainloop (self);
	return result;
}


gint test_app_run (TestApp* self) {
	gint result = 0;
	GMainLoop* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = g_main_loop_new (NULL, FALSE);
	_g_main_loop_unref0 (self->priv->loop);
	self->priv->loop = _tmp0_;
	g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _test_app_in_mainloop_gsource_func, g_object_ref (self), g_object_unref);
	g_main_loop_run (self->priv->loop);
	result = self->priv->res;
	return result;
}


static void test_app_class_init (TestAppClass * klass) {
	test_app_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (TestAppPrivate));
	G_OBJECT_CLASS (klass)->finalize = test_app_finalize;
}


static void test_app_instance_init (TestApp * self) {
	self->priv = TEST_APP_GET_PRIVATE (self);
	self->priv->res = 0;
}


static void test_app_finalize (GObject* obj) {
	TestApp * self;
	self = TEST_APP (obj);
	_g_main_loop_unref0 (self->priv->loop);
	_g_object_unref0 (self->priv->con);
	G_OBJECT_CLASS (test_app_parent_class)->finalize (obj);
}


GType test_app_get_type (void) {
	static volatile gsize test_app_type_id__volatile = 0;
	if (g_once_init_enter (&test_app_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (TestAppClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) test_app_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TestApp), 0, (GInstanceInitFunc) test_app_instance_init, NULL };
		GType test_app_type_id;
		test_app_type_id = g_type_register_static (G_TYPE_OBJECT, "TestApp", &g_define_type_info, 0);
		g_once_init_leave (&test_app_type_id__volatile, test_app_type_id);
	}
	return test_app_type_id__volatile;
}



