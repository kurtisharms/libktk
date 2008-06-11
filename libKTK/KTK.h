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


#endif // KTK_H
