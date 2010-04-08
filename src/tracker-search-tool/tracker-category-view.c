/* tracker-category-view.c generated by valac, the Vala compiler
 * generated from tracker-category-view.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <gdk-pixbuf/gdk-pixdata.h>
#include <gdk/gdk.h>
#include <glib/gi18n-lib.h>


#define TYPE_CATEGORY_COLUMNS (category_columns_get_type ())

#define TYPE_TRACKER_CATEGORY_VIEW (tracker_category_view_get_type ())
#define TRACKER_CATEGORY_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRACKER_CATEGORY_VIEW, TrackerCategoryView))
#define TRACKER_CATEGORY_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRACKER_CATEGORY_VIEW, TrackerCategoryViewClass))
#define IS_TRACKER_CATEGORY_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRACKER_CATEGORY_VIEW))
#define IS_TRACKER_CATEGORY_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRACKER_CATEGORY_VIEW))
#define TRACKER_CATEGORY_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRACKER_CATEGORY_VIEW, TrackerCategoryViewClass))

typedef struct _TrackerCategoryView TrackerCategoryView;
typedef struct _TrackerCategoryViewClass TrackerCategoryViewClass;
typedef struct _TrackerCategoryViewPrivate TrackerCategoryViewPrivate;

#define TYPE_CATEGORIES (categories_get_type ())

#define TYPE_TRACKER_QUERY (tracker_query_get_type ())
#define TRACKER_QUERY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRACKER_QUERY, TrackerQuery))
#define TRACKER_QUERY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRACKER_QUERY, TrackerQueryClass))
#define IS_TRACKER_QUERY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRACKER_QUERY))
#define IS_TRACKER_QUERY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRACKER_QUERY))
#define TRACKER_QUERY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRACKER_QUERY, TrackerQueryClass))

typedef struct _TrackerQuery TrackerQuery;
typedef struct _TrackerQueryClass TrackerQueryClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

typedef enum  {
	CATEGORY_COLUMNS_Icon,
	CATEGORY_COLUMNS_Name,
	CATEGORY_COLUMNS_DisplayName,
	CATEGORY_COLUMNS_NumOfCols
} CategoryColumns;

typedef enum  {
	CATEGORIES_Application,
	CATEGORIES_Contact,
	CATEGORIES_Email,
	CATEGORIES_EmailAttachment,
	CATEGORIES_File,
	CATEGORIES_Folder,
	CATEGORIES_Music,
	CATEGORIES_Video,
	CATEGORIES_Image,
	CATEGORIES_Document,
	CATEGORIES_Text,
	CATEGORIES_Development,
	CATEGORIES_Web,
	CATEGORIES_WebHistory
} Categories;

struct _TrackerCategoryView {
	GtkScrolledWindow parent_instance;
	TrackerCategoryViewPrivate * priv;
	GtkListStore* store;
	GtkTreeView* treeview;
	GtkLabel* lab;
	Categories catergory;
};

struct _TrackerCategoryViewClass {
	GtkScrolledWindowClass parent_class;
};

struct _TrackerCategoryViewPrivate {
	TrackerQuery* _Query;
};


static gpointer tracker_category_view_parent_class = NULL;

GType category_columns_get_type (void);
#define icon_size 16
GType tracker_category_view_get_type (void);
GType categories_get_type (void);
GType tracker_query_get_type (void);
#define TRACKER_CATEGORY_VIEW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_TRACKER_CATEGORY_VIEW, TrackerCategoryViewPrivate))
enum  {
	TRACKER_CATEGORY_VIEW_DUMMY_PROPERTY,
	TRACKER_CATEGORY_VIEW_QUERY
};
TrackerQuery* tracker_category_view_get_Query (TrackerCategoryView* self);
void tracker_query_set_Category (TrackerQuery* self, const char* value);
void tracker_category_view_selection_changed (TrackerCategoryView* self, GtkTreeSelection* sel);
TrackerCategoryView* tracker_category_view_new (void);
TrackerCategoryView* tracker_category_view_construct (GType object_type);
void tracker_category_view_set_Query (TrackerCategoryView* self, TrackerQuery* value);
GdkPixbuf* tracker_utils_GetThemePixbufByName (const char* icon_name, gint size, GdkScreen* screen);
static void _tracker_category_view_selection_changed_gtk_tree_selection_changed (GtkTreeSelection* _sender, gpointer self);
static GObject * tracker_category_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void tracker_category_view_finalize (GObject* obj);
static void tracker_category_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void tracker_category_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



GType category_columns_get_type (void) {
	static volatile gsize category_columns_type_id__volatile = 0;
	if (g_once_init_enter (&category_columns_type_id__volatile)) {
		static const GEnumValue values[] = {{CATEGORY_COLUMNS_Icon, "CATEGORY_COLUMNS_Icon", "icon"}, {CATEGORY_COLUMNS_Name, "CATEGORY_COLUMNS_Name", "name"}, {CATEGORY_COLUMNS_DisplayName, "CATEGORY_COLUMNS_DisplayName", "displayname"}, {CATEGORY_COLUMNS_NumOfCols, "CATEGORY_COLUMNS_NumOfCols", "numofcols"}, {0, NULL, NULL}};
		GType category_columns_type_id;
		category_columns_type_id = g_enum_register_static ("CategoryColumns", values);
		g_once_init_leave (&category_columns_type_id__volatile, category_columns_type_id);
	}
	return category_columns_type_id__volatile;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 90 "tracker-category-view.gs"
void tracker_category_view_selection_changed (TrackerCategoryView* self, GtkTreeSelection* sel) {
#line 130 "tracker-category-view.c"
	GtkTreeIter iter = {0};
	GtkTreeModel* model;
	GtkTreeModel* _tmp1_;
	GtkTreeModel* _tmp0_ = NULL;
	const char* name;
#line 90 "tracker-category-view.gs"
	g_return_if_fail (self != NULL);
#line 90 "tracker-category-view.gs"
	g_return_if_fail (sel != NULL);
#line 140 "tracker-category-view.c"
	model = NULL;
#line 94 "tracker-category-view.gs"
	gtk_tree_selection_get_selected (sel, &_tmp0_, &iter);
#line 94 "tracker-category-view.gs"
	model = (_tmp1_ = _g_object_ref0 (_tmp0_), _g_object_unref0 (model), _tmp1_);
#line 146 "tracker-category-view.c"
	name = NULL;
#line 98 "tracker-category-view.gs"
	gtk_tree_model_get ((GtkTreeModel*) self->store, &iter, CATEGORY_COLUMNS_Name, &name, -1);
#line 100 "tracker-category-view.gs"
	if (self->priv->_Query != NULL) {
#line 101 "tracker-category-view.gs"
		tracker_query_set_Category (self->priv->_Query, name);
#line 154 "tracker-category-view.c"
	}
	_g_object_unref0 (model);
}


#line 36 "tracker-category-view.gs"
TrackerCategoryView* tracker_category_view_construct (GType object_type) {
#line 162 "tracker-category-view.c"
	TrackerCategoryView * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


#line 36 "tracker-category-view.gs"
TrackerCategoryView* tracker_category_view_new (void) {
#line 36 "tracker-category-view.gs"
	return tracker_category_view_construct (TYPE_TRACKER_CATEGORY_VIEW);
#line 173 "tracker-category-view.c"
}


TrackerQuery* tracker_category_view_get_Query (TrackerCategoryView* self) {
	TrackerQuery* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_Query;
#line 42 "tracker-category-view.gs"
	return result;
#line 183 "tracker-category-view.c"
}


void tracker_category_view_set_Query (TrackerCategoryView* self, TrackerQuery* value) {
	g_return_if_fail (self != NULL);
	self->priv->_Query = value;
	g_object_notify ((GObject *) self, "Query");
}


#line 90 "tracker-category-view.gs"
static void _tracker_category_view_selection_changed_gtk_tree_selection_changed (GtkTreeSelection* _sender, gpointer self) {
#line 196 "tracker-category-view.c"
	tracker_category_view_selection_changed (self, _sender);
}


static GObject * tracker_category_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	TrackerCategoryView * self;
	parent_class = G_OBJECT_CLASS (tracker_category_view_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = TRACKER_CATEGORY_VIEW (obj);
	{
		GtkListStore* _tmp0_;
		GtkTreeIter iter = {0};
		GdkPixbuf* _tmp1_;
		GdkPixbuf* _tmp2_;
		GdkPixbuf* _tmp3_;
		GdkPixbuf* _tmp4_;
		GdkPixbuf* _tmp5_;
		GdkPixbuf* _tmp6_;
		GtkTreeView* _tmp7_;
		GtkCellRendererPixbuf* _tmp8_;
		GtkCellRendererText* _tmp9_;
		GtkTreeSelection* category_selection;
#line 46 "tracker-category-view.gs"
		g_object_set ((GtkScrolledWindow*) self, "hscrollbar-policy", GTK_POLICY_NEVER, NULL);
#line 47 "tracker-category-view.gs"
		g_object_set ((GtkScrolledWindow*) self, "vscrollbar-policy", GTK_POLICY_AUTOMATIC, NULL);
#line 48 "tracker-category-view.gs"
		gtk_scrolled_window_set_shadow_type ((GtkScrolledWindow*) self, GTK_SHADOW_ETCHED_OUT);
#line 50 "tracker-category-view.gs"
		self->store = (_tmp0_ = gtk_list_store_new ((gint) CATEGORY_COLUMNS_NumOfCols, GDK_TYPE_PIXBUF, G_TYPE_STRING, G_TYPE_STRING, NULL), _g_object_unref0 (self->store), _tmp0_);
#line 52 "tracker-category-view.gs"
		gtk_list_store_append (self->store, &iter);
#line 53 "tracker-category-view.gs"
		gtk_list_store_set (self->store, &iter, CATEGORY_COLUMNS_Icon, _tmp1_ = tracker_utils_GetThemePixbufByName ("system-file-manager", icon_size, gtk_widget_get_screen ((GtkWidget*) self)), CATEGORY_COLUMNS_Name, "All", CATEGORY_COLUMNS_DisplayName, N_ ("All Files"), -1, -1);
#line 233 "tracker-category-view.c"
		_g_object_unref0 (_tmp1_);
#line 56 "tracker-category-view.gs"
		gtk_list_store_append (self->store, &iter);
#line 57 "tracker-category-view.gs"
		gtk_list_store_set (self->store, &iter, CATEGORY_COLUMNS_Icon, _tmp2_ = tracker_utils_GetThemePixbufByName ("x-office-document", icon_size, gtk_widget_get_screen ((GtkWidget*) self)), CATEGORY_COLUMNS_Name, "nfo:Document", CATEGORY_COLUMNS_DisplayName, N_ ("Office Documents"), -1, -1);
#line 239 "tracker-category-view.c"
		_g_object_unref0 (_tmp2_);
#line 60 "tracker-category-view.gs"
		gtk_list_store_append (self->store, &iter);
#line 61 "tracker-category-view.gs"
		gtk_list_store_set (self->store, &iter, CATEGORY_COLUMNS_Icon, _tmp3_ = tracker_utils_GetThemePixbufByName ("image-x-generic", icon_size, gtk_widget_get_screen ((GtkWidget*) self)), CATEGORY_COLUMNS_Name, "nfo:Image", CATEGORY_COLUMNS_DisplayName, N_ ("Images"), -1, -1);
#line 245 "tracker-category-view.c"
		_g_object_unref0 (_tmp3_);
#line 64 "tracker-category-view.gs"
		gtk_list_store_append (self->store, &iter);
#line 65 "tracker-category-view.gs"
		gtk_list_store_set (self->store, &iter, CATEGORY_COLUMNS_Icon, _tmp4_ = tracker_utils_GetThemePixbufByName ("audio-x-generic", icon_size, gtk_widget_get_screen ((GtkWidget*) self)), CATEGORY_COLUMNS_Name, "nmm:MusicPiece", CATEGORY_COLUMNS_DisplayName, N_ ("Music"), -1, -1);
#line 251 "tracker-category-view.c"
		_g_object_unref0 (_tmp4_);
#line 68 "tracker-category-view.gs"
		gtk_list_store_append (self->store, &iter);
#line 69 "tracker-category-view.gs"
		gtk_list_store_set (self->store, &iter, CATEGORY_COLUMNS_Icon, _tmp5_ = tracker_utils_GetThemePixbufByName ("video-x-generic", icon_size, gtk_widget_get_screen ((GtkWidget*) self)), CATEGORY_COLUMNS_Name, "nmm:Video", CATEGORY_COLUMNS_DisplayName, N_ ("Videos"), -1, -1);
#line 257 "tracker-category-view.c"
		_g_object_unref0 (_tmp5_);
#line 72 "tracker-category-view.gs"
		gtk_list_store_append (self->store, &iter);
#line 73 "tracker-category-view.gs"
		gtk_list_store_set (self->store, &iter, CATEGORY_COLUMNS_Icon, _tmp6_ = tracker_utils_GetThemePixbufByName ("system-run", icon_size, gtk_widget_get_screen ((GtkWidget*) self)), CATEGORY_COLUMNS_Name, "nfo:SoftwareApplication", CATEGORY_COLUMNS_DisplayName, N_ ("Applications"), -1, -1);
#line 263 "tracker-category-view.c"
		_g_object_unref0 (_tmp6_);
#line 76 "tracker-category-view.gs"
		self->treeview = (_tmp7_ = g_object_ref_sink ((GtkTreeView*) gtk_tree_view_new_with_model ((GtkTreeModel*) self->store)), _g_object_unref0 (self->treeview), _tmp7_);
#line 77 "tracker-category-view.gs"
		gtk_tree_view_insert_column_with_attributes (self->treeview, -1, "icon", (GtkCellRenderer*) (_tmp8_ = g_object_ref_sink ((GtkCellRendererPixbuf*) gtk_cell_renderer_pixbuf_new ())), "pixbuf", 0, NULL, NULL);
#line 269 "tracker-category-view.c"
		_g_object_unref0 (_tmp8_);
#line 78 "tracker-category-view.gs"
		gtk_tree_view_insert_column_with_attributes (self->treeview, -1, "name", (GtkCellRenderer*) (_tmp9_ = g_object_ref_sink ((GtkCellRendererText*) gtk_cell_renderer_text_new ())), "text", 2, NULL, NULL);
#line 273 "tracker-category-view.c"
		_g_object_unref0 (_tmp9_);
#line 79 "tracker-category-view.gs"
		gtk_tree_view_set_headers_visible (self->treeview, FALSE);
#line 81 "tracker-category-view.gs"
		category_selection = _g_object_ref0 (gtk_tree_view_get_selection (self->treeview));
#line 82 "tracker-category-view.gs"
		gtk_tree_selection_set_mode (category_selection, GTK_SELECTION_BROWSE);
#line 84 "tracker-category-view.gs"
		g_signal_connect_object (category_selection, "changed", (GCallback) _tracker_category_view_selection_changed_gtk_tree_selection_changed, self, 0);
#line 86 "tracker-category-view.gs"
		gtk_container_add ((GtkContainer*) self, (GtkWidget*) self->treeview);
#line 88 "tracker-category-view.gs"
		gtk_widget_show_all ((GtkWidget*) self);
#line 287 "tracker-category-view.c"
		_g_object_unref0 (category_selection);
	}
	return obj;
}


static void tracker_category_view_class_init (TrackerCategoryViewClass * klass) {
	tracker_category_view_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (TrackerCategoryViewPrivate));
	G_OBJECT_CLASS (klass)->get_property = tracker_category_view_get_property;
	G_OBJECT_CLASS (klass)->set_property = tracker_category_view_set_property;
	G_OBJECT_CLASS (klass)->constructor = tracker_category_view_constructor;
	G_OBJECT_CLASS (klass)->finalize = tracker_category_view_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), TRACKER_CATEGORY_VIEW_QUERY, g_param_spec_object ("Query", "Query", "Query", TYPE_TRACKER_QUERY, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void tracker_category_view_instance_init (TrackerCategoryView * self) {
	self->priv = TRACKER_CATEGORY_VIEW_GET_PRIVATE (self);
}


static void tracker_category_view_finalize (GObject* obj) {
	TrackerCategoryView * self;
	self = TRACKER_CATEGORY_VIEW (obj);
	_g_object_unref0 (self->store);
	_g_object_unref0 (self->treeview);
	_g_object_unref0 (self->lab);
	G_OBJECT_CLASS (tracker_category_view_parent_class)->finalize (obj);
}


GType tracker_category_view_get_type (void) {
	static volatile gsize tracker_category_view_type_id__volatile = 0;
	if (g_once_init_enter (&tracker_category_view_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (TrackerCategoryViewClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) tracker_category_view_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TrackerCategoryView), 0, (GInstanceInitFunc) tracker_category_view_instance_init, NULL };
		GType tracker_category_view_type_id;
		tracker_category_view_type_id = g_type_register_static (GTK_TYPE_SCROLLED_WINDOW, "TrackerCategoryView", &g_define_type_info, 0);
		g_once_init_leave (&tracker_category_view_type_id__volatile, tracker_category_view_type_id);
	}
	return tracker_category_view_type_id__volatile;
}


static void tracker_category_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	TrackerCategoryView * self;
	self = TRACKER_CATEGORY_VIEW (object);
	switch (property_id) {
		case TRACKER_CATEGORY_VIEW_QUERY:
		g_value_set_object (value, tracker_category_view_get_Query (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void tracker_category_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	TrackerCategoryView * self;
	self = TRACKER_CATEGORY_VIEW (object);
	switch (property_id) {
		case TRACKER_CATEGORY_VIEW_QUERY:
		tracker_category_view_set_Query (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



