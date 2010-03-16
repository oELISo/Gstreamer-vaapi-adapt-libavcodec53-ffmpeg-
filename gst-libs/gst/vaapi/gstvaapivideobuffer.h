/*
 *  gstvaapivideobuffer.h - Gstreamer/VA video buffer
 *
 *  gstreamer-vaapi (C) 2010 Splitted-Desktop Systems
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#ifndef GST_VAAPI_VIDEO_BUFFER_H
#define GST_VAAPI_VIDEO_BUFFER_H

#include <gst/gstbuffer.h>
#include <gst/vaapi/gstvaapiimage.h>
#include <gst/vaapi/gstvaapisurface.h>
#include <gst/vaapi/gstvaapivideopool.h>

G_BEGIN_DECLS

#define GST_VAAPI_TYPE_VIDEO_BUFFER \
    (gst_vaapi_video_buffer_get_type())

#define GST_VAAPI_VIDEO_BUFFER(obj)                             \
    (G_TYPE_CHECK_INSTANCE_CAST((obj),                          \
                                GST_VAAPI_TYPE_VIDEO_BUFFER,    \
                                GstVaapiVideoBuffer))

#define GST_VAAPI_VIDEO_BUFFER_CLASS(klass)                     \
    (G_TYPE_CHECK_CLASS_CAST((klass),                           \
                             GST_VAAPI_TYPE_VIDEO_BUFFER,       \
                             GstVaapiVideoBufferClass))

#define GST_VAAPI_IS_VIDEO_BUFFER(obj) \
    (G_TYPE_CHECK_INSTANCE_TYPE((obj), GST_VAAPI_TYPE_VIDEO_BUFFER))

#define GST_VAAPI_IS_VIDEO_BUFFER_CLASS(klass) \
    (G_TYPE_CHECK_CLASS_TYPE((klass), GST_VAAPI_TYPE_VIDEO_BUFFER))

#define GST_VAAPI_VIDEO_BUFFER_GET_CLASS(obj)                   \
    (G_TYPE_INSTANCE_GET_CLASS((obj),                           \
                               GST_VAAPI_TYPE_VIDEO_BUFFER,     \
                               GstVaapiVideoBufferClass))

typedef struct _GstVaapiVideoBuffer             GstVaapiVideoBuffer;
typedef struct _GstVaapiVideoBufferPrivate      GstVaapiVideoBufferPrivate;
typedef struct _GstVaapiVideoBufferClass        GstVaapiVideoBufferClass;

struct _GstVaapiVideoBuffer {
    /*< private >*/
    GstBuffer parent_instance;

    GstVaapiVideoBufferPrivate *priv;
};

struct _GstVaapiVideoBufferClass {
    /*< private >*/
    GstBufferClass parent_class;
};

GType
gst_vaapi_video_buffer_get_type(void);

GstBuffer *
gst_vaapi_video_buffer_new_from_pool(GstVaapiVideoPool *pool);

GstBuffer *
gst_vaapi_video_buffer_new_with_image(GstVaapiImage *image);

GstBuffer *
gst_vaapi_video_buffer_new_with_surface(GstVaapiSurface *surface);

GstVaapiImage *
gst_vaapi_video_buffer_get_image(GstVaapiVideoBuffer *buffer);

GstVaapiSurface *
gst_vaapi_video_buffer_get_surface(GstVaapiVideoBuffer *buffer);

G_END_DECLS

#endif /* GST_VAAPI_VIDEO_BUFFER_H */