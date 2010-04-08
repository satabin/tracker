/*
 * Copyright (C) 2008, Nokia <ivan.frade@nokia.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 */
#include "tracker-test-helpers.h"

static gchar *nonutf8_str = NULL;

gboolean
tracker_test_helpers_cmpstr_equal (const gchar *obtained,
                                   const gchar *expected)
{
	gboolean result;

	if (expected == obtained) {
		return TRUE;
	}

	if (expected && obtained) {
		result = !g_utf8_collate (expected, obtained);
		if (!result) {
			g_warning ("Expected %s - obtained %s", expected, obtained);
		}
		return result;
	} else {
		g_warning ("\n Only one of the strings is NULL\n");
		return FALSE;
	}
}

const gchar *
tracker_test_helpers_get_nonutf8 (void)
{
	GMappedFile *file = NULL;

	if (!nonutf8_str) {
		file = g_mapped_file_new (TEST_TEXT, FALSE, NULL);
		nonutf8_str = g_strdup (g_mapped_file_get_contents (file));
		nonutf8_str [g_mapped_file_get_length (file) -1] = '\0';
#if GLIB_CHECK_VERSION(2,22,0)
		g_mapped_file_unref (file);
#else
		g_mapped_file_free (file);
#endif
	}

	return nonutf8_str;
}

void
tracker_test_helpers_free_nonutf8 (void)
{
	if (nonutf8_str) {
		g_free (nonutf8_str);
		nonutf8_str = NULL;
	}
}