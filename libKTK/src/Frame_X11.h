#ifndef FRAME_H
#define FRAME_H
#include "Ktk.h"
#include "FrameBase.h"
#ifdef CAIRO_HAS_XLIB_SURFACE

namespace Ktk
{

    class Frame: public Ktk::FrameBase
    {
    public:
        Frame(string title, int width, int height, int xpos, int ypos);
        virtual ~Frame();

        cairo_t *cr;

        void setVisible(bool visible);
        void destroy();
        int exec();
        void setTitle(string title);
        void setSize(int width, int height);
        void setBackgroundColor(float red, float green, float blue);
        void setPosition(int xpos, int ypos);
        void setIconify(bool state);

        string getTitle();
        int getWidth();
        int getHeight();
        int getPosX();
        int getPosY();

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

    };

} // Ktk namespace

#endif // CAIRO_HAS_XLIB_SURFACE
#endif // FRAME_H
