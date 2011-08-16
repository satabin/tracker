/* test-direct-query.c generated by valac 0.12.0, the Vala compiler
 * generated from test-direct-query.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <libtracker-sparql/tracker-sparql.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Block1Data Block1Data;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define TYPE_TEST_APP (test_app_get_type ())
#define TEST_APP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TEST_APP, TestApp))
#define TEST_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TEST_APP, TestAppClass))
#define IS_TEST_APP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TEST_APP))
#define IS_TEST_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TEST_APP))
#define TEST_APP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TEST_APP, TestAppClass))

typedef struct _TestApp TestApp;
typedef struct _TestAppClass TestAppClass;

struct _Block1Data {
	int _ref_count_;
	TrackerSparqlConnection* c;
};


extern gint res;
gint res = 0;
extern GMainLoop* loop;
GMainLoop* loop = NULL;

void test_async (void);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (Block1Data* _data1_);
static void _lambda0_ (GObject* o, GAsyncResult* res, Block1Data* _data1_);
static void __lambda0__gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self);
TestApp* test_app_new (TrackerSparqlConnection* connection);
TestApp* test_app_construct (GType object_type, TrackerSparqlConnection* connection);
GType test_app_get_type (void) G_GNUC_CONST;
gint test_app_run (TestApp* self);
void test_sync (void);
gint _vala_main (gchar** args, int args_length1);


static Block1Data* block1_data_ref (Block1Data* _data1_) {
	g_atomic_int_inc (&_data1_->_ref_count_);
	return _data1_;
}


static void block1_data_unref (Block1Data* _data1_) {
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
		_g_object_unref0 (_data1_->c);
		g_slice_free (Block1Data, _data1_);
	}
}


static void _lambda0_ (GObject* o, GAsyncResult* res, Block1Data* _data1_) {
	TrackerSparqlConnection* _tmp0_ = NULL;
	TrackerSparqlConnection* _tmp1_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (res != NULL);
	_tmp0_ = tracker_sparql_connection_get_finish (res, &_inner_error_);
	_tmp1_ = _tmp0_;
	if (_inner_error_ != NULL) {
		goto __catch3_g_error;
	}
	_g_object_unref0 (_data1_->c);
	_data1_->c = _tmp1_;
	goto __finally3;
	__catch3_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		g_warning ("test-direct-query.vala:17: Couldn't perform test: %s", e->message);
		_g_error_free0 (e);
	}
	__finally3:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	g_main_loop_quit (loop);
}


static void __lambda0__gasync_ready_callback (GObject* source_object, GAsyncResult* res, gpointer self) {
	_lambda0_ (source_object, res, self);
	block1_data_unref (self);
}


void test_async (void) {
	Block1Data* _data1_;
	GMainLoop* _tmp0_ = NULL;
	TestApp* _tmp1_ = NULL;
	TestApp* app;
	gint _tmp2_;
	_data1_ = g_slice_new0 (Block1Data);
	_data1_->_ref_count_ = 1;
	_data1_->c = NULL;
	g_print ("Getting connection asynchronously\n");
	_tmp0_ = g_main_loop_new (NULL, FALSE);
	_g_main_loop_unref0 (loop);
	loop = _tmp0_;
	tracker_sparql_connection_get_async (NULL, __lambda0__gasync_ready_callback, block1_data_ref (_data1_));
	g_main_loop_run (loop);
	g_print ("Got it %p\n", _data1_->c);
	g_print ("Creating app with connection\n");
	_tmp1_ = test_app_new (_data1_->c);
	app = _tmp1_;
	g_print ("Running app\n");
	_tmp2_ = test_app_run (app);
	res = _tmp2_;
	g_print ("\n");
	_g_object_unref0 (app);
	block1_data_unref (_data1_);
	_data1_ = NULL;
}


void test_sync (void) {
	TrackerSparqlConnection* c = NULL;
	TrackerSparqlConnection* _tmp0_ = NULL;
	TrackerSparqlConnection* _tmp1_;
	TestApp* _tmp2_ = NULL;
	TestApp* app;
	gint _tmp3_;
	GError * _inner_error_ = NULL;
	g_print ("Getting connection synchronously\n");
	_tmp0_ = tracker_sparql_connection_get (NULL, &_inner_error_);
	_tmp1_ = _tmp0_;
	if (_inner_error_ != NULL) {
		_g_object_unref0 (c);
		goto __catch4_g_error;
	}
	_g_object_unref0 (c);
	c = _tmp1_;
	g_print ("Got it %p\n", c);
	g_print ("Creating app with connection\n");
	_tmp2_ = test_app_new (c);
	app = _tmp2_;
	g_print ("Running app\n");
	_tmp3_ = test_app_run (app);
	res = _tmp3_;
	_g_object_unref0 (app);
	_g_object_unref0 (c);
	goto __finally4;
	__catch4_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		g_warning ("test-direct-query.vala:50: Couldn't perform test: %s", e->message);
		_g_error_free0 (e);
	}
	__finally4:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	g_print ("\n");
}


gint _vala_main (gchar** args, int args_length1) {
	gint result = 0;
	g_print ("Starting...\n");
	test_sync ();
	if (res < 0) {
		result = res;
		return result;
	}
	test_async ();
	result = res;
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return _vala_main (argv, argc);
}



