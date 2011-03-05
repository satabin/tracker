/* tracker-direct.c generated by valac 0.11.4, the Vala compiler
 * generated from tracker-direct.vala, do not modify */

/*
 * Copyright (C) 2010, Nokia <ivan.frade@nokia.com>
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

#include <glib.h>
#include <glib-object.h>
#include <libtracker-sparql/tracker-sparql.h>
#include <libtracker-data/tracker-data-manager.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <libtracker-data/tracker-db-manager.h>
#include <libtracker-data/tracker-db-interface.h>
#include <libtracker-data/tracker-sparql-query.h>
#include <libtracker-common/tracker-date-time.h>


#define TRACKER_DIRECT_TYPE_CONNECTION (tracker_direct_connection_get_type ())
#define TRACKER_DIRECT_CONNECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TRACKER_DIRECT_TYPE_CONNECTION, TrackerDirectConnection))
#define TRACKER_DIRECT_CONNECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TRACKER_DIRECT_TYPE_CONNECTION, TrackerDirectConnectionClass))
#define TRACKER_DIRECT_IS_CONNECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TRACKER_DIRECT_TYPE_CONNECTION))
#define TRACKER_DIRECT_IS_CONNECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TRACKER_DIRECT_TYPE_CONNECTION))
#define TRACKER_DIRECT_CONNECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TRACKER_DIRECT_TYPE_CONNECTION, TrackerDirectConnectionClass))

typedef struct _TrackerDirectConnection TrackerDirectConnection;
typedef struct _TrackerDirectConnectionClass TrackerDirectConnectionClass;
typedef struct _TrackerDirectConnectionPrivate TrackerDirectConnectionPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _TrackerDirectConnectionInitAsyncData TrackerDirectConnectionInitAsyncData;
typedef struct _Block1Data Block1Data;
typedef struct _Block2Data Block2Data;
typedef struct _TrackerDirectConnectionQueryAsyncData TrackerDirectConnectionQueryAsyncData;

struct _TrackerDirectConnection {
	TrackerSparqlConnection parent_instance;
	TrackerDirectConnectionPrivate * priv;
};

struct _TrackerDirectConnectionClass {
	TrackerSparqlConnectionClass parent_class;
};

struct _TrackerDirectConnectionInitAsyncData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	TrackerDirectConnection* self;
	guint select_cache_size;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* env_cache_size;
	gint _tmp2_;
	GError * e;
	GError* _tmp3_;
	GError * _inner_error_;
};

struct _Block1Data {
	int _ref_count_;
	TrackerDirectConnection * self;
	gchar* sparql;
	GCancellable* cancellable;
	gpointer _async_data_;
};

struct _Block2Data {
	int _ref_count_;
	Block1Data * _data1_;
	GError* sparql_error;
	GError* io_error;
	GError* dbus_error;
	TrackerSparqlCursor* _result_;
};

struct _TrackerDirectConnectionQueryAsyncData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	TrackerDirectConnection* self;
	gchar* sparql;
	GCancellable* cancellable;
	TrackerSparqlCursor* result;
	Block1Data* _data1_;
	gboolean _tmp0_;
	Block2Data* _data2_;
	GError* _tmp1_;
	GError* _tmp2_;
	GError* _tmp3_;
	TrackerSparqlCursor* _tmp4_;
	TrackerSparqlCursor* _tmp5_;
	TrackerSparqlCursor* _tmp6_;
	GError * _inner_error_;
};


static gpointer tracker_direct_connection_parent_class = NULL;
static gboolean tracker_direct_connection_initialized;
static gboolean tracker_direct_connection_initialized = FALSE;

GType tracker_direct_connection_get_type (void) G_GNUC_CONST;
enum  {
	TRACKER_DIRECT_CONNECTION_DUMMY_PROPERTY
};
TrackerDirectConnection* tracker_direct_connection_new (GError** error);
TrackerDirectConnection* tracker_direct_connection_construct (GType object_type, GError** error);
static void tracker_direct_connection_real_init (TrackerSparqlConnection* base, GError** error);
static void tracker_direct_connection_real_init_async_data_free (gpointer _data);
static void tracker_direct_connection_real_init_async (TrackerSparqlConnection* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean tracker_direct_connection_real_init_async_co (TrackerDirectConnectionInitAsyncData* data);
static void tracker_direct_connection_init_async_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static TrackerSparqlCursor* tracker_direct_connection_query_unlocked (TrackerDirectConnection* self, const gchar* sparql, GCancellable* cancellable, GError** error);
static TrackerSparqlCursor* tracker_direct_connection_real_query (TrackerSparqlConnection* base, const gchar* sparql, GCancellable* cancellable, GError** error);
static void tracker_direct_connection_real_query_async_data_free (gpointer _data);
static void tracker_direct_connection_real_query_async (TrackerSparqlConnection* base, const gchar* sparql, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean tracker_direct_connection_real_query_async_co (TrackerDirectConnectionQueryAsyncData* data);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (Block1Data* _data1_);
static Block2Data* block2_data_ref (Block2Data* _data2_);
static void block2_data_unref (Block2Data* _data2_);
static gboolean _lambda0_ (GIOSchedulerJob* job, Block2Data* _data2_);
static gboolean __lambda0__gio_scheduler_job_func (GIOSchedulerJob* job, GCancellable* cancellable, gpointer self);
static void tracker_direct_connection_finalize (GObject* obj);
TrackerSparqlConnection* module_init (GError** error);


TrackerDirectConnection* tracker_direct_connection_construct (GType object_type, GError** error) {
	TrackerDirectConnection * self = NULL;
	g_return_val_if_fail (!tracker_direct_connection_initialized, NULL);
	self = (TrackerDirectConnection*) tracker_sparql_connection_construct (object_type);
	return self;
}


TrackerDirectConnection* tracker_direct_connection_new (GError** error) {
	return tracker_direct_connection_construct (TRACKER_DIRECT_TYPE_CONNECTION, error);
}


static void tracker_direct_connection_real_init (TrackerSparqlConnection* base, GError** error) {
	TrackerDirectConnection * self;
	guint select_cache_size;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_;
	gchar* env_cache_size;
	GError * _inner_error_ = NULL;
	self = (TrackerDirectConnection*) base;
	select_cache_size = (guint) 100;
	_tmp0_ = g_getenv ("TRACKER_SPARQL_CACHE_SIZE");
	_tmp1_ = g_strdup (_tmp0_);
	env_cache_size = _tmp1_;
	if (env_cache_size != NULL) {
		gint _tmp2_;
		_tmp2_ = atoi (env_cache_size);
		select_cache_size = (guint) _tmp2_;
	}
	tracker_data_manager_init (TRACKER_DB_MANAGER_READONLY, NULL, NULL, FALSE, select_cache_size, (guint) 0, NULL, NULL, NULL, &_inner_error_);
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == TRACKER_DB_INTERFACE_ERROR) {
			goto __catch0_tracker_db_interface_error;
		}
		_g_free0 (env_cache_size);
		g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	goto __finally0;
	__catch0_tracker_db_interface_error:
	{
		GError * e;
		GError* _tmp3_ = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp3_ = g_error_new_literal (TRACKER_SPARQL_ERROR, TRACKER_SPARQL_ERROR_INTERNAL, e->message);
		_inner_error_ = _tmp3_;
		_g_error_free0 (e);
		goto __finally0;
	}
	__finally0:
	if (_inner_error_ != NULL) {
		if (((_inner_error_->domain == TRACKER_SPARQL_ERROR) || (_inner_error_->domain == G_IO_ERROR)) || (_inner_error_->domain == G_DBUS_ERROR)) {
			g_propagate_error (error, _inner_error_);
			_g_free0 (env_cache_size);
			return;
		} else {
			_g_free0 (env_cache_size);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	tracker_direct_connection_initialized = TRUE;
	_g_free0 (env_cache_size);
}


static void tracker_direct_connection_real_init_async_data_free (gpointer _data) {
	TrackerDirectConnectionInitAsyncData* data;
	data = _data;
	_g_object_unref0 (data->self);
	g_slice_free (TrackerDirectConnectionInitAsyncData, data);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void tracker_direct_connection_real_init_async (TrackerSparqlConnection* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	TrackerDirectConnection * self;
	TrackerDirectConnectionInitAsyncData* _data_;
	self = (TrackerDirectConnection*) base;
	_data_ = g_slice_new0 (TrackerDirectConnectionInitAsyncData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, tracker_direct_connection_real_init_async);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, tracker_direct_connection_real_init_async_data_free);
	_data_->self = _g_object_ref0 (self);
	tracker_direct_connection_real_init_async_co (_data_);
}


static void tracker_direct_connection_real_init_finish (TrackerSparqlConnection* base, GAsyncResult* _res_, GError** error) {
	TrackerDirectConnectionInitAsyncData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void tracker_direct_connection_init_async_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	TrackerDirectConnectionInitAsyncData* data;
	data = _user_data_;
	data->_source_object_ = source_object;
	data->_res_ = _res_;
	tracker_direct_connection_real_init_async_co (data);
}


static gboolean tracker_direct_connection_real_init_async_co (TrackerDirectConnectionInitAsyncData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	data->select_cache_size = (guint) 100;
	data->_tmp0_ = NULL;
	data->_tmp0_ = g_getenv ("TRACKER_SPARQL_CACHE_SIZE");
	data->_tmp1_ = g_strdup (data->_tmp0_);
	data->env_cache_size = data->_tmp1_;
	if (data->env_cache_size != NULL) {
		data->_tmp2_ = atoi (data->env_cache_size);
		data->select_cache_size = (guint) data->_tmp2_;
	}
	data->_state_ = 1;
	tracker_data_manager_init_async (TRACKER_DB_MANAGER_READONLY, NULL, FALSE, data->select_cache_size, (guint) 0, NULL, NULL, NULL, tracker_direct_connection_init_async_ready, data);
	return FALSE;
	_state_1:
	tracker_data_manager_init_finish (data->_res_, &data->_inner_error_);
	if (data->_inner_error_ != NULL) {
		if (data->_inner_error_->domain == TRACKER_DB_INTERFACE_ERROR) {
			goto __catch1_tracker_db_interface_error;
		}
		_g_free0 (data->env_cache_size);
		g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
		g_clear_error (&data->_inner_error_);
		return FALSE;
	}
	goto __finally1;
	__catch1_tracker_db_interface_error:
	{
		data->e = data->_inner_error_;
		data->_inner_error_ = NULL;
		data->_tmp3_ = NULL;
		data->_tmp3_ = g_error_new_literal (TRACKER_SPARQL_ERROR, TRACKER_SPARQL_ERROR_INTERNAL, data->e->message);
		data->_inner_error_ = data->_tmp3_;
		_g_error_free0 (data->e);
		goto __finally1;
	}
	__finally1:
	if (data->_inner_error_ != NULL) {
		if (((data->_inner_error_->domain == TRACKER_SPARQL_ERROR) || (data->_inner_error_->domain == G_IO_ERROR)) || (data->_inner_error_->domain == G_DBUS_ERROR)) {
			g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
			g_error_free (data->_inner_error_);
			_g_free0 (data->env_cache_size);
			if (data->_state_ == 0) {
				g_simple_async_result_complete_in_idle (data->_async_result);
			} else {
				g_simple_async_result_complete (data->_async_result);
			}
			g_object_unref (data->_async_result);
			return FALSE;
		} else {
			_g_free0 (data->env_cache_size);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
			g_clear_error (&data->_inner_error_);
			return FALSE;
		}
	}
	tracker_direct_connection_initialized = TRUE;
	_g_free0 (data->env_cache_size);
	if (data->_state_ == 0) {
		g_simple_async_result_complete_in_idle (data->_async_result);
	} else {
		g_simple_async_result_complete (data->_async_result);
	}
	g_object_unref (data->_async_result);
	return FALSE;
}


static TrackerSparqlCursor* tracker_direct_connection_query_unlocked (TrackerDirectConnection* self, const gchar* sparql, GCancellable* cancellable, GError** error) {
	TrackerSparqlCursor* result = NULL;
	TrackerSparqlQuery* _tmp0_ = NULL;
	TrackerSparqlQuery* query_object;
	TrackerDBCursor* _tmp1_ = NULL;
	TrackerDBCursor* cursor;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (sparql != NULL, NULL);
	_tmp0_ = tracker_sparql_query_new (sparql);
	query_object = _tmp0_;
	_tmp1_ = tracker_sparql_query_execute_cursor (query_object, TRUE, &_inner_error_);
	cursor = _tmp1_;
	if (_inner_error_ != NULL) {
		_g_object_unref0 (query_object);
		if (_inner_error_->domain == TRACKER_DB_INTERFACE_ERROR) {
			goto __catch2_tracker_db_interface_error;
		}
		if (_inner_error_->domain == TRACKER_DATE_ERROR) {
			goto __catch2_tracker_date_error;
		}
		goto __finally2;
	}
	tracker_sparql_cursor_set_connection ((TrackerSparqlCursor*) cursor, (TrackerSparqlConnection*) self);
	result = (TrackerSparqlCursor*) cursor;
	_g_object_unref0 (query_object);
	return result;
	_g_object_unref0 (cursor);
	_g_object_unref0 (query_object);
	goto __finally2;
	__catch2_tracker_db_interface_error:
	{
		GError * e;
		GError* _tmp2_ = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp2_ = g_error_new_literal (TRACKER_SPARQL_ERROR, TRACKER_SPARQL_ERROR_INTERNAL, e->message);
		_inner_error_ = _tmp2_;
		_g_error_free0 (e);
		goto __finally2;
	}
	goto __finally2;
	__catch2_tracker_date_error:
	{
		GError * e;
		GError* _tmp3_ = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp3_ = g_error_new_literal (TRACKER_SPARQL_ERROR, TRACKER_SPARQL_ERROR_PARSE, e->message);
		_inner_error_ = _tmp3_;
		_g_error_free0 (e);
		goto __finally2;
	}
	__finally2:
	if (((_inner_error_->domain == TRACKER_SPARQL_ERROR) || (_inner_error_->domain == G_IO_ERROR)) || (_inner_error_->domain == G_DBUS_ERROR)) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	} else {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


static TrackerSparqlCursor* tracker_direct_connection_real_query (TrackerSparqlConnection* base, const gchar* sparql, GCancellable* cancellable, GError** error) {
	TrackerDirectConnection * self;
	TrackerSparqlCursor* result = NULL;
	TrackerSparqlCursor* _tmp0_ = NULL;
	TrackerSparqlCursor* _tmp1_;
	GError * _inner_error_ = NULL;
	self = (TrackerDirectConnection*) base;
	g_return_val_if_fail (sparql != NULL, NULL);
	tracker_db_manager_lock ();
	_tmp0_ = tracker_direct_connection_query_unlocked (self, sparql, cancellable, &_inner_error_);
	_tmp1_ = _tmp0_;
	if (_inner_error_ != NULL) {
		goto __finally3;
	}
	result = _tmp1_;
	tracker_db_manager_unlock ();
	return result;
	__finally3:
	tracker_db_manager_unlock ();
	if (((_inner_error_->domain == TRACKER_SPARQL_ERROR) || (_inner_error_->domain == G_IO_ERROR)) || (_inner_error_->domain == G_DBUS_ERROR)) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	} else {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


static void tracker_direct_connection_real_query_async_data_free (gpointer _data) {
	TrackerDirectConnectionQueryAsyncData* data;
	data = _data;
	_g_free0 (data->sparql);
	_g_object_unref0 (data->cancellable);
	_g_object_unref0 (data->result);
	_g_object_unref0 (data->self);
	g_slice_free (TrackerDirectConnectionQueryAsyncData, data);
}


static void tracker_direct_connection_real_query_async (TrackerSparqlConnection* base, const gchar* sparql, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	TrackerDirectConnection * self;
	TrackerDirectConnectionQueryAsyncData* _data_;
	self = (TrackerDirectConnection*) base;
	_data_ = g_slice_new0 (TrackerDirectConnectionQueryAsyncData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, tracker_direct_connection_real_query_async);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, tracker_direct_connection_real_query_async_data_free);
	_data_->self = _g_object_ref0 (self);
	_data_->sparql = g_strdup (sparql);
	_data_->cancellable = _g_object_ref0 (cancellable);
	tracker_direct_connection_real_query_async_co (_data_);
}


static TrackerSparqlCursor* tracker_direct_connection_real_query_finish (TrackerSparqlConnection* base, GAsyncResult* _res_, GError** error) {
	TrackerSparqlCursor* result;
	TrackerDirectConnectionQueryAsyncData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static Block1Data* block1_data_ref (Block1Data* _data1_) {
	g_atomic_int_inc (&_data1_->_ref_count_);
	return _data1_;
}


static void block1_data_unref (Block1Data* _data1_) {
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
		_g_object_unref0 (_data1_->self);
		_g_free0 (_data1_->sparql);
		_g_object_unref0 (_data1_->cancellable);
		g_slice_free (Block1Data, _data1_);
	}
}


static Block2Data* block2_data_ref (Block2Data* _data2_) {
	g_atomic_int_inc (&_data2_->_ref_count_);
	return _data2_;
}


static void block2_data_unref (Block2Data* _data2_) {
	if (g_atomic_int_dec_and_test (&_data2_->_ref_count_)) {
		block1_data_unref (_data2_->_data1_);
		_g_object_unref0 (_data2_->_result_);
		_g_error_free0 (_data2_->dbus_error);
		_g_error_free0 (_data2_->io_error);
		_g_error_free0 (_data2_->sparql_error);
		g_slice_free (Block2Data, _data2_);
	}
}


static gpointer _g_error_copy0 (gpointer self) {
	return self ? g_error_copy (self) : NULL;
}


static gboolean _lambda0_ (GIOSchedulerJob* job, Block2Data* _data2_) {
	Block1Data* _data1_;
	TrackerDirectConnection * self;
	gboolean result = FALSE;
	TrackerSparqlCursor* _tmp0_ = NULL;
	TrackerSparqlCursor* _tmp1_;
	TrackerSparqlCursor* _tmp2_;
	GError * _inner_error_ = NULL;
	_data1_ = _data2_->_data1_;
	self = _data1_->self;
	g_return_val_if_fail (job != NULL, FALSE);
	_tmp0_ = tracker_sparql_connection_query ((TrackerSparqlConnection*) self, _data1_->sparql, _data1_->cancellable, &_inner_error_);
	_tmp1_ = _tmp0_;
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == G_IO_ERROR) {
			goto __catch4_g_io_error;
		}
		if (_inner_error_->domain == TRACKER_SPARQL_ERROR) {
			goto __catch4_tracker_sparql_error;
		}
		if (_inner_error_->domain == G_DBUS_ERROR) {
			goto __catch4_g_dbus_error;
		}
		g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	_tmp2_ = _tmp1_;
	_g_object_unref0 (_data2_->_result_);
	_data2_->_result_ = _tmp2_;
	goto __finally4;
	__catch4_g_io_error:
	{
		GError * e_io;
		GError* _tmp3_;
		GError* _tmp4_;
		e_io = _inner_error_;
		_inner_error_ = NULL;
		_tmp3_ = _g_error_copy0 (e_io);
		_tmp4_ = _tmp3_;
		_g_error_free0 (_data2_->io_error);
		_data2_->io_error = _tmp4_;
		_g_error_free0 (e_io);
	}
	goto __finally4;
	__catch4_tracker_sparql_error:
	{
		GError * e_spql;
		GError* _tmp5_;
		GError* _tmp6_;
		e_spql = _inner_error_;
		_inner_error_ = NULL;
		_tmp5_ = _g_error_copy0 (e_spql);
		_tmp6_ = _tmp5_;
		_g_error_free0 (_data2_->sparql_error);
		_data2_->sparql_error = _tmp6_;
		_g_error_free0 (e_spql);
	}
	goto __finally4;
	__catch4_g_dbus_error:
	{
		GError * e_dbus;
		GError* _tmp7_;
		GError* _tmp8_;
		e_dbus = _inner_error_;
		_inner_error_ = NULL;
		_tmp7_ = _g_error_copy0 (e_dbus);
		_tmp8_ = _tmp7_;
		_g_error_free0 (_data2_->dbus_error);
		_data2_->dbus_error = _tmp8_;
		_g_error_free0 (e_dbus);
	}
	__finally4:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	tracker_direct_connection_real_query_async_co (_data1_->_async_data_);
	result = FALSE;
	return result;
}


static gboolean __lambda0__gio_scheduler_job_func (GIOSchedulerJob* job, GCancellable* cancellable, gpointer self) {
	gboolean result;
	result = _lambda0_ (job, self);
	return result;
}


static gboolean tracker_direct_connection_real_query_async_co (TrackerDirectConnectionQueryAsyncData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	data->_data1_ = g_slice_new0 (Block1Data);
	data->_data1_->_ref_count_ = 1;
	data->_data1_->self = g_object_ref (data->self);
	data->_data1_->sparql = g_strdup (data->sparql);
	data->_data1_->cancellable = _g_object_ref0 (data->cancellable);
	data->_data1_->_async_data_ = data;
	data->_tmp0_ = tracker_db_manager_trylock ();
	if (!data->_tmp0_) {
		data->_data2_ = g_slice_new0 (Block2Data);
		data->_data2_->_ref_count_ = 1;
		data->_data2_->_data1_ = block1_data_ref (data->_data1_);
		data->_data2_->sparql_error = NULL;
		data->_data2_->io_error = NULL;
		data->_data2_->dbus_error = NULL;
		data->_data2_->_result_ = NULL;
		g_io_scheduler_push_job (__lambda0__gio_scheduler_job_func, block2_data_ref (data->_data2_), block2_data_unref, G_PRIORITY_DEFAULT, NULL);
		data->_state_ = 1;
		return FALSE;
		_state_1:
		;
		if (data->_data2_->sparql_error != NULL) {
			data->_tmp1_ = _g_error_copy0 (data->_data2_->sparql_error);
			data->_inner_error_ = data->_tmp1_;
			if (((data->_inner_error_->domain == TRACKER_SPARQL_ERROR) || (data->_inner_error_->domain == G_IO_ERROR)) || (data->_inner_error_->domain == G_DBUS_ERROR)) {
				g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
				g_error_free (data->_inner_error_);
				block2_data_unref (data->_data2_);
				block1_data_unref (data->_data1_);
				if (data->_state_ == 0) {
					g_simple_async_result_complete_in_idle (data->_async_result);
				} else {
					g_simple_async_result_complete (data->_async_result);
				}
				g_object_unref (data->_async_result);
				return FALSE;
			} else {
				block2_data_unref (data->_data2_);
				block1_data_unref (data->_data1_);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
				g_clear_error (&data->_inner_error_);
				return FALSE;
			}
		} else {
			if (data->_data2_->io_error != NULL) {
				data->_tmp2_ = _g_error_copy0 (data->_data2_->io_error);
				data->_inner_error_ = data->_tmp2_;
				if (((data->_inner_error_->domain == TRACKER_SPARQL_ERROR) || (data->_inner_error_->domain == G_IO_ERROR)) || (data->_inner_error_->domain == G_DBUS_ERROR)) {
					g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
					g_error_free (data->_inner_error_);
					block2_data_unref (data->_data2_);
					block1_data_unref (data->_data1_);
					if (data->_state_ == 0) {
						g_simple_async_result_complete_in_idle (data->_async_result);
					} else {
						g_simple_async_result_complete (data->_async_result);
					}
					g_object_unref (data->_async_result);
					return FALSE;
				} else {
					block2_data_unref (data->_data2_);
					block1_data_unref (data->_data1_);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
					g_clear_error (&data->_inner_error_);
					return FALSE;
				}
			} else {
				if (data->_data2_->dbus_error != NULL) {
					data->_tmp3_ = _g_error_copy0 (data->_data2_->dbus_error);
					data->_inner_error_ = data->_tmp3_;
					if (((data->_inner_error_->domain == TRACKER_SPARQL_ERROR) || (data->_inner_error_->domain == G_IO_ERROR)) || (data->_inner_error_->domain == G_DBUS_ERROR)) {
						g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
						g_error_free (data->_inner_error_);
						block2_data_unref (data->_data2_);
						block1_data_unref (data->_data1_);
						if (data->_state_ == 0) {
							g_simple_async_result_complete_in_idle (data->_async_result);
						} else {
							g_simple_async_result_complete (data->_async_result);
						}
						g_object_unref (data->_async_result);
						return FALSE;
					} else {
						block2_data_unref (data->_data2_);
						block1_data_unref (data->_data1_);
						g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
						g_clear_error (&data->_inner_error_);
						return FALSE;
					}
				} else {
					data->_tmp4_ = _g_object_ref0 (data->_data2_->_result_);
					data->result = data->_tmp4_;
					block2_data_unref (data->_data2_);
					block1_data_unref (data->_data1_);
					if (data->_state_ == 0) {
						g_simple_async_result_complete_in_idle (data->_async_result);
					} else {
						g_simple_async_result_complete (data->_async_result);
					}
					g_object_unref (data->_async_result);
					return FALSE;
				}
			}
		}
		block2_data_unref (data->_data2_);
	}
	data->_tmp5_ = NULL;
	data->_tmp5_ = tracker_direct_connection_query_unlocked (data->self, data->_data1_->sparql, data->_data1_->cancellable, &data->_inner_error_);
	data->_tmp6_ = data->_tmp5_;
	if (data->_inner_error_ != NULL) {
		goto __finally5;
	}
	data->result = data->_tmp6_;
	tracker_db_manager_unlock ();
	block1_data_unref (data->_data1_);
	if (data->_state_ == 0) {
		g_simple_async_result_complete_in_idle (data->_async_result);
	} else {
		g_simple_async_result_complete (data->_async_result);
	}
	g_object_unref (data->_async_result);
	return FALSE;
	__finally5:
	tracker_db_manager_unlock ();
	if (((data->_inner_error_->domain == TRACKER_SPARQL_ERROR) || (data->_inner_error_->domain == G_IO_ERROR)) || (data->_inner_error_->domain == G_DBUS_ERROR)) {
		g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
		g_error_free (data->_inner_error_);
		block1_data_unref (data->_data1_);
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	} else {
		block1_data_unref (data->_data1_);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
		g_clear_error (&data->_inner_error_);
		return FALSE;
	}
	block1_data_unref (data->_data1_);
	if (data->_state_ == 0) {
		g_simple_async_result_complete_in_idle (data->_async_result);
	} else {
		g_simple_async_result_complete (data->_async_result);
	}
	g_object_unref (data->_async_result);
	return FALSE;
}


static void tracker_direct_connection_class_init (TrackerDirectConnectionClass * klass) {
	tracker_direct_connection_parent_class = g_type_class_peek_parent (klass);
	TRACKER_SPARQL_CONNECTION_CLASS (klass)->init = tracker_direct_connection_real_init;
	TRACKER_SPARQL_CONNECTION_CLASS (klass)->init_async = tracker_direct_connection_real_init_async;
	TRACKER_SPARQL_CONNECTION_CLASS (klass)->init_finish = tracker_direct_connection_real_init_finish;
	TRACKER_SPARQL_CONNECTION_CLASS (klass)->query = tracker_direct_connection_real_query;
	TRACKER_SPARQL_CONNECTION_CLASS (klass)->query_async = tracker_direct_connection_real_query_async;
	TRACKER_SPARQL_CONNECTION_CLASS (klass)->query_finish = tracker_direct_connection_real_query_finish;
	G_OBJECT_CLASS (klass)->finalize = tracker_direct_connection_finalize;
}


static void tracker_direct_connection_instance_init (TrackerDirectConnection * self) {
}


static void tracker_direct_connection_finalize (GObject* obj) {
	TrackerDirectConnection * self;
	self = TRACKER_DIRECT_CONNECTION (obj);
	if (tracker_direct_connection_initialized) {
		tracker_data_manager_shutdown ();
		tracker_direct_connection_initialized = FALSE;
	}
	G_OBJECT_CLASS (tracker_direct_connection_parent_class)->finalize (obj);
}


GType tracker_direct_connection_get_type (void) {
	static volatile gsize tracker_direct_connection_type_id__volatile = 0;
	if (g_once_init_enter (&tracker_direct_connection_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (TrackerDirectConnectionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) tracker_direct_connection_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TrackerDirectConnection), 0, (GInstanceInitFunc) tracker_direct_connection_instance_init, NULL };
		GType tracker_direct_connection_type_id;
		tracker_direct_connection_type_id = g_type_register_static (TRACKER_SPARQL_TYPE_CONNECTION, "TrackerDirectConnection", &g_define_type_info, 0);
		g_once_init_leave (&tracker_direct_connection_type_id__volatile, tracker_direct_connection_type_id);
	}
	return tracker_direct_connection_type_id__volatile;
}


TrackerSparqlConnection* module_init (GError** error) {
	TrackerSparqlConnection* result = NULL;
	TrackerDirectConnection* _tmp0_ = NULL;
	TrackerSparqlConnection* plugin;
	GError * _inner_error_ = NULL;
	_tmp0_ = tracker_direct_connection_new (&_inner_error_);
	plugin = (TrackerSparqlConnection*) _tmp0_;
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	result = plugin;
	return result;
}



