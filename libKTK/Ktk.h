#ifndef KTK_H
#define KTK_H

#include "depends.h"

#ifdef CAIRO_HAS_XLIB_SURFACE
extern "C"
{
#include <cairo-xlib.h>
#include <X11/Xutil.h>
}

#include "Frame_X11.h"
#endif // CAIRO_HAS_XLIB_SURFACE

/*
    We won't include the files below if we are building the library
    BUILD_LIB should be defined in the library project's #defines list options
*/
#ifndef BUILD_LIB
#include "Widget.h"
#include "Button.h"
#endif // BUILD_LIB

#endif // KTK_H
