/* tracker-utils.c generated by valac 0.12.1, the Vala compiler
 * generated from tracker-utils.vala, do not modify */

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
#include <time.h>
#include <glib/gi18n-lib.h>
#include <float.h>
#include <math.h>
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixdata.h>
#include <gio/gio.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))



#define secs_per_day ((60 * 60) * 24)
gchar* tracker_time_format_from_iso8601 (const gchar* s);
gchar* tracker_time_format_from_seconds (const gchar* seconds_str);
GdkPixbuf* tracker_pixbuf_new_from_file (GtkIconTheme* theme, const gchar* filename, gint size, gboolean is_image);
GdkPixbuf* tracker_pixbuf_new_from_name (GtkIconTheme* theme, const gchar* name, gint size);
static gint _vala_array_length (gpointer array);


static gchar* g_time_format (struct tm *self, const gchar* format) {
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	gchar* buffer;
	gint buffer_length1;
	gint _buffer_size_;
	gchar* _tmp1_;
	g_return_val_if_fail (format != NULL, NULL);
	_tmp0_ = g_new0 (gchar, 64);
	buffer = _tmp0_;
	buffer_length1 = 64;
	_buffer_size_ = 64;
	strftime (buffer, buffer_length1, format, &(*self));
	_tmp1_ = g_strdup ((const gchar*) buffer);
	result = _tmp1_;
	buffer = (g_free (buffer), NULL);
	return result;
}


gchar* tracker_time_format_from_iso8601 (const gchar* s) {
	gchar* result = NULL;
	struct tm t = {0};
	GTimeVal tv_now = {0};
	GTimeVal tv_then = {0};
	glong diff_sec;
	glong diff_days;
	glong _tmp0_;
	glong diff_days_abs;
	g_return_val_if_fail (s != NULL, NULL);
	memset (&t, 0, sizeof (struct tm));
	strptime (s, "%FT%T", &t);
	g_get_current_time (&tv_now);
	g_get_current_time (&tv_now);
	g_get_current_time (&tv_then);
	g_time_val_from_iso8601 (s, &tv_then);
	diff_sec = tv_now.tv_sec - tv_then.tv_sec;
	diff_days = diff_sec / secs_per_day;
	_tmp0_ = labs (diff_days);
	diff_days_abs = _tmp0_;
	if (diff_days_abs > 7) {
		const gchar* _tmp1_ = NULL;
		gchar* _tmp2_ = NULL;
		_tmp1_ = _ ("%x");
		_tmp2_ = g_time_format (&t, _tmp1_);
		result = _tmp2_;
		return result;
	}
	if (diff_days_abs == 0) {
		const gchar* _tmp3_ = NULL;
		gchar* _tmp4_;
		_tmp3_ = _ ("Today");
		_tmp4_ = g_strdup (_tmp3_);
		result = _tmp4_;
		return result;
	} else {
		gboolean future;
		future = FALSE;
		if (diff_days < 0) {
			future = TRUE;
		}
		if (diff_days <= 1) {
			if (future) {
				const gchar* _tmp5_ = NULL;
				gchar* _tmp6_;
				_tmp5_ = _ ("Tomorrow");
				_tmp6_ = g_strdup (_tmp5_);
				result = _tmp6_;
				return result;
			} else {
				const gchar* _tmp7_ = NULL;
				gchar* _tmp8_;
				_tmp7_ = _ ("Yesterday");
				_tmp8_ = g_strdup (_tmp7_);
				result = _tmp8_;
				return result;
			}
		} else {
			if (future) {
				const gchar* _tmp9_ = NULL;
				gchar* _tmp10_ = NULL;
				_tmp9_ = ngettext ("%ld day from now", "%ld days from now", (gulong) diff_days_abs);
				_tmp10_ = g_strdup_printf (_tmp9_, diff_days_abs);
				result = _tmp10_;
				return result;
			} else {
				const gchar* _tmp11_ = NULL;
				gchar* _tmp12_ = NULL;
				_tmp11_ = ngettext ("%ld day ago", "%ld days ago", (gulong) diff_days_abs);
				_tmp12_ = g_strdup_printf (_tmp11_, diff_days_abs);
				result = _tmp12_;
				return result;
			}
		}
	}
}


gchar* tracker_time_format_from_seconds (const gchar* seconds_str) {
	gchar* result = NULL;
	gint _tmp0_;
	gdouble seconds;
	gdouble total = 0.0;
	gint d = 0;
	gint h = 0;
	gint m = 0;
	gint s = 0;
	GString* _tmp3_ = NULL;
	GString* output;
	const gchar* _tmp11_ = NULL;
	gchar* _tmp12_ = NULL;
	gchar* _tmp13_;
	gchar* _tmp16_;
	gchar* str;
	const gchar* _tmp17_ = NULL;
	gchar* _tmp18_;
	g_return_val_if_fail (seconds_str != NULL, NULL);
	_tmp0_ = atoi (seconds_str);
	seconds = (gdouble) _tmp0_;
	if (seconds == 0.0) {
		const gchar* _tmp1_ = NULL;
		gchar* _tmp2_;
		_tmp1_ = _ ("Less than one second");
		_tmp2_ = g_strdup (_tmp1_);
		result = _tmp2_;
		return result;
	}
	total = seconds;
	s = ((gint) total) % 60;
	total = total / ((gdouble) 60);
	m = ((gint) total) % 60;
	total = total / ((gdouble) 60);
	h = ((gint) total) % 24;
	d = ((gint) total) / 24;
	_tmp3_ = g_string_new ("");
	output = _tmp3_;
	if (d > 0) {
		gchar* _tmp4_ = NULL;
		gchar* _tmp5_;
		_tmp4_ = g_strdup_printf (" %dd", d);
		_tmp5_ = _tmp4_;
		g_string_append (output, _tmp5_);
		_g_free0 (_tmp5_);
	}
	if (h > 0) {
		gchar* _tmp6_ = NULL;
		gchar* _tmp7_;
		_tmp6_ = g_strdup_printf (" %.2d", h);
		_tmp7_ = _tmp6_;
		g_string_append (output, _tmp7_);
		_g_free0 (_tmp7_);
	}
	if (m > 0) {
		const gchar* _tmp8_ = NULL;
		gchar* _tmp9_ = NULL;
		gchar* _tmp10_;
		if (h > 0) {
			_tmp8_ = ":";
		} else {
			_tmp8_ = "";
		}
		_tmp9_ = g_strdup_printf ("%s%.2d", _tmp8_, m);
		_tmp10_ = _tmp9_;
		g_string_append (output, _tmp10_);
		_g_free0 (_tmp10_);
	}
	if (m > 0) {
		_tmp11_ = ":";
	} else {
		_tmp11_ = "0:";
	}
	_tmp12_ = g_strdup_printf ("%s%.2d", _tmp11_, s);
	_tmp13_ = _tmp12_;
	g_string_append (output, _tmp13_);
	_g_free0 (_tmp13_);
	if (output->len < 1) {
		const gchar* _tmp14_ = NULL;
		gchar* _tmp15_;
		_tmp14_ = _ ("Less than one second");
		_tmp15_ = g_strdup (_tmp14_);
		result = _tmp15_;
		_g_string_free0 (output);
		return result;
	}
	_tmp16_ = g_strdup (output->str);
	str = _tmp16_;
	_tmp17_ = g_strchug (str);
	_tmp18_ = g_strdup (_tmp17_);
	result = _tmp18_;
	_g_free0 (str);
	_g_string_free0 (output);
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


GdkPixbuf* tracker_pixbuf_new_from_file (GtkIconTheme* theme, const gchar* filename, gint size, gboolean is_image) {
	GdkPixbuf* result = NULL;
	GFile* _tmp0_ = NULL;
	GFile* file;
	gpointer _tmp1_;
	GdkPixbuf* _tmp2_;
	GdkPixbuf* pixbuf;
	gboolean _tmp10_;
	GdkPixbuf* _tmp28_ = NULL;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (theme != NULL, NULL);
	g_return_val_if_fail (filename != NULL, NULL);
	_tmp0_ = g_file_new_for_uri (filename);
	file = _tmp0_;
	_tmp1_ = NULL;
	_tmp2_ = _g_object_ref0 (GDK_IS_PIXBUF (_tmp1_) ? ((GdkPixbuf*) _tmp1_) : NULL);
	pixbuf = _tmp2_;
	if (is_image) {
		gchar* _tmp3_ = NULL;
		gchar* _tmp4_;
		GdkPixbuf* _tmp5_ = NULL;
		GdkPixbuf* _tmp6_;
		GdkPixbuf* _tmp7_;
		_tmp3_ = g_file_get_path (file);
		_tmp4_ = _tmp3_;
		_tmp5_ = gdk_pixbuf_new_from_file_at_size (_tmp4_, size, size, &_inner_error_);
		_tmp6_ = _tmp5_;
		_g_free0 (_tmp4_);
		_tmp7_ = _tmp6_;
		if (_inner_error_ != NULL) {
			goto __catch15_g_error;
		}
		_g_object_unref0 (pixbuf);
		pixbuf = _tmp7_;
		goto __finally15;
		__catch15_g_error:
		{
			GError * e;
			gchar* _tmp8_;
			gchar* _tmp9_;
			e = _inner_error_;
			_inner_error_ = NULL;
			_tmp8_ = g_strconcat ("Error loading icon pixbuf: ", e->message, NULL);
			_tmp9_ = _tmp8_;
			g_warning ("tracker-utils.vala:123: %s", _tmp9_);
			_g_free0 (_tmp9_);
			_g_error_free0 (e);
		}
		__finally15:
		if (_inner_error_ != NULL) {
			_g_object_unref0 (pixbuf);
			_g_object_unref0 (file);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		if (pixbuf != NULL) {
			result = pixbuf;
			_g_object_unref0 (file);
			return result;
		}
	}
	_tmp10_ = g_file_query_exists (file, NULL);
	if (_tmp10_) {
		GFileInfo* _tmp11_ = NULL;
		GFileInfo* file_info;
		_tmp11_ = g_file_query_info (file, "standard::icon", G_FILE_QUERY_INFO_NONE, NULL, &_inner_error_);
		file_info = _tmp11_;
		if (_inner_error_ != NULL) {
			goto __catch16_g_error;
		}
		if (file_info != NULL) {
			GIcon* _tmp12_ = NULL;
			GIcon* _tmp13_;
			GIcon* icon;
			_tmp12_ = g_file_info_get_icon (file_info);
			_tmp13_ = _g_object_ref0 (_tmp12_);
			icon = _tmp13_;
			if (G_IS_FILE_ICON (icon)) {
				GFile* _tmp14_ = NULL;
				gchar* _tmp15_ = NULL;
				gchar* _tmp16_;
				GdkPixbuf* _tmp17_ = NULL;
				GdkPixbuf* _tmp18_;
				GdkPixbuf* _tmp19_;
				_tmp14_ = g_file_icon_get_file (G_FILE_ICON (icon));
				_tmp15_ = g_file_get_path (_tmp14_);
				_tmp16_ = _tmp15_;
				_tmp17_ = gdk_pixbuf_new_from_file (_tmp16_, &_inner_error_);
				_tmp18_ = _tmp17_;
				_g_free0 (_tmp16_);
				_tmp19_ = _tmp18_;
				if (_inner_error_ != NULL) {
					goto __catch17_g_error;
				}
				_g_object_unref0 (pixbuf);
				pixbuf = _tmp19_;
			} else {
				if (G_IS_THEMED_ICON (icon)) {
					gchar** _tmp20_;
					gchar** _tmp21_ = NULL;
					GdkPixbuf* _tmp22_ = NULL;
					GdkPixbuf* _tmp23_;
					_tmp21_ = _tmp20_ = g_themed_icon_get_names (G_THEMED_ICON (icon));
					_tmp22_ = gtk_icon_theme_load_icon (theme, _tmp21_[0], size, GTK_ICON_LOOKUP_USE_BUILTIN, &_inner_error_);
					_tmp23_ = _tmp22_;
					if (_inner_error_ != NULL) {
						goto __catch17_g_error;
					}
					_g_object_unref0 (pixbuf);
					pixbuf = _tmp23_;
				}
			}
			goto __finally17;
			__catch17_g_error:
			{
				GError * e;
				gchar* _tmp24_;
				gchar* _tmp25_;
				e = _inner_error_;
				_inner_error_ = NULL;
				_tmp24_ = g_strconcat ("Error loading icon pixbuf: ", e->message, NULL);
				_tmp25_ = _tmp24_;
				g_warning ("tracker-utils.vala:147: %s", _tmp25_);
				_g_free0 (_tmp25_);
				_g_error_free0 (e);
			}
			__finally17:
			if (_inner_error_ != NULL) {
				_g_object_unref0 (icon);
				_g_object_unref0 (file_info);
				goto __catch16_g_error;
			}
			_g_object_unref0 (icon);
		}
		_g_object_unref0 (file_info);
		goto __finally16;
		__catch16_g_error:
		{
			GError * e;
			gchar* _tmp26_;
			gchar* _tmp27_;
			e = _inner_error_;
			_inner_error_ = NULL;
			_tmp26_ = g_strconcat ("Error looking up file for pixbuf: ", e->message, NULL);
			_tmp27_ = _tmp26_;
			g_warning ("tracker-utils.vala:151: %s", _tmp27_);
			_g_free0 (_tmp27_);
			_g_error_free0 (e);
		}
		__finally16:
		if (_inner_error_ != NULL) {
			_g_object_unref0 (pixbuf);
			_g_object_unref0 (file);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	if (pixbuf != NULL) {
		result = pixbuf;
		_g_object_unref0 (file);
		return result;
	}
	_tmp28_ = tracker_pixbuf_new_from_name (theme, "text-x-generic", size);
	result = _tmp28_;
	_g_object_unref0 (pixbuf);
	_g_object_unref0 (file);
	return result;
}


GdkPixbuf* tracker_pixbuf_new_from_name (GtkIconTheme* theme, const gchar* name, gint size) {
	GdkPixbuf* result = NULL;
	gpointer _tmp0_;
	GdkPixbuf* _tmp1_;
	GdkPixbuf* pixbuf;
	GdkPixbuf* _tmp2_ = NULL;
	GdkPixbuf* _tmp3_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (theme != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	_tmp0_ = NULL;
	_tmp1_ = _g_object_ref0 (GDK_IS_PIXBUF (_tmp0_) ? ((GdkPixbuf*) _tmp0_) : NULL);
	pixbuf = _tmp1_;
	_tmp2_ = gtk_icon_theme_load_icon (theme, name, size, GTK_ICON_LOOKUP_USE_BUILTIN, &_inner_error_);
	_tmp3_ = _tmp2_;
	if (_inner_error_ != NULL) {
		goto __catch18_g_error;
	}
	_g_object_unref0 (pixbuf);
	pixbuf = _tmp3_;
	goto __finally18;
	__catch18_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		g_warning ("tracker-utils.vala:169: Could not load default icon pixbuf from theme " \
"for '%s': %s", name, e->message);
		_g_error_free0 (e);
	}
	__finally18:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (pixbuf);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	result = pixbuf;
	return result;
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



