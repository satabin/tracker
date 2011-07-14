/* tracker-status.c generated by valac 0.12.1, the Vala compiler
 * generated from tracker-status.vala, do not modify */

/*
 * Copyright (C) 2008-2011, Nokia <ivan.frade@nokia.com>
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
 *
 * Authors:
 *  Philip Van Hoof <philip@codeminded.be>
 */

#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <libtracker-data/tracker-data-update.h>
#include <gio/gio.h>


#define TRACKER_TYPE_STATUS (tracker_status_get_type ())
#define TRACKER_STATUS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TRACKER_TYPE_STATUS, TrackerStatus))
#define TRACKER_STATUS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TRACKER_TYPE_STATUS, TrackerStatusClass))
#define TRACKER_IS_STATUS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TRACKER_TYPE_STATUS))
#define TRACKER_IS_STATUS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TRACKER_TYPE_STATUS))
#define TRACKER_STATUS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TRACKER_TYPE_STATUS, TrackerStatusClass))

typedef struct _TrackerStatus TrackerStatus;
typedef struct _TrackerStatusClass TrackerStatusClass;
typedef struct _TrackerStatusPrivate TrackerStatusPrivate;

#define TRACKER_STATUS_TYPE_WAIT_CONTEXT (tracker_status_wait_context_get_type ())
#define TRACKER_STATUS_WAIT_CONTEXT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TRACKER_STATUS_TYPE_WAIT_CONTEXT, TrackerStatusWaitContext))
#define TRACKER_STATUS_WAIT_CONTEXT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TRACKER_STATUS_TYPE_WAIT_CONTEXT, TrackerStatusWaitContextClass))
#define TRACKER_STATUS_IS_WAIT_CONTEXT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TRACKER_STATUS_TYPE_WAIT_CONTEXT))
#define TRACKER_STATUS_IS_WAIT_CONTEXT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TRACKER_STATUS_TYPE_WAIT_CONTEXT))
#define TRACKER_STATUS_WAIT_CONTEXT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TRACKER_STATUS_TYPE_WAIT_CONTEXT, TrackerStatusWaitContextClass))

typedef struct _TrackerStatusWaitContext TrackerStatusWaitContext;
typedef struct _TrackerStatusWaitContextClass TrackerStatusWaitContextClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define __g_list_free__g_object_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_object_unref0_ (var), NULL)))
typedef struct _TrackerStatusWaitContextPrivate TrackerStatusWaitContextPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _TrackerStatusWaitData TrackerStatusWaitData;

struct _TrackerStatus {
	GObject parent_instance;
	TrackerStatusPrivate * priv;
};

struct _TrackerStatusClass {
	GObjectClass parent_class;
};

struct _TrackerStatusPrivate {
	gdouble _progress;
	gchar* status;
	guint timer_id;
	GList* wait_list;
};

struct _TrackerStatusWaitContext {
	GObject parent_instance;
	TrackerStatusWaitContextPrivate * priv;
	GSourceFunc callback;
	gpointer callback_target;
	GDestroyNotify callback_target_destroy_notify;
};

struct _TrackerStatusWaitContextClass {
	GObjectClass parent_class;
};

struct _TrackerStatusWaitData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	TrackerStatus* self;
	TrackerStatusWaitContext* _tmp0_;
	TrackerStatusWaitContext* context;
	TrackerStatusWaitContext* _tmp1_;
};


static gpointer tracker_status_parent_class = NULL;
static gboolean tracker_status_first_time;
static gboolean tracker_status_first_time = TRUE;
static gpointer tracker_status_wait_context_parent_class = NULL;

GType tracker_status_get_type (void) G_GNUC_CONST;
guint tracker_status_register_object (void* object, GDBusConnection* connection, const gchar* path, GError** error);
static GType tracker_status_wait_context_get_type (void) G_GNUC_CONST G_GNUC_UNUSED;
#define TRACKER_STATUS_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TRACKER_TYPE_STATUS, TrackerStatusPrivate))
enum  {
	TRACKER_STATUS_DUMMY_PROPERTY
};
static void _g_object_unref0_ (gpointer var);
static void _g_list_free__g_object_unref0_ (GList* self);
#define TRACKER_STATUS_PATH "/org/freedesktop/Tracker1/Status"
#define TRACKER_STATUS_PROGRESS_TIMEOUT_S 5
static gboolean tracker_status_busy_notification_timeout (TrackerStatus* self);
static void tracker_status_callback (TrackerStatus* self, const gchar* status, gdouble progress);
static gboolean _tracker_status_busy_notification_timeout_gsource_func (gpointer self);
TrackerBusyCallback tracker_status_get_callback (TrackerStatus* self, void** result_target, GDestroyNotify* result_target_destroy_notify);
static void _tracker_status_callback_tracker_busy_callback (const gchar* status, gdouble progress, gpointer self);
gdouble tracker_status_get_progress (TrackerStatus* self);
gchar* tracker_status_get_status (TrackerStatus* self);
static void tracker_status_wait_data_free (gpointer _data);
void tracker_status_wait (TrackerStatus* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void tracker_status_wait_finish (TrackerStatus* self, GAsyncResult* _res_, GError** error);
static gboolean tracker_status_wait_co (TrackerStatusWaitData* data);
static TrackerStatusWaitContext* tracker_status_wait_context_new (void);
static TrackerStatusWaitContext* tracker_status_wait_context_construct (GType object_type);
static gboolean _tracker_status_wait_co_gsource_func (gpointer self);
TrackerStatus* tracker_status_new (void);
TrackerStatus* tracker_status_construct (GType object_type);
static void g_cclosure_user_marshal_VOID__STRING_DOUBLE (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);
enum  {
	TRACKER_STATUS_WAIT_CONTEXT_DUMMY_PROPERTY
};
static void tracker_status_wait_context_finalize (GObject* obj);
static void tracker_status_finalize (GObject* obj);
static void _dbus_tracker_status_get_progress (TrackerStatus* self, GVariant* parameters, GDBusMethodInvocation* invocation);
static void _dbus_tracker_status_get_status (TrackerStatus* self, GVariant* parameters, GDBusMethodInvocation* invocation);
static void _dbus_tracker_status_wait (TrackerStatus* self, GVariant* parameters, GDBusMethodInvocation* invocation);
static void _dbus_tracker_status_wait_ready (GObject * source_object, GAsyncResult * _res_, gpointer _user_data_);
static void tracker_status_dbus_interface_method_call (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* method_name, GVariant* parameters, GDBusMethodInvocation* invocation, gpointer user_data);
static GVariant* tracker_status_dbus_interface_get_property (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* property_name, GError** error, gpointer user_data);
static gboolean tracker_status_dbus_interface_set_property (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* property_name, GVariant* value, GError** error, gpointer user_data);
static void _dbus_tracker_status_progress (GObject* _sender, const gchar* status, gdouble progres, gpointer* _data);
static void _tracker_status_unregister_object (gpointer user_data);

static const GDBusArgInfo _tracker_status_dbus_arg_info_get_progress_result = {-1, "result", "d"};
static const GDBusArgInfo * const _tracker_status_dbus_arg_info_get_progress_in[] = {NULL};
static const GDBusArgInfo * const _tracker_status_dbus_arg_info_get_progress_out[] = {&_tracker_status_dbus_arg_info_get_progress_result, NULL};
static const GDBusMethodInfo _tracker_status_dbus_method_info_get_progress = {-1, "GetProgress", (GDBusArgInfo **) (&_tracker_status_dbus_arg_info_get_progress_in), (GDBusArgInfo **) (&_tracker_status_dbus_arg_info_get_progress_out)};
static const GDBusArgInfo _tracker_status_dbus_arg_info_get_status_result = {-1, "result", "s"};
static const GDBusArgInfo * const _tracker_status_dbus_arg_info_get_status_in[] = {NULL};
static const GDBusArgInfo * const _tracker_status_dbus_arg_info_get_status_out[] = {&_tracker_status_dbus_arg_info_get_status_result, NULL};
static const GDBusMethodInfo _tracker_status_dbus_method_info_get_status = {-1, "GetStatus", (GDBusArgInfo **) (&_tracker_status_dbus_arg_info_get_status_in), (GDBusArgInfo **) (&_tracker_status_dbus_arg_info_get_status_out)};
static const GDBusArgInfo * const _tracker_status_dbus_arg_info_wait_in[] = {NULL};
static const GDBusArgInfo * const _tracker_status_dbus_arg_info_wait_out[] = {NULL};
static const GDBusMethodInfo _tracker_status_dbus_method_info_wait = {-1, "Wait", (GDBusArgInfo **) (&_tracker_status_dbus_arg_info_wait_in), (GDBusArgInfo **) (&_tracker_status_dbus_arg_info_wait_out)};
static const GDBusMethodInfo * const _tracker_status_dbus_method_info[] = {&_tracker_status_dbus_method_info_get_progress, &_tracker_status_dbus_method_info_get_status, &_tracker_status_dbus_method_info_wait, NULL};
static const GDBusArgInfo _tracker_status_dbus_arg_info_progress_status = {-1, "status", "s"};
static const GDBusArgInfo _tracker_status_dbus_arg_info_progress_progres = {-1, "progres", "d"};
static const GDBusArgInfo * const _tracker_status_dbus_arg_info_progress[] = {&_tracker_status_dbus_arg_info_progress_status, &_tracker_status_dbus_arg_info_progress_progres, NULL};
static const GDBusSignalInfo _tracker_status_dbus_signal_info_progress = {-1, "Progress", (GDBusArgInfo **) (&_tracker_status_dbus_arg_info_progress)};
static const GDBusSignalInfo * const _tracker_status_dbus_signal_info[] = {&_tracker_status_dbus_signal_info_progress, NULL};
static const GDBusPropertyInfo * const _tracker_status_dbus_property_info[] = {NULL};
static const GDBusInterfaceInfo _tracker_status_dbus_interface_info = {-1, "org.freedesktop.Tracker1.Status", (GDBusMethodInfo **) (&_tracker_status_dbus_method_info), (GDBusSignalInfo **) (&_tracker_status_dbus_signal_info), (GDBusPropertyInfo **) (&_tracker_status_dbus_property_info)};
static const GDBusInterfaceVTable _tracker_status_dbus_interface_vtable = {tracker_status_dbus_interface_method_call, tracker_status_dbus_interface_get_property, tracker_status_dbus_interface_set_property};

static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void _g_list_free__g_object_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_object_unref0_, NULL);
	g_list_free (self);
}


static gboolean tracker_status_busy_notification_timeout (TrackerStatus* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_signal_emit_by_name (self, "progress", self->priv->status, self->priv->_progress);
	self->priv->timer_id = (guint) 0;
	result = FALSE;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gboolean _tracker_status_busy_notification_timeout_gsource_func (gpointer self) {
	gboolean result;
	result = tracker_status_busy_notification_timeout (self);
	return result;
}


static void tracker_status_callback (TrackerStatus* self, const gchar* status, gdouble progress) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	g_return_if_fail (status != NULL);
	self->priv->_progress = progress;
	if (progress == 1) {
		_tmp0_ = self->priv->wait_list != NULL;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		self->priv->wait_list = g_list_reverse (self->priv->wait_list);
		{
			GList* context_collection;
			GList* context_it;
			context_collection = self->priv->wait_list;
			for (context_it = context_collection; context_it != NULL; context_it = context_it->next) {
				TrackerStatusWaitContext* _tmp1_;
				TrackerStatusWaitContext* context;
				_tmp1_ = _g_object_ref0 ((TrackerStatusWaitContext*) context_it->data);
				context = _tmp1_;
				{
					context->callback (context->callback_target);
					_g_object_unref0 (context);
				}
			}
		}
		__g_list_free__g_object_unref0_0 (self->priv->wait_list);
		self->priv->wait_list = NULL;
	}
	if (g_strcmp0 (status, self->priv->status) != 0) {
		gchar* _tmp2_;
		_tmp2_ = g_strdup (status);
		_g_free0 (self->priv->status);
		self->priv->status = _tmp2_;
	}
	if (self->priv->timer_id == 0) {
		if (tracker_status_first_time) {
			guint _tmp3_;
			_tmp3_ = g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _tracker_status_busy_notification_timeout_gsource_func, g_object_ref (self), g_object_unref);
			self->priv->timer_id = _tmp3_;
			tracker_status_first_time = FALSE;
		} else {
			guint _tmp4_;
			_tmp4_ = g_timeout_add_seconds_full (G_PRIORITY_DEFAULT, (guint) TRACKER_STATUS_PROGRESS_TIMEOUT_S, _tracker_status_busy_notification_timeout_gsource_func, g_object_ref (self), g_object_unref);
			self->priv->timer_id = _tmp4_;
		}
	}
	while (TRUE) {
		GMainContext* _tmp5_ = NULL;
		gboolean _tmp6_;
		_tmp5_ = g_main_context_default ();
		_tmp6_ = g_main_context_iteration (_tmp5_, FALSE);
		if (!_tmp6_) {
			break;
		}
	}
}


static void _tracker_status_callback_tracker_busy_callback (const gchar* status, gdouble progress, gpointer self) {
	tracker_status_callback (self, status, progress);
}


TrackerBusyCallback tracker_status_get_callback (TrackerStatus* self, void** result_target, GDestroyNotify* result_target_destroy_notify) {
	TrackerBusyCallback result = NULL;
	gpointer _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = _tracker_status_callback_tracker_busy_callback;
	*result_target = g_object_ref (self);
	*result_target_destroy_notify = g_object_unref;
	result = _tmp0_;
	return result;
}


gdouble tracker_status_get_progress (TrackerStatus* self) {
	gdouble result = 0.0;
	g_return_val_if_fail (self != NULL, 0.0);
	result = self->priv->_progress;
	return result;
}


gchar* tracker_status_get_status (TrackerStatus* self) {
	gchar* result = NULL;
	gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_strdup (self->priv->status);
	result = _tmp0_;
	return result;
}


static void tracker_status_wait_data_free (gpointer _data) {
	TrackerStatusWaitData* data;
	data = _data;
	_g_object_unref0 (data->self);
	g_slice_free (TrackerStatusWaitData, data);
}


void tracker_status_wait (TrackerStatus* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	TrackerStatusWaitData* _data_;
	_data_ = g_slice_new0 (TrackerStatusWaitData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, tracker_status_wait);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, tracker_status_wait_data_free);
	_data_->self = _g_object_ref0 (self);
	tracker_status_wait_co (_data_);
}


void tracker_status_wait_finish (TrackerStatus* self, GAsyncResult* _res_, GError** error) {
	TrackerStatusWaitData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean _tracker_status_wait_co_gsource_func (gpointer self) {
	gboolean result;
	result = tracker_status_wait_co (self);
	return result;
}


static gboolean tracker_status_wait_co (TrackerStatusWaitData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	if (data->self->priv->_progress == 1) {
	} else {
		data->_tmp0_ = NULL;
		data->_tmp0_ = tracker_status_wait_context_new ();
		data->context = data->_tmp0_;
		(data->context->callback_target_destroy_notify == NULL) ? NULL : (data->context->callback_target_destroy_notify (data->context->callback_target), NULL);
		data->context->callback = NULL;
		data->context->callback_target = NULL;
		data->context->callback_target_destroy_notify = NULL;
		data->context->callback = _tracker_status_wait_co_gsource_func;
		data->context->callback_target = data;
		data->context->callback_target_destroy_notify = NULL;
		data->_tmp1_ = _g_object_ref0 (data->context);
		data->self->priv->wait_list = g_list_prepend (data->self->priv->wait_list, data->_tmp1_);
		data->_state_ = 1;
		return FALSE;
		_state_1:
		;
		_g_object_unref0 (data->context);
	}
	if (data->_state_ == 0) {
		g_simple_async_result_complete_in_idle (data->_async_result);
	} else {
		g_simple_async_result_complete (data->_async_result);
	}
	g_object_unref (data->_async_result);
	return FALSE;
}


TrackerStatus* tracker_status_construct (GType object_type) {
	TrackerStatus * self = NULL;
	self = (TrackerStatus*) g_object_new (object_type, NULL);
	return self;
}


TrackerStatus* tracker_status_new (void) {
	return tracker_status_construct (TRACKER_TYPE_STATUS);
}


static void g_cclosure_user_marshal_VOID__STRING_DOUBLE (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__STRING_DOUBLE) (gpointer data1, const char* arg_1, gdouble arg_2, gpointer data2);
	register GMarshalFunc_VOID__STRING_DOUBLE callback;
	register GCClosure * cc;
	register gpointer data1, data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 3);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__STRING_DOUBLE) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_string (param_values + 1), g_value_get_double (param_values + 2), data2);
}


static TrackerStatusWaitContext* tracker_status_wait_context_construct (GType object_type) {
	TrackerStatusWaitContext * self = NULL;
	self = (TrackerStatusWaitContext*) g_object_new (object_type, NULL);
	return self;
}


static TrackerStatusWaitContext* tracker_status_wait_context_new (void) {
	return tracker_status_wait_context_construct (TRACKER_STATUS_TYPE_WAIT_CONTEXT);
}


static void tracker_status_wait_context_class_init (TrackerStatusWaitContextClass * klass) {
	tracker_status_wait_context_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = tracker_status_wait_context_finalize;
}


static void tracker_status_wait_context_instance_init (TrackerStatusWaitContext * self) {
}


static void tracker_status_wait_context_finalize (GObject* obj) {
	TrackerStatusWaitContext * self;
	self = TRACKER_STATUS_WAIT_CONTEXT (obj);
	(self->callback_target_destroy_notify == NULL) ? NULL : (self->callback_target_destroy_notify (self->callback_target), NULL);
	self->callback = NULL;
	self->callback_target = NULL;
	self->callback_target_destroy_notify = NULL;
	G_OBJECT_CLASS (tracker_status_wait_context_parent_class)->finalize (obj);
}


static GType tracker_status_wait_context_get_type (void) {
	static volatile gsize tracker_status_wait_context_type_id__volatile = 0;
	if (g_once_init_enter (&tracker_status_wait_context_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (TrackerStatusWaitContextClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) tracker_status_wait_context_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TrackerStatusWaitContext), 0, (GInstanceInitFunc) tracker_status_wait_context_instance_init, NULL };
		GType tracker_status_wait_context_type_id;
		tracker_status_wait_context_type_id = g_type_register_static (G_TYPE_OBJECT, "TrackerStatusWaitContext", &g_define_type_info, 0);
		g_once_init_leave (&tracker_status_wait_context_type_id__volatile, tracker_status_wait_context_type_id);
	}
	return tracker_status_wait_context_type_id__volatile;
}


static void tracker_status_class_init (TrackerStatusClass * klass) {
	tracker_status_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (TrackerStatusPrivate));
	G_OBJECT_CLASS (klass)->finalize = tracker_status_finalize;
	/**
	 * TrackerStatus::progress:
	 * @notifier: the TrackerStatus
	 * @status: store status
	 * @progress: a #gdouble indicating store progress, from 0 to 1.
	 *
	 * the ::progress signal will be emitted by TrackerStatus
	 * to indicate progress about the store process. @status will
	 * contain a translated string with the current status and @progress
	 * will indicate how much has been processed so far.
	 **/
	g_signal_new ("progress", TRACKER_TYPE_STATUS, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__STRING_DOUBLE, G_TYPE_NONE, 2, G_TYPE_STRING, G_TYPE_DOUBLE);
}


static void tracker_status_instance_init (TrackerStatus * self) {
	gchar* _tmp0_;
	self->priv = TRACKER_STATUS_GET_PRIVATE (self);
	_tmp0_ = g_strdup ("Idle");
	self->priv->status = _tmp0_;
}


static void tracker_status_finalize (GObject* obj) {
	TrackerStatus * self;
	self = TRACKER_STATUS (obj);
	if (self->priv->timer_id != 0) {
		g_source_remove (self->priv->timer_id);
	}
	_g_free0 (self->priv->status);
	__g_list_free__g_object_unref0_0 (self->priv->wait_list);
	G_OBJECT_CLASS (tracker_status_parent_class)->finalize (obj);
}


GType tracker_status_get_type (void) {
	static volatile gsize tracker_status_type_id__volatile = 0;
	if (g_once_init_enter (&tracker_status_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (TrackerStatusClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) tracker_status_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TrackerStatus), 0, (GInstanceInitFunc) tracker_status_instance_init, NULL };
		GType tracker_status_type_id;
		tracker_status_type_id = g_type_register_static (G_TYPE_OBJECT, "TrackerStatus", &g_define_type_info, 0);
		g_type_set_qdata (tracker_status_type_id, g_quark_from_static_string ("vala-dbus-register-object"), (void*) tracker_status_register_object);
		g_once_init_leave (&tracker_status_type_id__volatile, tracker_status_type_id);
	}
	return tracker_status_type_id__volatile;
}


static void _dbus_tracker_status_get_progress (TrackerStatus* self, GVariant* parameters, GDBusMethodInvocation* invocation) {
	GError* error = NULL;
	GVariantIter _arguments_iter;
	GDBusMessage* _reply_message;
	GVariant* _reply;
	GVariantBuilder _reply_builder;
	gdouble result;
	g_variant_iter_init (&_arguments_iter, parameters);
	result = tracker_status_get_progress (self);
	_reply_message = g_dbus_message_new_method_reply (g_dbus_method_invocation_get_message (invocation));
	g_variant_builder_init (&_reply_builder, G_VARIANT_TYPE_TUPLE);
	g_variant_builder_add_value (&_reply_builder, g_variant_new_double (result));
	_reply = g_variant_builder_end (&_reply_builder);
	g_dbus_message_set_body (_reply_message, _reply);
	g_dbus_connection_send_message (g_dbus_method_invocation_get_connection (invocation), _reply_message, G_DBUS_SEND_MESSAGE_FLAGS_NONE, NULL, NULL);
	g_object_unref (invocation);
	g_object_unref (_reply_message);
}


static void _dbus_tracker_status_get_status (TrackerStatus* self, GVariant* parameters, GDBusMethodInvocation* invocation) {
	GError* error = NULL;
	GVariantIter _arguments_iter;
	GDBusMessage* _reply_message;
	GVariant* _reply;
	GVariantBuilder _reply_builder;
	gchar* result;
	g_variant_iter_init (&_arguments_iter, parameters);
	result = tracker_status_get_status (self);
	_reply_message = g_dbus_message_new_method_reply (g_dbus_method_invocation_get_message (invocation));
	g_variant_builder_init (&_reply_builder, G_VARIANT_TYPE_TUPLE);
	g_variant_builder_add_value (&_reply_builder, g_variant_new_string (result));
	_g_free0 ( result);
	_reply = g_variant_builder_end (&_reply_builder);
	g_dbus_message_set_body (_reply_message, _reply);
	g_dbus_connection_send_message (g_dbus_method_invocation_get_connection (invocation), _reply_message, G_DBUS_SEND_MESSAGE_FLAGS_NONE, NULL, NULL);
	g_object_unref (invocation);
	g_object_unref (_reply_message);
}


static void _dbus_tracker_status_wait (TrackerStatus* self, GVariant* parameters, GDBusMethodInvocation* invocation) {
	GVariantIter _arguments_iter;
	g_variant_iter_init (&_arguments_iter, parameters);
	tracker_status_wait (self, (GAsyncReadyCallback) _dbus_tracker_status_wait_ready, invocation);
}


static void _dbus_tracker_status_wait_ready (GObject * source_object, GAsyncResult * _res_, gpointer _user_data_) {
	GDBusMethodInvocation * invocation;
	GError* error = NULL;
	GDBusMessage* _reply_message;
	GVariant* _reply;
	GVariantBuilder _reply_builder;
	invocation = _user_data_;
	tracker_status_wait_finish ((TrackerStatus*) source_object, _res_, &error);
	if (error) {
		g_dbus_method_invocation_return_gerror (invocation, error);
		return;
	}
	_reply_message = g_dbus_message_new_method_reply (g_dbus_method_invocation_get_message (invocation));
	g_variant_builder_init (&_reply_builder, G_VARIANT_TYPE_TUPLE);
	_reply = g_variant_builder_end (&_reply_builder);
	g_dbus_message_set_body (_reply_message, _reply);
	g_dbus_connection_send_message (g_dbus_method_invocation_get_connection (invocation), _reply_message, G_DBUS_SEND_MESSAGE_FLAGS_NONE, NULL, NULL);
	g_object_unref (invocation);
	g_object_unref (_reply_message);
}


static void tracker_status_dbus_interface_method_call (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* method_name, GVariant* parameters, GDBusMethodInvocation* invocation, gpointer user_data) {
	gpointer* data;
	gpointer object;
	data = user_data;
	object = data[0];
	if (strcmp (method_name, "GetProgress") == 0) {
		_dbus_tracker_status_get_progress (object, parameters, invocation);
	} else if (strcmp (method_name, "GetStatus") == 0) {
		_dbus_tracker_status_get_status (object, parameters, invocation);
	} else if (strcmp (method_name, "Wait") == 0) {
		_dbus_tracker_status_wait (object, parameters, invocation);
	} else {
		g_object_unref (invocation);
	}
}


static GVariant* tracker_status_dbus_interface_get_property (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* property_name, GError** error, gpointer user_data) {
	gpointer* data;
	gpointer object;
	data = user_data;
	object = data[0];
	return NULL;
}


static gboolean tracker_status_dbus_interface_set_property (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* property_name, GVariant* value, GError** error, gpointer user_data) {
	gpointer* data;
	gpointer object;
	data = user_data;
	object = data[0];
	return FALSE;
}


static void _dbus_tracker_status_progress (GObject* _sender, const gchar* status, gdouble progres, gpointer* _data) {
	GDBusConnection * _connection;
	const gchar * _path;
	GVariant *_arguments;
	GVariantBuilder _arguments_builder;
	_connection = _data[1];
	_path = _data[2];
	g_variant_builder_init (&_arguments_builder, G_VARIANT_TYPE_TUPLE);
	g_variant_builder_add_value (&_arguments_builder, g_variant_new_string (status));
	g_variant_builder_add_value (&_arguments_builder, g_variant_new_double (progres));
	_arguments = g_variant_builder_end (&_arguments_builder);
	g_dbus_connection_emit_signal (_connection, NULL, _path, "org.freedesktop.Tracker1.Status", "Progress", _arguments, NULL);
}


guint tracker_status_register_object (gpointer object, GDBusConnection* connection, const gchar* path, GError** error) {
	guint result;
	gpointer *data;
	data = g_new (gpointer, 3);
	data[0] = g_object_ref (object);
	data[1] = g_object_ref (connection);
	data[2] = g_strdup (path);
	result = g_dbus_connection_register_object (connection, path, (GDBusInterfaceInfo *) (&_tracker_status_dbus_interface_info), &_tracker_status_dbus_interface_vtable, data, _tracker_status_unregister_object, error);
	if (!result) {
		return 0;
	}
	g_signal_connect (object, "progress", (GCallback) _dbus_tracker_status_progress, data);
	return result;
}


static void _tracker_status_unregister_object (gpointer user_data) {
	gpointer* data;
	data = user_data;
	g_object_unref (data[0]);
	g_object_unref (data[1]);
	g_free (data[2]);
	g_free (data);
}



