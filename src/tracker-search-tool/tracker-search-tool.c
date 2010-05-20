/* tracker-search-tool.c generated by valac, the Vala compiler
 * generated from tracker-search-tool.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <glib/gi18n-lib.h>
#include <gdk/gdk.h>
#include <dbus/dbus.h>


#define TYPE_TRACKER_SEARCH_TOOL_SERVER (tracker_search_tool_server_get_type ())
#define TRACKER_SEARCH_TOOL_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRACKER_SEARCH_TOOL_SERVER, TrackerSearchToolServer))
#define TRACKER_SEARCH_TOOL_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRACKER_SEARCH_TOOL_SERVER, TrackerSearchToolServerClass))
#define IS_TRACKER_SEARCH_TOOL_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRACKER_SEARCH_TOOL_SERVER))
#define IS_TRACKER_SEARCH_TOOL_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRACKER_SEARCH_TOOL_SERVER))
#define TRACKER_SEARCH_TOOL_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRACKER_SEARCH_TOOL_SERVER, TrackerSearchToolServerClass))

typedef struct _TrackerSearchToolServer TrackerSearchToolServer;
typedef struct _TrackerSearchToolServerClass TrackerSearchToolServerClass;
typedef struct _TrackerSearchToolServerPrivate TrackerSearchToolServerPrivate;
#define _g_option_context_free0(var) ((var == NULL) ? NULL : (var = (g_option_context_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))

#define TYPE_TRACKER_QUERY (tracker_query_get_type ())
#define TRACKER_QUERY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRACKER_QUERY, TrackerQuery))
#define TRACKER_QUERY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRACKER_QUERY, TrackerQueryClass))
#define IS_TRACKER_QUERY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRACKER_QUERY))
#define IS_TRACKER_QUERY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRACKER_QUERY))
#define TRACKER_QUERY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRACKER_QUERY, TrackerQueryClass))

typedef struct _TrackerQuery TrackerQuery;
typedef struct _TrackerQueryClass TrackerQueryClass;

#define TYPE_TRACKER_SEARCH_ENTRY (tracker_search_entry_get_type ())
#define TRACKER_SEARCH_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRACKER_SEARCH_ENTRY, TrackerSearchEntry))
#define TRACKER_SEARCH_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRACKER_SEARCH_ENTRY, TrackerSearchEntryClass))
#define IS_TRACKER_SEARCH_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRACKER_SEARCH_ENTRY))
#define IS_TRACKER_SEARCH_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRACKER_SEARCH_ENTRY))
#define TRACKER_SEARCH_ENTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRACKER_SEARCH_ENTRY, TrackerSearchEntryClass))

typedef struct _TrackerSearchEntry TrackerSearchEntry;
typedef struct _TrackerSearchEntryClass TrackerSearchEntryClass;

#define TYPE_TRACKER_RESULT_GRID (tracker_result_grid_get_type ())
#define TRACKER_RESULT_GRID(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRACKER_RESULT_GRID, TrackerResultGrid))
#define TRACKER_RESULT_GRID_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRACKER_RESULT_GRID, TrackerResultGridClass))
#define IS_TRACKER_RESULT_GRID(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRACKER_RESULT_GRID))
#define IS_TRACKER_RESULT_GRID_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRACKER_RESULT_GRID))
#define TRACKER_RESULT_GRID_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRACKER_RESULT_GRID, TrackerResultGridClass))

typedef struct _TrackerResultGrid TrackerResultGrid;
typedef struct _TrackerResultGridClass TrackerResultGridClass;

#define TYPE_TRACKER_CATEGORY_VIEW (tracker_category_view_get_type ())
#define TRACKER_CATEGORY_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRACKER_CATEGORY_VIEW, TrackerCategoryView))
#define TRACKER_CATEGORY_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRACKER_CATEGORY_VIEW, TrackerCategoryViewClass))
#define IS_TRACKER_CATEGORY_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRACKER_CATEGORY_VIEW))
#define IS_TRACKER_CATEGORY_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRACKER_CATEGORY_VIEW))
#define TRACKER_CATEGORY_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRACKER_CATEGORY_VIEW, TrackerCategoryViewClass))

typedef struct _TrackerCategoryView TrackerCategoryView;
typedef struct _TrackerCategoryViewClass TrackerCategoryViewClass;

#define TYPE_TRACKER_METADATA_TILE (tracker_metadata_tile_get_type ())
#define TRACKER_METADATA_TILE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRACKER_METADATA_TILE, TrackerMetadataTile))
#define TRACKER_METADATA_TILE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRACKER_METADATA_TILE, TrackerMetadataTileClass))
#define IS_TRACKER_METADATA_TILE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRACKER_METADATA_TILE))
#define IS_TRACKER_METADATA_TILE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRACKER_METADATA_TILE))
#define TRACKER_METADATA_TILE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRACKER_METADATA_TILE, TrackerMetadataTileClass))

typedef struct _TrackerMetadataTile TrackerMetadataTile;
typedef struct _TrackerMetadataTileClass TrackerMetadataTileClass;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _DBusObjectVTable _DBusObjectVTable;

struct _TrackerSearchToolServer {
	GObject parent_instance;
	TrackerSearchToolServerPrivate * priv;
};

struct _TrackerSearchToolServerClass {
	GObjectClass parent_class;
};

struct _DBusObjectVTable {
	void (*register_object) (DBusConnection*, const char*, void*);
};


extern GtkWindow* window;
GtkWindow* window = NULL;
extern char** terms;
extern gint terms_length1;
char** terms = NULL;
gint terms_length1 = 0;
extern char* search_string;
char* search_string = NULL;
extern gboolean print_version;
gboolean print_version = FALSE;
static gpointer tracker_search_tool_server_parent_class = NULL;

#define ABOUT "Tracker " PACKAGE_VERSION "\n"
#define LICENSE "This program is free software and comes without any warranty.\n" "It is licensed under version 2 or later of the General Public " "License which can be viewed at:\n" "\n" "  http://www.gnu.org/licenses/gpl.txt\n"
GType tracker_search_tool_server_get_type (void);
enum  {
	TRACKER_SEARCH_TOOL_SERVER_DUMMY_PROPERTY
};
void tracker_search_tool_server_Show (TrackerSearchToolServer* self);
TrackerSearchToolServer* tracker_search_tool_server_new (void);
TrackerSearchToolServer* tracker_search_tool_server_construct (GType object_type);
void tracker_search_tool_server_dbus_register_object (DBusConnection* connection, const char* path, void* object);
void _tracker_search_tool_server_dbus_unregister (DBusConnection* connection, void* _user_data_);
DBusHandlerResult tracker_search_tool_server_dbus_message (DBusConnection* connection, DBusMessage* message, void* object);
static DBusHandlerResult _dbus_tracker_search_tool_server_introspect (TrackerSearchToolServer* self, DBusConnection* connection, DBusMessage* message);
static DBusHandlerResult _dbus_tracker_search_tool_server_property_get_all (TrackerSearchToolServer* self, DBusConnection* connection, DBusMessage* message);
static DBusHandlerResult _dbus_tracker_search_tool_server_Show (TrackerSearchToolServer* self, DBusConnection* connection, DBusMessage* message);
static guint _dynamic_request_name0 (DBusGProxy* self, const char* param1, guint param2, GError** error);
static void _dynamic_show1 (DBusGProxy* self, GError** error);
static void _gtk_main_quit_gtk_object_destroy (GtkWindow* _sender, gpointer self);
TrackerQuery* tracker_query_new (void);
TrackerQuery* tracker_query_construct (GType object_type);
GType tracker_query_get_type (void);
TrackerSearchEntry* tracker_search_entry_new (void);
TrackerSearchEntry* tracker_search_entry_construct (GType object_type);
GType tracker_search_entry_get_type (void);
TrackerResultGrid* tracker_result_grid_new (void);
TrackerResultGrid* tracker_result_grid_construct (GType object_type);
GType tracker_result_grid_get_type (void);
TrackerCategoryView* tracker_category_view_new (void);
TrackerCategoryView* tracker_category_view_construct (GType object_type);
GType tracker_category_view_get_type (void);
TrackerMetadataTile* tracker_metadata_tile_new (void);
TrackerMetadataTile* tracker_metadata_tile_construct (GType object_type);
GType tracker_metadata_tile_get_type (void);
gboolean tracker_query_Connect (TrackerQuery* self);
void tracker_search_entry_set_Query (TrackerSearchEntry* self, TrackerQuery* value);
void tracker_result_grid_set_Query (TrackerResultGrid* self, TrackerQuery* value);
void tracker_category_view_set_Query (TrackerCategoryView* self, TrackerQuery* value);
void tracker_metadata_tile_set_ResultGrid (TrackerMetadataTile* self, TrackerResultGrid* value);
void tracker_metadata_tile_set_Query (TrackerMetadataTile* self, TrackerQuery* value);
void _vala_main (char** args, int args_length1);
static void _vala_dbus_register_object (DBusConnection* connection, const char* path, void* object);
static void _vala_dbus_unregister_object (gpointer connection, GObject* object);

const GOptionEntry options[3] = {{"version", 'V', 0, G_OPTION_ARG_NONE, &print_version, "Print version", NULL}, {"", (gchar) 0, 0, G_OPTION_ARG_STRING_ARRAY, &terms, "search terms", NULL}, {NULL}};
static const DBusObjectPathVTable _tracker_search_tool_server_dbus_path_vtable = {_tracker_search_tool_server_dbus_unregister, tracker_search_tool_server_dbus_message};
static const _DBusObjectVTable _tracker_search_tool_server_dbus_vtable = {tracker_search_tool_server_dbus_register_object};


#line 45 "tracker-search-tool.gs"
void tracker_search_tool_server_Show (TrackerSearchToolServer* self) {
#line 45 "tracker-search-tool.gs"
	g_return_if_fail (self != NULL);
#line 46 "tracker-search-tool.gs"
	gtk_window_present (window);
#line 166 "tracker-search-tool.c"
}


#line 44 "tracker-search-tool.gs"
TrackerSearchToolServer* tracker_search_tool_server_construct (GType object_type) {
#line 172 "tracker-search-tool.c"
	TrackerSearchToolServer * self;
#line 44 "tracker-search-tool.gs"
	self = (TrackerSearchToolServer*) g_object_new (object_type, NULL);
#line 176 "tracker-search-tool.c"
	return self;
}


#line 44 "tracker-search-tool.gs"
TrackerSearchToolServer* tracker_search_tool_server_new (void) {
#line 44 "tracker-search-tool.gs"
	return tracker_search_tool_server_construct (TYPE_TRACKER_SEARCH_TOOL_SERVER);
#line 185 "tracker-search-tool.c"
}


void _tracker_search_tool_server_dbus_unregister (DBusConnection* connection, void* _user_data_) {
}


static DBusHandlerResult _dbus_tracker_search_tool_server_introspect (TrackerSearchToolServer* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessage* reply;
	DBusMessageIter iter;
	GString* xml_data;
	char** children;
	int i;
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &iter);
	xml_data = g_string_new ("<!DOCTYPE node PUBLIC \"-//freedesktop//DTD D-BUS Object Introspection 1.0//EN\" \"http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd\">\n");
	g_string_append (xml_data, "<node>\n<interface name=\"org.freedesktop.DBus.Introspectable\">\n  <method name=\"Introspect\">\n    <arg name=\"data\" direction=\"out\" type=\"s\"/>\n  </method>\n</interface>\n<interface name=\"org.freedesktop.DBus.Properties\">\n  <method name=\"Get\">\n    <arg name=\"interface\" direction=\"in\" type=\"s\"/>\n    <arg name=\"propname\" direction=\"in\" type=\"s\"/>\n    <arg name=\"value\" direction=\"out\" type=\"v\"/>\n  </method>\n  <method name=\"Set\">\n    <arg name=\"interface\" direction=\"in\" type=\"s\"/>\n    <arg name=\"propname\" direction=\"in\" type=\"s\"/>\n    <arg name=\"value\" direction=\"in\" type=\"v\"/>\n  </method>\n  <method name=\"GetAll\">\n    <arg name=\"interface\" direction=\"in\" type=\"s\"/>\n    <arg name=\"props\" direction=\"out\" type=\"a{sv}\"/>\n  </method>\n</interface>\n<interface name=\"org.freedesktop.Tracker1.SearchTool\">\n  <method name=\"Show\">\n  </method>\n</interface>\n");
	dbus_connection_list_registered (connection, g_object_get_data ((GObject *) self, "dbus_object_path"), &children);
	for (i = 0; children[i]; i++) {
		g_string_append_printf (xml_data, "<node name=\"%s\"/>\n", children[i]);
	}
	dbus_free_string_array (children);
	g_string_append (xml_data, "</node>\n");
	dbus_message_iter_append_basic (&iter, DBUS_TYPE_STRING, &xml_data->str);
	g_string_free (xml_data, TRUE);
	if (reply) {
		dbus_connection_send (connection, reply, NULL);
		dbus_message_unref (reply);
		return DBUS_HANDLER_RESULT_HANDLED;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


static DBusHandlerResult _dbus_tracker_search_tool_server_property_get_all (TrackerSearchToolServer* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessage* reply;
	DBusMessageIter iter, reply_iter, subiter;
	char* interface_name;
	const char* _tmp0_;
	if (strcmp (dbus_message_get_signature (message), "s")) {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
	dbus_message_iter_init (message, &iter);
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &reply_iter);
	dbus_message_iter_get_basic (&iter, &_tmp0_);
	dbus_message_iter_next (&iter);
	interface_name = g_strdup (_tmp0_);
	if (strcmp (interface_name, "org.freedesktop.Tracker1.SearchTool") == 0) {
		dbus_message_iter_open_container (&reply_iter, DBUS_TYPE_ARRAY, "{sv}", &subiter);
		dbus_message_iter_close_container (&reply_iter, &subiter);
	} else {
		dbus_message_unref (reply);
		reply = NULL;
	}
	g_free (interface_name);
	if (reply) {
		dbus_connection_send (connection, reply, NULL);
		dbus_message_unref (reply);
		return DBUS_HANDLER_RESULT_HANDLED;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


static DBusHandlerResult _dbus_tracker_search_tool_server_Show (TrackerSearchToolServer* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessageIter iter;
	GError* error;
	DBusMessage* reply;
	error = NULL;
	if (strcmp (dbus_message_get_signature (message), "")) {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
	dbus_message_iter_init (message, &iter);
	tracker_search_tool_server_Show (self);
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &iter);
	if (reply) {
		dbus_connection_send (connection, reply, NULL);
		dbus_message_unref (reply);
		return DBUS_HANDLER_RESULT_HANDLED;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


DBusHandlerResult tracker_search_tool_server_dbus_message (DBusConnection* connection, DBusMessage* message, void* object) {
	DBusHandlerResult result;
	result = DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	if (dbus_message_is_method_call (message, "org.freedesktop.DBus.Introspectable", "Introspect")) {
		result = _dbus_tracker_search_tool_server_introspect (object, connection, message);
	} else if (dbus_message_is_method_call (message, "org.freedesktop.DBus.Properties", "GetAll")) {
		result = _dbus_tracker_search_tool_server_property_get_all (object, connection, message);
	} else if (dbus_message_is_method_call (message, "org.freedesktop.Tracker1.SearchTool", "Show")) {
		result = _dbus_tracker_search_tool_server_Show (object, connection, message);
	}
	if (result == DBUS_HANDLER_RESULT_HANDLED) {
		return result;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


void tracker_search_tool_server_dbus_register_object (DBusConnection* connection, const char* path, void* object) {
	if (!g_object_get_data (object, "dbus_object_path")) {
		g_object_set_data (object, "dbus_object_path", g_strdup (path));
		dbus_connection_register_object_path (connection, path, &_tracker_search_tool_server_dbus_path_vtable, object);
		g_object_weak_ref (object, _vala_dbus_unregister_object, connection);
	}
}


static void tracker_search_tool_server_class_init (TrackerSearchToolServerClass * klass) {
	tracker_search_tool_server_parent_class = g_type_class_peek_parent (klass);
	g_type_set_qdata (TYPE_TRACKER_SEARCH_TOOL_SERVER, g_quark_from_static_string ("DBusObjectVTable"), (void*) (&_tracker_search_tool_server_dbus_vtable));
}


static void tracker_search_tool_server_instance_init (TrackerSearchToolServer * self) {
}


GType tracker_search_tool_server_get_type (void) {
	static volatile gsize tracker_search_tool_server_type_id__volatile = 0;
	if (g_once_init_enter (&tracker_search_tool_server_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (TrackerSearchToolServerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) tracker_search_tool_server_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TrackerSearchToolServer), 0, (GInstanceInitFunc) tracker_search_tool_server_instance_init, NULL };
		GType tracker_search_tool_server_type_id;
		tracker_search_tool_server_type_id = g_type_register_static (G_TYPE_OBJECT, "TrackerSearchToolServer", &g_define_type_info, 0);
		g_once_init_leave (&tracker_search_tool_server_type_id__volatile, tracker_search_tool_server_type_id);
	}
	return tracker_search_tool_server_type_id__volatile;
}


static guint _dynamic_request_name0 (DBusGProxy* self, const char* param1, guint param2, GError** error) {
	guint result;
	dbus_g_proxy_call (self, "RequestName", error, G_TYPE_STRING, param1, G_TYPE_UINT, param2, G_TYPE_INVALID, G_TYPE_UINT, &result, G_TYPE_INVALID);
	if (*error) {
		return 0U;
	}
	return result;
}


static void _dynamic_show1 (DBusGProxy* self, GError** error) {
	dbus_g_proxy_call (self, "Show", error, G_TYPE_INVALID, G_TYPE_INVALID);
	if (*error) {
		return;
	}
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 7712 "gtk+-2.0.vapi"
static void _gtk_main_quit_gtk_object_destroy (GtkWindow* _sender, gpointer self) {
#line 349 "tracker-search-tool.c"
	gtk_main_quit ();
}


#line 48 "tracker-search-tool.gs"
void _vala_main (char** args, int args_length1) {
#line 356 "tracker-search-tool.c"
	GError * _inner_error_;
	GOptionContext* option_context;
	TrackerSearchToolServer* server;
	GtkBuilder* builder;
	GtkWindow* _tmp4_;
	GObject* _tmp3_;
	GtkAccelGroup* accel_group;
	GtkEntry* entry;
	TrackerQuery* query;
	TrackerSearchEntry* search_entry;
	TrackerResultGrid* grid;
	TrackerCategoryView* categories;
	TrackerMetadataTile* tile;
	GObject* _tmp5_;
	GtkContainer* entry_box;
	GObject* _tmp6_;
	GtkContainer* grid_box;
	GObject* _tmp7_;
	GtkContainer* category_box;
	GObject* _tmp8_;
	GtkVBox* main_box;
	GObject* _tmp9_;
	GtkLabel* search_label;
	guint keyval = 0U;
	GdkModifierType mods = 0;
	GtkEntry* _tmp11_;
	GtkWidget* _tmp10_;
	GtkAlignment* a;
	_inner_error_ = NULL;
#line 49 "tracker-search-tool.gs"
	gtk_init (&args_length1, &args);
#line 53 "tracker-search-tool.gs"
	option_context = g_option_context_new ("tracker-search-tool");
#line 54 "tracker-search-tool.gs"
	g_option_context_set_help_enabled (option_context, TRUE);
#line 55 "tracker-search-tool.gs"
	g_option_context_add_main_entries (option_context, options, NULL);
#line 394 "tracker-search-tool.c"
	{
#line 58 "tracker-search-tool.gs"
		g_option_context_parse (option_context, &args_length1, &args, &_inner_error_);
#line 398 "tracker-search-tool.c"
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_OPTION_ERROR) {
				goto __catch4_g_option_error;
			}
			_g_option_context_free0 (option_context);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	goto __finally4;
	__catch4_g_option_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 62 "tracker-search-tool.gs"
			fprintf (stdout, "%s\n", e->message);
#line 63 "tracker-search-tool.gs"
			fprintf (stdout, "Run '%s --help' to see a full list of available command line options.\n", args[0]);
#line 420 "tracker-search-tool.c"
			_g_error_free0 (e);
			_g_option_context_free0 (option_context);
#line 64 "tracker-search-tool.gs"
			return;
#line 425 "tracker-search-tool.c"
		}
	}
	__finally4:
	if (_inner_error_ != NULL) {
		_g_option_context_free0 (option_context);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
#line 66 "tracker-search-tool.gs"
	if (print_version) {
#line 67 "tracker-search-tool.gs"
		fprintf (stdout, "%s", "\n" ABOUT "\n" LICENSE "\n");
#line 439 "tracker-search-tool.c"
		_g_option_context_free0 (option_context);
#line 68 "tracker-search-tool.gs"
		return;
#line 443 "tracker-search-tool.c"
	}
#line 70 "tracker-search-tool.gs"
	server = tracker_search_tool_server_new ();
#line 447 "tracker-search-tool.c"
	{
		DBusGProxy* bus;
		guint _result_ = 0U;
		DBusGConnection* conn;
		DBusGProxy* _tmp0_;
		guint _tmp1_;
		bus = NULL;
#line 76 "tracker-search-tool.gs"
		conn = dbus_g_bus_get (DBUS_BUS_SESSION, &_inner_error_);
#line 457 "tracker-search-tool.c"
		if (_inner_error_ != NULL) {
			_g_object_unref0 (bus);
			if (_inner_error_->domain == DBUS_GERROR) {
				goto __catch5_dbus_gerror;
			}
			_g_object_unref0 (bus);
			_g_option_context_free0 (option_context);
			_g_object_unref0 (server);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
#line 78 "tracker-search-tool.gs"
		bus = (_tmp0_ = dbus_g_proxy_new_for_name (conn, "org.freedesktop.DBus", "/org/freedesktop/DBus", "org.freedesktop.DBus"), _g_object_unref0 (bus), _tmp0_);
#line 82 "tracker-search-tool.gs"
		_tmp1_ = _dynamic_request_name0 (bus, "org.freedesktop.Tracker1.SearchTool", (guint) 0, &_inner_error_);
#line 474 "tracker-search-tool.c"
		if (_inner_error_ != NULL) {
			_g_object_unref0 (bus);
			_dbus_g_connection_unref0 (conn);
			if (_inner_error_->domain == DBUS_GERROR) {
				goto __catch5_dbus_gerror;
			}
			goto __finally5;
		}
#line 82 "tracker-search-tool.gs"
		_result_ = _tmp1_;
#line 84 "tracker-search-tool.gs"
		if (_result_ == DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER) {
#line 85 "tracker-search-tool.gs"
			_vala_dbus_register_object (dbus_g_connection_get_connection (conn), "/org/freedesktop/Tracker1/SearchTool", (GObject*) server);
#line 489 "tracker-search-tool.c"
		} else {
			DBusGProxy* remote;
			DBusGProxy* _tmp2_;
			remote = NULL;
#line 89 "tracker-search-tool.gs"
			remote = (_tmp2_ = dbus_g_proxy_new_for_name (conn, "org.freedesktop.Tracker1.SearchTool", "/org/freedesktop/Tracker1/SearchTool", "org.freedesktop.Tracker1.SearchTool"), _g_object_unref0 (remote), _tmp2_);
#line 93 "tracker-search-tool.gs"
			_dynamic_show1 (remote, &_inner_error_);
#line 498 "tracker-search-tool.c"
			if (_inner_error_ != NULL) {
				_g_object_unref0 (remote);
				_g_object_unref0 (bus);
				_dbus_g_connection_unref0 (conn);
				if (_inner_error_->domain == DBUS_GERROR) {
					goto __catch5_dbus_gerror;
				}
				goto __finally5;
			}
			_g_object_unref0 (remote);
			_g_object_unref0 (bus);
			_dbus_g_connection_unref0 (conn);
			_g_option_context_free0 (option_context);
			_g_object_unref0 (server);
#line 94 "tracker-search-tool.gs"
			return;
#line 515 "tracker-search-tool.c"
		}
		_g_object_unref0 (bus);
		_dbus_g_connection_unref0 (conn);
	}
	goto __finally5;
	__catch5_dbus_gerror:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 96 "tracker-search-tool.gs"
			g_warning ("tracker-search-tool.gs:96: %s", e->message);
#line 529 "tracker-search-tool.c"
			_g_error_free0 (e);
		}
	}
	__finally5:
	if (_inner_error_ != NULL) {
		_g_option_context_free0 (option_context);
		_g_object_unref0 (server);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
#line 98 "tracker-search-tool.gs"
	builder = gtk_builder_new ();
#line 543 "tracker-search-tool.c"
	{
#line 101 "tracker-search-tool.gs"
		gtk_builder_add_from_file (builder, SRCDIR "tst.ui", &_inner_error_);
#line 547 "tracker-search-tool.c"
		if (_inner_error_ != NULL) {
			goto __catch6_g_error;
		}
	}
	goto __finally6;
	__catch6_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			{
#line 106 "tracker-search-tool.gs"
				gtk_builder_add_from_file (builder, TRACKER_UI_DIR "tst.ui", &_inner_error_);
#line 562 "tracker-search-tool.c"
				if (_inner_error_ != NULL) {
					goto __catch7_g_error;
				}
			}
			goto __finally7;
			__catch7_g_error:
			{
				GError * e;
				e = _inner_error_;
				_inner_error_ = NULL;
				{
					GtkMessageDialog* msg;
#line 108 "tracker-search-tool.gs"
					msg = g_object_ref_sink ((GtkMessageDialog*) gtk_message_dialog_new (NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, N_ ("Failed to load UI\n%s"), e->message));
#line 111 "tracker-search-tool.gs"
					gtk_dialog_run ((GtkDialog*) msg);
#line 112 "tracker-search-tool.gs"
					gtk_main_quit ();
#line 581 "tracker-search-tool.c"
					_g_error_free0 (e);
					_g_object_unref0 (msg);
				}
			}
			__finally7:
			if (_inner_error_ != NULL) {
				_g_error_free0 (e);
				_g_option_context_free0 (option_context);
				_g_object_unref0 (server);
				_g_object_unref0 (builder);
				_g_error_free0 (e);
				_g_option_context_free0 (option_context);
				_g_object_unref0 (server);
				_g_object_unref0 (builder);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
			_g_error_free0 (e);
		}
	}
	__finally6:
	if (_inner_error_ != NULL) {
		_g_option_context_free0 (option_context);
		_g_object_unref0 (server);
		_g_object_unref0 (builder);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
#line 114 "tracker-search-tool.gs"
	window = (_tmp4_ = _g_object_ref0 ((_tmp3_ = gtk_builder_get_object (builder, "window"), GTK_IS_WINDOW (_tmp3_) ? ((GtkWindow*) _tmp3_) : NULL)), _g_object_unref0 (window), _tmp4_);
#line 115 "tracker-search-tool.gs"
	g_signal_connect ((GtkObject*) window, "destroy", (GCallback) _gtk_main_quit_gtk_object_destroy, NULL);
#line 119 "tracker-search-tool.gs"
	accel_group = gtk_accel_group_new ();
#line 120 "tracker-search-tool.gs"
	entry = g_object_ref_sink ((GtkEntry*) gtk_entry_new ());
#line 122 "tracker-search-tool.gs"
	query = tracker_query_new ();
#line 123 "tracker-search-tool.gs"
	search_entry = g_object_ref_sink (tracker_search_entry_new ());
#line 124 "tracker-search-tool.gs"
	grid = g_object_ref_sink (tracker_result_grid_new ());
#line 125 "tracker-search-tool.gs"
	categories = g_object_ref_sink (tracker_category_view_new ());
#line 126 "tracker-search-tool.gs"
	tile = g_object_ref_sink (tracker_metadata_tile_new ());
#line 128 "tracker-search-tool.gs"
	entry_box = _g_object_ref0 ((_tmp5_ = gtk_builder_get_object (builder, "EntryBox"), GTK_IS_CONTAINER (_tmp5_) ? ((GtkContainer*) _tmp5_) : NULL));
#line 129 "tracker-search-tool.gs"
	grid_box = _g_object_ref0 ((_tmp6_ = gtk_builder_get_object (builder, "GridBox"), GTK_IS_CONTAINER (_tmp6_) ? ((GtkContainer*) _tmp6_) : NULL));
#line 130 "tracker-search-tool.gs"
	category_box = _g_object_ref0 ((_tmp7_ = gtk_builder_get_object (builder, "CategoryBox"), GTK_IS_CONTAINER (_tmp7_) ? ((GtkContainer*) _tmp7_) : NULL));
#line 131 "tracker-search-tool.gs"
	main_box = _g_object_ref0 ((_tmp8_ = gtk_builder_get_object (builder, "MainBox"), GTK_IS_VBOX (_tmp8_) ? ((GtkVBox*) _tmp8_) : NULL));
#line 132 "tracker-search-tool.gs"
	search_label = _g_object_ref0 ((_tmp9_ = gtk_builder_get_object (builder, "SearchLabel"), GTK_IS_LABEL (_tmp9_) ? ((GtkLabel*) _tmp9_) : NULL));
#line 134 "tracker-search-tool.gs"
	gtk_window_add_accel_group (window, accel_group);
#line 135 "tracker-search-tool.gs"
	gtk_label_set_mnemonic_widget (search_label, (GtkWidget*) search_entry);
#line 137 "tracker-search-tool.gs"
	tracker_query_Connect (query);
#line 138 "tracker-search-tool.gs"
	tracker_search_entry_set_Query (search_entry, query);
#line 139 "tracker-search-tool.gs"
	gtk_container_add (entry_box, (GtkWidget*) search_entry);
#line 143 "tracker-search-tool.gs"
	gtk_accelerator_parse ("<Ctrl>s", &keyval, &mods);
#line 144 "tracker-search-tool.gs"
	entry = (_tmp11_ = _g_object_ref0 ((_tmp10_ = gtk_bin_get_child ((GtkBin*) search_entry), GTK_IS_ENTRY (_tmp10_) ? ((GtkEntry*) _tmp10_) : NULL)), _g_object_unref0 (entry), _tmp11_);
#line 145 "tracker-search-tool.gs"
	gtk_widget_add_accelerator ((GtkWidget*) entry, "activate", accel_group, keyval, mods, GTK_ACCEL_VISIBLE | GTK_ACCEL_LOCKED);
#line 148 "tracker-search-tool.gs"
	tracker_result_grid_set_Query (grid, query);
#line 149 "tracker-search-tool.gs"
	gtk_container_add (grid_box, (GtkWidget*) grid);
#line 151 "tracker-search-tool.gs"
	tracker_category_view_set_Query (categories, query);
#line 152 "tracker-search-tool.gs"
	gtk_container_add (category_box, (GtkWidget*) categories);
#line 154 "tracker-search-tool.gs"
	tracker_metadata_tile_set_ResultGrid (tile, grid);
#line 155 "tracker-search-tool.gs"
	tracker_metadata_tile_set_Query (tile, query);
#line 157 "tracker-search-tool.gs"
	a = g_object_ref_sink ((GtkAlignment*) gtk_alignment_new (0.5f, 0.5f, 1.0f, 0.5f));
#line 158 "tracker-search-tool.gs"
	gtk_container_add ((GtkContainer*) a, (GtkWidget*) tile);
#line 159 "tracker-search-tool.gs"
	gtk_box_pack_end ((GtkBox*) main_box, (GtkWidget*) a, FALSE, FALSE, (guint) 0);
#line 161 "tracker-search-tool.gs"
	gtk_widget_show_all ((GtkWidget*) window);
#line 163 "tracker-search-tool.gs"
	if (terms != NULL) {
#line 678 "tracker-search-tool.c"
		char* _tmp12_;
#line 164 "tracker-search-tool.gs"
		search_string = (_tmp12_ = g_strjoinv (" ", terms), _g_free0 (search_string), _tmp12_);
#line 165 "tracker-search-tool.gs"
		gtk_entry_set_text (entry, search_string);
#line 684 "tracker-search-tool.c"
	}
#line 167 "tracker-search-tool.gs"
	gtk_main ();
#line 688 "tracker-search-tool.c"
	_g_option_context_free0 (option_context);
	_g_object_unref0 (server);
	_g_object_unref0 (builder);
	_g_object_unref0 (accel_group);
	_g_object_unref0 (entry);
	_g_object_unref0 (query);
	_g_object_unref0 (search_entry);
	_g_object_unref0 (grid);
	_g_object_unref0 (categories);
	_g_object_unref0 (tile);
	_g_object_unref0 (entry_box);
	_g_object_unref0 (grid_box);
	_g_object_unref0 (category_box);
	_g_object_unref0 (main_box);
	_g_object_unref0 (search_label);
	_g_object_unref0 (a);
}


#line 48 "tracker-search-tool.gs"
int main (int argc, char ** argv) {
#line 48 "tracker-search-tool.gs"
	g_type_init ();
#line 48 "tracker-search-tool.gs"
	_vala_main (argv, argc);
#line 48 "tracker-search-tool.gs"
	return 0;
#line 716 "tracker-search-tool.c"
}


static void _vala_dbus_register_object (DBusConnection* connection, const char* path, void* object) {
	const _DBusObjectVTable * vtable;
	vtable = g_type_get_qdata (G_TYPE_FROM_INSTANCE (object), g_quark_from_static_string ("DBusObjectVTable"));
	if (vtable) {
		vtable->register_object (connection, path, object);
	} else {
		g_warning ("Object does not implement any D-Bus interface");
	}
}


static void _vala_dbus_unregister_object (gpointer connection, GObject* object) {
	char* path;
	path = g_object_steal_data ((GObject*) object, "dbus_object_path");
	dbus_connection_unregister_object_path (connection, path);
	g_free (path);
}




