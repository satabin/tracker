/* tracker-cursor.c generated by valac 0.27.1, the Vala compiler
 * generated from tracker-cursor.vala, do not modify */

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
/**
 * SECTION: tracker-sparql-cursor
 * @short_description: Iteration of the query results
 * @title: TrackerSparqlCursor
 * @stability: Stable
 * @include: tracker-sparql.h
 *
 * <para>
 * #TrackerSparqlCursor is an object which provides methods to iterate the
 * results of a query to the Tracker Store.
 * </para>
 */
/**
 * tracker_sparql_cursor_next_finish:
 * @self: a #TrackerSparqlCursor
 * @_res_: a #GAsyncResult with the result of the operation
 * @error: #GError for error reporting.
 *
 * Finishes the asynchronous iteration to the next result.
 *
 * Returns: %FALSE if no more results found, otherwise %TRUE.
 *
 * Since: 0.10
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <float.h>
#include <math.h>


#define TRACKER_SPARQL_TYPE_VALUE_TYPE (tracker_sparql_value_type_get_type ())

#define TRACKER_SPARQL_TYPE_CURSOR (tracker_sparql_cursor_get_type ())
#define TRACKER_SPARQL_CURSOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TRACKER_SPARQL_TYPE_CURSOR, TrackerSparqlCursor))
#define TRACKER_SPARQL_CURSOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TRACKER_SPARQL_TYPE_CURSOR, TrackerSparqlCursorClass))
#define TRACKER_SPARQL_IS_CURSOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TRACKER_SPARQL_TYPE_CURSOR))
#define TRACKER_SPARQL_IS_CURSOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TRACKER_SPARQL_TYPE_CURSOR))
#define TRACKER_SPARQL_CURSOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TRACKER_SPARQL_TYPE_CURSOR, TrackerSparqlCursorClass))

typedef struct _TrackerSparqlCursor TrackerSparqlCursor;
typedef struct _TrackerSparqlCursorClass TrackerSparqlCursorClass;
typedef struct _TrackerSparqlCursorPrivate TrackerSparqlCursorPrivate;

#define TRACKER_SPARQL_TYPE_CONNECTION (tracker_sparql_connection_get_type ())
#define TRACKER_SPARQL_CONNECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TRACKER_SPARQL_TYPE_CONNECTION, TrackerSparqlConnection))
#define TRACKER_SPARQL_CONNECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TRACKER_SPARQL_TYPE_CONNECTION, TrackerSparqlConnectionClass))
#define TRACKER_SPARQL_IS_CONNECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TRACKER_SPARQL_TYPE_CONNECTION))
#define TRACKER_SPARQL_IS_CONNECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TRACKER_SPARQL_TYPE_CONNECTION))
#define TRACKER_SPARQL_CONNECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TRACKER_SPARQL_TYPE_CONNECTION, TrackerSparqlConnectionClass))

typedef struct _TrackerSparqlConnection TrackerSparqlConnection;
typedef struct _TrackerSparqlConnectionClass TrackerSparqlConnectionClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

typedef enum  {
	TRACKER_SPARQL_VALUE_TYPE_UNBOUND,
	TRACKER_SPARQL_VALUE_TYPE_URI,
	TRACKER_SPARQL_VALUE_TYPE_STRING,
	TRACKER_SPARQL_VALUE_TYPE_INTEGER,
	TRACKER_SPARQL_VALUE_TYPE_DOUBLE,
	TRACKER_SPARQL_VALUE_TYPE_DATETIME,
	TRACKER_SPARQL_VALUE_TYPE_BLANK_NODE,
	TRACKER_SPARQL_VALUE_TYPE_BOOLEAN
} TrackerSparqlValueType;

struct _TrackerSparqlCursor {
	GObject parent_instance;
	TrackerSparqlCursorPrivate * priv;
};

struct _TrackerSparqlCursorClass {
	GObjectClass parent_class;
	TrackerSparqlValueType (*get_value_type) (TrackerSparqlCursor* self, gint column);
	const gchar* (*get_variable_name) (TrackerSparqlCursor* self, gint column);
	const gchar* (*get_string) (TrackerSparqlCursor* self, gint column, glong* length);
	gboolean (*next) (TrackerSparqlCursor* self, GCancellable* cancellable, GError** error);
	void (*next_async) (TrackerSparqlCursor* self, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
	gboolean (*next_finish) (TrackerSparqlCursor* self, GAsyncResult* _res_, GError** error);
	void (*rewind) (TrackerSparqlCursor* self);
	void (*close) (TrackerSparqlCursor* self);
	gint64 (*get_integer) (TrackerSparqlCursor* self, gint column);
	gdouble (*get_double) (TrackerSparqlCursor* self, gint column);
	gboolean (*get_boolean) (TrackerSparqlCursor* self, gint column);
	gboolean (*is_bound) (TrackerSparqlCursor* self, gint column);
	gint (*get_n_columns) (TrackerSparqlCursor* self);
};

struct _TrackerSparqlCursorPrivate {
	TrackerSparqlConnection* _connection;
};


static gpointer tracker_sparql_cursor_parent_class = NULL;

GType tracker_sparql_value_type_get_type (void) G_GNUC_CONST;
GType tracker_sparql_cursor_get_type (void) G_GNUC_CONST;
GType tracker_sparql_connection_get_type (void) G_GNUC_CONST;
#define TRACKER_SPARQL_CURSOR_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TRACKER_SPARQL_TYPE_CURSOR, TrackerSparqlCursorPrivate))
enum  {
	TRACKER_SPARQL_CURSOR_DUMMY_PROPERTY,
	TRACKER_SPARQL_CURSOR_CONNECTION,
	TRACKER_SPARQL_CURSOR_N_COLUMNS
};
TrackerSparqlValueType tracker_sparql_cursor_get_value_type (TrackerSparqlCursor* self, gint column);
static TrackerSparqlValueType tracker_sparql_cursor_real_get_value_type (TrackerSparqlCursor* self, gint column);
const gchar* tracker_sparql_cursor_get_variable_name (TrackerSparqlCursor* self, gint column);
static const gchar* tracker_sparql_cursor_real_get_variable_name (TrackerSparqlCursor* self, gint column);
const gchar* tracker_sparql_cursor_get_string (TrackerSparqlCursor* self, gint column, glong* length);
static const gchar* tracker_sparql_cursor_real_get_string (TrackerSparqlCursor* self, gint column, glong* length);
gboolean tracker_sparql_cursor_next (TrackerSparqlCursor* self, GCancellable* cancellable, GError** error);
static gboolean tracker_sparql_cursor_real_next (TrackerSparqlCursor* self, GCancellable* cancellable, GError** error);
void tracker_sparql_cursor_next_async (TrackerSparqlCursor* self, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
gboolean tracker_sparql_cursor_next_finish (TrackerSparqlCursor* self, GAsyncResult* _res_, GError** error);
void tracker_sparql_cursor_rewind (TrackerSparqlCursor* self);
static void tracker_sparql_cursor_real_rewind (TrackerSparqlCursor* self);
void tracker_sparql_cursor_close (TrackerSparqlCursor* self);
static void tracker_sparql_cursor_real_close (TrackerSparqlCursor* self);
gint64 tracker_sparql_cursor_get_integer (TrackerSparqlCursor* self, gint column);
static gint64 tracker_sparql_cursor_real_get_integer (TrackerSparqlCursor* self, gint column);
gdouble tracker_sparql_cursor_get_double (TrackerSparqlCursor* self, gint column);
static gdouble tracker_sparql_cursor_real_get_double (TrackerSparqlCursor* self, gint column);
gboolean tracker_sparql_cursor_get_boolean (TrackerSparqlCursor* self, gint column);
static gboolean tracker_sparql_cursor_real_get_boolean (TrackerSparqlCursor* self, gint column);
gboolean tracker_sparql_cursor_is_bound (TrackerSparqlCursor* self, gint column);
static gboolean tracker_sparql_cursor_real_is_bound (TrackerSparqlCursor* self, gint column);
TrackerSparqlCursor* tracker_sparql_cursor_construct (GType object_type);
TrackerSparqlConnection* tracker_sparql_cursor_get_connection (TrackerSparqlCursor* self);
void tracker_sparql_cursor_set_connection (TrackerSparqlCursor* self, TrackerSparqlConnection* value);
gint tracker_sparql_cursor_get_n_columns (TrackerSparqlCursor* self);
static void tracker_sparql_cursor_finalize (GObject* obj);
static void _vala_tracker_sparql_cursor_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_tracker_sparql_cursor_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


/**
 * TrackerSparqlValueType:
 * @TRACKER_SPARQL_VALUE_TYPE_UNBOUND: Unbound value type
 * @TRACKER_SPARQL_VALUE_TYPE_URI: Uri value type, rdfs:Resource
 * @TRACKER_SPARQL_VALUE_TYPE_STRING: String value type, xsd:string
 * @TRACKER_SPARQL_VALUE_TYPE_INTEGER: Integer value type, xsd:integer
 * @TRACKER_SPARQL_VALUE_TYPE_DOUBLE: Double value type, xsd:double
 * @TRACKER_SPARQL_VALUE_TYPE_DATETIME: Datetime value type, xsd:dateTime
 * @TRACKER_SPARQL_VALUE_TYPE_BLANK_NODE: Blank node value type
 * @TRACKER_SPARQL_VALUE_TYPE_BOOLEAN: Boolean value type, xsd:boolean
 *
 * Enumeration with the possible types of the cursor's cells
 *
 * Since: 0.10
 */
GType tracker_sparql_value_type_get_type (void) {
	static volatile gsize tracker_sparql_value_type_type_id__volatile = 0;
	if (g_once_init_enter (&tracker_sparql_value_type_type_id__volatile)) {
		static const GEnumValue values[] = {{TRACKER_SPARQL_VALUE_TYPE_UNBOUND, "TRACKER_SPARQL_VALUE_TYPE_UNBOUND", "unbound"}, {TRACKER_SPARQL_VALUE_TYPE_URI, "TRACKER_SPARQL_VALUE_TYPE_URI", "uri"}, {TRACKER_SPARQL_VALUE_TYPE_STRING, "TRACKER_SPARQL_VALUE_TYPE_STRING", "string"}, {TRACKER_SPARQL_VALUE_TYPE_INTEGER, "TRACKER_SPARQL_VALUE_TYPE_INTEGER", "integer"}, {TRACKER_SPARQL_VALUE_TYPE_DOUBLE, "TRACKER_SPARQL_VALUE_TYPE_DOUBLE", "double"}, {TRACKER_SPARQL_VALUE_TYPE_DATETIME, "TRACKER_SPARQL_VALUE_TYPE_DATETIME", "datetime"}, {TRACKER_SPARQL_VALUE_TYPE_BLANK_NODE, "TRACKER_SPARQL_VALUE_TYPE_BLANK_NODE", "blank-node"}, {TRACKER_SPARQL_VALUE_TYPE_BOOLEAN, "TRACKER_SPARQL_VALUE_TYPE_BOOLEAN", "boolean"}, {0, NULL, NULL}};
		GType tracker_sparql_value_type_type_id;
		tracker_sparql_value_type_type_id = g_enum_register_static ("TrackerSparqlValueType", values);
		g_once_init_leave (&tracker_sparql_value_type_type_id__volatile, tracker_sparql_value_type_type_id);
	}
	return tracker_sparql_value_type_type_id__volatile;
}


/**
 * tracker_sparql_cursor_get_value_type:
 * @self: a #TrackerSparqlCursor
 * @column: column number to retrieve (first one is 0)
 *
 * The data type bound to the current row in @column is returned.
 *
 * Returns: a #TrackerSparqlValueType.
 *
 * Since: 0.10
 */
static TrackerSparqlValueType tracker_sparql_cursor_real_get_value_type (TrackerSparqlCursor* self, gint column) {
#line 126 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_critical ("Type `%s' does not implement abstract method `tracker_sparql_cursor_get_value_type'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
#line 126 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return 0;
#line 204 "tracker-cursor.c"
}


TrackerSparqlValueType tracker_sparql_cursor_get_value_type (TrackerSparqlCursor* self, gint column) {
#line 126 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_return_val_if_fail (self != NULL, 0);
#line 126 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return TRACKER_SPARQL_CURSOR_GET_CLASS (self)->get_value_type (self, column);
#line 213 "tracker-cursor.c"
}


/**
 * tracker_sparql_cursor_get_variable_name:
 * @self: a #TrackerSparqlCursor
 * @column: column number to retrieve (first one is 0)
 *
 * Retrieves the variable name for the current row in @column.
 *
 * Returns: a string which must not be freed.
 *
 * Since: 0.10
 */
static const gchar* tracker_sparql_cursor_real_get_variable_name (TrackerSparqlCursor* self, gint column) {
#line 139 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_critical ("Type `%s' does not implement abstract method `tracker_sparql_cursor_get_variable_name'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
#line 139 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return NULL;
#line 233 "tracker-cursor.c"
}


const gchar* tracker_sparql_cursor_get_variable_name (TrackerSparqlCursor* self, gint column) {
#line 139 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 139 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return TRACKER_SPARQL_CURSOR_GET_CLASS (self)->get_variable_name (self, column);
#line 242 "tracker-cursor.c"
}


/**
 * tracker_sparql_cursor_get_string:
 * @self: a #TrackerSparqlCursor
 * @column: column number to retrieve (first one is 0)
 * @length: length of the returned string
 *
 * Retrieves a string representation of the data in the current
 * row in @column.
 *
 * Returns: a string which must not be freed. %NULL is returned if
 * the column is not in the [0,#n_columns] range.
 *
 * Since: 0.10
 */
static const gchar* tracker_sparql_cursor_real_get_string (TrackerSparqlCursor* self, gint column, glong* length) {
#line 155 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_critical ("Type `%s' does not implement abstract method `tracker_sparql_cursor_get_string'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
#line 155 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return NULL;
#line 265 "tracker-cursor.c"
}


const gchar* tracker_sparql_cursor_get_string (TrackerSparqlCursor* self, gint column, glong* length) {
#line 155 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 155 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return TRACKER_SPARQL_CURSOR_GET_CLASS (self)->get_string (self, column, length);
#line 274 "tracker-cursor.c"
}


/**
 * tracker_sparql_cursor_next:
 * @self: a #TrackerSparqlCursor
 * @cancellable: a #GCancellable used to cancel the operation
 * @error: #GError for error reporting.
 *
 * Iterates to the next result. This is completely synchronous and
 * it may block.
 *
 * Returns: %FALSE if no more results found, otherwise %TRUE.
 *
 * Since: 0.10
 */
static gboolean tracker_sparql_cursor_real_next (TrackerSparqlCursor* self, GCancellable* cancellable, GError** error) {
#line 170 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_critical ("Type `%s' does not implement abstract method `tracker_sparql_cursor_next'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
#line 170 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return FALSE;
#line 296 "tracker-cursor.c"
}


gboolean tracker_sparql_cursor_next (TrackerSparqlCursor* self, GCancellable* cancellable, GError** error) {
#line 170 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 170 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return TRACKER_SPARQL_CURSOR_GET_CLASS (self)->next (self, cancellable, error);
#line 305 "tracker-cursor.c"
}


void tracker_sparql_cursor_next_async (TrackerSparqlCursor* self, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_) {
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	TRACKER_SPARQL_CURSOR_GET_CLASS (self)->next_async (self, cancellable, _callback_, _user_data_);
#line 312 "tracker-cursor.c"
}


gboolean tracker_sparql_cursor_next_finish (TrackerSparqlCursor* self, GAsyncResult* _res_, GError** error) {
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return TRACKER_SPARQL_CURSOR_GET_CLASS (self)->next_finish (self, _res_, error);
#line 319 "tracker-cursor.c"
}


/**
 * tracker_sparql_cursor_rewind:
 * @self: a #TrackerSparqlCursor
 *
 * Resets the iterator to point back to the first result.
 *
 * Since: 0.10
 */
static void tracker_sparql_cursor_real_rewind (TrackerSparqlCursor* self) {
#line 207 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_critical ("Type `%s' does not implement abstract method `tracker_sparql_cursor_rewind'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
#line 207 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return;
#line 336 "tracker-cursor.c"
}


void tracker_sparql_cursor_rewind (TrackerSparqlCursor* self) {
#line 207 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_return_if_fail (self != NULL);
#line 207 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	TRACKER_SPARQL_CURSOR_GET_CLASS (self)->rewind (self);
#line 345 "tracker-cursor.c"
}


/**
 * tracker_sparql_cursor_close:
 * @self: a #TrackerSparqlCursor
 *
 * Closes the iterator, making it invalid.
 *
 * Since: 0.12
 */
static void tracker_sparql_cursor_real_close (TrackerSparqlCursor* self) {
}


void tracker_sparql_cursor_close (TrackerSparqlCursor* self) {
#line 217 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_return_if_fail (self != NULL);
#line 217 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	TRACKER_SPARQL_CURSOR_GET_CLASS (self)->close (self);
#line 366 "tracker-cursor.c"
}


/**
 * tracker_sparql_cursor_get_integer:
 * @self: a #TrackerSparqlCursor
 * @column: column number to retrieve (first one is 0)
 *
 * Retrieve an integer for the current row in @column.
 *
 * Returns: a #gint64.
 *
 * Since: 0.10
 */
static gint64 int64_parse (const gchar* str) {
	gint64 result = 0LL;
	const gchar* _tmp0_ = NULL;
	gint64 _tmp1_ = 0LL;
#line 605 "/usr/share/vala-0.28/vapi/glib-2.0.vapi"
	g_return_val_if_fail (str != NULL, 0LL);
#line 606 "/usr/share/vala-0.28/vapi/glib-2.0.vapi"
	_tmp0_ = str;
#line 606 "/usr/share/vala-0.28/vapi/glib-2.0.vapi"
	_tmp1_ = g_ascii_strtoll (_tmp0_, NULL, (guint) 0);
#line 606 "/usr/share/vala-0.28/vapi/glib-2.0.vapi"
	result = _tmp1_;
#line 606 "/usr/share/vala-0.28/vapi/glib-2.0.vapi"
	return result;
#line 395 "tracker-cursor.c"
}


static gint64 tracker_sparql_cursor_real_get_integer (TrackerSparqlCursor* self, gint column) {
	gint64 result = 0LL;
	gint _tmp0_ = 0;
	TrackerSparqlValueType _tmp1_ = 0;
	const gchar* as_str = NULL;
	gint _tmp2_ = 0;
	const gchar* _tmp3_ = NULL;
	gint64 _tmp4_ = 0LL;
#line 232 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp0_ = column;
#line 232 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp1_ = tracker_sparql_cursor_get_value_type (self, _tmp0_);
#line 232 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_return_val_if_fail (_tmp1_ == TRACKER_SPARQL_VALUE_TYPE_INTEGER, 0);
#line 233 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp2_ = column;
#line 233 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp3_ = tracker_sparql_cursor_get_string (self, _tmp2_, NULL);
#line 233 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	as_str = _tmp3_;
#line 234 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp4_ = int64_parse (as_str);
#line 234 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	result = _tmp4_;
#line 234 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return result;
#line 425 "tracker-cursor.c"
}


gint64 tracker_sparql_cursor_get_integer (TrackerSparqlCursor* self, gint column) {
#line 231 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_return_val_if_fail (self != NULL, 0LL);
#line 231 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return TRACKER_SPARQL_CURSOR_GET_CLASS (self)->get_integer (self, column);
#line 434 "tracker-cursor.c"
}


/**
 * tracker_sparql_cursor_get_double:
 * @self: a #TrackerSparqlCursor
 * @column: column number to retrieve (first one is 0)
 *
 * Retrieve a double for the current row in @column.
 *
 * Returns: a double.
 *
 * Since: 0.10
 */
static gdouble double_parse (const gchar* str) {
	gdouble result = 0.0;
	const gchar* _tmp0_ = NULL;
	gdouble _tmp1_ = 0.0;
#line 789 "/usr/share/vala-0.28/vapi/glib-2.0.vapi"
	g_return_val_if_fail (str != NULL, 0.0);
#line 790 "/usr/share/vala-0.28/vapi/glib-2.0.vapi"
	_tmp0_ = str;
#line 790 "/usr/share/vala-0.28/vapi/glib-2.0.vapi"
	_tmp1_ = g_ascii_strtod (_tmp0_, NULL);
#line 790 "/usr/share/vala-0.28/vapi/glib-2.0.vapi"
	result = _tmp1_;
#line 790 "/usr/share/vala-0.28/vapi/glib-2.0.vapi"
	return result;
#line 463 "tracker-cursor.c"
}


static gdouble tracker_sparql_cursor_real_get_double (TrackerSparqlCursor* self, gint column) {
	gdouble result = 0.0;
	gint _tmp0_ = 0;
	TrackerSparqlValueType _tmp1_ = 0;
	const gchar* as_str = NULL;
	gint _tmp2_ = 0;
	const gchar* _tmp3_ = NULL;
	gdouble _tmp4_ = 0.0;
#line 249 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp0_ = column;
#line 249 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp1_ = tracker_sparql_cursor_get_value_type (self, _tmp0_);
#line 249 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_return_val_if_fail (_tmp1_ == TRACKER_SPARQL_VALUE_TYPE_DOUBLE, 0);
#line 250 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp2_ = column;
#line 250 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp3_ = tracker_sparql_cursor_get_string (self, _tmp2_, NULL);
#line 250 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	as_str = _tmp3_;
#line 251 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp4_ = double_parse (as_str);
#line 251 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	result = _tmp4_;
#line 251 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return result;
#line 493 "tracker-cursor.c"
}


gdouble tracker_sparql_cursor_get_double (TrackerSparqlCursor* self, gint column) {
#line 248 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_return_val_if_fail (self != NULL, 0.0);
#line 248 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return TRACKER_SPARQL_CURSOR_GET_CLASS (self)->get_double (self, column);
#line 502 "tracker-cursor.c"
}


/**
 * tracker_sparql_cursor_get_boolean:
 * @self: a #TrackerSparqlCursor
 * @column: column number to retrieve (first one is 0)
 *
 * Retrieve a boolean for the current row in @column.
 *
 * Returns: a #gboolean.
 *
 * Since: 0.10
 */
static gboolean tracker_sparql_cursor_real_get_boolean (TrackerSparqlCursor* self, gint column) {
	gboolean result = FALSE;
	TrackerSparqlValueType type = 0;
	gint _tmp0_ = 0;
	TrackerSparqlValueType _tmp1_ = 0;
	TrackerSparqlValueType _tmp2_ = 0;
	const gchar* as_str = NULL;
	gint _tmp3_ = 0;
	const gchar* _tmp4_ = NULL;
	gboolean _tmp5_ = FALSE;
	const gchar* _tmp6_ = NULL;
#line 266 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp0_ = column;
#line 266 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp1_ = tracker_sparql_cursor_get_value_type (self, _tmp0_);
#line 266 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	type = _tmp1_;
#line 267 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp2_ = type;
#line 267 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_return_val_if_fail (_tmp2_ == TRACKER_SPARQL_VALUE_TYPE_BOOLEAN, 0);
#line 268 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp3_ = column;
#line 268 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp4_ = tracker_sparql_cursor_get_string (self, _tmp3_, NULL);
#line 268 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	as_str = _tmp4_;
#line 270 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp6_ = as_str;
#line 270 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	if (_tmp6_ != NULL) {
#line 548 "tracker-cursor.c"
		const gchar* _tmp7_ = NULL;
		gint _tmp8_ = 0;
#line 270 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		_tmp7_ = as_str;
#line 270 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		_tmp8_ = g_ascii_strcasecmp (_tmp7_, "true");
#line 270 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		_tmp5_ = _tmp8_ == 0;
#line 557 "tracker-cursor.c"
	} else {
#line 270 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		_tmp5_ = FALSE;
#line 561 "tracker-cursor.c"
	}
#line 270 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	if (_tmp5_) {
#line 271 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		result = TRUE;
#line 271 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		return result;
#line 569 "tracker-cursor.c"
	}
#line 274 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	result = FALSE;
#line 274 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return result;
#line 575 "tracker-cursor.c"
}


gboolean tracker_sparql_cursor_get_boolean (TrackerSparqlCursor* self, gint column) {
#line 265 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 265 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return TRACKER_SPARQL_CURSOR_GET_CLASS (self)->get_boolean (self, column);
#line 584 "tracker-cursor.c"
}


/**
 * tracker_sparql_cursor_is_bound:
 * @self: a #TrackerSparqlCursor
 * @column: column number to retrieve (first one is 0)
 *
 * If the current row and @column are bound to a value, %TRUE is returned.
 *
 * Returns: a %TRUE or %FALSE.
 *
 * Since: 0.10
 */
static gboolean tracker_sparql_cursor_real_is_bound (TrackerSparqlCursor* self, gint column) {
	gboolean result = FALSE;
	gint _tmp0_ = 0;
	TrackerSparqlValueType _tmp1_ = 0;
#line 289 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp0_ = column;
#line 289 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp1_ = tracker_sparql_cursor_get_value_type (self, _tmp0_);
#line 289 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	if (_tmp1_ != TRACKER_SPARQL_VALUE_TYPE_UNBOUND) {
#line 290 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		result = TRUE;
#line 290 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		return result;
#line 613 "tracker-cursor.c"
	}
#line 292 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	result = FALSE;
#line 292 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return result;
#line 619 "tracker-cursor.c"
}


gboolean tracker_sparql_cursor_is_bound (TrackerSparqlCursor* self, gint column) {
#line 288 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 288 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return TRACKER_SPARQL_CURSOR_GET_CLASS (self)->is_bound (self, column);
#line 628 "tracker-cursor.c"
}


TrackerSparqlCursor* tracker_sparql_cursor_construct (GType object_type) {
	TrackerSparqlCursor * self = NULL;
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	self = (TrackerSparqlCursor*) g_object_new (object_type, NULL);
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return self;
#line 638 "tracker-cursor.c"
}


/**
 * tracker_sparql_cursor_get_connection:
 * @self: a #TrackerSparqlCursor
 *
 * Returns: the #TrackerSparqlConnection associated with this
 * #TrackerSparqlCursor. The returned object must not be unreferenced
 * by the caller.
 *
 * Since: 0.10
 */
TrackerSparqlConnection* tracker_sparql_cursor_get_connection (TrackerSparqlCursor* self) {
	TrackerSparqlConnection* result;
	TrackerSparqlConnection* _tmp0_ = NULL;
#line 85 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 85 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp0_ = self->priv->_connection;
#line 85 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	result = _tmp0_;
#line 85 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return result;
#line 663 "tracker-cursor.c"
}


static gpointer _g_object_ref0 (gpointer self) {
#line 88 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return self ? g_object_ref (self) : NULL;
#line 670 "tracker-cursor.c"
}


void tracker_sparql_cursor_set_connection (TrackerSparqlCursor* self, TrackerSparqlConnection* value) {
	TrackerSparqlConnection* _tmp0_ = NULL;
	TrackerSparqlConnection* _tmp1_ = NULL;
#line 88 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_return_if_fail (self != NULL);
#line 88 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp0_ = value;
#line 88 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_tmp1_ = _g_object_ref0 (_tmp0_);
#line 88 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_g_object_unref0 (self->priv->_connection);
#line 88 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	self->priv->_connection = _tmp1_;
#line 88 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_object_notify ((GObject *) self, "connection");
#line 689 "tracker-cursor.c"
}


/**
 * tracker_sparql_cursor_get_n_columns:
 * @self: a #TrackerSparqlCursor
 *
 * This method should only be called after a successful
 * tracker_sparql_cursor_next(); otherwise its return value
 * will be undefined.
 *
 * Returns: a #gint representing the number of columns available in the
 * results to iterate.
 *
 * Since: 0.10
 */
gint tracker_sparql_cursor_get_n_columns (TrackerSparqlCursor* self) {
#line 112 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_return_val_if_fail (self != NULL, 0);
#line 112 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	return TRACKER_SPARQL_CURSOR_GET_CLASS (self)->get_n_columns (self);
#line 711 "tracker-cursor.c"
}


static void tracker_sparql_cursor_class_init (TrackerSparqlCursorClass * klass) {
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	tracker_sparql_cursor_parent_class = g_type_class_peek_parent (klass);
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_type_class_add_private (klass, sizeof (TrackerSparqlCursorPrivate));
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	((TrackerSparqlCursorClass *) klass)->get_value_type = tracker_sparql_cursor_real_get_value_type;
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	((TrackerSparqlCursorClass *) klass)->get_variable_name = tracker_sparql_cursor_real_get_variable_name;
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	((TrackerSparqlCursorClass *) klass)->get_string = tracker_sparql_cursor_real_get_string;
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	((TrackerSparqlCursorClass *) klass)->next = tracker_sparql_cursor_real_next;
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	((TrackerSparqlCursorClass *) klass)->rewind = tracker_sparql_cursor_real_rewind;
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	((TrackerSparqlCursorClass *) klass)->close = tracker_sparql_cursor_real_close;
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	((TrackerSparqlCursorClass *) klass)->get_integer = tracker_sparql_cursor_real_get_integer;
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	((TrackerSparqlCursorClass *) klass)->get_double = tracker_sparql_cursor_real_get_double;
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	((TrackerSparqlCursorClass *) klass)->get_boolean = tracker_sparql_cursor_real_get_boolean;
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	((TrackerSparqlCursorClass *) klass)->is_bound = tracker_sparql_cursor_real_is_bound;
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	G_OBJECT_CLASS (klass)->get_property = _vala_tracker_sparql_cursor_get_property;
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	G_OBJECT_CLASS (klass)->set_property = _vala_tracker_sparql_cursor_set_property;
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	G_OBJECT_CLASS (klass)->finalize = tracker_sparql_cursor_finalize;
#line 746 "tracker-cursor.c"
	/**
	 * TrackerSparqlCursor:connection:
	 *
	 * The #TrackerSparqlConnection used to retrieve the results.
	 *
	 * Since: 0.10
	 */
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_object_class_install_property (G_OBJECT_CLASS (klass), TRACKER_SPARQL_CURSOR_CONNECTION, g_param_spec_object ("connection", "connection", "connection", TRACKER_SPARQL_TYPE_CONNECTION, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
#line 756 "tracker-cursor.c"
	/**
	 * TrackerSparqlCursor:n_columns:
	 *
	 * Number of columns available in the results to iterate.
	 *
	 * Since: 0.10
	 */
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	g_object_class_install_property (G_OBJECT_CLASS (klass), TRACKER_SPARQL_CURSOR_N_COLUMNS, g_param_spec_int ("n-columns", "n-columns", "n-columns", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
#line 766 "tracker-cursor.c"
}


static void tracker_sparql_cursor_instance_init (TrackerSparqlCursor * self) {
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	self->priv = TRACKER_SPARQL_CURSOR_GET_PRIVATE (self);
#line 773 "tracker-cursor.c"
}


static void tracker_sparql_cursor_finalize (GObject* obj) {
	TrackerSparqlCursor * self;
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TRACKER_SPARQL_TYPE_CURSOR, TrackerSparqlCursor);
#line 74 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	_g_object_unref0 (self->priv->_connection);
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	G_OBJECT_CLASS (tracker_sparql_cursor_parent_class)->finalize (obj);
#line 785 "tracker-cursor.c"
}


/**
 * TrackerSparqlCursor:
 *
 * The <structname>TrackerSparqlCursor</structname> object represents an
 * iterator of results.
 */
GType tracker_sparql_cursor_get_type (void) {
	static volatile gsize tracker_sparql_cursor_type_id__volatile = 0;
	if (g_once_init_enter (&tracker_sparql_cursor_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (TrackerSparqlCursorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) tracker_sparql_cursor_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TrackerSparqlCursor), 0, (GInstanceInitFunc) tracker_sparql_cursor_instance_init, NULL };
		GType tracker_sparql_cursor_type_id;
		tracker_sparql_cursor_type_id = g_type_register_static (G_TYPE_OBJECT, "TrackerSparqlCursor", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&tracker_sparql_cursor_type_id__volatile, tracker_sparql_cursor_type_id);
	}
	return tracker_sparql_cursor_type_id__volatile;
}


static void _vala_tracker_sparql_cursor_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	TrackerSparqlCursor * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TRACKER_SPARQL_TYPE_CURSOR, TrackerSparqlCursor);
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	switch (property_id) {
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		case TRACKER_SPARQL_CURSOR_CONNECTION:
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		g_value_set_object (value, tracker_sparql_cursor_get_connection (self));
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		break;
#line 818 "tracker-cursor.c"
		default:
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		break;
#line 824 "tracker-cursor.c"
	}
}


static void _vala_tracker_sparql_cursor_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	TrackerSparqlCursor * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TRACKER_SPARQL_TYPE_CURSOR, TrackerSparqlCursor);
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
	switch (property_id) {
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		case TRACKER_SPARQL_CURSOR_CONNECTION:
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		tracker_sparql_cursor_set_connection (self, g_value_get_object (value));
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		break;
#line 840 "tracker-cursor.c"
		default:
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
#line 65 "/home/carlos/Source/gnome/tracker/src/libtracker-sparql/tracker-cursor.vala"
		break;
#line 846 "tracker-cursor.c"
	}
}



