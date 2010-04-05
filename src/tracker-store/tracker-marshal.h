
#ifndef __tracker_marshal_MARSHAL_H__
#define __tracker_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* VOID:STRING,STRING,INT,INT,INT,DOUBLE (tracker-marshal.list:1) */
extern void tracker_marshal_VOID__STRING_STRING_INT_INT_INT_DOUBLE (GClosure     *closure,
                                                                    GValue       *return_value,
                                                                    guint         n_param_values,
                                                                    const GValue *param_values,
                                                                    gpointer      invocation_hint,
                                                                    gpointer      marshal_data);

/* VOID:STRING,BOOLEAN (tracker-marshal.list:2) */
extern void tracker_marshal_VOID__STRING_BOOLEAN (GClosure     *closure,
                                                  GValue       *return_value,
                                                  guint         n_param_values,
                                                  const GValue *param_values,
                                                  gpointer      invocation_hint,
                                                  gpointer      marshal_data);

/* VOID:STRING,STRING (tracker-marshal.list:3) */
extern void tracker_marshal_VOID__STRING_STRING (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);

/* VOID:STRING,BOOLEAN,BOOLEAN,BOOLEAN,BOOLEAN,BOOLEAN,BOOLEAN (tracker-marshal.list:4) */
extern void tracker_marshal_VOID__STRING_BOOLEAN_BOOLEAN_BOOLEAN_BOOLEAN_BOOLEAN_BOOLEAN (GClosure     *closure,
                                                                                          GValue       *return_value,
                                                                                          guint         n_param_values,
                                                                                          const GValue *param_values,
                                                                                          gpointer      invocation_hint,
                                                                                          gpointer      marshal_data);

/* VOID:BOXED (tracker-marshal.list:5) */
#define tracker_marshal_VOID__BOXED	g_cclosure_marshal_VOID__BOXED

/* VOID:BOXED,BOXED (tracker-marshal.list:6) */
extern void tracker_marshal_VOID__BOXED_BOXED (GClosure     *closure,
                                               GValue       *return_value,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint,
                                               gpointer      marshal_data);

/* VOID:DOUBLE,UINT,UINT,BOOL (tracker-marshal.list:9) */
extern void tracker_marshal_VOID__DOUBLE_UINT_UINT_BOOLEAN (GClosure     *closure,
                                                            GValue       *return_value,
                                                            guint         n_param_values,
                                                            const GValue *param_values,
                                                            gpointer      invocation_hint,
                                                            gpointer      marshal_data);
#define tracker_marshal_VOID__DOUBLE_UINT_UINT_BOOL	tracker_marshal_VOID__DOUBLE_UINT_UINT_BOOLEAN

/* VOID:DOUBLE,STRING,UINT,UINT,UINT (tracker-marshal.list:10) */
extern void tracker_marshal_VOID__DOUBLE_STRING_UINT_UINT_UINT (GClosure     *closure,
                                                                GValue       *return_value,
                                                                guint         n_param_values,
                                                                const GValue *param_values,
                                                                gpointer      invocation_hint,
                                                                gpointer      marshal_data);

/* VOID:STRING,DOUBLE (tracker-marshal.list:11) */
extern void tracker_marshal_VOID__STRING_DOUBLE (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);

G_END_DECLS

#endif /* __tracker_marshal_MARSHAL_H__ */

