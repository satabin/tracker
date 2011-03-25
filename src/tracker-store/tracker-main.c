/* tracker-main.c generated by valac 0.11.5, the Vala compiler
 * generated from tracker-main.vala, do not modify */

/*
 * Copyright (C) 2006, Jamie McCracken <jamiemcc@gnome.org>
 * Copyright (C) 2008-2011, Nokia <ivan.frade@nokia.com>
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

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <tracker-store/tracker-config.h>
#include <signal.h>
#include <sys/select.h>
#include <libtracker-common/tracker-common.h>
#include <libtracker-data/tracker-data-query.h>
#include <libtracker-data/tracker-data-update.h>
#include <libtracker-data/tracker-data-backup.h>
#include <libtracker-data/tracker-db-interface.h>
#include <libtracker-sparql/tracker-sparql.h>
#include <locale.h>
#include <glib/gi18n-lib.h>
#include <libtracker-data/tracker-db-config.h>
#include <libtracker-data/tracker-db-manager.h>
#include <libtracker-data/tracker-data-manager.h>
#include <tracker-store/tracker-locale-change.h>
#include <tracker-store/tracker-events.h>
#include <tracker-store/tracker-writeback.h>
#include <gobject/gvaluecollector.h>


#define TRACKER_TYPE_MAIN (tracker_main_get_type ())
#define TRACKER_MAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TRACKER_TYPE_MAIN, TrackerMain))
#define TRACKER_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TRACKER_TYPE_MAIN, TrackerMainClass))
#define TRACKER_IS_MAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TRACKER_TYPE_MAIN))
#define TRACKER_IS_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TRACKER_TYPE_MAIN))
#define TRACKER_MAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TRACKER_TYPE_MAIN, TrackerMainClass))

typedef struct _TrackerMain TrackerMain;
typedef struct _TrackerMainClass TrackerMainClass;
typedef struct _TrackerMainPrivate TrackerMainPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_option_context_free0(var) ((var == NULL) ? NULL : (var = (g_option_context_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define TRACKER_TYPE_STATUS (tracker_status_get_type ())
#define TRACKER_STATUS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TRACKER_TYPE_STATUS, TrackerStatus))
#define TRACKER_STATUS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TRACKER_TYPE_STATUS, TrackerStatusClass))
#define TRACKER_IS_STATUS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TRACKER_TYPE_STATUS))
#define TRACKER_IS_STATUS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TRACKER_TYPE_STATUS))
#define TRACKER_STATUS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TRACKER_TYPE_STATUS, TrackerStatusClass))

typedef struct _TrackerStatus TrackerStatus;
typedef struct _TrackerStatusClass TrackerStatusClass;
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))
typedef struct _TrackerParamSpecMain TrackerParamSpecMain;

struct _TrackerMain {
	GTypeInstance parent_instance;
	volatile int ref_count;
	TrackerMainPrivate * priv;
};

struct _TrackerMainClass {
	GTypeClass parent_class;
	void (*finalize) (TrackerMain *self);
};

struct _TrackerParamSpecMain {
	GParamSpec parent_instance;
};


static gpointer tracker_main_parent_class = NULL;
static GMainLoop* tracker_main_main_loop;
static GMainLoop* tracker_main_main_loop = NULL;
static gchar* tracker_main_log_filename;
static gchar* tracker_main_log_filename = NULL;
static gboolean tracker_main_shutdown;
static gboolean tracker_main_shutdown = FALSE;
static gboolean tracker_main_version;
static gboolean tracker_main_version = FALSE;
static gint tracker_main_verbosity;
static gint tracker_main_verbosity = 0;
static gboolean tracker_main_force_reindex;
static gboolean tracker_main_force_reindex = FALSE;
static gboolean tracker_main_readonly_mode;
static gboolean tracker_main_readonly_mode = FALSE;
static gboolean tracker_main_in_loop;
static gboolean tracker_main_in_loop = FALSE;

gpointer tracker_main_ref (gpointer instance);
void tracker_main_unref (gpointer instance);
GParamSpec* tracker_param_spec_main (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void tracker_value_set_main (GValue* value, gpointer v_object);
void tracker_value_take_main (GValue* value, gpointer v_object);
gpointer tracker_value_get_main (const GValue* value);
GType tracker_main_get_type (void) G_GNUC_CONST;
enum  {
	TRACKER_MAIN_DUMMY_PROPERTY
};
#define TRACKER_MAIN_LICENSE "This program is free software and comes without any warranty.\n" \
"It is licensed under version 2 or later of the General Public\n" \
"License which can be viewed at:\n" \
"  http://www.gnu.org/licenses/gpl.txt\n"
#define TRACKER_MAIN_SELECT_CACHE_SIZE 100
#define TRACKER_MAIN_UPDATE_CACHE_SIZE 100
static void tracker_main_sanity_check_option_values (TrackerConfig* config);
static void tracker_main_do_shutdown (void);
static gboolean tracker_main_shutdown_timeout_cb (void);
static void tracker_main_signal_handler (gint signo);
static void tracker_main_initialize_signal_handler (void);
static void _tracker_main_signal_handler_sighandler_t (gint signal);
static void tracker_main_initialize_priority (void);
static gchar** tracker_main_get_writeback_predicates (void);
static void _vala_array_add1 (gchar*** array, int* length, int* size, gchar* value);
static void tracker_main_config_verbosity_changed_cb (GObject* object, GParamSpec* spec);
static gint tracker_main_main (gchar** args, int args_length1);
void tzset (void);
static void _tracker_main_config_verbosity_changed_cb_g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self);
gboolean tracker_dbus_init (void);
GType tracker_status_get_type (void) G_GNUC_CONST;
guint tracker_status_register_object (void* object, GDBusConnection* connection, const gchar* path, GError** error);
TrackerStatus* tracker_dbus_register_notifier (void);
TrackerBusyCallback tracker_status_get_callback (TrackerStatus* self, void** result_target, GDestroyNotify* result_target_destroy_notify);
void tracker_store_init (void);
gboolean tracker_dbus_register_objects (void);
gboolean tracker_dbus_register_names (void);
gboolean tracker_dbus_register_prepare_class_signal (void);
static gchar** _tracker_main_get_writeback_predicates_tracker_writeback_get_predicates_func (int* result_length1);
void tracker_store_resume (void);
void tracker_store_shutdown (void);
static gboolean _tracker_main_shutdown_timeout_cb_gsource_func (gpointer self);
void tracker_dbus_shutdown (void);
TrackerMain* tracker_main_new (void);
TrackerMain* tracker_main_construct (GType object_type);
static void tracker_main_finalize (TrackerMain* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);

static const GOptionEntry TRACKER_MAIN_entries[5] = {{"version", 'V', 0, G_OPTION_ARG_NONE, &tracker_main_version, "Displays version information", NULL}, {"verbosity", 'v', 0, G_OPTION_ARG_INT, &tracker_main_verbosity, "Logging, 0 = errors only, 1 = minimal, 2 = detailed and 3 = debug (def" \
"ault = 0)", NULL}, {"force-reindex", 'r', 0, G_OPTION_ARG_NONE, &tracker_main_force_reindex, "Force a re-index of all content", NULL}, {"readonly-mode", 'n', 0, G_OPTION_ARG_NONE, &tracker_main_readonly_mode, "Only allow read based actions on the database", NULL}, {NULL}};

static void tracker_main_sanity_check_option_values (TrackerConfig* config) {
	gint _tmp0_;
	const gchar* _tmp1_ = NULL;
	g_return_if_fail (config != NULL);
	g_message ("General options:");
	_tmp0_ = tracker_config_get_verbosity (config);
	g_message ("  Verbosity  ............................  %d", _tmp0_);
	g_message ("Store options:");
	if (tracker_main_readonly_mode) {
		_tmp1_ = "yes";
	} else {
		_tmp1_ = "no";
	}
	g_message ("  Readonly mode  ........................  %s", _tmp1_);
}


static void tracker_main_do_shutdown (void) {
	if (tracker_main_main_loop != NULL) {
		g_main_loop_quit (tracker_main_main_loop);
	}
	tracker_main_shutdown = TRUE;
}


static gboolean tracker_main_shutdown_timeout_cb (void) {
	gboolean result = FALSE;
	g_critical ("Could not exit in a timely fashion - terminating...");
	exit (1);
	return result;
}


static void tracker_main_signal_handler (gint signo) {
	if (tracker_main_in_loop) {
		exit (1);
	}
	switch (signo) {
		case SIGTERM:
		case SIGINT:
		{
			const gchar* _tmp0_ = NULL;
			tracker_main_in_loop = TRUE;
			tracker_main_do_shutdown ();
			_tmp0_ = g_strsignal (signo);
			if (_tmp0_ != NULL) {
				const gchar* _tmp1_ = NULL;
				g_print ("\n");
				_tmp1_ = g_strsignal (signo);
				g_print ("Received signal:%d->'%s'", signo, _tmp1_);
			}
			break;
		}
		default:
		{
			const gchar* _tmp2_ = NULL;
			_tmp2_ = g_strsignal (signo);
			if (_tmp2_ != NULL) {
				const gchar* _tmp3_ = NULL;
				g_print ("\n");
				_tmp3_ = g_strsignal (signo);
				g_print ("Received signal:%d->'%s'", signo, _tmp3_);
			}
			break;
		}
	}
}


static void _tracker_main_signal_handler_sighandler_t (gint signal) {
	tracker_main_signal_handler (signal);
}


static void tracker_main_initialize_signal_handler (void) {
	sigset_t empty_mask = {0};
	struct sigaction act = {0};
	memset (&empty_mask, 0, sizeof (sigset_t));
	sigemptyset (&empty_mask);
	memset (&act, 0, sizeof (struct sigaction));
	act.sa_handler = _tracker_main_signal_handler_sighandler_t;
	act.sa_mask = empty_mask;
	act.sa_flags = 0;
	sigaction (SIGTERM, &act, NULL);
	sigaction (SIGINT, &act, NULL);
	sigaction (SIGHUP, &act, NULL);
}


static void tracker_main_initialize_priority (void) {
	tracker_ioprio_init ();
}


static void _vala_array_add1 (gchar*** array, int* length, int* size, gchar* value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar*, *array, (*size) + 1);
	}
	(*array)[(*length)++] = value;
	(*array)[*length] = NULL;
}


static gchar** tracker_main_get_writeback_predicates (void) {
	gchar** result = NULL;
	gchar** predicates_to_signal;
	gint predicates_to_signal_length1;
	gint _predicates_to_signal_size_;
	TrackerDBCursor* _tmp0_ = NULL;
	TrackerDBCursor* cursor;
	GError * _inner_error_ = NULL;
	predicates_to_signal = NULL;
	predicates_to_signal_length1 = 0;
	_predicates_to_signal_size_ = 0;
	_tmp0_ = tracker_data_query_sparql_cursor ("SELECT ?predicate WHERE { ?predicate tracker:writeback true }", &_inner_error_);
	cursor = _tmp0_;
	if (_inner_error_ != NULL) {
		goto __catch5_g_error;
	}
	while (TRUE) {
		gboolean _tmp1_;
		gboolean _tmp2_;
		const gchar* _tmp3_ = NULL;
		gchar* _tmp4_;
		_tmp1_ = tracker_sparql_cursor_next ((TrackerSparqlCursor*) cursor, NULL, &_inner_error_);
		_tmp2_ = _tmp1_;
		if (_inner_error_ != NULL) {
			_g_object_unref0 (cursor);
			goto __catch5_g_error;
		}
		if (!_tmp2_) {
			break;
		}
		_tmp3_ = tracker_sparql_cursor_get_string ((TrackerSparqlCursor*) cursor, 0, NULL);
		_tmp4_ = g_strdup (_tmp3_);
		_vala_array_add1 (&predicates_to_signal, &predicates_to_signal_length1, &_predicates_to_signal_size_, _tmp4_);
	}
	_g_object_unref0 (cursor);
	goto __finally5;
	__catch5_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		g_critical ("Unable to retrieve tracker:writeback properties: %s", e->message);
		_g_error_free0 (e);
	}
	__finally5:
	if (_inner_error_ != NULL) {
		predicates_to_signal = (_vala_array_free (predicates_to_signal, predicates_to_signal_length1, (GDestroyNotify) g_free), NULL);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	result = predicates_to_signal;
	return result;
}


static void tracker_main_config_verbosity_changed_cb (GObject* object, GParamSpec* spec) {
	gint _tmp0_;
	gint verbosity;
	const gchar* _tmp1_ = NULL;
	g_return_if_fail (object != NULL);
	_tmp0_ = tracker_config_get_verbosity (TRACKER_CONFIG (object));
	verbosity = _tmp0_;
	if (verbosity > 0) {
		_tmp1_ = "enabling";
	} else {
		_tmp1_ = "disabling";
	}
	g_message ("Log verbosity is set to %d, %s D-Bus client lookup", verbosity, _tmp1_);
	tracker_dbus_enable_client_lookup (verbosity > 0);
}


static void _tracker_main_config_verbosity_changed_cb_g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self) {
	tracker_main_config_verbosity_changed_cb (_sender, pspec);
}


static gchar** _tracker_main_get_writeback_predicates_tracker_writeback_get_predicates_func (int* result_length1) {
	gchar** result;
	result = tracker_main_get_writeback_predicates ();
	return result;
}


static gboolean _tracker_main_shutdown_timeout_cb_gsource_func (gpointer self) {
	gboolean result;
	result = tracker_main_shutdown_timeout_cb ();
	return result;
}


static gint tracker_main_main (gchar** args, int args_length1) {
	gint result = 0;
	const gchar* _tmp0_ = NULL;
	GOptionContext* _tmp1_ = NULL;
	GOptionContext* context;
	gboolean _tmp2_;
	TrackerConfig* _tmp3_ = NULL;
	TrackerConfig* config;
	TrackerDBConfig* _tmp4_ = NULL;
	TrackerDBConfig* db_config;
	gulong _tmp5_;
	gulong config_verbosity_id;
	gboolean _tmp6_;
	gint _tmp7_;
	gchar* _tmp8_ = NULL;
	TrackerDBManagerFlags flags;
	TrackerStatus* _tmp9_ = NULL;
	TrackerStatus* notifier;
	void* _tmp10_ = NULL;
	GDestroyNotify _tmp11_ = NULL;
	TrackerBusyCallback _tmp12_ = NULL;
	TrackerBusyCallback busy_callback;
	void* busy_callback_target = NULL;
	GDestroyNotify busy_callback_target_destroy_notify = NULL;
	gboolean _tmp13_;
	gboolean _tmp14_;
	gint _tmp15_;
	gint chunk_size_mb;
	gsize chunk_size;
	const gchar* _tmp16_ = NULL;
	gchar* _tmp17_;
	gchar* rotate_to;
	gboolean do_rotating;
	gint select_cache_size = 0;
	gint update_cache_size = 0;
	gchar* cache_size_s = NULL;
	const gchar* _tmp19_ = NULL;
	gchar* _tmp20_;
	gchar* _tmp21_;
	gboolean _tmp22_ = FALSE;
	const gchar* _tmp24_ = NULL;
	gchar* _tmp25_;
	gchar* _tmp26_;
	gboolean _tmp27_ = FALSE;
	gboolean is_first_time_index = FALSE;
	gboolean _tmp29_;
	TrackerDBConfig* _tmp30_;
	TrackerStatus* _tmp31_;
	TrackerConfig* _tmp34_;
	gchar* _tmp35_;
	GMainLoop* _tmp36_;
	GError * _inner_error_ = NULL;
	setlocale (LC_ALL, "");
	bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);
	tzset ();
	tracker_main_verbosity = -1;
	_tmp0_ = _ ("- start the tracker daemon");
	_tmp1_ = g_option_context_new (_tmp0_);
	context = _tmp1_;
	g_option_context_add_main_entries (context, TRACKER_MAIN_entries, NULL);
	g_option_context_parse (context, &args_length1, &args, &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_option_context_free0 (context);
		goto __catch6_g_error;
	}
	_g_option_context_free0 (context);
	goto __finally6;
	__catch6_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		g_printerr ("Invalid arguments, %s\n", e->message);
		result = 1;
		_g_error_free0 (e);
		return result;
	}
	__finally6:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
	if (tracker_main_version) {
		g_print ("%s", "\nTracker " PACKAGE_VERSION "\n\n" TRACKER_MAIN_LICENSE "\n");
		result = 0;
		return result;
	}
	g_print ("Initializing tracker-store...\n");
	tracker_main_initialize_signal_handler ();
	_tmp2_ = tracker_env_check_xdg_dirs ();
	if (!_tmp2_) {
		result = 1;
		return result;
	}
	tracker_main_initialize_priority ();
	_tmp3_ = tracker_config_new ();
	config = _tmp3_;
	_tmp4_ = tracker_db_config_new ();
	db_config = _tmp4_;
	_tmp5_ = g_signal_connect ((GObject*) config, "notify::verbosity", (GCallback) _tracker_main_config_verbosity_changed_cb_g_object_notify, NULL);
	config_verbosity_id = _tmp5_;
	if (tracker_main_verbosity > (-1)) {
		tracker_config_set_verbosity (config, tracker_main_verbosity);
	} else {
		tracker_main_config_verbosity_changed_cb ((GObject*) config, NULL);
	}
	_tmp6_ = tracker_dbus_init ();
	if (!_tmp6_) {
		result = 1;
		_g_object_unref0 (db_config);
		_g_object_unref0 (config);
		return result;
	}
	_tmp7_ = tracker_config_get_verbosity (config);
	tracker_log_init (_tmp7_, &_tmp8_);
	_g_free0 (tracker_main_log_filename);
	tracker_main_log_filename = _tmp8_;
	g_print ("Starting log:\n  File:'%s'\n", tracker_main_log_filename);
	tracker_main_sanity_check_option_values (config);
	flags = TRACKER_DB_MANAGER_REMOVE_CACHE;
	if (tracker_main_force_reindex) {
		flags = flags | TRACKER_DB_MANAGER_FORCE_REINDEX;
	}
	_tmp9_ = tracker_dbus_register_notifier ();
	notifier = _tmp9_;
	_tmp12_ = tracker_status_get_callback (notifier, &_tmp10_, &_tmp11_);
	busy_callback = _tmp12_;
	busy_callback_target = _tmp10_;
	busy_callback_target_destroy_notify = _tmp11_;
	tracker_store_init ();
	_tmp13_ = tracker_dbus_register_objects ();
	if (!_tmp13_) {
		result = 1;
		(busy_callback_target_destroy_notify == NULL) ? NULL : (busy_callback_target_destroy_notify (busy_callback_target), NULL);
		busy_callback = NULL;
		busy_callback_target = NULL;
		busy_callback_target_destroy_notify = NULL;
		_g_object_unref0 (notifier);
		_g_object_unref0 (db_config);
		_g_object_unref0 (config);
		return result;
	}
	_tmp14_ = tracker_dbus_register_names ();
	if (!_tmp14_) {
		result = 1;
		(busy_callback_target_destroy_notify == NULL) ? NULL : (busy_callback_target_destroy_notify (busy_callback_target), NULL);
		busy_callback = NULL;
		busy_callback_target = NULL;
		busy_callback_target_destroy_notify = NULL;
		_g_object_unref0 (notifier);
		_g_object_unref0 (db_config);
		_g_object_unref0 (config);
		return result;
	}
	_tmp15_ = tracker_db_config_get_journal_chunk_size (db_config);
	chunk_size_mb = _tmp15_;
	chunk_size = (gsize) ((((gsize) chunk_size_mb) * ((gsize) 1024)) * ((gsize) 1024));
	_tmp16_ = tracker_db_config_get_journal_rotate_destination (db_config);
	_tmp17_ = g_strdup (_tmp16_);
	rotate_to = _tmp17_;
	if (g_strcmp0 (rotate_to, "") == 0) {
		gchar* _tmp18_;
		_tmp18_ = NULL;
		_g_free0 (rotate_to);
		rotate_to = _tmp18_;
	}
	do_rotating = chunk_size_mb != (-1);
	tracker_db_journal_set_rotating (do_rotating, chunk_size, rotate_to);
	_tmp19_ = g_getenv ("TRACKER_STORE_SELECT_CACHE_SIZE");
	_tmp20_ = g_strdup (_tmp19_);
	_tmp21_ = _tmp20_;
	_g_free0 (cache_size_s);
	cache_size_s = _tmp21_;
	if (cache_size_s != NULL) {
		_tmp22_ = g_strcmp0 (cache_size_s, "") != 0;
	} else {
		_tmp22_ = FALSE;
	}
	if (_tmp22_) {
		gint _tmp23_;
		_tmp23_ = atoi (cache_size_s);
		select_cache_size = _tmp23_;
	} else {
		select_cache_size = TRACKER_MAIN_SELECT_CACHE_SIZE;
	}
	_tmp24_ = g_getenv ("TRACKER_STORE_UPDATE_CACHE_SIZE");
	_tmp25_ = g_strdup (_tmp24_);
	_tmp26_ = _tmp25_;
	_g_free0 (cache_size_s);
	cache_size_s = _tmp26_;
	if (cache_size_s != NULL) {
		_tmp27_ = g_strcmp0 (cache_size_s, "") != 0;
	} else {
		_tmp27_ = FALSE;
	}
	if (_tmp27_) {
		gint _tmp28_;
		_tmp28_ = atoi (cache_size_s);
		update_cache_size = _tmp28_;
	} else {
		update_cache_size = TRACKER_MAIN_UPDATE_CACHE_SIZE;
	}
	tracker_data_manager_init (flags, NULL, &_tmp29_, TRUE, (guint) select_cache_size, (guint) update_cache_size, busy_callback, busy_callback_target, "Initializing", &_inner_error_);
	is_first_time_index = _tmp29_;
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == TRACKER_DB_INTERFACE_ERROR) {
			goto __catch7_tracker_db_interface_error;
		}
		_g_free0 (cache_size_s);
		_g_free0 (rotate_to);
		(busy_callback_target_destroy_notify == NULL) ? NULL : (busy_callback_target_destroy_notify (busy_callback_target), NULL);
		busy_callback = NULL;
		busy_callback_target = NULL;
		busy_callback_target_destroy_notify = NULL;
		_g_object_unref0 (notifier);
		_g_object_unref0 (db_config);
		_g_object_unref0 (config);
		g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
	goto __finally7;
	__catch7_tracker_db_interface_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		g_critical ("Cannot initialize database: %s", e->message);
		result = 1;
		_g_error_free0 (e);
		_g_free0 (cache_size_s);
		_g_free0 (rotate_to);
		(busy_callback_target_destroy_notify == NULL) ? NULL : (busy_callback_target_destroy_notify (busy_callback_target), NULL);
		busy_callback = NULL;
		busy_callback_target = NULL;
		busy_callback_target_destroy_notify = NULL;
		_g_object_unref0 (notifier);
		_g_object_unref0 (db_config);
		_g_object_unref0 (config);
		return result;
	}
	__finally7:
	if (_inner_error_ != NULL) {
		_g_free0 (cache_size_s);
		_g_free0 (rotate_to);
		(busy_callback_target_destroy_notify == NULL) ? NULL : (busy_callback_target_destroy_notify (busy_callback_target), NULL);
		busy_callback = NULL;
		busy_callback_target = NULL;
		busy_callback_target_destroy_notify = NULL;
		_g_object_unref0 (notifier);
		_g_object_unref0 (db_config);
		_g_object_unref0 (config);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
	_tmp30_ = NULL;
	_g_object_unref0 (db_config);
	db_config = _tmp30_;
	_tmp31_ = NULL;
	_g_object_unref0 (notifier);
	notifier = _tmp31_;
	if (!tracker_main_shutdown) {
		tracker_locale_change_initialize_subscription ();
		tracker_dbus_register_prepare_class_signal ();
		tracker_events_init ();
		tracker_writeback_init (_tracker_main_get_writeback_predicates_tracker_writeback_get_predicates_func);
		tracker_store_resume ();
		g_message ("Waiting for D-Bus requests...");
	}
	if (!tracker_main_shutdown) {
		GMainLoop* _tmp32_ = NULL;
		GMainLoop* _tmp33_;
		_tmp32_ = g_main_loop_new (NULL, FALSE);
		_tmp33_ = _tmp32_;
		_g_main_loop_unref0 (tracker_main_main_loop);
		tracker_main_main_loop = _tmp33_;
		g_main_loop_run (tracker_main_main_loop);
	}
	g_message ("Shutdown started");
	tracker_store_shutdown ();
	g_timeout_add_full (G_PRIORITY_LOW, (guint) 5000, _tracker_main_shutdown_timeout_cb_gsource_func, NULL, NULL);
	g_message ("Cleaning up");
	tracker_writeback_shutdown ();
	tracker_events_shutdown ();
	tracker_locale_change_shutdown_subscription ();
	tracker_dbus_shutdown ();
	tracker_data_manager_shutdown ();
	tracker_log_shutdown ();
	g_signal_handler_disconnect ((GObject*) config, config_verbosity_id);
	_tmp34_ = NULL;
	_g_object_unref0 (config);
	config = _tmp34_;
	tracker_db_journal_set_rotating (chunk_size_mb != (-1), chunk_size, NULL);
	g_print ("\nOK\n\n");
	_tmp35_ = NULL;
	_g_free0 (tracker_main_log_filename);
	tracker_main_log_filename = _tmp35_;
	_tmp36_ = NULL;
	_g_main_loop_unref0 (tracker_main_main_loop);
	tracker_main_main_loop = _tmp36_;
	result = 0;
	_g_free0 (cache_size_s);
	_g_free0 (rotate_to);
	(busy_callback_target_destroy_notify == NULL) ? NULL : (busy_callback_target_destroy_notify (busy_callback_target), NULL);
	busy_callback = NULL;
	busy_callback_target = NULL;
	busy_callback_target_destroy_notify = NULL;
	_g_object_unref0 (notifier);
	_g_object_unref0 (db_config);
	_g_object_unref0 (config);
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return tracker_main_main (argv, argc);
}


TrackerMain* tracker_main_construct (GType object_type) {
	TrackerMain* self = NULL;
	self = (TrackerMain*) g_type_create_instance (object_type);
	return self;
}


TrackerMain* tracker_main_new (void) {
	return tracker_main_construct (TRACKER_TYPE_MAIN);
}


static void tracker_value_main_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void tracker_value_main_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		tracker_main_unref (value->data[0].v_pointer);
	}
}


static void tracker_value_main_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = tracker_main_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer tracker_value_main_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* tracker_value_main_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		TrackerMain* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = tracker_main_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* tracker_value_main_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	TrackerMain** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = tracker_main_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* tracker_param_spec_main (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	TrackerParamSpecMain* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TRACKER_TYPE_MAIN), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer tracker_value_get_main (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TRACKER_TYPE_MAIN), NULL);
	return value->data[0].v_pointer;
}


void tracker_value_set_main (GValue* value, gpointer v_object) {
	TrackerMain* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TRACKER_TYPE_MAIN));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TRACKER_TYPE_MAIN));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		tracker_main_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		tracker_main_unref (old);
	}
}


void tracker_value_take_main (GValue* value, gpointer v_object) {
	TrackerMain* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TRACKER_TYPE_MAIN));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TRACKER_TYPE_MAIN));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		tracker_main_unref (old);
	}
}


static void tracker_main_class_init (TrackerMainClass * klass) {
	tracker_main_parent_class = g_type_class_peek_parent (klass);
	TRACKER_MAIN_CLASS (klass)->finalize = tracker_main_finalize;
}


static void tracker_main_instance_init (TrackerMain * self) {
	self->ref_count = 1;
}


static void tracker_main_finalize (TrackerMain* obj) {
	TrackerMain * self;
	self = TRACKER_MAIN (obj);
}


GType tracker_main_get_type (void) {
	static volatile gsize tracker_main_type_id__volatile = 0;
	if (g_once_init_enter (&tracker_main_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { tracker_value_main_init, tracker_value_main_free_value, tracker_value_main_copy_value, tracker_value_main_peek_pointer, "p", tracker_value_main_collect_value, "p", tracker_value_main_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (TrackerMainClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) tracker_main_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TrackerMain), 0, (GInstanceInitFunc) tracker_main_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType tracker_main_type_id;
		tracker_main_type_id = g_type_register_fundamental (g_type_fundamental_next (), "TrackerMain", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&tracker_main_type_id__volatile, tracker_main_type_id);
	}
	return tracker_main_type_id__volatile;
}


gpointer tracker_main_ref (gpointer instance) {
	TrackerMain* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void tracker_main_unref (gpointer instance) {
	TrackerMain* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		TRACKER_MAIN_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
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



