/* tracker-history.c generated by valac 0.14.2, the Vala compiler
 * generated from tracker-history.vala, do not modify */

/**/
/* Copyright 2010, Martyn Russell <martyn@lanedo.com>*/
/**/
/* This program is free software; you can redistribute it and/or*/
/* modify it under the terms of the GNU General Public License*/
/* as published by the Free Software Foundation; either version 2*/
/* of the License, or (at your option) any later version.*/
/**/
/* This program is distributed in the hope that it will be useful,*/
/* but WITHOUT ANY WARRANTY; without even the implied warranty of*/
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the*/
/* GNU General Public License for more details.*/
/**/
/* You should have received a copy of the GNU General Public License*/
/* along with this program; if not, write to the Free Software*/
/* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA*/
/* 02110-1301, USA.*/
/**/

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gstdio.h>
#include <gobject/gvaluecollector.h>


#define TRACKER_TYPE_HISTORY (tracker_history_get_type ())
#define TRACKER_HISTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TRACKER_TYPE_HISTORY, TrackerHistory))
#define TRACKER_HISTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TRACKER_TYPE_HISTORY, TrackerHistoryClass))
#define TRACKER_IS_HISTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TRACKER_TYPE_HISTORY))
#define TRACKER_IS_HISTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TRACKER_TYPE_HISTORY))
#define TRACKER_HISTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TRACKER_TYPE_HISTORY, TrackerHistoryClass))

typedef struct _TrackerHistory TrackerHistory;
typedef struct _TrackerHistoryClass TrackerHistoryClass;
typedef struct _TrackerHistoryPrivate TrackerHistoryPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_key_file_free0(var) ((var == NULL) ? NULL : (var = (g_key_file_free (var), NULL)))
typedef struct _TrackerParamSpecHistory TrackerParamSpecHistory;

struct _TrackerHistory {
	GTypeInstance parent_instance;
	volatile int ref_count;
	TrackerHistoryPrivate * priv;
};

struct _TrackerHistoryClass {
	GTypeClass parent_class;
	void (*finalize) (TrackerHistory *self);
};

struct _TrackerHistoryPrivate {
	GKeyFile* data;
	gchar* filename;
	gchar** history;
	gint history_length1;
	gint _history_size_;
};

struct _TrackerParamSpecHistory {
	GParamSpec parent_instance;
};


static gpointer tracker_history_parent_class = NULL;

gpointer tracker_history_ref (gpointer instance);
void tracker_history_unref (gpointer instance);
GParamSpec* tracker_param_spec_history (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void tracker_value_set_history (GValue* value, gpointer v_object);
void tracker_value_take_history (GValue* value, gpointer v_object);
gpointer tracker_value_get_history (const GValue* value);
GType tracker_history_get_type (void) G_GNUC_CONST;
#define TRACKER_HISTORY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TRACKER_TYPE_HISTORY, TrackerHistoryPrivate))
enum  {
	TRACKER_HISTORY_DUMMY_PROPERTY
};
TrackerHistory* tracker_history_new (void);
TrackerHistory* tracker_history_construct (GType object_type);
void tracker_history_add (TrackerHistory* self, const gchar* criteria);
static void _vala_array_add1 (gchar*** array, int* length, int* size, gchar* value);
gchar** tracker_history_get (TrackerHistory* self, int* result_length1);
static gchar** _vala_array_dup1 (gchar** self, int length);
static void tracker_history_finalize (TrackerHistory* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


TrackerHistory* tracker_history_construct (GType object_type) {
	TrackerHistory* self = NULL;
	GKeyFile* _tmp0_;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	GKeyFile* _tmp14_;
	gboolean _tmp15_ = FALSE;
	gchar** _tmp23_;
	gint _tmp23__length1;
	GError * _inner_error_ = NULL;
	self = (TrackerHistory*) g_type_create_instance (object_type);
	g_debug ("tracker-history.vala:26: Loading history");
	_tmp0_ = g_key_file_new ();
	_g_key_file_free0 (self->priv->data);
	self->priv->data = _tmp0_;
	_tmp1_ = g_get_user_data_dir ();
	_tmp2_ = g_build_filename (_tmp1_, "tracker", "tracker-needle.txt", NULL, NULL);
	_g_free0 (self->priv->filename);
	self->priv->filename = _tmp2_;
	{
		GKeyFile* _tmp3_;
		const gchar* _tmp4_;
		_tmp3_ = self->priv->data;
		_tmp4_ = self->priv->filename;
		g_key_file_load_from_file (_tmp3_, _tmp4_, G_KEY_FILE_KEEP_COMMENTS | G_KEY_FILE_KEEP_TRANSLATIONS, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_KEY_FILE_ERROR) {
				goto __catch1_g_key_file_error;
			}
			if (_inner_error_->domain == G_FILE_ERROR) {
				goto __catch1_g_file_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	goto __finally1;
	__catch1_g_key_file_error:
	{
		GError* e1 = NULL;
		const gchar* _tmp5_;
		GError* _tmp6_;
		const gchar* _tmp7_;
		e1 = _inner_error_;
		_inner_error_ = NULL;
		_tmp5_ = self->priv->filename;
		_tmp6_ = e1;
		_tmp7_ = _tmp6_->message;
		g_warning ("tracker-history.vala:34: Could not load history from file:'%s': %s", _tmp5_, _tmp7_);
		_g_error_free0 (e1);
		return self;
	}
	goto __finally1;
	__catch1_g_file_error:
	{
		GError* e2 = NULL;
		GError* _tmp8_;
		gint _tmp9_;
		e2 = _inner_error_;
		_inner_error_ = NULL;
		_tmp8_ = e2;
		_tmp9_ = _tmp8_->code;
		if (_tmp9_ == 4) {
			const gchar* _tmp10_;
			_tmp10_ = self->priv->filename;
			g_message ("tracker-history.vala:38: Creating new history file:'%s'", _tmp10_);
		} else {
			const gchar* _tmp11_;
			GError* _tmp12_;
			const gchar* _tmp13_;
			_tmp11_ = self->priv->filename;
			_tmp12_ = e2;
			_tmp13_ = _tmp12_->message;
			g_warning ("tracker-history.vala:40: Could not load history from file:'%s': %s", _tmp11_, _tmp13_);
		}
		_g_error_free0 (e2);
		return self;
	}
	__finally1:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	_tmp14_ = self->priv->data;
	_tmp15_ = g_key_file_has_group (_tmp14_, "History");
	if (_tmp15_ == FALSE) {
		g_debug ("tracker-history.vala:45:   No history found");
		return self;
	}
	{
		GKeyFile* _tmp16_;
		gsize _tmp17_;
		gchar** _tmp18_ = NULL;
		gchar** _tmp19_;
		gint _tmp19__length1;
		gint __tmp19__size_;
		_tmp16_ = self->priv->data;
		_tmp18_ = g_key_file_get_string_list (_tmp16_, "History", "criteria", &_tmp17_, &_inner_error_);
		_tmp19_ = _tmp18_;
		_tmp19__length1 = _tmp17_;
		__tmp19__size_ = _tmp19__length1;
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_KEY_FILE_ERROR) {
				goto __catch2_g_key_file_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		self->priv->history = (_vala_array_free (self->priv->history, self->priv->history_length1, (GDestroyNotify) g_free), NULL);
		self->priv->history = _tmp19_;
		self->priv->history_length1 = _tmp19__length1;
		self->priv->_history_size_ = self->priv->history_length1;
	}
	goto __finally2;
	__catch2_g_key_file_error:
	{
		GError* e1 = NULL;
		const gchar* _tmp20_;
		GError* _tmp21_;
		const gchar* _tmp22_;
		e1 = _inner_error_;
		_inner_error_ = NULL;
		_tmp20_ = self->priv->filename;
		_tmp21_ = e1;
		_tmp22_ = _tmp21_->message;
		g_warning ("tracker-history.vala:52: Could not load history from file:'%s': %s", _tmp20_, _tmp22_);
		_g_error_free0 (e1);
		return self;
	}
	__finally2:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	_tmp23_ = self->priv->history;
	_tmp23__length1 = self->priv->history_length1;
	g_debug ("tracker-history.vala:56:   Found %d previous search histories", _tmp23__length1);
	g_debug ("tracker-history.vala:58:   Done");
	return self;
}


TrackerHistory* tracker_history_new (void) {
	return tracker_history_construct (TRACKER_TYPE_HISTORY);
}


static void _vala_array_add1 (gchar*** array, int* length, int* size, gchar* value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar*, *array, (*size) + 1);
	}
	(*array)[(*length)++] = value;
	(*array)[*length] = NULL;
}


void tracker_history_add (TrackerHistory* self, const gchar* criteria) {
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	gchar** _tmp4_;
	gint _tmp4__length1;
	gchar** _tmp8_;
	gint _tmp8__length1;
	const gchar* _tmp9_;
	gchar* _tmp10_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (criteria != NULL);
	_tmp0_ = criteria;
	_tmp1_ = criteria;
	_tmp2_ = strlen (_tmp1_);
	_tmp3_ = _tmp2_;
	g_return_if_fail ((_tmp0_ != NULL) && (_tmp3_ > 0));
	_tmp4_ = self->priv->history;
	_tmp4__length1 = self->priv->history_length1;
	{
		gchar** check_collection = NULL;
		gint check_collection_length1 = 0;
		gint _check_collection_size_ = 0;
		gint check_it = 0;
		check_collection = _tmp4_;
		check_collection_length1 = _tmp4__length1;
		for (check_it = 0; check_it < _tmp4__length1; check_it = check_it + 1) {
			gchar* _tmp5_;
			gchar* check = NULL;
			_tmp5_ = g_strdup (check_collection[check_it]);
			check = _tmp5_;
			{
				const gchar* _tmp6_;
				const gchar* _tmp7_;
				_tmp6_ = check;
				_tmp7_ = criteria;
				if (g_strcmp0 (_tmp6_, _tmp7_) == 0) {
					_g_free0 (check);
					return;
				}
				_g_free0 (check);
			}
		}
	}
	_tmp8_ = self->priv->history;
	_tmp8__length1 = self->priv->history_length1;
	_tmp9_ = criteria;
	_tmp10_ = g_strdup (_tmp9_);
	_vala_array_add1 (&self->priv->history, &self->priv->history_length1, &self->priv->_history_size_, _tmp10_);
}


static gchar** _vala_array_dup1 (gchar** self, int length) {
	gchar** result;
	int i;
	result = g_new0 (gchar*, length + 1);
	for (i = 0; i < length; i++) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (self[i]);
		result[i] = _tmp0_;
	}
	return result;
}


gchar** tracker_history_get (TrackerHistory* self, int* result_length1) {
	gchar** result = NULL;
	gchar** _tmp0_;
	gint _tmp0__length1;
	gchar** _tmp1_;
	gint _tmp1__length1;
	gchar** _tmp2_;
	gint _tmp2__length1;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->history;
	_tmp0__length1 = self->priv->history_length1;
	_tmp1_ = (_tmp0_ != NULL) ? _vala_array_dup1 (_tmp0_, _tmp0__length1) : ((gpointer) _tmp0_);
	_tmp1__length1 = _tmp0__length1;
	_tmp2_ = _tmp1_;
	_tmp2__length1 = _tmp1__length1;
	if (result_length1) {
		*result_length1 = _tmp2__length1;
	}
	result = _tmp2_;
	return result;
}


static void tracker_value_history_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void tracker_value_history_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		tracker_history_unref (value->data[0].v_pointer);
	}
}


static void tracker_value_history_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = tracker_history_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer tracker_value_history_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* tracker_value_history_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		TrackerHistory* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = tracker_history_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* tracker_value_history_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	TrackerHistory** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = tracker_history_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* tracker_param_spec_history (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	TrackerParamSpecHistory* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TRACKER_TYPE_HISTORY), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer tracker_value_get_history (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TRACKER_TYPE_HISTORY), NULL);
	return value->data[0].v_pointer;
}


void tracker_value_set_history (GValue* value, gpointer v_object) {
	TrackerHistory* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TRACKER_TYPE_HISTORY));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TRACKER_TYPE_HISTORY));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		tracker_history_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		tracker_history_unref (old);
	}
}


void tracker_value_take_history (GValue* value, gpointer v_object) {
	TrackerHistory* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TRACKER_TYPE_HISTORY));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TRACKER_TYPE_HISTORY));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		tracker_history_unref (old);
	}
}


static void tracker_history_class_init (TrackerHistoryClass * klass) {
	tracker_history_parent_class = g_type_class_peek_parent (klass);
	TRACKER_HISTORY_CLASS (klass)->finalize = tracker_history_finalize;
	g_type_class_add_private (klass, sizeof (TrackerHistoryPrivate));
}


static void tracker_history_instance_init (TrackerHistory * self) {
	self->priv = TRACKER_HISTORY_GET_PRIVATE (self);
	self->ref_count = 1;
}


static void tracker_history_finalize (TrackerHistory* obj) {
	TrackerHistory * self;
	GKeyFile* _tmp0_;
	gchar** _tmp1_;
	gint _tmp1__length1;
	GError * _inner_error_ = NULL;
	self = TRACKER_HISTORY (obj);
	g_debug ("tracker-history.vala:62: Saving history");
	_tmp0_ = self->priv->data;
	_tmp1_ = self->priv->history;
	_tmp1__length1 = self->priv->history_length1;
	g_key_file_set_string_list (_tmp0_, "History", "criteria", (const gchar* const*) _tmp1_, _tmp1__length1);
	{
		GKeyFile* _tmp2_;
		gchar* _tmp3_ = NULL;
		gchar* output;
		const gchar* _tmp4_;
		const gchar* _tmp5_;
		_tmp2_ = self->priv->data;
		_tmp3_ = g_key_file_to_data (_tmp2_, NULL, NULL);
		output = _tmp3_;
		_tmp4_ = self->priv->filename;
		_tmp5_ = output;
		g_file_set_contents (_tmp4_, _tmp5_, (gssize) (-1), &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_free0 (output);
			if (_inner_error_->domain == G_FILE_ERROR) {
				goto __catch0_g_file_error;
			}
			_g_free0 (output);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		_g_free0 (output);
	}
	goto __finally0;
	__catch0_g_file_error:
	{
		GError* e1 = NULL;
		const gchar* _tmp6_;
		GError* _tmp7_;
		const gchar* _tmp8_;
		e1 = _inner_error_;
		_inner_error_ = NULL;
		_tmp6_ = self->priv->filename;
		_tmp7_ = e1;
		_tmp8_ = _tmp7_->message;
		g_warning ("tracker-history.vala:71: Could not save history to file:'%s': %s", _tmp6_, _tmp8_);
		_g_error_free0 (e1);
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
	}
	g_debug ("tracker-history.vala:74:   Done");
	_g_key_file_free0 (self->priv->data);
	_g_free0 (self->priv->filename);
	self->priv->history = (_vala_array_free (self->priv->history, self->priv->history_length1, (GDestroyNotify) g_free), NULL);
}


GType tracker_history_get_type (void) {
	static volatile gsize tracker_history_type_id__volatile = 0;
	if (g_once_init_enter (&tracker_history_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { tracker_value_history_init, tracker_value_history_free_value, tracker_value_history_copy_value, tracker_value_history_peek_pointer, "p", tracker_value_history_collect_value, "p", tracker_value_history_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (TrackerHistoryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) tracker_history_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TrackerHistory), 0, (GInstanceInitFunc) tracker_history_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType tracker_history_type_id;
		tracker_history_type_id = g_type_register_fundamental (g_type_fundamental_next (), "TrackerHistory", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&tracker_history_type_id__volatile, tracker_history_type_id);
	}
	return tracker_history_type_id__volatile;
}


gpointer tracker_history_ref (gpointer instance) {
	TrackerHistory* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void tracker_history_unref (gpointer instance) {
	TrackerHistory* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		TRACKER_HISTORY_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



