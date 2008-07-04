#include "Frame_X11.h"
#ifdef CAIRO_HAS_XLIB_SURFACE

namespace Ktk
{

    Frame::Frame(string title, int width, int height, int xpos, int ypos)
    {
        win = new win_t();
        win->title = title;
        win->width = width;
        win->height = height;
        win->xpos = xpos;
        win->ypos = ypos;

        win_init();
    }


    Frame::~Frame()
    {
        XDestroyWindow(win->dpy, win->win);
    }

    void Frame::win_init()
    {
        win->dpy = XOpenDisplay(0);

        if (win->dpy == NULL)
        {
            fprintf(stderr, "Failed to open display\n");
        }

        Window root;

        //win->width = getWidth();
        //win->height = getHeight();

        root = DefaultRootWindow(win->dpy);
        win->scr = DefaultScreen(win->dpy);

        win->win = XCreateSimpleWindow(win->dpy, root, 0, 0,
                                       win->width, win->height, 0,
                                       BlackPixel(win->dpy, win->scr), WhitePixel(win->dpy, win->scr));

        win->quit_code = XKeysymToKeycode(win->dpy, XStringToKeysym("Q"));

        XSelectInput(win->dpy, win->win,
                     KeyPressMask
                     |StructureNotifyMask
                     |ExposureMask);

        /* Create the window title property */
        XTextProperty window_title_property;
        /* This is the string to be translated into a property. */
        char* window_title = new char [getTitle().size()+1];
        strcpy (window_title, getTitle().c_str());
        /* translate the given string into an X property. */
        XStringListToTextProperty(&window_title, 1, &window_title_property);
        /* Apply the window title */
        XSetWMName(win->dpy, win->win, &window_title_property);

        setPosition(win->xpos, win->ypos);
    }

    void Frame::setVisible(bool visible)
    {
        if (visible)
        {
            XMapWindow(win->dpy, win->win);
            win_draw();
        }
        else
            XUnmapWindow(win->dpy, win->win);
    }

    void Frame::win_draw()
    {
    }

    void Frame::win_handle_events()
    {
        XEvent xev;

        while (1)
        {
            XNextEvent(win->dpy, &xev);
            switch (xev.type)
            {
            case KeyPress:
            {
                XKeyEvent *kev = &xev.xkey;

                if (kev->keycode == win->quit_code)
                {
                    return;
                }
            }
            break;
            case ConfigureNotify:
            {
                XConfigureEvent *cev = &xev.xconfigure;

                win->width = cev->width;
                win->height = cev->height;
            }
            break;
            case Expose:
            {
                XExposeEvent *eev = &xev.xexpose;

                if (eev->count == 0)
                    win_draw();
            }
            break;
            }
        }
    }

    int Frame::exec()
    {
        win_handle_events();
        return 1;
    }


    void Frame::destroy()
    {
        XDestroyWindow(win->dpy, win->win);
    }

    void Frame::setTitle(string title)
    {
        win->title = title;
        /* Create the window title property */
        XTextProperty window_title_property;
        /* This is the string to be translated into a property. */
        char* window_title = new char [getTitle().size()+1];
        strcpy (window_title, getTitle().c_str());
        /* translate the given string into an X property. */
        XStringListToTextProperty(&window_title, 1, &window_title_property);
        /* Apply the window title */
        XSetWMName(win->dpy, win->win, &window_title_property);
    }

    void Frame::setSize(int width, int height)
    {
        win->width = width;
        win->height = height;
        XResizeWindow(win->dpy, win->win, win->width, win->height);
    }

    void Frame::setPosition(int xpos, int ypos)
    {
        win->xpos = xpos;
        win->ypos = ypos;
        XMoveWindow(win->dpy, win->win, win->xpos, win->ypos);
    }

    void Frame::setIconify(bool state)
    {
        if (state)
            XIconifyWindow(win->dpy, win->win, DefaultScreen(win->dpy));
        else
            XMapWindow(win->dpy, win->win);
    }

    void Frame::setBackgroundColor(int red, int green, int blue)
    {
        red = (red > 255) ? 255 : red;
        red = (red < 0) ? 0 : red;

        green = (green > 255) ? 255 : green;
        green = (green < 0) ? 0 : green;

        blue = (blue > 255) ? 255 : blue;
        blue = (blue < 0) ? 0 : blue;

        win->backgroundColor[0] = red;
        win->backgroundColor[1] = green;
        win->backgroundColor[2] = blue;
    }

    string Frame::getTitle()
    {
        return win->title;
    }

    int Frame::getWidth()
    {
        XWindowAttributes win_attr;
        XGetWindowAttributes(win->dpy, win->win, &win_attr);
        win->width = win_attr.width;
        return win->width;
    }

    int Frame::getHeight()
    {
        XWindowAttributes win_attr;
        XGetWindowAttributes(win->dpy, win->win, &win_attr);
        win->height = win_attr.height;
        return win->height;
    }

    int Frame::getPosX()
    {
        XWindowAttributes win_attr;
        XGetWindowAttributes(win->dpy, win->win, &win_attr);
        win->xpos = win_attr.x;
        return win->xpos;
    }

    int Frame::getPosY()
    {
        XWindowAttributes win_attr;
        XGetWindowAttributes(win->dpy, win->win, &win_attr);
        win->ypos = win_attr.y;
        return win->ypos;
    }

    void Frame::raise()
    {
        XRaiseWindow(win->dpy, win->win);
    }

    void Frame::lower()
    {
        XLowerWindow(win->dpy, win->win);
    }

} // Ktk namespace

#endif // CAIRO_HAS_XLIB_SURFACE






