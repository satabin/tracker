/* tracker-miner-mock.h generated by valac, the Vala compiler, do not modify */


#ifndef __TRACKER_MINER_MOCK_H__
#define __TRACKER_MINER_MOCK_H__

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>

G_BEGIN_DECLS


#define TYPE_TRACKER_MINER_MOCK (tracker_miner_mock_get_type ())
#define TRACKER_MINER_MOCK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRACKER_MINER_MOCK, TrackerMinerMock))
#define TRACKER_MINER_MOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRACKER_MINER_MOCK, TrackerMinerMockClass))
#define IS_TRACKER_MINER_MOCK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRACKER_MINER_MOCK))
#define IS_TRACKER_MINER_MOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRACKER_MINER_MOCK))
#define TRACKER_MINER_MOCK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRACKER_MINER_MOCK, TrackerMinerMockClass))

typedef struct _TrackerMinerMock TrackerMinerMock;
typedef struct _TrackerMinerMockClass TrackerMinerMockClass;
typedef struct _TrackerMinerMockPrivate TrackerMinerMockPrivate;

struct _TrackerMinerMock {
	GObject parent_instance;
	TrackerMinerMockPrivate * priv;
	gboolean is_paused;
};

struct _TrackerMinerMockClass {
	GObjectClass parent_class;
};


GType tracker_miner_mock_get_type (void) G_GNUC_CONST;
TrackerMinerMock* tracker_miner_mock_new (const char* name);
TrackerMinerMock* tracker_miner_mock_construct (GType object_type, const char* name);
void tracker_miner_mock_set_paused (TrackerMinerMock* self, gboolean paused);
gboolean tracker_miner_mock_get_paused (TrackerMinerMock* self);
void tracker_miner_mock_pause (TrackerMinerMock* self, const char* app, const char* reason);
void tracker_miner_mock_resume (TrackerMinerMock* self);
const char* tracker_miner_mock_get_pause_reason (TrackerMinerMock* self);
void tracker_miner_mock_set_pause_reason (TrackerMinerMock* self, const char* value);
const char* tracker_miner_mock_get_name (TrackerMinerMock* self);
void tracker_miner_mock_set_name (TrackerMinerMock* self, const char* value);
char** tracker_miner_mock_get_apps (TrackerMinerMock* self, int* result_length1);
char** tracker_miner_mock_get_reasons (TrackerMinerMock* self, int* result_length1);


G_END_DECLS

#endif
