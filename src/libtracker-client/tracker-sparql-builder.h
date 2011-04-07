/* tracker-sparql-builder.h generated by valac 0.12.0.69-6c49, the Vala compiler, do not modify */


#ifndef __TRACKER_SPARQL_BUILDER_H__
#define __TRACKER_SPARQL_BUILDER_H__

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <float.h>
#include <math.h>

G_BEGIN_DECLS


#define TRACKER_TYPE_SPARQL_BUILDER (tracker_sparql_builder_get_type ())
#define TRACKER_SPARQL_BUILDER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TRACKER_TYPE_SPARQL_BUILDER, TrackerSparqlBuilder))
#define TRACKER_SPARQL_BUILDER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TRACKER_TYPE_SPARQL_BUILDER, TrackerSparqlBuilderClass))
#define TRACKER_IS_SPARQL_BUILDER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TRACKER_TYPE_SPARQL_BUILDER))
#define TRACKER_IS_SPARQL_BUILDER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TRACKER_TYPE_SPARQL_BUILDER))
#define TRACKER_SPARQL_BUILDER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TRACKER_TYPE_SPARQL_BUILDER, TrackerSparqlBuilderClass))

typedef struct _TrackerSparqlBuilder TrackerSparqlBuilder;
typedef struct _TrackerSparqlBuilderClass TrackerSparqlBuilderClass;
typedef struct _TrackerSparqlBuilderPrivate TrackerSparqlBuilderPrivate;

#define TRACKER_SPARQL_BUILDER_TYPE_STATE (tracker_sparql_builder_state_get_type ())

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
	TRACKER_SPARQL_BUILDER_STATE_EMBEDDED_INSERT
} TrackerSparqlBuilderState;


GType tracker_sparql_builder_get_type (void) G_GNUC_CONST;
GType tracker_sparql_builder_state_get_type (void) G_GNUC_CONST;
TrackerSparqlBuilder* tracker_sparql_builder_new_update (void);
TrackerSparqlBuilder* tracker_sparql_builder_construct_update (GType object_type);
TrackerSparqlBuilder* tracker_sparql_builder_new_embedded_insert (void);
TrackerSparqlBuilder* tracker_sparql_builder_construct_embedded_insert (GType object_type);
void tracker_sparql_builder_drop_graph (TrackerSparqlBuilder* self, const gchar* iri);
void tracker_sparql_builder_insert_open (TrackerSparqlBuilder* self, const gchar* graph);
void tracker_sparql_builder_insert_silent_open (TrackerSparqlBuilder* self, const gchar* graph);
void tracker_sparql_builder_insert_close (TrackerSparqlBuilder* self);
void tracker_sparql_builder_delete_open (TrackerSparqlBuilder* self, const gchar* graph);
void tracker_sparql_builder_delete_close (TrackerSparqlBuilder* self);
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


G_END_DECLS

#endif
