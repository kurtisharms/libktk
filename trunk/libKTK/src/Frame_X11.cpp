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
        setBackgroundColor(1,1,1);

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
        cairo_surface_t *surface;
        //cairo_t *cr; We declare this in the Frame_X11.h class header file
        Visual *visual = DefaultVisual(win->dpy, DefaultScreen (win->dpy));

        XClearWindow(win->dpy, win->win);

        surface = cairo_xlib_surface_create (win->dpy, win->win, visual,
                                             win->width, win->height);
        cr = cairo_create(surface);

        cairo_set_source_rgb(cr, win->backgroundColor[0], win->backgroundColor[1], win->backgroundColor[2]);
        cairo_rectangle(cr, 0, 0, getWidth(), getHeight());
        cairo_fill(cr);

        std::sort(WidgetVector.begin(), WidgetVector.end());
        for (unsigned int i=0; i<WidgetVector.size(); i++)
        {
            WidgetVector[i]->draw_call(cr);
        }

        cairo_destroy(cr);
        cairo_surface_destroy (surface);
    }

    void Frame::win_handle_events()
    {
        XEvent xev;

        while (1)
        {
            XNextEvent(win->dpy, &xev);
            switch (xev.type)
            {

            case ButtonPress:
            {
                /* store the mouse button coordinates in 'int' variables. */
                /* also store the ID of the window on which the mouse was */
                /* pressed.                                               */
                int x = xev.xbutton.x;
                int y = xev.xbutton.y;
                //the_win = xev.xbutton.window;

                /* check which mouse button was pressed, and act accordingly. */
                switch (xev.xbutton.button)
                {
                case Button1:
                    /* draw a pixel at the mouse position. */
                    break;
                case Button2:
                    /* erase a pixel at the mouse position. */
                    break;
                default: /* probably 3rd button - just ignore this event. */
                    break;
                }
                break;
            }


            case MotionNotify:
            {
                /* store the mouse button coordinates in 'int' variables. */
                /* also store the ID of the window on which the mouse was */
                /* pressed.                                               */
                int x = xev.xmotion.x;
                int y = xev.xmotion.y;
                //the_win = an_event.xbutton.window;

                /* if the 1st mouse button was held during this event, draw a pixel */
                /* at the mouse pointer location.                                   */
                if (xev.xmotion.state & Button1Mask)
                {
                    /* draw a pixel at the mouse position. */
                }
                break;
            }



            case KeyPress:
            {
                XKeyEvent *xkev = &xev.xkey;
                if (xkev->keycode == win->quit_code)
                {
                    return;
                }

                KeySym key_symbol = XKeycodeToKeysym(win->dpy, xev.xkey.keycode, 0);
                switch (key_symbol)
                {
                case XK_1:
                case XK_KP_1: /* '1' key was pressed, either the normal '1', or */
                    /* the '1' on the keypad. draw the current pixel. */
                    break;
                case XK_Delete: /* DEL key was pressed, erase the current pixel. */
                    break;
                default:  /* anything else - check if it is a letter key */
                    if (key_symbol >= XK_A && key_symbol <= XK_Z)
                    {
                        int ascii_key = key_symbol - XK_A + 'A';
                        char c = static_cast<char>(ascii_key);
                        kev->ckey = c;
                        kev->key.assign(1,c);
                        OnKeyDownCall(kev);
                    }
                    if (key_symbol >= XK_a && key_symbol <= XK_z)
                    {
                        int ascii_key = key_symbol - XK_a + 'a';
                        char c = static_cast<char>(ascii_key);
                        kev->ckey = c;
                        kev->key.assign(1,c);
                        OnKeyDownCall(kev);
                    }
                    break;

                }
                OnKeyDown.raise(kev);
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

    void Frame::setBackgroundColor(float red, float green, float blue)
    {
        red = (red > 1.0) ? 1.0 : red;
        red = (red < 0) ? 0 : red;

        green = (green > 1.0) ? 1.0 : green;
        green = (green < 0) ? 0 : green;

        blue = (blue > 1.0) ? 1.0 : blue;
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






