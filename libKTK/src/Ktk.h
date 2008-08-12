#ifndef KTK_H
#define KTK_H

#include "depends.h"

#ifdef CAIRO_HAS_XLIB_SURFACE
extern "C"
{
#include <cairo-xlib.h>
#include <X11/Xutil.h>
}
#ifndef BUILD_LIB
#include "FrameBase.h"
#include "Frame_X11.h"
#endif // BUILD_LIB
#endif // CAIRO_HAS_XLIB_SURFACE

/*
    We won't include the files below if we are building the library
    BUILD_LIB should be defined in the library project's #defines list options
*/
#ifndef BUILD_LIB
#include "Event.h"
#include "Signal.h"
#include "Widget.h"
#include "WidgetCollection.h"
#include "Button.h"
#endif // BUILD_LIB

#endif // KTK_H
