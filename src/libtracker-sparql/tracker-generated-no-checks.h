/* tracker-generated-no-checks.h generated by valac 0.24.0.131-42e78, the Vala compiler, do not modify */


#ifndef __TRACKER_GENERATED_NO_CHECKS_H__
#define __TRACKER_GENERATED_NO_CHECKS_H__

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <float.h>
#include <math.h>
#include <gio/gio.h>
#include <stdarg.h>

G_BEGIN_DECLS


#define TRACKER_SPARQL_TYPE_BUILDER (tracker_sparql_builder_get_type ())
#define TRACKER_SPARQL_BUILDER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TRACKER_SPARQL_TYPE_BUILDER, TrackerSparqlBuilder))
#define TRACKER_SPARQL_BUILDER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TRACKER_SPARQL_TYPE_BUILDER, TrackerSparqlBuilderClass))
#define TRACKER_SPARQL_IS_BUILDER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TRACKER_SPARQL_TYPE_BUILDER))
#define TRACKER_SPARQL_IS_BUILDER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TRACKER_SPARQL_TYPE_BUILDER))
#define TRACKER_SPARQL_BUILDER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TRACKER_SPARQL_TYPE_BUILDER, TrackerSparqlBuilderClass))

typedef struct _TrackerSparqlBuilder TrackerSparqlBuilder;
typedef struct _TrackerSparqlBuilderClass TrackerSparqlBuilderClass;
typedef struct _TrackerSparqlBuilderPrivate TrackerSparqlBuilderPrivate;

#define TRACKER_SPARQL_BUILDER_TYPE_STATE (tracker_sparql_builder_state_get_type ())

#define TRACKER_SPARQL_TYPE_CONNECTION (tracker_sparql_connection_get_type ())
#define TRACKER_SPARQL_CONNECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TRACKER_SPARQL_TYPE_CONNECTION, TrackerSparqlConnection))
#define TRACKER_SPARQL_CONNECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TRACKER_SPARQL_TYPE_CONNECTION, TrackerSparqlConnectionClass))
#define TRACKER_SPARQL_IS_CONNECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TRACKER_SPARQL_TYPE_CONNECTION))
#define TRACKER_SPARQL_IS_CONNECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TRACKER_SPARQL_TYPE_CONNECTION))
#define TRACKER_SPARQL_CONNECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TRACKER_SPARQL_TYPE_CONNECTION, TrackerSparqlConnectionClass))

typedef struct _TrackerSparqlConnection TrackerSparqlConnection;
typedef struct _TrackerSparqlConnectionClass TrackerSparqlConnectionClass;
typedef struct _TrackerSparqlConnectionPrivate TrackerSparqlConnectionPrivate;

#define TRACKER_SPARQL_TYPE_CURSOR (tracker_sparql_cursor_get_type ())
#define TRACKER_SPARQL_CURSOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TRACKER_SPARQL_TYPE_CURSOR, TrackerSparqlCursor))
#define TRACKER_SPARQL_CURSOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TRACKER_SPARQL_TYPE_CURSOR, TrackerSparqlCursorClass))
#define TRACKER_SPARQL_IS_CURSOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TRACKER_SPARQL_TYPE_CURSOR))
#define TRACKER_SPARQL_IS_CURSOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TRACKER_SPARQL_TYPE_CURSOR))
#define TRACKER_SPARQL_CURSOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TRACKER_SPARQL_TYPE_CURSOR, TrackerSparqlCursorClass))

typedef struct _TrackerSparqlCursor TrackerSparqlCursor;
typedef struct _TrackerSparqlCursorClass TrackerSparqlCursorClass;

#define TRACKER_SPARQL_TYPE_VALUE_TYPE (tracker_sparql_value_type_get_type ())
typedef struct _TrackerSparqlCursorPrivate TrackerSparqlCursorPrivate;

struct _TrackerSparqlBuilder {
	GObject parent_instance;
	TrackerSparqlBuilderPrivate * priv;
};

struct _TrackerSparqlBuilderClass {
	GObjectClass parent_class;
};

typedef enum  {
	TRACKER_SPARQL_BUILDER_STATE_UPDATE,
	TRACKER_SPARQL_BUILDER_STATE_INSERT,
	TRACKER_SPARQL_BUILDER_STATE_DELETE,
	TRACKER_SPARQL_BUILDER_STATE_SUBJECT,
	TRACKER_SPARQL_BUILDER_STATE_PREDICATE,
	TRACKER_SPARQL_BUILDER_STATE_OBJECT,
	TRACKER_SPARQL_BUILDER_STATE_BLANK,
	TRACKER_SPARQL_BUILDER_STATE_WHERE,
	TRACKER_SPARQL_BUILDER_STATE_EMBEDDED_INSERT,
	TRACKER_SPARQL_BUILDER_STATE_GRAPH
} TrackerSparqlBuilderState;

typedef enum  {
	TRACKER_SPARQL_ERROR_PARSE,
	TRACKER_SPARQL_ERROR_UNKNOWN_CLASS,
	TRACKER_SPARQL_ERROR_UNKNOWN_PROPERTY,
	TRACKER_SPARQL_ERROR_TYPE,
	TRACKER_SPARQL_ERROR_CONSTRAINT,
	TRACKER_SPARQL_ERROR_NO_SPACE,
	TRACKER_SPARQL_ERROR_INTERNAL,
	TRACKER_SPARQL_ERROR_UNSUPPORTED
} TrackerSparqlError;
#define TRACKER_SPARQL_ERROR tracker_sparql_error_quark ()
struct _TrackerSparqlConnection {
	GObject parent_instance;
	TrackerSparqlConnectionPrivate * priv;
};

struct _TrackerSparqlConnectionClass {
	GObjectClass parent_class;
	TrackerSparqlCursor* (*query) (TrackerSparqlConnection* self, const gchar* sparql, GCancellable* cancellable, GError** error);
	void (*query_async) (TrackerSparqlConnection* self, const gchar* sparql, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
	TrackerSparqlCursor* (*query_finish) (TrackerSparqlConnection* self, GAsyncResult* _res_, GError** error);
	void (*update) (TrackerSparqlConnection* self, const gchar* sparql, gint priority, GCancellable* cancellable, GError** error);
	void (*update_async) (TrackerSparqlConnection* self, const gchar* sparql, gint priority, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*update_finish) (TrackerSparqlConnection* self, GAsyncResult* _res_, GError** error);
	void (*update_array_async) (TrackerSparqlConnection* self, gchar** sparql, int sparql_length1, gint priority, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
	GPtrArray* (*update_array_finish) (TrackerSparqlConnection* self, GAsyncResult* _res_, GError** error);
	GVariant* (*update_blank) (TrackerSparqlConnection* self, const gchar* sparql, gint priority, GCancellable* cancellable, GError** error);
	void (*update_blank_async) (TrackerSparqlConnection* self, const gchar* sparql, gint priority, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
	GVariant* (*update_blank_finish) (TrackerSparqlConnection* self, GAsyncResult* _res_, GError** error);
	void (*load) (TrackerSparqlConnection* self, GFile* file, GCancellable* cancellable, GError** error);
	void (*load_async) (TrackerSparqlConnection* self, GFile* file, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*load_finish) (TrackerSparqlConnection* self, GAsyncResult* _res_, GError** error);
	TrackerSparqlCursor* (*statistics) (TrackerSparqlConnection* self, GCancellable* cancellable, GError** error);
	void (*statistics_async) (TrackerSparqlConnection* self, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
	TrackerSparqlCursor* (*statistics_finish) (TrackerSparqlConnection* self, GAsyncResult* _res_, GError** error);
};

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


GType tracker_sparql_builder_get_type (void) G_GNUC_CONST;
GType tracker_sparql_builder_state_get_type (void) G_GNUC_CONST;
TrackerSparqlBuilder* tracker_sparql_builder_new_update (void);
TrackerSparqlBuilder* tracker_sparql_builder_construct_update (GType object_type);
TrackerSparqlBuilder* tracker_sparql_builder_new_embedded_insert (void);
TrackerSparqlBuilder* tracker_sparql_builder_construct_embedded_insert (GType object_type);
void tracker_sparql_builder_insert_open (TrackerSparqlBuilder* self, const gchar* graph);
void tracker_sparql_builder_insert_silent_open (TrackerSparqlBuilder* self, const gchar* graph);
void tracker_sparql_builder_insert_close (TrackerSparqlBuilder* self);
void tracker_sparql_builder_delete_open (TrackerSparqlBuilder* self, const gchar* graph);
void tracker_sparql_builder_delete_close (TrackerSparqlBuilder* self);
void tracker_sparql_builder_graph_open (TrackerSparqlBuilder* self, const gchar* graph);
void tracker_sparql_builder_graph_close (TrackerSparqlBuilder* self);
void tracker_sparql_builder_where_open (TrackerSparqlBuilder* self);
void tracker_sparql_builder_where_close (TrackerSparqlBuilder* self);
void tracker_sparql_builder_subject_variable (TrackerSparqlBuilder* self, const gchar* var_name);
void tracker_sparql_builder_object_variable (TrackerSparqlBuilder* self, const gchar* var_name);
void tracker_sparql_builder_subject_iri (TrackerSparqlBuilder* self, const gchar* iri);
void tracker_sparql_builder_subject (TrackerSparqlBuilder* self, const gchar* s);
void tracker_sparql_builder_predicate_iri (TrackerSparqlBuilder* self, const gchar* iri);
void tracker_sparql_builder_predicate (TrackerSparqlBuilder* self, const gchar* s);
void tracker_sparql_builder_object_iri (TrackerSparqlBuilder* self, const gchar* iri);
void tracker_sparql_builder_object (TrackerSparqlBuilder* self, const gchar* s);
void tracker_sparql_builder_object_string (TrackerSparqlBuilder* self, const gchar* literal);
void tracker_sparql_builder_object_unvalidated (TrackerSparqlBuilder* self, const gchar* value);
void tracker_sparql_builder_object_boolean (TrackerSparqlBuilder* self, gboolean literal);
void tracker_sparql_builder_object_int64 (TrackerSparqlBuilder* self, gint64 literal);
void tracker_sparql_builder_object_date (TrackerSparqlBuilder* self, time_t* literal);
void tracker_sparql_builder_object_double (TrackerSparqlBuilder* self, gdouble literal);
void tracker_sparql_builder_object_blank_open (TrackerSparqlBuilder* self);
void tracker_sparql_builder_object_blank_close (TrackerSparqlBuilder* self);
void tracker_sparql_builder_prepend (TrackerSparqlBuilder* self, const gchar* raw);
void tracker_sparql_builder_append (TrackerSparqlBuilder* self, const gchar* raw);
TrackerSparqlBuilder* tracker_sparql_builder_new (void);
TrackerSparqlBuilder* tracker_sparql_builder_construct (GType object_type);
const gchar* tracker_sparql_builder_get_result (TrackerSparqlBuilder* self);
gint tracker_sparql_builder_get_length (TrackerSparqlBuilder* self);
TrackerSparqlBuilderState tracker_sparql_builder_get_state (TrackerSparqlBuilder* self);
#define TRACKER_DBUS_SERVICE "org.freedesktop.Tracker1"
#define TRACKER_DBUS_INTERFACE_RESOURCES TRACKER_DBUS_SERVICE ".Resources"
#define TRACKER_DBUS_OBJECT_RESOURCES "/org/freedesktop/Tracker1/Resources"
#define TRACKER_DBUS_INTERFACE_STATISTICS TRACKER_DBUS_SERVICE ".Statistics"
#define TRACKER_DBUS_OBJECT_STATISTICS "/org/freedesktop/Tracker1/Statistics"
#define TRACKER_DBUS_INTERFACE_STATUS TRACKER_DBUS_SERVICE ".Status"
#define TRACKER_DBUS_OBJECT_STATUS "/org/freedesktop/Tracker1/Status"
#define TRACKER_DBUS_INTERFACE_STEROIDS TRACKER_DBUS_SERVICE ".Steroids"
#define TRACKER_DBUS_OBJECT_STEROIDS "/org/freedesktop/Tracker1/Steroids"
GQuark tracker_sparql_error_quark (void);
GType tracker_sparql_connection_get_type (void) G_GNUC_CONST;
GType tracker_sparql_cursor_get_type (void) G_GNUC_CONST;
void tracker_sparql_connection_get_async (GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
TrackerSparqlConnection* tracker_sparql_connection_get_finish (GAsyncResult* _res_, GError** error);
TrackerSparqlConnection* tracker_sparql_connection_get (GCancellable* cancellable, GError** error);
void tracker_sparql_connection_get_direct_async (GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
TrackerSparqlConnection* tracker_sparql_connection_get_direct_finish (GAsyncResult* _res_, GError** error);
TrackerSparqlConnection* tracker_sparql_connection_get_direct (GCancellable* cancellable, GError** error) G_GNUC_DEPRECATED;
TrackerSparqlCursor* tracker_sparql_connection_query (TrackerSparqlConnection* self, const gchar* sparql, GCancellable* cancellable, GError** error);
void tracker_sparql_connection_query_async (TrackerSparqlConnection* self, const gchar* sparql, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
TrackerSparqlCursor* tracker_sparql_connection_query_finish (TrackerSparqlConnection* self, GAsyncResult* _res_, GError** error);
void tracker_sparql_connection_update (TrackerSparqlConnection* self, const gchar* sparql, gint priority, GCancellable* cancellable, GError** error);
void tracker_sparql_connection_update_async (TrackerSparqlConnection* self, const gchar* sparql, gint priority, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
void tracker_sparql_connection_update_finish (TrackerSparqlConnection* self, GAsyncResult* _res_, GError** error);
void tracker_sparql_connection_update_array_async (TrackerSparqlConnection* self, gchar** sparql, int sparql_length1, gint priority, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
GPtrArray* tracker_sparql_connection_update_array_finish (TrackerSparqlConnection* self, GAsyncResult* _res_, GError** error);
GVariant* tracker_sparql_connection_update_blank (TrackerSparqlConnection* self, const gchar* sparql, gint priority, GCancellable* cancellable, GError** error);
void tracker_sparql_connection_update_blank_async (TrackerSparqlConnection* self, const gchar* sparql, gint priority, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
GVariant* tracker_sparql_connection_update_blank_finish (TrackerSparqlConnection* self, GAsyncResult* _res_, GError** error);
void tracker_sparql_connection_load (TrackerSparqlConnection* self, GFile* file, GCancellable* cancellable, GError** error);
void tracker_sparql_connection_load_async (TrackerSparqlConnection* self, GFile* file, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
void tracker_sparql_connection_load_finish (TrackerSparqlConnection* self, GAsyncResult* _res_, GError** error);
TrackerSparqlCursor* tracker_sparql_connection_statistics (TrackerSparqlConnection* self, GCancellable* cancellable, GError** error);
void tracker_sparql_connection_statistics_async (TrackerSparqlConnection* self, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
TrackerSparqlCursor* tracker_sparql_connection_statistics_finish (TrackerSparqlConnection* self, GAsyncResult* _res_, GError** error);
TrackerSparqlConnection* tracker_sparql_connection_construct (GType object_type);
GType tracker_sparql_value_type_get_type (void) G_GNUC_CONST;
TrackerSparqlValueType tracker_sparql_cursor_get_value_type (TrackerSparqlCursor* self, gint column);
const gchar* tracker_sparql_cursor_get_variable_name (TrackerSparqlCursor* self, gint column);
const gchar* tracker_sparql_cursor_get_string (TrackerSparqlCursor* self, gint column, glong* length);
gboolean tracker_sparql_cursor_next (TrackerSparqlCursor* self, GCancellable* cancellable, GError** error);
void tracker_sparql_cursor_next_async (TrackerSparqlCursor* self, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
gboolean tracker_sparql_cursor_next_finish (TrackerSparqlCursor* self, GAsyncResult* _res_, GError** error);
void tracker_sparql_cursor_rewind (TrackerSparqlCursor* self);
void tracker_sparql_cursor_close (TrackerSparqlCursor* self);
gint64 tracker_sparql_cursor_get_integer (TrackerSparqlCursor* self, gint column);
gdouble tracker_sparql_cursor_get_double (TrackerSparqlCursor* self, gint column);
gboolean tracker_sparql_cursor_get_boolean (TrackerSparqlCursor* self, gint column);
gboolean tracker_sparql_cursor_is_bound (TrackerSparqlCursor* self, gint column);
TrackerSparqlCursor* tracker_sparql_cursor_construct (GType object_type);
TrackerSparqlConnection* tracker_sparql_cursor_get_connection (TrackerSparqlCursor* self);
void tracker_sparql_cursor_set_connection (TrackerSparqlCursor* self, TrackerSparqlConnection* value);
gint tracker_sparql_cursor_get_n_columns (TrackerSparqlCursor* self);
gchar* tracker_sparql_escape_uri_vprintf (const gchar* format, va_list args);
gchar* tracker_sparql_escape_uri_printf (const gchar* format, ...);
gchar* tracker_sparql_escape_string (const gchar* literal);
gchar* tracker_sparql_get_uuid_urn (void);


G_END_DECLS

#endif
