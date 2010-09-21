/* tracker-entry.c generated by valac 0.9.5.4-19a5, the Vala compiler
 * generated from tracker-entry.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gi18n-lib.h>
#include <gdk/gdk.h>


#define TYPE_TRACKER_SEARCH_ENTRY (tracker_search_entry_get_type ())
#define TRACKER_SEARCH_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRACKER_SEARCH_ENTRY, TrackerSearchEntry))
#define TRACKER_SEARCH_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRACKER_SEARCH_ENTRY, TrackerSearchEntryClass))
#define IS_TRACKER_SEARCH_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRACKER_SEARCH_ENTRY))
#define IS_TRACKER_SEARCH_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRACKER_SEARCH_ENTRY))
#define TRACKER_SEARCH_ENTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRACKER_SEARCH_ENTRY, TrackerSearchEntryClass))

typedef struct _TrackerSearchEntry TrackerSearchEntry;
typedef struct _TrackerSearchEntryClass TrackerSearchEntryClass;
typedef struct _TrackerSearchEntryPrivate TrackerSearchEntryPrivate;

#define TYPE_TRACKER_QUERY (tracker_query_get_type ())
#define TRACKER_QUERY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRACKER_QUERY, TrackerQuery))
#define TRACKER_QUERY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRACKER_QUERY, TrackerQueryClass))
#define IS_TRACKER_QUERY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRACKER_QUERY))
#define IS_TRACKER_QUERY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRACKER_QUERY))
#define TRACKER_QUERY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRACKER_QUERY, TrackerQueryClass))

typedef struct _TrackerQuery TrackerQuery;
typedef struct _TrackerQueryClass TrackerQueryClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _TrackerSearchEntry {
	GtkComboBoxEntry parent_instance;
	TrackerSearchEntryPrivate * priv;
	guint id_invoker;
	GtkEntry* entry;
	GeeArrayList* history;
};

struct _TrackerSearchEntryClass {
	GtkComboBoxEntryClass parent_class;
};

struct _TrackerSearchEntryPrivate {
	TrackerQuery* _Query;
};


static gpointer tracker_search_entry_parent_class = NULL;
static GtkActivatableIface* tracker_search_entry_gtk_activatable_parent_iface = NULL;

#define RUN_DELAY 500
GType tracker_search_entry_get_type (void) G_GNUC_CONST;
GType tracker_query_get_type (void) G_GNUC_CONST;
#define TRACKER_SEARCH_ENTRY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_TRACKER_SEARCH_ENTRY, TrackerSearchEntryPrivate))
enum  {
	TRACKER_SEARCH_ENTRY_DUMMY_PROPERTY,
	TRACKER_SEARCH_ENTRY_QUERY
};
TrackerQuery* tracker_search_entry_get_Query (TrackerSearchEntry* self);
void tracker_query_set_SearchTerms (TrackerQuery* self, const char* value);
static gboolean tracker_search_entry_run_query (TrackerSearchEntry* self);
static gboolean _tracker_search_entry_run_query_gsource_func (gpointer self);
static void tracker_search_entry_entry_changed (TrackerSearchEntry* self);
static void tracker_search_entry_entry_activate (TrackerSearchEntry* self);
char* tracker_utils_EscapeSparql (const char* sparql, gboolean add_wildcard);
static void tracker_search_entry_real_sync_action_properties (GtkActivatable* base, GtkAction* action);
static void tracker_search_entry_real_update (GtkActivatable* base, GtkAction* action, const char* prop);
TrackerSearchEntry* tracker_search_entry_new (void);
TrackerSearchEntry* tracker_search_entry_construct (GType object_type);
void tracker_search_entry_set_Query (TrackerSearchEntry* self, TrackerQuery* value);
static void _tracker_search_entry_entry_activate_gtk_entry_activate (GtkEntry* _sender, gpointer self);
static void _tracker_search_entry_entry_changed_gtk_editable_changed (GtkEntry* _sender, gpointer self);
static void _lambda1_ (GtkEntryIconPosition p0, TrackerSearchEntry* self);
static void __lambda1__gtk_entry_icon_press (GtkEntry* _sender, GtkEntryIconPosition p0, GdkEvent* p1, gpointer self);
static GObject * tracker_search_entry_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void tracker_search_entry_finalize (GObject* obj);
static void tracker_search_entry_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void tracker_search_entry_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static int _vala_strcmp0 (const char * str1, const char * str2);



#line 75 "tracker-entry.gs"
static gboolean _tracker_search_entry_run_query_gsource_func (gpointer self) {
#line 93 "tracker-entry.c"
	gboolean result;
	result = tracker_search_entry_run_query (self);
	return result;
}


#line 61 "tracker-entry.gs"
static void tracker_search_entry_entry_changed (TrackerSearchEntry* self) {
#line 61 "tracker-entry.gs"
	g_return_if_fail (self != NULL);
#line 62 "tracker-entry.gs"
	if (gtk_entry_get_text (self->entry) == NULL) {
#line 63 "tracker-entry.gs"
		tracker_query_set_SearchTerms (self->priv->_Query, "");
#line 64 "tracker-entry.gs"
		if (self->id_invoker != 0) {
#line 65 "tracker-entry.gs"
			g_source_remove (self->id_invoker);
#line 66 "tracker-entry.gs"
			self->id_invoker = (guint) 0;
#line 114 "tracker-entry.c"
		}
	} else {
#line 68 "tracker-entry.gs"
		if (self->id_invoker != 0) {
#line 69 "tracker-entry.gs"
			g_source_remove (self->id_invoker);
#line 121 "tracker-entry.c"
		}
#line 70 "tracker-entry.gs"
		self->id_invoker = g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) RUN_DELAY, _tracker_search_entry_run_query_gsource_func, g_object_ref (self), g_object_unref);
#line 125 "tracker-entry.c"
	}
}


#line 72 "tracker-entry.gs"
static void tracker_search_entry_entry_activate (TrackerSearchEntry* self) {
#line 72 "tracker-entry.gs"
	g_return_if_fail (self != NULL);
#line 73 "tracker-entry.gs"
	gtk_widget_grab_focus ((GtkWidget*) self->entry);
#line 136 "tracker-entry.c"
}


#line 1018 "glib-2.0.vapi"
static char* string_chug (const char* self) {
#line 142 "tracker-entry.c"
	char* result = NULL;
	char* _result_;
#line 1018 "glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 1019 "glib-2.0.vapi"
	_result_ = g_strdup (self);
#line 1020 "glib-2.0.vapi"
	g_strchug (_result_);
#line 151 "tracker-entry.c"
	result = _result_;
#line 1021 "glib-2.0.vapi"
	return result;
#line 155 "tracker-entry.c"
}


#line 1101 "glib-2.0.vapi"
static char* string_slice (const char* self, glong start, glong end) {
#line 161 "tracker-entry.c"
	char* result = NULL;
	glong string_length;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	const char* start_string;
#line 1101 "glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 1102 "glib-2.0.vapi"
	string_length = g_utf8_strlen (self, -1);
#line 1103 "glib-2.0.vapi"
	if (start < 0) {
#line 1104 "glib-2.0.vapi"
		start = string_length + start;
#line 175 "tracker-entry.c"
	}
#line 1106 "glib-2.0.vapi"
	if (end < 0) {
#line 1107 "glib-2.0.vapi"
		end = string_length + end;
#line 181 "tracker-entry.c"
	}
#line 1109 "glib-2.0.vapi"
	if (start >= 0) {
#line 1109 "glib-2.0.vapi"
		_tmp0_ = start <= string_length;
#line 187 "tracker-entry.c"
	} else {
#line 1109 "glib-2.0.vapi"
		_tmp0_ = FALSE;
#line 191 "tracker-entry.c"
	}
#line 1109 "glib-2.0.vapi"
	g_return_val_if_fail (_tmp0_, NULL);
#line 1110 "glib-2.0.vapi"
	if (end >= 0) {
#line 1110 "glib-2.0.vapi"
		_tmp1_ = end <= string_length;
#line 199 "tracker-entry.c"
	} else {
#line 1110 "glib-2.0.vapi"
		_tmp1_ = FALSE;
#line 203 "tracker-entry.c"
	}
#line 1110 "glib-2.0.vapi"
	g_return_val_if_fail (_tmp1_, NULL);
#line 1111 "glib-2.0.vapi"
	g_return_val_if_fail (start <= end, NULL);
#line 1112 "glib-2.0.vapi"
	start_string = g_utf8_offset_to_pointer (self, start);
#line 211 "tracker-entry.c"
	result = g_strndup (start_string, ((gchar*) g_utf8_offset_to_pointer (start_string, end - start)) - ((gchar*) start_string));
#line 1113 "glib-2.0.vapi"
	return result;
#line 215 "tracker-entry.c"
}


#line 75 "tracker-entry.gs"
static gboolean tracker_search_entry_run_query (TrackerSearchEntry* self) {
#line 221 "tracker-entry.c"
	gboolean result = FALSE;
	char* txt;
	gboolean _tmp0_ = FALSE;
	char* _tmp1_;
	glong len;
#line 75 "tracker-entry.gs"
	g_return_val_if_fail (self != NULL, FALSE);
#line 76 "tracker-entry.gs"
	txt = g_strdup (gtk_entry_get_text (self->entry));
#line 77 "tracker-entry.gs"
	if (txt == NULL) {
#line 77 "tracker-entry.gs"
		_tmp0_ = TRUE;
#line 235 "tracker-entry.c"
	} else {
#line 77 "tracker-entry.gs"
		_tmp0_ = _vala_strcmp0 (txt, "") == 0;
#line 239 "tracker-entry.c"
	}
#line 77 "tracker-entry.gs"
	if (_tmp0_) {
#line 78 "tracker-entry.gs"
		tracker_query_set_SearchTerms (self->priv->_Query, "");
#line 245 "tracker-entry.c"
		result = FALSE;
		_g_free0 (txt);
#line 79 "tracker-entry.gs"
		return result;
#line 250 "tracker-entry.c"
	}
#line 82 "tracker-entry.gs"
	txt = (_tmp1_ = string_chug (txt), _g_free0 (txt), _tmp1_);
#line 84 "tracker-entry.gs"
	len = g_utf8_strlen (txt, -1);
#line 85 "tracker-entry.gs"
	if (len > 2) {
#line 258 "tracker-entry.c"
		char* _tmp4_;
#line 88 "tracker-entry.gs"
		while (TRUE) {
#line 262 "tracker-entry.c"
			char* _tmp2_;
#line 88 "tracker-entry.gs"
			if (!(!g_unichar_isalnum (g_utf8_get_char (g_utf8_offset_to_pointer (txt, 0))))) {
#line 88 "tracker-entry.gs"
				break;
#line 268 "tracker-entry.c"
			}
#line 89 "tracker-entry.gs"
			if (g_utf8_get_char (g_utf8_offset_to_pointer (txt, 0)) == '_') {
#line 90 "tracker-entry.gs"
				break;
#line 274 "tracker-entry.c"
			}
#line 91 "tracker-entry.gs"
			txt = (_tmp2_ = string_slice (txt, (glong) 1, len--), _g_free0 (txt), _tmp2_);
#line 92 "tracker-entry.gs"
			if (len < 3) {
#line 280 "tracker-entry.c"
				result = FALSE;
				_g_free0 (txt);
#line 93 "tracker-entry.gs"
				return result;
#line 285 "tracker-entry.c"
			}
		}
#line 96 "tracker-entry.gs"
		if (!g_unichar_isalnum (g_utf8_get_char (g_utf8_offset_to_pointer (txt, len - 1)))) {
#line 97 "tracker-entry.gs"
			while (TRUE) {
#line 292 "tracker-entry.c"
				char* _tmp3_;
#line 97 "tracker-entry.gs"
				if (!(!g_unichar_isalnum (g_utf8_get_char (g_utf8_offset_to_pointer (txt, len - 2))))) {
#line 97 "tracker-entry.gs"
					break;
#line 298 "tracker-entry.c"
				}
#line 98 "tracker-entry.gs"
				if (g_utf8_get_char (g_utf8_offset_to_pointer (txt, len - 2)) == '_') {
#line 99 "tracker-entry.gs"
					break;
#line 304 "tracker-entry.c"
				}
#line 100 "tracker-entry.gs"
				txt = (_tmp3_ = string_slice (txt, (glong) 0, len - 2), _g_free0 (txt), _tmp3_);
#line 101 "tracker-entry.gs"
				len--;
#line 102 "tracker-entry.gs"
				if (len < 3) {
#line 312 "tracker-entry.c"
					result = FALSE;
					_g_free0 (txt);
#line 103 "tracker-entry.gs"
					return result;
#line 317 "tracker-entry.c"
				}
			}
		}
#line 106 "tracker-entry.gs"
		tracker_query_set_SearchTerms (self->priv->_Query, _tmp4_ = tracker_utils_EscapeSparql (txt, TRUE));
#line 323 "tracker-entry.c"
		_g_free0 (_tmp4_);
		{
			GeeIterator* _item_it;
#line 109 "tracker-entry.gs"
			_item_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->history);
#line 109 "tracker-entry.gs"
			while (TRUE) {
#line 331 "tracker-entry.c"
				char* item;
#line 109 "tracker-entry.gs"
				if (!gee_iterator_next (_item_it)) {
#line 109 "tracker-entry.gs"
					break;
#line 337 "tracker-entry.c"
				}
#line 109 "tracker-entry.gs"
				item = (char*) gee_iterator_get (_item_it);
#line 110 "tracker-entry.gs"
				if (_vala_strcmp0 (txt, item) == 0) {
#line 343 "tracker-entry.c"
					result = FALSE;
					_g_free0 (item);
					_g_object_unref0 (_item_it);
					_g_free0 (txt);
#line 111 "tracker-entry.gs"
					return result;
#line 350 "tracker-entry.c"
				}
				_g_free0 (item);
			}
			_g_object_unref0 (_item_it);
		}
#line 113 "tracker-entry.gs"
		gee_abstract_collection_add ((GeeAbstractCollection*) self->history, txt);
#line 114 "tracker-entry.gs"
		gtk_combo_box_prepend_text ((GtkComboBox*) self, txt);
#line 360 "tracker-entry.c"
	}
	result = FALSE;
	_g_free0 (txt);
#line 116 "tracker-entry.gs"
	return result;
#line 366 "tracker-entry.c"
}


#line 118 "tracker-entry.gs"
static void tracker_search_entry_real_sync_action_properties (GtkActivatable* base, GtkAction* action) {
#line 372 "tracker-entry.c"
	TrackerSearchEntry * self;
	self = (TrackerSearchEntry*) base;
#line 118 "tracker-entry.gs"
	g_return_if_fail (action != NULL);
#line 119 "tracker-entry.gs"
	return;
#line 379 "tracker-entry.c"
}


#line 121 "tracker-entry.gs"
static void tracker_search_entry_real_update (GtkActivatable* base, GtkAction* action, const char* prop) {
#line 385 "tracker-entry.c"
	TrackerSearchEntry * self;
	self = (TrackerSearchEntry*) base;
#line 121 "tracker-entry.gs"
	g_return_if_fail (action != NULL);
#line 121 "tracker-entry.gs"
	g_return_if_fail (prop != NULL);
#line 122 "tracker-entry.gs"
	return;
#line 394 "tracker-entry.c"
}


#line 30 "tracker-entry.gs"
TrackerSearchEntry* tracker_search_entry_construct (GType object_type) {
#line 400 "tracker-entry.c"
	TrackerSearchEntry * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


#line 30 "tracker-entry.gs"
TrackerSearchEntry* tracker_search_entry_new (void) {
#line 30 "tracker-entry.gs"
	return tracker_search_entry_construct (TYPE_TRACKER_SEARCH_ENTRY);
#line 411 "tracker-entry.c"
}


TrackerQuery* tracker_search_entry_get_Query (TrackerSearchEntry* self) {
	TrackerQuery* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_Query;
#line 35 "tracker-entry.gs"
	return result;
#line 421 "tracker-entry.c"
}


void tracker_search_entry_set_Query (TrackerSearchEntry* self, TrackerQuery* value) {
	g_return_if_fail (self != NULL);
	self->priv->_Query = value;
	g_object_notify ((GObject *) self, "Query");
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 72 "tracker-entry.gs"
static void _tracker_search_entry_entry_activate_gtk_entry_activate (GtkEntry* _sender, gpointer self) {
#line 439 "tracker-entry.c"
	tracker_search_entry_entry_activate (self);
}


#line 61 "tracker-entry.gs"
static void _tracker_search_entry_entry_changed_gtk_editable_changed (GtkEntry* _sender, gpointer self) {
#line 446 "tracker-entry.c"
	tracker_search_entry_entry_changed (self);
}


#line 55 "tracker-entry.gs"
static void _lambda1_ (GtkEntryIconPosition p0, TrackerSearchEntry* self) {
#line 56 "tracker-entry.gs"
	if (p0 == GTK_ENTRY_ICON_SECONDARY) {
#line 57 "tracker-entry.gs"
		gtk_entry_set_text (self->entry, "");
#line 457 "tracker-entry.c"
	}
}


#line 55 "tracker-entry.gs"
static void __lambda1__gtk_entry_icon_press (GtkEntry* _sender, GtkEntryIconPosition p0, GdkEvent* p1, gpointer self) {
#line 464 "tracker-entry.c"
	_lambda1_ (p0, self);
}


static GObject * tracker_search_entry_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	TrackerSearchEntry * self;
	parent_class = G_OBJECT_CLASS (tracker_search_entry_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = TRACKER_SEARCH_ENTRY (obj);
	{
		GtkWidget* _tmp0_;
		GtkEntry* _tmp1_;
		GtkListStore* model;
		GtkEntryCompletion* completion;
		GeeArrayList* _tmp2_;
#line 38 "tracker-entry.gs"
		self->entry = (_tmp1_ = _g_object_ref0 ((_tmp0_ = gtk_bin_get_child ((GtkBin*) self), GTK_IS_ENTRY (_tmp0_) ? ((GtkEntry*) _tmp0_) : NULL)), _g_object_unref0 (self->entry), _tmp1_);
#line 39 "tracker-entry.gs"
		gtk_entry_set_icon_from_stock (self->entry, GTK_ENTRY_ICON_SECONDARY, GTK_STOCK_CLEAR);
#line 40 "tracker-entry.gs"
		gtk_entry_set_icon_sensitive (self->entry, GTK_ENTRY_ICON_SECONDARY, TRUE);
#line 41 "tracker-entry.gs"
		gtk_entry_set_icon_tooltip_text (self->entry, GTK_ENTRY_ICON_SECONDARY, _ ("Clear the search text"));
#line 44 "tracker-entry.gs"
		model = gtk_list_store_new (1, G_TYPE_STRING);
#line 45 "tracker-entry.gs"
		gtk_combo_box_set_model ((GtkComboBox*) self, (GtkTreeModel*) model);
#line 46 "tracker-entry.gs"
		gtk_combo_box_entry_set_text_column ((GtkComboBoxEntry*) self, 0);
#line 48 "tracker-entry.gs"
		completion = gtk_entry_completion_new ();
#line 49 "tracker-entry.gs"
		gtk_entry_completion_set_model (completion, (GtkTreeModel*) model);
#line 50 "tracker-entry.gs"
		gtk_entry_completion_set_text_column (completion, 0);
#line 51 "tracker-entry.gs"
		gtk_entry_set_completion (self->entry, completion);
#line 53 "tracker-entry.gs"
		g_signal_connect_object (self->entry, "activate", (GCallback) _tracker_search_entry_entry_activate_gtk_entry_activate, self, 0);
#line 54 "tracker-entry.gs"
		g_signal_connect_object ((GtkEditable*) self->entry, "changed", (GCallback) _tracker_search_entry_entry_changed_gtk_editable_changed, self, 0);
#line 55 "tracker-entry.gs"
		g_signal_connect_object (self->entry, "icon-press", (GCallback) __lambda1__gtk_entry_icon_press, self, 0);
#line 59 "tracker-entry.gs"
		self->history = (_tmp2_ = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, g_str_equal), _g_object_unref0 (self->history), _tmp2_);
#line 512 "tracker-entry.c"
		_g_object_unref0 (completion);
		_g_object_unref0 (model);
	}
	return obj;
}


static void tracker_search_entry_class_init (TrackerSearchEntryClass * klass) {
	tracker_search_entry_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (TrackerSearchEntryPrivate));
	G_OBJECT_CLASS (klass)->get_property = tracker_search_entry_get_property;
	G_OBJECT_CLASS (klass)->set_property = tracker_search_entry_set_property;
	G_OBJECT_CLASS (klass)->constructor = tracker_search_entry_constructor;
	G_OBJECT_CLASS (klass)->finalize = tracker_search_entry_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), TRACKER_SEARCH_ENTRY_QUERY, g_param_spec_object ("Query", "Query", "Query", TYPE_TRACKER_QUERY, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void tracker_search_entry_gtk_activatable_interface_init (GtkActivatableIface * iface) {
	tracker_search_entry_gtk_activatable_parent_iface = g_type_interface_peek_parent (iface);
	iface->sync_action_properties = tracker_search_entry_real_sync_action_properties;
	iface->update = tracker_search_entry_real_update;
}


static void tracker_search_entry_instance_init (TrackerSearchEntry * self) {
	self->priv = TRACKER_SEARCH_ENTRY_GET_PRIVATE (self);
	self->id_invoker = (guint) 0;
}


static void tracker_search_entry_finalize (GObject* obj) {
	TrackerSearchEntry * self;
	self = TRACKER_SEARCH_ENTRY (obj);
	_g_object_unref0 (self->entry);
	_g_object_unref0 (self->history);
	G_OBJECT_CLASS (tracker_search_entry_parent_class)->finalize (obj);
}


GType tracker_search_entry_get_type (void) {
	static volatile gsize tracker_search_entry_type_id__volatile = 0;
	if (g_once_init_enter (&tracker_search_entry_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (TrackerSearchEntryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) tracker_search_entry_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TrackerSearchEntry), 0, (GInstanceInitFunc) tracker_search_entry_instance_init, NULL };
		static const GInterfaceInfo gtk_activatable_info = { (GInterfaceInitFunc) tracker_search_entry_gtk_activatable_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType tracker_search_entry_type_id;
		tracker_search_entry_type_id = g_type_register_static (GTK_TYPE_COMBO_BOX_ENTRY, "TrackerSearchEntry", &g_define_type_info, 0);
		g_type_add_interface_static (tracker_search_entry_type_id, GTK_TYPE_ACTIVATABLE, &gtk_activatable_info);
		g_once_init_leave (&tracker_search_entry_type_id__volatile, tracker_search_entry_type_id);
	}
	return tracker_search_entry_type_id__volatile;
}


static void tracker_search_entry_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	TrackerSearchEntry * self;
	self = TRACKER_SEARCH_ENTRY (object);
	switch (property_id) {
		case TRACKER_SEARCH_ENTRY_QUERY:
		g_value_set_object (value, tracker_search_entry_get_Query (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void tracker_search_entry_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	TrackerSearchEntry * self;
	self = TRACKER_SEARCH_ENTRY (object);
	switch (property_id) {
		case TRACKER_SEARCH_ENTRY_QUERY:
		tracker_search_entry_set_Query (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}



