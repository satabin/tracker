/* Generated by dbus-binding-tool; do not edit! */

#include <glib.h>
#include <dbus/dbus-glib.h>

G_BEGIN_DECLS

#ifndef DBUS_GLIB_CLIENT_WRAPPERS_org_freedesktop_Tracker_Metadata
#define DBUS_GLIB_CLIENT_WRAPPERS_org_freedesktop_Tracker_Metadata

static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_Tracker_Metadata_get (DBusGProxy *proxy, const char * IN_service_type, const char * IN_uri, const char ** IN_keys, char *** OUT_metadata, GError **error)

{
  return dbus_g_proxy_call (proxy, "Get", error, G_TYPE_STRING, IN_service_type, G_TYPE_STRING, IN_uri, G_TYPE_STRV, IN_keys, G_TYPE_INVALID, G_TYPE_STRV, OUT_metadata, G_TYPE_INVALID);
}

typedef void (*org_freedesktop_Tracker_Metadata_get_reply) (DBusGProxy *proxy, char * *OUT_metadata, GError *error, gpointer userdata);

static void
org_freedesktop_Tracker_Metadata_get_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char ** OUT_metadata;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRV, &OUT_metadata, G_TYPE_INVALID);
  (*(org_freedesktop_Tracker_Metadata_get_reply)data->cb) (proxy, OUT_metadata, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_Tracker_Metadata_get_async (DBusGProxy *proxy, const char * IN_service_type, const char * IN_uri, const char ** IN_keys, org_freedesktop_Tracker_Metadata_get_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Get", org_freedesktop_Tracker_Metadata_get_async_callback, stuff, g_free, G_TYPE_STRING, IN_service_type, G_TYPE_STRING, IN_uri, G_TYPE_STRV, IN_keys, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_Tracker_Metadata_get_all (DBusGProxy *proxy, const char * IN_service_type, const char * IN_uri, GPtrArray** OUT_metadata, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetAll", error, G_TYPE_STRING, IN_service_type, G_TYPE_STRING, IN_uri, G_TYPE_INVALID, dbus_g_type_get_collection ("GPtrArray", G_TYPE_STRV), OUT_metadata, G_TYPE_INVALID);
}

typedef void (*org_freedesktop_Tracker_Metadata_get_all_reply) (DBusGProxy *proxy, GPtrArray *OUT_metadata, GError *error, gpointer userdata);

static void
org_freedesktop_Tracker_Metadata_get_all_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  GPtrArray* OUT_metadata;
  dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_collection ("GPtrArray", G_TYPE_STRV), &OUT_metadata, G_TYPE_INVALID);
  (*(org_freedesktop_Tracker_Metadata_get_all_reply)data->cb) (proxy, OUT_metadata, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_Tracker_Metadata_get_all_async (DBusGProxy *proxy, const char * IN_service_type, const char * IN_uri, org_freedesktop_Tracker_Metadata_get_all_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetAll", org_freedesktop_Tracker_Metadata_get_all_async_callback, stuff, g_free, G_TYPE_STRING, IN_service_type, G_TYPE_STRING, IN_uri, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_Tracker_Metadata_set (DBusGProxy *proxy, const char * IN_service_type, const char * IN_uri, const char ** IN_keys, const char ** IN_metadata, GError **error)

{
  return dbus_g_proxy_call (proxy, "Set", error, G_TYPE_STRING, IN_service_type, G_TYPE_STRING, IN_uri, G_TYPE_STRV, IN_keys, G_TYPE_STRV, IN_metadata, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freedesktop_Tracker_Metadata_set_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freedesktop_Tracker_Metadata_set_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freedesktop_Tracker_Metadata_set_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_Tracker_Metadata_set_async (DBusGProxy *proxy, const char * IN_service_type, const char * IN_uri, const char ** IN_keys, const char ** IN_metadata, org_freedesktop_Tracker_Metadata_set_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Set", org_freedesktop_Tracker_Metadata_set_async_callback, stuff, g_free, G_TYPE_STRING, IN_service_type, G_TYPE_STRING, IN_uri, G_TYPE_STRV, IN_keys, G_TYPE_STRV, IN_metadata, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_Tracker_Metadata_get_type_details (DBusGProxy *proxy, const char * IN_metadata, char ** OUT_data_type, gboolean* OUT_is_embedded, gboolean* OUT_is_writable, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetTypeDetails", error, G_TYPE_STRING, IN_metadata, G_TYPE_INVALID, G_TYPE_STRING, OUT_data_type, G_TYPE_BOOLEAN, OUT_is_embedded, G_TYPE_BOOLEAN, OUT_is_writable, G_TYPE_INVALID);
}

typedef void (*org_freedesktop_Tracker_Metadata_get_type_details_reply) (DBusGProxy *proxy, char * OUT_data_type, gboolean OUT_is_embedded, gboolean OUT_is_writable, GError *error, gpointer userdata);

static void
org_freedesktop_Tracker_Metadata_get_type_details_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char * OUT_data_type;
  gboolean OUT_is_embedded;
  gboolean OUT_is_writable;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRING, &OUT_data_type, G_TYPE_BOOLEAN, &OUT_is_embedded, G_TYPE_BOOLEAN, &OUT_is_writable, G_TYPE_INVALID);
  (*(org_freedesktop_Tracker_Metadata_get_type_details_reply)data->cb) (proxy, OUT_data_type, OUT_is_embedded, OUT_is_writable, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_Tracker_Metadata_get_type_details_async (DBusGProxy *proxy, const char * IN_metadata, org_freedesktop_Tracker_Metadata_get_type_details_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetTypeDetails", org_freedesktop_Tracker_Metadata_get_type_details_async_callback, stuff, g_free, G_TYPE_STRING, IN_metadata, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_Tracker_Metadata_get_registered_types (DBusGProxy *proxy, const char * IN_service_type, char *** OUT_result, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetRegisteredTypes", error, G_TYPE_STRING, IN_service_type, G_TYPE_INVALID, G_TYPE_STRV, OUT_result, G_TYPE_INVALID);
}

typedef void (*org_freedesktop_Tracker_Metadata_get_registered_types_reply) (DBusGProxy *proxy, char * *OUT_result, GError *error, gpointer userdata);

static void
org_freedesktop_Tracker_Metadata_get_registered_types_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char ** OUT_result;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRV, &OUT_result, G_TYPE_INVALID);
  (*(org_freedesktop_Tracker_Metadata_get_registered_types_reply)data->cb) (proxy, OUT_result, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_Tracker_Metadata_get_registered_types_async (DBusGProxy *proxy, const char * IN_service_type, org_freedesktop_Tracker_Metadata_get_registered_types_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetRegisteredTypes", org_freedesktop_Tracker_Metadata_get_registered_types_async_callback, stuff, g_free, G_TYPE_STRING, IN_service_type, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_Tracker_Metadata_get_registered_classes (DBusGProxy *proxy, char *** OUT_result, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetRegisteredClasses", error, G_TYPE_INVALID, G_TYPE_STRV, OUT_result, G_TYPE_INVALID);
}

typedef void (*org_freedesktop_Tracker_Metadata_get_registered_classes_reply) (DBusGProxy *proxy, char * *OUT_result, GError *error, gpointer userdata);

static void
org_freedesktop_Tracker_Metadata_get_registered_classes_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char ** OUT_result;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRV, &OUT_result, G_TYPE_INVALID);
  (*(org_freedesktop_Tracker_Metadata_get_registered_classes_reply)data->cb) (proxy, OUT_result, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_Tracker_Metadata_get_registered_classes_async (DBusGProxy *proxy, org_freedesktop_Tracker_Metadata_get_registered_classes_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetRegisteredClasses", org_freedesktop_Tracker_Metadata_get_registered_classes_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_Tracker_Metadata_get_unique_values (DBusGProxy *proxy, const char * IN_service, const char ** IN_meta_types, const char * IN_query, const gboolean IN_descending, const gint IN_offset, const gint IN_max_hits, GPtrArray** OUT_result, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetUniqueValues", error, G_TYPE_STRING, IN_service, G_TYPE_STRV, IN_meta_types, G_TYPE_STRING, IN_query, G_TYPE_BOOLEAN, IN_descending, G_TYPE_INT, IN_offset, G_TYPE_INT, IN_max_hits, G_TYPE_INVALID, dbus_g_type_get_collection ("GPtrArray", G_TYPE_STRV), OUT_result, G_TYPE_INVALID);
}

typedef void (*org_freedesktop_Tracker_Metadata_get_unique_values_reply) (DBusGProxy *proxy, GPtrArray *OUT_result, GError *error, gpointer userdata);

static void
org_freedesktop_Tracker_Metadata_get_unique_values_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  GPtrArray* OUT_result;
  dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_collection ("GPtrArray", G_TYPE_STRV), &OUT_result, G_TYPE_INVALID);
  (*(org_freedesktop_Tracker_Metadata_get_unique_values_reply)data->cb) (proxy, OUT_result, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_Tracker_Metadata_get_unique_values_async (DBusGProxy *proxy, const char * IN_service, const char ** IN_meta_types, const char * IN_query, const gboolean IN_descending, const gint IN_offset, const gint IN_max_hits, org_freedesktop_Tracker_Metadata_get_unique_values_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetUniqueValues", org_freedesktop_Tracker_Metadata_get_unique_values_async_callback, stuff, g_free, G_TYPE_STRING, IN_service, G_TYPE_STRV, IN_meta_types, G_TYPE_STRING, IN_query, G_TYPE_BOOLEAN, IN_descending, G_TYPE_INT, IN_offset, G_TYPE_INT, IN_max_hits, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_Tracker_Metadata_get_sum (DBusGProxy *proxy, const char * IN_service, const char * IN_field, const char * IN_query, gint* OUT_result, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetSum", error, G_TYPE_STRING, IN_service, G_TYPE_STRING, IN_field, G_TYPE_STRING, IN_query, G_TYPE_INVALID, G_TYPE_INT, OUT_result, G_TYPE_INVALID);
}

typedef void (*org_freedesktop_Tracker_Metadata_get_sum_reply) (DBusGProxy *proxy, gint OUT_result, GError *error, gpointer userdata);

static void
org_freedesktop_Tracker_Metadata_get_sum_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  gint OUT_result;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INT, &OUT_result, G_TYPE_INVALID);
  (*(org_freedesktop_Tracker_Metadata_get_sum_reply)data->cb) (proxy, OUT_result, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_Tracker_Metadata_get_sum_async (DBusGProxy *proxy, const char * IN_service, const char * IN_field, const char * IN_query, org_freedesktop_Tracker_Metadata_get_sum_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetSum", org_freedesktop_Tracker_Metadata_get_sum_async_callback, stuff, g_free, G_TYPE_STRING, IN_service, G_TYPE_STRING, IN_field, G_TYPE_STRING, IN_query, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_Tracker_Metadata_get_count (DBusGProxy *proxy, const char * IN_service, const char * IN_field, const char * IN_query, gint* OUT_result, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetCount", error, G_TYPE_STRING, IN_service, G_TYPE_STRING, IN_field, G_TYPE_STRING, IN_query, G_TYPE_INVALID, G_TYPE_INT, OUT_result, G_TYPE_INVALID);
}

typedef void (*org_freedesktop_Tracker_Metadata_get_count_reply) (DBusGProxy *proxy, gint OUT_result, GError *error, gpointer userdata);

static void
org_freedesktop_Tracker_Metadata_get_count_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  gint OUT_result;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INT, &OUT_result, G_TYPE_INVALID);
  (*(org_freedesktop_Tracker_Metadata_get_count_reply)data->cb) (proxy, OUT_result, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_Tracker_Metadata_get_count_async (DBusGProxy *proxy, const char * IN_service, const char * IN_field, const char * IN_query, org_freedesktop_Tracker_Metadata_get_count_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetCount", org_freedesktop_Tracker_Metadata_get_count_async_callback, stuff, g_free, G_TYPE_STRING, IN_service, G_TYPE_STRING, IN_field, G_TYPE_STRING, IN_query, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_Tracker_Metadata_get_unique_values_with_count (DBusGProxy *proxy, const char * IN_service, const char ** IN_meta_types, const char * IN_query, const char * IN_count_field, const gboolean IN_descending, const gint IN_offset, const gint IN_max_hits, GPtrArray** OUT_result, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetUniqueValuesWithCount", error, G_TYPE_STRING, IN_service, G_TYPE_STRV, IN_meta_types, G_TYPE_STRING, IN_query, G_TYPE_STRING, IN_count_field, G_TYPE_BOOLEAN, IN_descending, G_TYPE_INT, IN_offset, G_TYPE_INT, IN_max_hits, G_TYPE_INVALID, dbus_g_type_get_collection ("GPtrArray", G_TYPE_STRV), OUT_result, G_TYPE_INVALID);
}

typedef void (*org_freedesktop_Tracker_Metadata_get_unique_values_with_count_reply) (DBusGProxy *proxy, GPtrArray *OUT_result, GError *error, gpointer userdata);

static void
org_freedesktop_Tracker_Metadata_get_unique_values_with_count_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  GPtrArray* OUT_result;
  dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_collection ("GPtrArray", G_TYPE_STRV), &OUT_result, G_TYPE_INVALID);
  (*(org_freedesktop_Tracker_Metadata_get_unique_values_with_count_reply)data->cb) (proxy, OUT_result, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_Tracker_Metadata_get_unique_values_with_count_async (DBusGProxy *proxy, const char * IN_service, const char ** IN_meta_types, const char * IN_query, const char * IN_count_field, const gboolean IN_descending, const gint IN_offset, const gint IN_max_hits, org_freedesktop_Tracker_Metadata_get_unique_values_with_count_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetUniqueValuesWithCount", org_freedesktop_Tracker_Metadata_get_unique_values_with_count_async_callback, stuff, g_free, G_TYPE_STRING, IN_service, G_TYPE_STRV, IN_meta_types, G_TYPE_STRING, IN_query, G_TYPE_STRING, IN_count_field, G_TYPE_BOOLEAN, IN_descending, G_TYPE_INT, IN_offset, G_TYPE_INT, IN_max_hits, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_Tracker_Metadata_get_unique_values_with_count_and_sum (DBusGProxy *proxy, const char * IN_service, const char ** IN_meta_types, const char * IN_query, const char * IN_count_field, const char * IN_sum_field, const gboolean IN_descending, const gint IN_offset, const gint IN_max_hits, GPtrArray** OUT_result, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetUniqueValuesWithCountAndSum", error, G_TYPE_STRING, IN_service, G_TYPE_STRV, IN_meta_types, G_TYPE_STRING, IN_query, G_TYPE_STRING, IN_count_field, G_TYPE_STRING, IN_sum_field, G_TYPE_BOOLEAN, IN_descending, G_TYPE_INT, IN_offset, G_TYPE_INT, IN_max_hits, G_TYPE_INVALID, dbus_g_type_get_collection ("GPtrArray", G_TYPE_STRV), OUT_result, G_TYPE_INVALID);
}

typedef void (*org_freedesktop_Tracker_Metadata_get_unique_values_with_count_and_sum_reply) (DBusGProxy *proxy, GPtrArray *OUT_result, GError *error, gpointer userdata);

static void
org_freedesktop_Tracker_Metadata_get_unique_values_with_count_and_sum_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  GPtrArray* OUT_result;
  dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_collection ("GPtrArray", G_TYPE_STRV), &OUT_result, G_TYPE_INVALID);
  (*(org_freedesktop_Tracker_Metadata_get_unique_values_with_count_and_sum_reply)data->cb) (proxy, OUT_result, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_Tracker_Metadata_get_unique_values_with_count_and_sum_async (DBusGProxy *proxy, const char * IN_service, const char ** IN_meta_types, const char * IN_query, const char * IN_count_field, const char * IN_sum_field, const gboolean IN_descending, const gint IN_offset, const gint IN_max_hits, org_freedesktop_Tracker_Metadata_get_unique_values_with_count_and_sum_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetUniqueValuesWithCountAndSum", org_freedesktop_Tracker_Metadata_get_unique_values_with_count_and_sum_async_callback, stuff, g_free, G_TYPE_STRING, IN_service, G_TYPE_STRV, IN_meta_types, G_TYPE_STRING, IN_query, G_TYPE_STRING, IN_count_field, G_TYPE_STRING, IN_sum_field, G_TYPE_BOOLEAN, IN_descending, G_TYPE_INT, IN_offset, G_TYPE_INT, IN_max_hits, G_TYPE_INVALID);
}
#endif /* defined DBUS_GLIB_CLIENT_WRAPPERS_org_freedesktop_Tracker_Metadata */

G_END_DECLS
