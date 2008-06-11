#ifndef FRAME_H
#define FRAME_H
#include "Ktk.h"
#ifdef CAIRO_HAS_XLIB_SURFACE

namespace Ktk
{

    class Frame
    {
    public:
        Frame(string title, int width, int height, int xpos, int ypos);
        virtual ~Frame();

        void setVisible(bool visible);
        void destroy();
        int exec();
        void setTitle(string title);
        void setSize(int width, int height);
        void setBackgroundColor(int red, int green, int blue);
        void setPosition(int xpos, int ypos);
        void setIconify(bool state);

        string getTitle();
        int getWidth();
        int getHeight();

        void raise();
        void lower();


    private:
        typedef struct win
        {
            Display *dpy;
            int scr;

            Window win;
            GC gc;

            KeyCode quit_code;

            string title;

            int backgroundColor[3];
            int width;
            int height;
            int xpos;
            int ypos;
        } win_t;

        win_t *win;

        void win_init();
        void win_draw();
        void win_handle_events();



    public:
        template <class WidgetType>
        void add(WidgetType *w)
        {
            cout << "hi" << w <<endl;
        }
        template <class WidgetType>
        void remove(WidgetType *w)
        {
        }

    };

} // Ktk namespace

#endif // CAIRO_HAS_XLIB_SURFACE
#endif // FRAME_H
