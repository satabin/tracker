/* tracker-miner-mock.c generated by valac 0.35.6.8-f2502, the Vala compiler
 * generated from tracker-miner-mock.vala, do not modify */

/**/
/* Copyright (C) 2010, Nokia*/
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
#include <float.h>
#include <math.h>


#define TYPE_TRACKER_MINER_MOCK (tracker_miner_mock_get_type ())
#define TRACKER_MINER_MOCK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRACKER_MINER_MOCK, TrackerMinerMock))
#define TRACKER_MINER_MOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRACKER_MINER_MOCK, TrackerMinerMockClass))
#define IS_TRACKER_MINER_MOCK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRACKER_MINER_MOCK))
#define IS_TRACKER_MINER_MOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRACKER_MINER_MOCK))
#define TRACKER_MINER_MOCK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRACKER_MINER_MOCK, TrackerMinerMockClass))

typedef struct _TrackerMinerMock TrackerMinerMock;
typedef struct _TrackerMinerMockClass TrackerMinerMockClass;
typedef struct _TrackerMinerMockPrivate TrackerMinerMockPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
enum  {
	TRACKER_MINER_MOCK_PROGRESS_SIGNAL,
	TRACKER_MINER_MOCK_PAUSED_SIGNAL,
	TRACKER_MINER_MOCK_RESUMED_SIGNAL,
	TRACKER_MINER_MOCK_LAST_SIGNAL
};
static guint tracker_miner_mock_signals[TRACKER_MINER_MOCK_LAST_SIGNAL] = {0};

struct _TrackerMinerMock {
	GObject parent_instance;
	TrackerMinerMockPrivate * priv;
	gboolean is_paused;
};

struct _TrackerMinerMockClass {
	GObjectClass parent_class;
};

struct _TrackerMinerMockPrivate {
	gchar* _pause_reason;
	gchar* _name;
	gchar** _apps;
	gint _apps_length1;
	gint __apps_size_;
	gchar** _reasons;
	gint _reasons_length1;
	gint __reasons_size_;
};


static gpointer tracker_miner_mock_parent_class = NULL;

GType tracker_miner_mock_get_type (void) G_GNUC_CONST;
#define TRACKER_MINER_MOCK_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_TRACKER_MINER_MOCK, TrackerMinerMockPrivate))
enum  {
	TRACKER_MINER_MOCK_DUMMY_PROPERTY,
	TRACKER_MINER_MOCK_PAUSE_REASON,
	TRACKER_MINER_MOCK_NAME,
	TRACKER_MINER_MOCK_APPS,
	TRACKER_MINER_MOCK_REASONS
};
TrackerMinerMock* tracker_miner_mock_new (const gchar* name);
TrackerMinerMock* tracker_miner_mock_construct (GType object_type, const gchar* name);
void tracker_miner_mock_set_name (TrackerMinerMock* self, const gchar* value);
void tracker_miner_mock_set_paused (TrackerMinerMock* self, gboolean paused);
gboolean tracker_miner_mock_get_paused (TrackerMinerMock* self);
void tracker_miner_mock_pause (TrackerMinerMock* self, const gchar* app, const gchar* reason);
static void _vala_array_add1 (gchar** * array, int* length, int* size, gchar* value);
static void _vala_array_add2 (gchar** * array, int* length, int* size, gchar* value);
void tracker_miner_mock_resume (TrackerMinerMock* self);
const gchar* tracker_miner_mock_get_pause_reason (TrackerMinerMock* self);
void tracker_miner_mock_set_pause_reason (TrackerMinerMock* self, const gchar* value);
const gchar* tracker_miner_mock_get_name (TrackerMinerMock* self);
gchar** tracker_miner_mock_get_apps (TrackerMinerMock* self, int* result_length1);
gchar** tracker_miner_mock_get_reasons (TrackerMinerMock* self, int* result_length1);
static void g_cclosure_user_marshal_VOID__STRING_STRING_DOUBLE (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);
static void tracker_miner_mock_finalize (GObject * obj);
static void _vala_tracker_miner_mock_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_tracker_miner_mock_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


TrackerMinerMock* tracker_miner_mock_construct (GType object_type, const gchar* name) {
	TrackerMinerMock * self = NULL;
	const gchar* _tmp0_;
	gchar** _tmp1_;
	gchar** _tmp2_;
#line 37 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_return_val_if_fail (name != NULL, NULL);
#line 37 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self = (TrackerMinerMock*) g_object_new (object_type, NULL);
#line 38 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp0_ = name;
#line 38 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	tracker_miner_mock_set_name (self, _tmp0_);
#line 39 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp1_ = g_new0 (gchar*, 0 + 1);
#line 39 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->_apps = (_vala_array_free (self->priv->_apps, self->priv->_apps_length1, (GDestroyNotify) g_free), NULL);
#line 39 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->_apps = _tmp1_;
#line 39 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->_apps_length1 = 0;
#line 39 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->__apps_size_ = self->priv->_apps_length1;
#line 40 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp2_ = g_new0 (gchar*, 0 + 1);
#line 40 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->_reasons = (_vala_array_free (self->priv->_reasons, self->priv->_reasons_length1, (GDestroyNotify) g_free), NULL);
#line 40 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->_reasons = _tmp2_;
#line 40 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->_reasons_length1 = 0;
#line 40 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->__reasons_size_ = self->priv->_reasons_length1;
#line 37 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	return self;
#line 141 "tracker-miner-mock.c"
}


TrackerMinerMock* tracker_miner_mock_new (const gchar* name) {
#line 37 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	return tracker_miner_mock_construct (TYPE_TRACKER_MINER_MOCK, name);
#line 148 "tracker-miner-mock.c"
}


void tracker_miner_mock_set_paused (TrackerMinerMock* self, gboolean paused) {
	gboolean _tmp0_;
#line 43 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_return_if_fail (self != NULL);
#line 43 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp0_ = paused;
#line 43 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->is_paused = _tmp0_;
#line 160 "tracker-miner-mock.c"
}


gboolean tracker_miner_mock_get_paused (TrackerMinerMock* self) {
	gboolean result = FALSE;
	gboolean _tmp0_;
#line 44 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 44 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp0_ = self->is_paused;
#line 44 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	result = _tmp0_;
#line 44 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	return result;
#line 175 "tracker-miner-mock.c"
}


static void _vala_array_add1 (gchar** * array, int* length, int* size, gchar* value) {
#line 51 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	if ((*length) == (*size)) {
#line 51 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		*size = (*size) ? (2 * (*size)) : 4;
#line 51 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		*array = g_renew (gchar*, *array, (*size) + 1);
#line 186 "tracker-miner-mock.c"
	}
#line 51 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	(*array)[(*length)++] = value;
#line 51 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	(*array)[*length] = NULL;
#line 192 "tracker-miner-mock.c"
}


static void _vala_array_add2 (gchar** * array, int* length, int* size, gchar* value) {
#line 57 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	if ((*length) == (*size)) {
#line 57 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		*size = (*size) ? (2 * (*size)) : 4;
#line 57 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		*array = g_renew (gchar*, *array, (*size) + 1);
#line 203 "tracker-miner-mock.c"
	}
#line 57 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	(*array)[(*length)++] = value;
#line 57 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	(*array)[*length] = NULL;
#line 209 "tracker-miner-mock.c"
}


void tracker_miner_mock_pause (TrackerMinerMock* self, const gchar* app, const gchar* reason) {
	gchar** _tmp0_;
	gint _tmp0__length1;
	gchar** _tmp7_;
	gint _tmp7__length1;
#line 46 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_return_if_fail (self != NULL);
#line 46 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_return_if_fail (app != NULL);
#line 46 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_return_if_fail (reason != NULL);
#line 48 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp0_ = self->priv->_apps;
#line 48 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp0__length1 = self->priv->_apps_length1;
#line 48 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	if (_tmp0__length1 == 0) {
#line 230 "tracker-miner-mock.c"
		const gchar* _tmp1_;
		gchar* _tmp2_;
		gchar** _tmp3_;
#line 49 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp1_ = app;
#line 49 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp2_ = g_strdup (_tmp1_);
#line 49 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp3_ = g_new0 (gchar*, 1 + 1);
#line 49 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp3_[0] = _tmp2_;
#line 49 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		self->priv->_apps = (_vala_array_free (self->priv->_apps, self->priv->_apps_length1, (GDestroyNotify) g_free), NULL);
#line 49 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		self->priv->_apps = _tmp3_;
#line 49 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		self->priv->_apps_length1 = 1;
#line 49 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		self->priv->__apps_size_ = self->priv->_apps_length1;
#line 250 "tracker-miner-mock.c"
	} else {
		gchar** _tmp4_;
		gint _tmp4__length1;
		const gchar* _tmp5_;
		gchar* _tmp6_;
#line 51 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp4_ = self->priv->_apps;
#line 51 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp4__length1 = self->priv->_apps_length1;
#line 51 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp5_ = app;
#line 51 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp6_ = g_strdup (_tmp5_);
#line 51 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_vala_array_add1 (&self->priv->_apps, &self->priv->_apps_length1, &self->priv->__apps_size_, _tmp6_);
#line 266 "tracker-miner-mock.c"
	}
#line 54 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp7_ = self->priv->_reasons;
#line 54 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp7__length1 = self->priv->_reasons_length1;
#line 54 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	if (_tmp7__length1 == 0) {
#line 274 "tracker-miner-mock.c"
		const gchar* _tmp8_;
		gchar* _tmp9_;
		gchar** _tmp10_;
#line 55 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp8_ = reason;
#line 55 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp9_ = g_strdup (_tmp8_);
#line 55 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp10_ = g_new0 (gchar*, 1 + 1);
#line 55 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp10_[0] = _tmp9_;
#line 55 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		self->priv->_reasons = (_vala_array_free (self->priv->_reasons, self->priv->_reasons_length1, (GDestroyNotify) g_free), NULL);
#line 55 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		self->priv->_reasons = _tmp10_;
#line 55 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		self->priv->_reasons_length1 = 1;
#line 55 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		self->priv->__reasons_size_ = self->priv->_reasons_length1;
#line 294 "tracker-miner-mock.c"
	} else {
		gchar** _tmp11_;
		gint _tmp11__length1;
		const gchar* _tmp12_;
		gchar* _tmp13_;
#line 57 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp11_ = self->priv->_reasons;
#line 57 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp11__length1 = self->priv->_reasons_length1;
#line 57 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp12_ = reason;
#line 57 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp13_ = g_strdup (_tmp12_);
#line 57 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_vala_array_add2 (&self->priv->_reasons, &self->priv->_reasons_length1, &self->priv->__reasons_size_, _tmp13_);
#line 310 "tracker-miner-mock.c"
	}
#line 59 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->is_paused = TRUE;
#line 60 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_signal_emit (self, tracker_miner_mock_signals[TRACKER_MINER_MOCK_PAUSED_SIGNAL], 0);
#line 316 "tracker-miner-mock.c"
}


void tracker_miner_mock_resume (TrackerMinerMock* self) {
#line 63 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_return_if_fail (self != NULL);
#line 64 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->_apps = (_vala_array_free (self->priv->_apps, self->priv->_apps_length1, (GDestroyNotify) g_free), NULL);
#line 64 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->_apps = NULL;
#line 64 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->_apps_length1 = 0;
#line 64 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->__apps_size_ = self->priv->_apps_length1;
#line 65 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->_reasons = (_vala_array_free (self->priv->_reasons, self->priv->_reasons_length1, (GDestroyNotify) g_free), NULL);
#line 65 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->_reasons = NULL;
#line 65 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->_reasons_length1 = 0;
#line 65 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->__reasons_size_ = self->priv->_reasons_length1;
#line 66 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->is_paused = FALSE;
#line 67 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_signal_emit (self, tracker_miner_mock_signals[TRACKER_MINER_MOCK_RESUMED_SIGNAL], 0);
#line 343 "tracker-miner-mock.c"
}


const gchar* tracker_miner_mock_get_pause_reason (TrackerMinerMock* self) {
	const gchar* result;
	const gchar* _tmp0_;
#line 25 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 25 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp0_ = self->priv->_pause_reason;
#line 25 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	result = _tmp0_;
#line 25 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	return result;
#line 358 "tracker-miner-mock.c"
}


void tracker_miner_mock_set_pause_reason (TrackerMinerMock* self, const gchar* value) {
#line 25 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_return_if_fail (self != NULL);
#line 25 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	if (g_strcmp0 (value, tracker_miner_mock_get_pause_reason (self)) != 0) {
#line 367 "tracker-miner-mock.c"
		const gchar* _tmp0_;
		gchar* _tmp1_;
#line 25 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp0_ = value;
#line 25 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp1_ = g_strdup (_tmp0_);
#line 25 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_g_free0 (self->priv->_pause_reason);
#line 25 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		self->priv->_pause_reason = _tmp1_;
#line 25 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		g_object_notify ((GObject *) self, "pause-reason");
#line 380 "tracker-miner-mock.c"
	}
}


const gchar* tracker_miner_mock_get_name (TrackerMinerMock* self) {
	const gchar* result;
	const gchar* _tmp0_;
#line 26 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 26 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp0_ = self->priv->_name;
#line 26 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	result = _tmp0_;
#line 26 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	return result;
#line 396 "tracker-miner-mock.c"
}


void tracker_miner_mock_set_name (TrackerMinerMock* self, const gchar* value) {
#line 26 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_return_if_fail (self != NULL);
#line 26 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	if (g_strcmp0 (value, tracker_miner_mock_get_name (self)) != 0) {
#line 405 "tracker-miner-mock.c"
		const gchar* _tmp0_;
		gchar* _tmp1_;
#line 26 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp0_ = value;
#line 26 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_tmp1_ = g_strdup (_tmp0_);
#line 26 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		_g_free0 (self->priv->_name);
#line 26 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		self->priv->_name = _tmp1_;
#line 26 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		g_object_notify ((GObject *) self, "name");
#line 418 "tracker-miner-mock.c"
	}
}


gchar** tracker_miner_mock_get_apps (TrackerMinerMock* self, int* result_length1) {
	gchar** result;
	gchar** _tmp0_;
	gint _tmp0__length1;
	gchar** _tmp1_;
	gint _tmp1__length1;
#line 27 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 27 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp0_ = self->priv->_apps;
#line 27 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp0__length1 = self->priv->_apps_length1;
#line 27 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp1_ = _tmp0_;
#line 27 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp1__length1 = _tmp0__length1;
#line 27 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	if (result_length1) {
#line 27 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		*result_length1 = _tmp1__length1;
#line 443 "tracker-miner-mock.c"
	}
#line 27 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	result = _tmp1_;
#line 27 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	return result;
#line 449 "tracker-miner-mock.c"
}


gchar** tracker_miner_mock_get_reasons (TrackerMinerMock* self, int* result_length1) {
	gchar** result;
	gchar** _tmp0_;
	gint _tmp0__length1;
	gchar** _tmp1_;
	gint _tmp1__length1;
#line 28 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 28 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp0_ = self->priv->_apps;
#line 28 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp0__length1 = self->priv->_apps_length1;
#line 28 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp1_ = _tmp0_;
#line 28 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp1__length1 = _tmp0__length1;
#line 28 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	if (result_length1) {
#line 28 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		*result_length1 = _tmp1__length1;
#line 473 "tracker-miner-mock.c"
	}
#line 28 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	result = _tmp1_;
#line 28 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	return result;
#line 479 "tracker-miner-mock.c"
}


static void g_cclosure_user_marshal_VOID__STRING_STRING_DOUBLE (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__STRING_STRING_DOUBLE) (gpointer data1, const char* arg_1, const char* arg_2, gdouble arg_3, gpointer data2);
	register GMarshalFunc_VOID__STRING_STRING_DOUBLE callback;
	register GCClosure * cc;
	register gpointer data1;
	register gpointer data2;
	cc = (GCClosure *) closure;
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_return_if_fail (n_param_values == 4);
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	if (G_CCLOSURE_SWAP_DATA (closure)) {
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		data1 = closure->data;
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		data2 = param_values->data[0].v_pointer;
#line 498 "tracker-miner-mock.c"
	} else {
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		data1 = param_values->data[0].v_pointer;
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		data2 = closure->data;
#line 504 "tracker-miner-mock.c"
	}
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	callback = (GMarshalFunc_VOID__STRING_STRING_DOUBLE) (marshal_data ? marshal_data : cc->callback);
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	callback (data1, g_value_get_string (param_values + 1), g_value_get_string (param_values + 2), g_value_get_double (param_values + 3), data2);
#line 510 "tracker-miner-mock.c"
}


static void tracker_miner_mock_class_init (TrackerMinerMockClass * klass) {
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	tracker_miner_mock_parent_class = g_type_class_peek_parent (klass);
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_type_class_add_private (klass, sizeof (TrackerMinerMockPrivate));
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	G_OBJECT_CLASS (klass)->get_property = _vala_tracker_miner_mock_get_property;
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	G_OBJECT_CLASS (klass)->set_property = _vala_tracker_miner_mock_set_property;
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	G_OBJECT_CLASS (klass)->finalize = tracker_miner_mock_finalize;
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_object_class_install_property (G_OBJECT_CLASS (klass), TRACKER_MINER_MOCK_PAUSE_REASON, g_param_spec_string ("pause-reason", "pause-reason", "pause-reason", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_object_class_install_property (G_OBJECT_CLASS (klass), TRACKER_MINER_MOCK_NAME, g_param_spec_string ("name", "name", "name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_object_class_install_property (G_OBJECT_CLASS (klass), TRACKER_MINER_MOCK_APPS, g_param_spec_boxed ("apps", "apps", "apps", G_TYPE_STRV, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	g_object_class_install_property (G_OBJECT_CLASS (klass), TRACKER_MINER_MOCK_REASONS, g_param_spec_boxed ("reasons", "reasons", "reasons", G_TYPE_STRV, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	tracker_miner_mock_signals[TRACKER_MINER_MOCK_PROGRESS_SIGNAL] = g_signal_new ("progress", TYPE_TRACKER_MINER_MOCK, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__STRING_STRING_DOUBLE, G_TYPE_NONE, 3, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_DOUBLE);
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	tracker_miner_mock_signals[TRACKER_MINER_MOCK_PAUSED_SIGNAL] = g_signal_new ("paused", TYPE_TRACKER_MINER_MOCK, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	tracker_miner_mock_signals[TRACKER_MINER_MOCK_RESUMED_SIGNAL] = g_signal_new ("resumed", TYPE_TRACKER_MINER_MOCK, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
#line 539 "tracker-miner-mock.c"
}


static void tracker_miner_mock_instance_init (TrackerMinerMock * self) {
	gchar* _tmp0_;
	gchar* _tmp1_;
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv = TRACKER_MINER_MOCK_GET_PRIVATE (self);
#line 25 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp0_ = g_strdup ("");
#line 25 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->_pause_reason = _tmp0_;
#line 26 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_tmp1_ = g_strdup ("");
#line 26 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->_name = _tmp1_;
#line 556 "tracker-miner-mock.c"
}


static void tracker_miner_mock_finalize (GObject * obj) {
	TrackerMinerMock * self;
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_TRACKER_MINER_MOCK, TrackerMinerMock);
#line 25 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_g_free0 (self->priv->_pause_reason);
#line 26 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	_g_free0 (self->priv->_name);
#line 34 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->_apps = (_vala_array_free (self->priv->_apps, self->priv->_apps_length1, (GDestroyNotify) g_free), NULL);
#line 35 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	self->priv->_reasons = (_vala_array_free (self->priv->_reasons, self->priv->_reasons_length1, (GDestroyNotify) g_free), NULL);
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	G_OBJECT_CLASS (tracker_miner_mock_parent_class)->finalize (obj);
#line 574 "tracker-miner-mock.c"
}


GType tracker_miner_mock_get_type (void) {
	static volatile gsize tracker_miner_mock_type_id__volatile = 0;
	if (g_once_init_enter (&tracker_miner_mock_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (TrackerMinerMockClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) tracker_miner_mock_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TrackerMinerMock), 0, (GInstanceInitFunc) tracker_miner_mock_instance_init, NULL };
		GType tracker_miner_mock_type_id;
		tracker_miner_mock_type_id = g_type_register_static (G_TYPE_OBJECT, "TrackerMinerMock", &g_define_type_info, 0);
		g_once_init_leave (&tracker_miner_mock_type_id__volatile, tracker_miner_mock_type_id);
	}
	return tracker_miner_mock_type_id__volatile;
}


static void _vala_tracker_miner_mock_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	TrackerMinerMock * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_TRACKER_MINER_MOCK, TrackerMinerMock);
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	switch (property_id) {
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		case TRACKER_MINER_MOCK_PAUSE_REASON:
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		g_value_set_string (value, tracker_miner_mock_get_pause_reason (self));
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		break;
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		case TRACKER_MINER_MOCK_NAME:
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		g_value_set_string (value, tracker_miner_mock_get_name (self));
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		break;
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		case TRACKER_MINER_MOCK_APPS:
#line 609 "tracker-miner-mock.c"
		{
			int length;
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
			g_value_set_boxed (value, tracker_miner_mock_get_apps (self, &length));
#line 614 "tracker-miner-mock.c"
		}
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		break;
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		case TRACKER_MINER_MOCK_REASONS:
#line 620 "tracker-miner-mock.c"
		{
			int length;
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
			g_value_set_boxed (value, tracker_miner_mock_get_reasons (self, &length));
#line 625 "tracker-miner-mock.c"
		}
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		break;
#line 629 "tracker-miner-mock.c"
		default:
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		break;
#line 635 "tracker-miner-mock.c"
	}
}


static void _vala_tracker_miner_mock_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	TrackerMinerMock * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_TRACKER_MINER_MOCK, TrackerMinerMock);
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
	switch (property_id) {
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		case TRACKER_MINER_MOCK_PAUSE_REASON:
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		tracker_miner_mock_set_pause_reason (self, g_value_get_string (value));
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		break;
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		case TRACKER_MINER_MOCK_NAME:
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		tracker_miner_mock_set_name (self, g_value_get_string (value));
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		break;
#line 657 "tracker-miner-mock.c"
		default:
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
#line 22 "/home/carlos/Source/gnome/tracker/tests/libtracker-miner/tracker-miner-mock.vala"
		break;
#line 663 "tracker-miner-mock.c"
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



