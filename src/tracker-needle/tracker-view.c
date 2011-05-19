/* tracker-view.c generated by valac 0.12.0, the Vala compiler
 * generated from tracker-view.vala, do not modify */

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
#include <gtk/gtk.h>
#include <glib/gi18n-lib.h>
#include <stdlib.h>
#include <string.h>
#include <pango/pango.h>
#include <float.h>
#include <math.h>
#include <gdk/gdk.h>


#define TRACKER_TYPE_VIEW (tracker_view_get_type ())
#define TRACKER_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TRACKER_TYPE_VIEW, TrackerView))
#define TRACKER_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TRACKER_TYPE_VIEW, TrackerViewClass))
#define TRACKER_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TRACKER_TYPE_VIEW))
#define TRACKER_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TRACKER_TYPE_VIEW))
#define TRACKER_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TRACKER_TYPE_VIEW, TrackerViewClass))

typedef struct _TrackerView TrackerView;
typedef struct _TrackerViewClass TrackerViewClass;
typedef struct _TrackerViewPrivate TrackerViewPrivate;

#define TRACKER_VIEW_TYPE_DISPLAY (tracker_view_display_get_type ())

#define TRACKER_TYPE_RESULT_STORE (tracker_result_store_get_type ())
#define TRACKER_RESULT_STORE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TRACKER_TYPE_RESULT_STORE, TrackerResultStore))
#define TRACKER_RESULT_STORE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TRACKER_TYPE_RESULT_STORE, TrackerResultStoreClass))
#define TRACKER_IS_RESULT_STORE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TRACKER_TYPE_RESULT_STORE))
#define TRACKER_IS_RESULT_STORE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TRACKER_TYPE_RESULT_STORE))
#define TRACKER_RESULT_STORE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TRACKER_TYPE_RESULT_STORE, TrackerResultStoreClass))

typedef struct _TrackerResultStore TrackerResultStore;
typedef struct _TrackerResultStoreClass TrackerResultStoreClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _gtk_tree_path_free0(var) ((var == NULL) ? NULL : (var = (gtk_tree_path_free (var), NULL)))

#define TRACKER_QUERY_TYPE_TYPE (tracker_query_type_get_type ())

struct _TrackerView {
	GtkScrolledWindow parent_instance;
	TrackerViewPrivate * priv;
};

struct _TrackerViewClass {
	GtkScrolledWindowClass parent_class;
};

typedef enum  {
	TRACKER_VIEW_DISPLAY_NO_RESULTS,
	TRACKER_VIEW_DISPLAY_CATEGORIES,
	TRACKER_VIEW_DISPLAY_FILE_LIST,
	TRACKER_VIEW_DISPLAY_FILE_ICONS
} TrackerViewDisplay;

struct _TrackerViewPrivate {
	TrackerViewDisplay _display;
	TrackerResultStore* _store;
	GtkWidget* view;
};

typedef enum  {
	TRACKER_QUERY_TYPE_ALL,
	TRACKER_QUERY_TYPE_CONTACTS,
	TRACKER_QUERY_TYPE_APPLICATIONS,
	TRACKER_QUERY_TYPE_MUSIC,
	TRACKER_QUERY_TYPE_IMAGES,
	TRACKER_QUERY_TYPE_VIDEOS,
	TRACKER_QUERY_TYPE_DOCUMENTS,
	TRACKER_QUERY_TYPE_MAIL,
	TRACKER_QUERY_TYPE_CALENDAR,
	TRACKER_QUERY_TYPE_FOLDERS
} TrackerQueryType;


static gpointer tracker_view_parent_class = NULL;

GType tracker_view_get_type (void) G_GNUC_CONST;
GType tracker_view_display_get_type (void) G_GNUC_CONST;
GType tracker_result_store_get_type (void) G_GNUC_CONST;
#define TRACKER_VIEW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TRACKER_TYPE_VIEW, TrackerViewPrivate))
enum  {
	TRACKER_VIEW_DUMMY_PROPERTY,
	TRACKER_VIEW_DISPLAY,
	TRACKER_VIEW_STORE
};
static void tracker_view_store_row_changed (TrackerView* self, GtkTreeModel* model, GtkTreePath* path, GtkTreeIter* iter);
static gboolean tracker_view_row_selection_func (TrackerView* self, GtkTreeSelection* selection, GtkTreeModel* model, GtkTreePath* path, gboolean path_selected);
static void tracker_view_real_unmap (GtkWidget* base);
TrackerResultStore* tracker_view_get_store (TrackerView* self);
void tracker_result_store_cancel_search (TrackerResultStore* self);
TrackerView* tracker_view_new (TrackerViewDisplay* _display, TrackerResultStore* store);
TrackerView* tracker_view_construct (GType object_type, TrackerViewDisplay* _display, TrackerResultStore* store);
static void tracker_view_set_display (TrackerView* self, TrackerViewDisplay value);
static void _tracker_view_store_row_changed_gtk_tree_model_row_changed (GtkTreeModel* _sender, GtkTreePath* path, GtkTreeIter* iter, gpointer self);
TrackerViewDisplay tracker_view_get_display (TrackerView* self);
static void tracker_view_setup_model (TrackerView* self);
static void tracker_view_renderer_background_func (TrackerView* self, GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter);
static void _tracker_view_renderer_background_func_gtk_cell_layout_data_func (GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter, gpointer self);
static void tracker_view_text_renderer_func (TrackerView* self, GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter);
static void _tracker_view_text_renderer_func_gtk_cell_layout_data_func (GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter, gpointer self);
static void tracker_view_file_date_renderer_func (TrackerView* self, GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter);
static void _tracker_view_file_date_renderer_func_gtk_cell_layout_data_func (GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter, gpointer self);
static void tracker_view_file_size_renderer_func (TrackerView* self, GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter);
static void _tracker_view_file_size_renderer_func_gtk_cell_layout_data_func (GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter, gpointer self);
static gboolean _tracker_view_row_selection_func_gtk_tree_selection_func (GtkTreeSelection* selection, GtkTreeModel* model, GtkTreePath* path, gboolean path_currently_selected, gpointer self);
static void tracker_view_category_detail_renderer_func (TrackerView* self, GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter);
static void _tracker_view_category_detail_renderer_func_gtk_cell_layout_data_func (GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter, gpointer self);
GType tracker_query_type_get_type (void) G_GNUC_CONST;
gchar* tracker_time_format_from_iso8601 (const gchar* s);
gchar* tracker_time_format_from_seconds (const gchar* seconds_str);
void tracker_view_set_store (TrackerView* self, TrackerResultStore* value);
static void tracker_view_finalize (GObject* obj);
static void _vala_tracker_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_tracker_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


GType tracker_view_display_get_type (void) {
	static volatile gsize tracker_view_display_type_id__volatile = 0;
	if (g_once_init_enter (&tracker_view_display_type_id__volatile)) {
		static const GEnumValue values[] = {{TRACKER_VIEW_DISPLAY_NO_RESULTS, "TRACKER_VIEW_DISPLAY_NO_RESULTS", "no-results"}, {TRACKER_VIEW_DISPLAY_CATEGORIES, "TRACKER_VIEW_DISPLAY_CATEGORIES", "categories"}, {TRACKER_VIEW_DISPLAY_FILE_LIST, "TRACKER_VIEW_DISPLAY_FILE_LIST", "file-list"}, {TRACKER_VIEW_DISPLAY_FILE_ICONS, "TRACKER_VIEW_DISPLAY_FILE_ICONS", "file-icons"}, {0, NULL, NULL}};
		GType tracker_view_display_type_id;
		tracker_view_display_type_id = g_enum_register_static ("TrackerViewDisplay", values);
		g_once_init_leave (&tracker_view_display_type_id__volatile, tracker_view_display_type_id);
	}
	return tracker_view_display_type_id__volatile;
}


static void tracker_view_store_row_changed (TrackerView* self, GtkTreeModel* model, GtkTreePath* path, GtkTreeIter* iter) {
	gint _tmp0_;
	gint n_children;
	g_return_if_fail (self != NULL);
	g_return_if_fail (model != NULL);
	g_return_if_fail (path != NULL);
	_tmp0_ = gtk_tree_model_iter_n_children (model, iter);
	n_children = _tmp0_;
	if (n_children > 0) {
		gtk_tree_view_expand_row (GTK_TREE_VIEW (self->priv->view), path, FALSE);
	}
}


static gboolean tracker_view_row_selection_func (TrackerView* self, GtkTreeSelection* selection, GtkTreeModel* model, GtkTreePath* path, gboolean path_selected) {
	gboolean result = FALSE;
	gint _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (selection != NULL, FALSE);
	g_return_val_if_fail (model != NULL, FALSE);
	g_return_val_if_fail (path != NULL, FALSE);
	_tmp0_ = gtk_tree_path_get_depth (path);
	if (_tmp0_ == 1) {
		result = FALSE;
		return result;
	}
	result = TRUE;
	return result;
}


static void tracker_view_real_unmap (GtkWidget* base) {
	TrackerView * self;
	TrackerResultStore* _tmp0_ = NULL;
	self = (TrackerView*) base;
	_tmp0_ = tracker_view_get_store (self);
	if (_tmp0_ != NULL) {
		TrackerResultStore* _tmp1_ = NULL;
		_tmp1_ = tracker_view_get_store (self);
		tracker_result_store_cancel_search (_tmp1_);
	}
	GTK_WIDGET_CLASS (tracker_view_parent_class)->unmap ((GtkWidget*) GTK_SCROLLED_WINDOW (self));
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _tracker_view_store_row_changed_gtk_tree_model_row_changed (GtkTreeModel* _sender, GtkTreePath* path, GtkTreeIter* iter, gpointer self) {
	tracker_view_store_row_changed (self, _sender, path, iter);
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


TrackerView* tracker_view_construct (GType object_type, TrackerViewDisplay* _display, TrackerResultStore* store) {
	TrackerView * self = NULL;
	self = (TrackerView*) g_object_new (object_type, NULL);
	gtk_scrolled_window_set_policy ((GtkScrolledWindow*) self, GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
	tracker_view_set_display (self, *_display);
	if (store != NULL) {
		TrackerResultStore* _tmp0_;
		_tmp0_ = _g_object_ref0 (store);
		_g_object_unref0 (self->priv->_store);
		self->priv->_store = _tmp0_;
		g_signal_connect_object ((GtkTreeModel*) store, "row-changed", (GCallback) _tracker_view_store_row_changed_gtk_tree_model_row_changed, self, 0);
		g_debug ("tracker-view.vala:100: using store:%p", store);
	}
	switch (self->priv->_display) {
		case TRACKER_VIEW_DISPLAY_NO_RESULTS:
		{
			GtkLabel* l = NULL;
			GtkLabel* _tmp1_ = NULL;
			const gchar* _tmp2_ = NULL;
			gchar* _tmp3_;
			gchar* message;
			const gchar* _tmp4_ = NULL;
			gchar* _tmp5_ = NULL;
			gchar* markup;
			GtkWidget* _tmp6_;
			_tmp1_ = (GtkLabel*) gtk_label_new ("");
			_g_object_unref0 (l);
			l = g_object_ref_sink (_tmp1_);
			_tmp2_ = _ ("No Search Results");
			_tmp3_ = g_strdup (_tmp2_);
			message = _tmp3_;
			_tmp4_ = string_to_string (message);
			_tmp5_ = g_strconcat ("<big>", _tmp4_, "</big>", NULL);
			markup = _tmp5_;
			gtk_label_set_use_markup (l, TRUE);
			gtk_label_set_markup (l, markup);
			_tmp6_ = _g_object_ref0 ((GtkWidget*) l);
			_g_object_unref0 (self->priv->view);
			self->priv->view = _tmp6_;
			_g_free0 (markup);
			_g_free0 (message);
			_g_object_unref0 (l);
			break;
		}
		case TRACKER_VIEW_DISPLAY_CATEGORIES:
		case TRACKER_VIEW_DISPLAY_FILE_LIST:
		{
			GtkTreeView* _tmp7_ = NULL;
			_tmp7_ = (GtkTreeView*) gtk_tree_view_new ();
			_g_object_unref0 (self->priv->view);
			self->priv->view = (GtkWidget*) g_object_ref_sink (_tmp7_);
			break;
		}
		case TRACKER_VIEW_DISPLAY_FILE_ICONS:
		{
			GtkIconView* _tmp8_ = NULL;
			_tmp8_ = (GtkIconView*) gtk_icon_view_new ();
			_g_object_unref0 (self->priv->view);
			self->priv->view = (GtkWidget*) g_object_ref_sink (_tmp8_);
			break;
		}
		default:
		break;
	}
	if (self->priv->_display == TRACKER_VIEW_DISPLAY_NO_RESULTS) {
		gtk_scrolled_window_add_with_viewport ((GtkScrolledWindow*) self, self->priv->view);
	} else {
		gtk_container_add ((GtkContainer*) self, self->priv->view);
		tracker_view_setup_model (self);
	}
	GTK_WIDGET_CLASS (tracker_view_parent_class)->show_all ((GtkWidget*) GTK_SCROLLED_WINDOW (self));
	return self;
}


TrackerView* tracker_view_new (TrackerViewDisplay* _display, TrackerResultStore* store) {
	return tracker_view_construct (TRACKER_TYPE_VIEW, _display, store);
}


static void _tracker_view_renderer_background_func_gtk_cell_layout_data_func (GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter, gpointer self) {
	tracker_view_renderer_background_func (self, cell_layout, cell, tree_model, iter);
}


static void _tracker_view_text_renderer_func_gtk_cell_layout_data_func (GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter, gpointer self) {
	tracker_view_text_renderer_func (self, cell_layout, cell, tree_model, iter);
}


static void _tracker_view_file_date_renderer_func_gtk_cell_layout_data_func (GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter, gpointer self) {
	tracker_view_file_date_renderer_func (self, cell_layout, cell, tree_model, iter);
}


static void _tracker_view_file_size_renderer_func_gtk_cell_layout_data_func (GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter, gpointer self) {
	tracker_view_file_size_renderer_func (self, cell_layout, cell, tree_model, iter);
}


static gboolean _tracker_view_row_selection_func_gtk_tree_selection_func (GtkTreeSelection* selection, GtkTreeModel* model, GtkTreePath* path, gboolean path_currently_selected, gpointer self) {
	gboolean result;
	result = tracker_view_row_selection_func (self, selection, model, path, path_currently_selected);
	return result;
}


static void _tracker_view_category_detail_renderer_func_gtk_cell_layout_data_func (GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter, gpointer self) {
	tracker_view_category_detail_renderer_func (self, cell_layout, cell, tree_model, iter);
}


static void tracker_view_setup_model (TrackerView* self) {
	g_return_if_fail (self != NULL);
	switch (self->priv->_display) {
		case TRACKER_VIEW_DISPLAY_FILE_ICONS:
		{
			{
				GtkIconView* _tmp0_;
				GtkIconView* iv;
				TrackerResultStore* _tmp1_ = NULL;
				_tmp0_ = _g_object_ref0 (GTK_ICON_VIEW (self->priv->view));
				iv = _tmp0_;
				_tmp1_ = tracker_view_get_store (self);
				gtk_icon_view_set_model (iv, (GtkTreeModel*) _tmp1_);
				gtk_icon_view_set_item_width (iv, 128);
				gtk_icon_view_set_item_padding (iv, 1);
				gtk_icon_view_set_row_spacing (iv, 2);
				gtk_icon_view_set_column_spacing (iv, 2);
				gtk_icon_view_set_selection_mode (iv, GTK_SELECTION_SINGLE);
				gtk_icon_view_set_pixbuf_column (iv, 6);
				gtk_icon_view_set_text_column (iv, -1);
				gtk_icon_view_set_tooltip_column (iv, 5);
				_g_object_unref0 (iv);
				break;
			}
		}
		case TRACKER_VIEW_DISPLAY_FILE_LIST:
		{
			{
				GtkTreeViewColumn* col = NULL;
				GtkTreeView* _tmp2_;
				GtkTreeView* tv;
				TrackerResultStore* _tmp3_ = NULL;
				GtkCellRendererPixbuf* _tmp4_ = NULL;
				GtkCellRendererPixbuf* renderer1;
				GtkCellRendererText* _tmp5_ = NULL;
				GtkCellRendererText* renderer2;
				GtkTreeViewColumn* _tmp6_ = NULL;
				const gchar* _tmp7_ = NULL;
				GtkCellRendererText* _tmp8_ = NULL;
				GtkCellRendererText* renderer3;
				GtkTreeViewColumn* _tmp9_ = NULL;
				const gchar* _tmp10_ = NULL;
				GtkCellRendererText* _tmp11_ = NULL;
				GtkCellRendererText* renderer4;
				GtkTreeViewColumn* _tmp12_ = NULL;
				const gchar* _tmp13_ = NULL;
				_tmp2_ = _g_object_ref0 (GTK_TREE_VIEW (self->priv->view));
				tv = _tmp2_;
				_tmp3_ = tracker_view_get_store (self);
				gtk_tree_view_set_model (tv, (GtkTreeModel*) _tmp3_);
				gtk_tree_view_set_tooltip_column (tv, 6);
				gtk_tree_view_set_rules_hint (tv, FALSE);
				gtk_tree_view_set_grid_lines (tv, GTK_TREE_VIEW_GRID_LINES_VERTICAL);
				gtk_tree_view_set_headers_visible (tv, TRUE);
				_tmp4_ = (GtkCellRendererPixbuf*) gtk_cell_renderer_pixbuf_new ();
				renderer1 = g_object_ref_sink (_tmp4_);
				_tmp5_ = (GtkCellRendererText*) gtk_cell_renderer_text_new ();
				renderer2 = g_object_ref_sink (_tmp5_);
				_tmp6_ = gtk_tree_view_column_new ();
				_g_object_unref0 (col);
				col = g_object_ref_sink (_tmp6_);
				gtk_tree_view_column_set_sizing (col, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
				gtk_cell_layout_pack_start ((GtkCellLayout*) col, (GtkCellRenderer*) renderer1, FALSE);
				gtk_cell_layout_add_attribute ((GtkCellLayout*) col, (GtkCellRenderer*) renderer1, "pixbuf", 7);
				g_object_set ((GtkCellRenderer*) renderer1, "xpad", (guint) 5, NULL);
				g_object_set ((GtkCellRenderer*) renderer1, "ypad", (guint) 5, NULL);
				gtk_cell_layout_pack_start ((GtkCellLayout*) col, (GtkCellRenderer*) renderer2, TRUE);
				gtk_cell_renderer_text_set_fixed_height_from_font (renderer2, 2);
				g_object_set (renderer2, "ellipsize", PANGO_ELLIPSIZE_MIDDLE, NULL);
				_tmp7_ = _ ("File");
				gtk_tree_view_column_set_title (col, _tmp7_);
				gtk_tree_view_column_set_resizable (col, TRUE);
				gtk_tree_view_column_set_expand (col, TRUE);
				gtk_cell_layout_set_cell_data_func ((GtkCellLayout*) col, (GtkCellRenderer*) renderer1, _tracker_view_renderer_background_func_gtk_cell_layout_data_func, g_object_ref (self), g_object_unref);
				gtk_cell_layout_set_cell_data_func ((GtkCellLayout*) col, (GtkCellRenderer*) renderer2, _tracker_view_text_renderer_func_gtk_cell_layout_data_func, g_object_ref (self), g_object_unref);
				gtk_tree_view_append_column (tv, col);
				_tmp8_ = (GtkCellRendererText*) gtk_cell_renderer_text_new ();
				renderer3 = g_object_ref_sink (_tmp8_);
				gtk_cell_renderer_text_set_fixed_height_from_font (renderer3, 2);
				_tmp9_ = gtk_tree_view_column_new ();
				_g_object_unref0 (col);
				col = g_object_ref_sink (_tmp9_);
				gtk_tree_view_column_set_sizing (col, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
				gtk_cell_layout_pack_start ((GtkCellLayout*) col, (GtkCellRenderer*) renderer3, TRUE);
				_tmp10_ = _ ("Last Changed");
				gtk_tree_view_column_set_title (col, _tmp10_);
				gtk_cell_layout_set_cell_data_func ((GtkCellLayout*) col, (GtkCellRenderer*) renderer3, _tracker_view_file_date_renderer_func_gtk_cell_layout_data_func, g_object_ref (self), g_object_unref);
				gtk_tree_view_append_column (tv, col);
				_tmp11_ = (GtkCellRendererText*) gtk_cell_renderer_text_new ();
				renderer4 = g_object_ref_sink (_tmp11_);
				gtk_cell_renderer_text_set_fixed_height_from_font (renderer4, 2);
				_tmp12_ = gtk_tree_view_column_new ();
				_g_object_unref0 (col);
				col = g_object_ref_sink (_tmp12_);
				gtk_tree_view_column_set_sizing (col, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
				gtk_cell_layout_pack_start ((GtkCellLayout*) col, (GtkCellRenderer*) renderer4, TRUE);
				_tmp13_ = _ ("Size");
				gtk_tree_view_column_set_title (col, _tmp13_);
				gtk_cell_layout_set_cell_data_func ((GtkCellLayout*) col, (GtkCellRenderer*) renderer4, _tracker_view_file_size_renderer_func_gtk_cell_layout_data_func, g_object_ref (self), g_object_unref);
				gtk_tree_view_append_column (tv, col);
				_g_object_unref0 (renderer4);
				_g_object_unref0 (renderer3);
				_g_object_unref0 (renderer2);
				_g_object_unref0 (renderer1);
				_g_object_unref0 (tv);
				_g_object_unref0 (col);
				break;
			}
		}
		case TRACKER_VIEW_DISPLAY_CATEGORIES:
		{
			{
				GtkTreeViewColumn* col = NULL;
				GtkTreeView* _tmp14_;
				GtkTreeView* tv;
				GtkTreeSelection* selection = NULL;
				TrackerResultStore* _tmp15_ = NULL;
				GtkTreeSelection* _tmp16_ = NULL;
				GtkTreeSelection* _tmp17_;
				GtkTreeViewColumn* _tmp18_ = NULL;
				GtkCellRendererPixbuf* _tmp19_ = NULL;
				GtkCellRendererPixbuf* renderer1;
				GtkCellRendererText* _tmp20_ = NULL;
				GtkCellRendererText* renderer2;
				GtkCellRendererText* _tmp21_ = NULL;
				GtkCellRendererText* renderer4;
				GtkTreeViewColumn* _tmp22_ = NULL;
				_tmp14_ = _g_object_ref0 (GTK_TREE_VIEW (self->priv->view));
				tv = _tmp14_;
				_tmp15_ = tracker_view_get_store (self);
				gtk_tree_view_set_model (tv, (GtkTreeModel*) _tmp15_);
				gtk_tree_view_set_tooltip_column (tv, 5);
				gtk_tree_view_set_rules_hint (tv, FALSE);
				gtk_tree_view_set_grid_lines (tv, GTK_TREE_VIEW_GRID_LINES_NONE);
				gtk_tree_view_set_headers_visible (tv, FALSE);
				gtk_tree_view_set_show_expanders (tv, FALSE);
				_tmp16_ = gtk_tree_view_get_selection (tv);
				_tmp17_ = _g_object_ref0 (_tmp16_);
				_g_object_unref0 (selection);
				selection = _tmp17_;
				gtk_tree_selection_set_select_function (selection, _tracker_view_row_selection_func_gtk_tree_selection_func, g_object_ref (self), g_object_unref);
				_tmp18_ = gtk_tree_view_column_new ();
				_g_object_unref0 (col);
				col = g_object_ref_sink (_tmp18_);
				gtk_tree_view_column_set_sizing (col, GTK_TREE_VIEW_COLUMN_FIXED);
				gtk_tree_view_column_set_expand (col, TRUE);
				_tmp19_ = (GtkCellRendererPixbuf*) gtk_cell_renderer_pixbuf_new ();
				renderer1 = g_object_ref_sink (_tmp19_);
				gtk_cell_layout_pack_start ((GtkCellLayout*) col, (GtkCellRenderer*) renderer1, FALSE);
				gtk_cell_layout_add_attribute ((GtkCellLayout*) col, (GtkCellRenderer*) renderer1, "pixbuf", 6);
				gtk_cell_layout_set_cell_data_func ((GtkCellLayout*) col, (GtkCellRenderer*) renderer1, _tracker_view_renderer_background_func_gtk_cell_layout_data_func, g_object_ref (self), g_object_unref);
				g_object_set ((GtkCellRenderer*) renderer1, "xpad", (guint) 5, NULL);
				g_object_set ((GtkCellRenderer*) renderer1, "ypad", (guint) 5, NULL);
				_tmp20_ = (GtkCellRendererText*) gtk_cell_renderer_text_new ();
				renderer2 = g_object_ref_sink (_tmp20_);
				gtk_cell_layout_pack_start ((GtkCellLayout*) col, (GtkCellRenderer*) renderer2, TRUE);
				gtk_cell_layout_set_cell_data_func ((GtkCellLayout*) col, (GtkCellRenderer*) renderer2, _tracker_view_text_renderer_func_gtk_cell_layout_data_func, g_object_ref (self), g_object_unref);
				gtk_cell_renderer_text_set_fixed_height_from_font (renderer2, 2);
				g_object_set (renderer2, "ellipsize", PANGO_ELLIPSIZE_MIDDLE, NULL);
				gtk_tree_view_append_column (tv, col);
				_tmp21_ = (GtkCellRendererText*) gtk_cell_renderer_text_new ();
				renderer4 = g_object_ref_sink (_tmp21_);
				gtk_cell_renderer_text_set_fixed_height_from_font (renderer4, 2);
				g_object_set (renderer4, "alignment", PANGO_ALIGN_RIGHT, NULL);
				g_object_set ((GtkCellRenderer*) renderer4, "xalign", (gfloat) 1, NULL);
				_tmp22_ = gtk_tree_view_column_new ();
				_g_object_unref0 (col);
				col = g_object_ref_sink (_tmp22_);
				gtk_tree_view_column_set_min_width (col, 80);
				gtk_tree_view_column_set_sizing (col, GTK_TREE_VIEW_COLUMN_FIXED);
				gtk_cell_layout_pack_start ((GtkCellLayout*) col, (GtkCellRenderer*) renderer4, TRUE);
				gtk_cell_layout_set_cell_data_func ((GtkCellLayout*) col, (GtkCellRenderer*) renderer4, _tracker_view_category_detail_renderer_func_gtk_cell_layout_data_func, g_object_ref (self), g_object_unref);
				gtk_tree_view_append_column (tv, col);
				_g_object_unref0 (renderer4);
				_g_object_unref0 (renderer2);
				_g_object_unref0 (renderer1);
				_g_object_unref0 (selection);
				_g_object_unref0 (tv);
				_g_object_unref0 (col);
				break;
			}
		}
		default:
		break;
	}
}


static void tracker_view_renderer_background_func (TrackerView* self, GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter) {
	GdkColor color = {0};
	GtkStyle* style = NULL;
	GtkTreePath* path = NULL;
	GtkStyle* _tmp0_ = NULL;
	GtkStyle* _tmp1_;
	gint sum_normal;
	gint sum_selected;
	GtkTreePath* _tmp2_ = NULL;
	gint* _tmp3_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (cell_layout != NULL);
	g_return_if_fail (cell != NULL);
	g_return_if_fail (tree_model != NULL);
	_tmp0_ = gtk_widget_get_style (self->priv->view);
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (style);
	style = _tmp1_;
	color = style->base[GTK_STATE_SELECTED];
	sum_normal = (gint) ((color.red + color.green) + color.blue);
	color = style->base[GTK_STATE_NORMAL];
	sum_selected = (gint) ((color.red + color.green) + color.blue);
	color = style->text_aa[GTK_STATE_INSENSITIVE];
	if (sum_normal < sum_selected) {
		color.red = (guint16) ((color.red + style->white.red) / 2);
		color.green = (guint16) ((color.green + style->white.green) / 2);
		color.blue = (guint16) ((color.blue + style->white.blue) / 2);
	} else {
		color.red = (guint16) ((color.red + style->black.red) / 2);
		color.green = (guint16) ((color.green + style->black.green) / 2);
		color.blue = (guint16) ((color.blue + style->black.blue) / 2);
	}
	_tmp2_ = gtk_tree_model_get_path (tree_model, iter);
	_gtk_tree_path_free0 (path);
	path = _tmp2_;
	_tmp3_ = gtk_tree_path_get_indices (path);
	if ((_tmp3_[0] % 2) != 0) {
		g_object_set ((GObject*) cell, "cell-background-gdk", &color, NULL);
	} else {
		g_object_set ((GObject*) cell, "cell-background-gdk", NULL, NULL);
	}
	_gtk_tree_path_free0 (path);
	_g_object_unref0 (style);
}


static void tracker_view_text_renderer_func (TrackerView* self, GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter) {
	gchar* text = NULL;
	gchar* subtext = NULL;
	gchar* markup;
	gint n_children = 0;
	gint _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (cell_layout != NULL);
	g_return_if_fail (cell != NULL);
	g_return_if_fail (tree_model != NULL);
	markup = NULL;
	tracker_view_renderer_background_func (self, cell_layout, cell, tree_model, iter);
	_tmp0_ = gtk_tree_model_iter_n_children (tree_model, iter);
	n_children = _tmp0_;
	if (n_children > 0) {
		TrackerQueryType type = 0;
		gchar* cat;
		const gchar* _tmp15_ = NULL;
		gchar* _tmp16_ = NULL;
		cat = NULL;
		gtk_tree_model_get (tree_model, iter, 7, &type, -1, -1);
		switch (type) {
			case TRACKER_QUERY_TYPE_APPLICATIONS:
			{
				const gchar* _tmp1_ = NULL;
				gchar* _tmp2_;
				_tmp1_ = _ ("Applications");
				_tmp2_ = g_strdup (_tmp1_);
				_g_free0 (cat);
				cat = _tmp2_;
				break;
			}
			case TRACKER_QUERY_TYPE_MUSIC:
			{
				const gchar* _tmp3_ = NULL;
				gchar* _tmp4_;
				_tmp3_ = _ ("Music");
				_tmp4_ = g_strdup (_tmp3_);
				_g_free0 (cat);
				cat = _tmp4_;
				break;
			}
			case TRACKER_QUERY_TYPE_IMAGES:
			{
				const gchar* _tmp5_ = NULL;
				gchar* _tmp6_;
				_tmp5_ = _ ("Images");
				_tmp6_ = g_strdup (_tmp5_);
				_g_free0 (cat);
				cat = _tmp6_;
				break;
			}
			case TRACKER_QUERY_TYPE_VIDEOS:
			{
				const gchar* _tmp7_ = NULL;
				gchar* _tmp8_;
				_tmp7_ = _ ("Videos");
				_tmp8_ = g_strdup (_tmp7_);
				_g_free0 (cat);
				cat = _tmp8_;
				break;
			}
			case TRACKER_QUERY_TYPE_DOCUMENTS:
			{
				const gchar* _tmp9_ = NULL;
				gchar* _tmp10_;
				_tmp9_ = _ ("Documents");
				_tmp10_ = g_strdup (_tmp9_);
				_g_free0 (cat);
				cat = _tmp10_;
				break;
			}
			case TRACKER_QUERY_TYPE_MAIL:
			{
				const gchar* _tmp11_ = NULL;
				gchar* _tmp12_;
				_tmp11_ = _ ("Mail");
				_tmp12_ = g_strdup (_tmp11_);
				_g_free0 (cat);
				cat = _tmp12_;
				break;
			}
			case TRACKER_QUERY_TYPE_FOLDERS:
			{
				const gchar* _tmp13_ = NULL;
				gchar* _tmp14_;
				_tmp13_ = _ ("Folders");
				_tmp14_ = g_strdup (_tmp13_);
				_g_free0 (cat);
				cat = _tmp14_;
				break;
			}
			default:
			break;
		}
		_tmp15_ = _ ("Items");
		_tmp16_ = g_strdup_printf ("<b><big>%s</big></b> <small>(%d %s)</small>", cat, n_children, _tmp15_);
		_g_free0 (markup);
		markup = _tmp16_;
		_g_free0 (cat);
	} else {
		gtk_tree_model_get (tree_model, iter, 2, &text, 3, &subtext, -1, -1);
		if (text != NULL) {
			gchar* _tmp17_ = NULL;
			_tmp17_ = g_markup_escape_text (text, (gssize) (-1));
			_g_free0 (markup);
			markup = _tmp17_;
			if (subtext != NULL) {
				gchar* _tmp18_ = NULL;
				gchar* _tmp19_;
				gchar* _tmp20_ = NULL;
				gchar* _tmp21_;
				gchar* _tmp22_;
				_tmp18_ = g_markup_escape_text (subtext, (gssize) (-1));
				_tmp19_ = _tmp18_;
				_tmp20_ = g_strdup_printf ("\n<small><span color='grey'>%s</span></small>", _tmp19_);
				_tmp21_ = _tmp20_;
				_tmp22_ = g_strconcat (markup, _tmp21_, NULL);
				_g_free0 (markup);
				markup = _tmp22_;
				_g_free0 (_tmp21_);
				_g_free0 (_tmp19_);
			}
		} else {
			const gchar* _tmp23_ = NULL;
			gchar* _tmp24_ = NULL;
			_tmp23_ = _ ("Loading...");
			_tmp24_ = g_strdup_printf ("<span color='grey'>%s</span>\n", _tmp23_);
			_g_free0 (markup);
			markup = _tmp24_;
		}
	}
	g_object_set ((GObject*) cell, "markup", markup, NULL);
	_g_free0 (markup);
	_g_free0 (subtext);
	_g_free0 (text);
}


static void tracker_view_file_size_renderer_func (TrackerView* self, GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter) {
	gchar* size = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (cell_layout != NULL);
	g_return_if_fail (cell != NULL);
	g_return_if_fail (tree_model != NULL);
	tracker_view_renderer_background_func (self, cell_layout, cell, tree_model, iter);
	gtk_tree_model_get (tree_model, iter, 4, &size, -1, -1);
	if (size != NULL) {
		gint _tmp0_;
		gchar* _tmp1_ = NULL;
		_tmp0_ = atoi (size);
		_tmp1_ = g_format_size_for_display ((gint64) _tmp0_);
		_g_free0 (size);
		size = _tmp1_;
	}
	g_object_set ((GObject*) cell, "text", size, NULL);
	_g_free0 (size);
}


static void tracker_view_file_date_renderer_func (TrackerView* self, GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter) {
	gchar* date = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (cell_layout != NULL);
	g_return_if_fail (cell != NULL);
	g_return_if_fail (tree_model != NULL);
	tracker_view_renderer_background_func (self, cell_layout, cell, tree_model, iter);
	gtk_tree_model_get (tree_model, iter, 5, &date, -1, -1);
	if (date != NULL) {
		gchar* _tmp0_ = NULL;
		_tmp0_ = tracker_time_format_from_iso8601 (date);
		_g_free0 (date);
		date = _tmp0_;
	}
	g_object_set ((GObject*) cell, "text", date, NULL);
	_g_free0 (date);
}


static void tracker_view_category_detail_renderer_func (TrackerView* self, GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter) {
	TrackerQueryType category = 0;
	gchar* markup;
	gchar* detail = NULL;
	gchar* _tmp8_ = NULL;
	gchar* _tmp9_;
	gchar* _tmp10_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (cell_layout != NULL);
	g_return_if_fail (cell != NULL);
	g_return_if_fail (tree_model != NULL);
	markup = NULL;
	tracker_view_renderer_background_func (self, cell_layout, cell, tree_model, iter);
	gtk_tree_model_get (tree_model, iter, 4, &detail, 7, &category, -1, -1);
	if (detail == NULL) {
		g_object_set ((GObject*) cell, "markup", NULL, NULL);
		_g_free0 (detail);
		_g_free0 (markup);
		return;
	}
	switch (category) {
		case TRACKER_QUERY_TYPE_FOLDERS:
		case TRACKER_QUERY_TYPE_MAIL:
		{
			gchar* _tmp0_ = NULL;
			_tmp0_ = tracker_time_format_from_iso8601 (detail);
			_g_free0 (detail);
			detail = _tmp0_;
			break;
		}
		case TRACKER_QUERY_TYPE_MUSIC:
		case TRACKER_QUERY_TYPE_VIDEOS:
		{
			gchar* _tmp1_ = NULL;
			_tmp1_ = tracker_time_format_from_seconds (detail);
			_g_free0 (detail);
			detail = _tmp1_;
			break;
		}
		case TRACKER_QUERY_TYPE_DOCUMENTS:
		{
			gchar* _tmp2_;
			gchar* _tmp3_;
			const gchar* _tmp4_ = NULL;
			gchar* _tmp5_;
			_tmp2_ = g_strconcat (detail, " ", NULL);
			_tmp3_ = _tmp2_;
			_tmp4_ = _ ("Pages");
			_tmp5_ = g_strconcat (_tmp3_, _tmp4_, NULL);
			_g_free0 (detail);
			detail = _tmp5_;
			_g_free0 (_tmp3_);
			break;
		}
		case TRACKER_QUERY_TYPE_IMAGES:
		{
			gint _tmp6_;
			gchar* _tmp7_ = NULL;
			_tmp6_ = atoi (detail);
			_tmp7_ = g_format_size_for_display ((gint64) _tmp6_);
			_g_free0 (detail);
			detail = _tmp7_;
			break;
		}
		default:
		break;
	}
	_tmp8_ = g_markup_escape_text (detail, (gssize) (-1));
	_tmp9_ = _tmp8_;
	_tmp10_ = g_strdup_printf ("<span color='grey'><small>%s</small></span>", _tmp9_);
	_g_free0 (markup);
	markup = _tmp10_;
	_g_free0 (_tmp9_);
	g_object_set ((GObject*) cell, "markup", markup, NULL);
	_g_free0 (detail);
	_g_free0 (markup);
}


TrackerViewDisplay tracker_view_get_display (TrackerView* self) {
	TrackerViewDisplay result;
	g_return_val_if_fail (self != NULL, 0);
	result = self->priv->_display;
	return result;
}


static void tracker_view_set_display (TrackerView* self, TrackerViewDisplay value) {
	g_return_if_fail (self != NULL);
	self->priv->_display = value;
	g_object_notify ((GObject *) self, "display");
}


TrackerResultStore* tracker_view_get_store (TrackerView* self) {
	TrackerResultStore* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_store;
	return result;
}


void tracker_view_set_store (TrackerView* self, TrackerResultStore* value) {
	TrackerResultStore* _tmp1_;
	g_return_if_fail (self != NULL);
	if (self->priv->_store != NULL) {
		guint _tmp0_;
		g_signal_parse_name ("row-changed", GTK_TYPE_TREE_MODEL, &_tmp0_, NULL, FALSE);
		g_signal_handlers_disconnect_matched ((GtkTreeModel*) self->priv->_store, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp0_, 0, NULL, (GCallback) _tracker_view_store_row_changed_gtk_tree_model_row_changed, self);
	}
	_tmp1_ = _g_object_ref0 (value);
	_g_object_unref0 (self->priv->_store);
	self->priv->_store = _tmp1_;
	if (self->priv->_store != NULL) {
		g_debug ("tracker-view.vala:48: using store:%p", self->priv->_store);
		g_signal_connect_object ((GtkTreeModel*) self->priv->_store, "row-changed", (GCallback) _tracker_view_store_row_changed_gtk_tree_model_row_changed, self, 0);
	}
	if (self->priv->_display != TRACKER_VIEW_DISPLAY_FILE_ICONS) {
		gtk_tree_view_set_model (GTK_TREE_VIEW (self->priv->view), (GtkTreeModel*) self->priv->_store);
	} else {
		gtk_icon_view_set_model (GTK_ICON_VIEW (self->priv->view), (GtkTreeModel*) self->priv->_store);
	}
	g_object_notify ((GObject *) self, "store");
}


static void tracker_view_class_init (TrackerViewClass * klass) {
	tracker_view_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (TrackerViewPrivate));
	GTK_WIDGET_CLASS (klass)->unmap = tracker_view_real_unmap;
	G_OBJECT_CLASS (klass)->get_property = _vala_tracker_view_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_tracker_view_set_property;
	G_OBJECT_CLASS (klass)->finalize = tracker_view_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), TRACKER_VIEW_DISPLAY, g_param_spec_enum ("display", "display", "display", TRACKER_VIEW_TYPE_DISPLAY, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), TRACKER_VIEW_STORE, g_param_spec_object ("store", "store", "store", TRACKER_TYPE_RESULT_STORE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void tracker_view_instance_init (TrackerView * self) {
	self->priv = TRACKER_VIEW_GET_PRIVATE (self);
	self->priv->view = NULL;
}


static void tracker_view_finalize (GObject* obj) {
	TrackerView * self;
	self = TRACKER_VIEW (obj);
	_g_object_unref0 (self->priv->_store);
	_g_object_unref0 (self->priv->view);
	G_OBJECT_CLASS (tracker_view_parent_class)->finalize (obj);
}


GType tracker_view_get_type (void) {
	static volatile gsize tracker_view_type_id__volatile = 0;
	if (g_once_init_enter (&tracker_view_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (TrackerViewClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) tracker_view_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TrackerView), 0, (GInstanceInitFunc) tracker_view_instance_init, NULL };
		GType tracker_view_type_id;
		tracker_view_type_id = g_type_register_static (GTK_TYPE_SCROLLED_WINDOW, "TrackerView", &g_define_type_info, 0);
		g_once_init_leave (&tracker_view_type_id__volatile, tracker_view_type_id);
	}
	return tracker_view_type_id__volatile;
}


static void _vala_tracker_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	TrackerView * self;
	self = TRACKER_VIEW (object);
	switch (property_id) {
		case TRACKER_VIEW_DISPLAY:
		g_value_set_enum (value, tracker_view_get_display (self));
		break;
		case TRACKER_VIEW_STORE:
		g_value_set_object (value, tracker_view_get_store (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_tracker_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	TrackerView * self;
	self = TRACKER_VIEW (object);
	switch (property_id) {
		case TRACKER_VIEW_DISPLAY:
		tracker_view_set_display (self, g_value_get_enum (value));
		break;
		case TRACKER_VIEW_STORE:
		tracker_view_set_store (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



