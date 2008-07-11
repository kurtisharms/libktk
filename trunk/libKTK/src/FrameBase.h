#ifndef FRAMEBASE_H
#define FRAMEBASE_H
#include "Ktk.h"
#include "Widget.h"

namespace Ktk
{

    class FrameBase
    {
    public:
        FrameBase();
        virtual ~FrameBase();
        vector<Ktk::Widget*> WidgetList;
        vector<Ktk::CairoSurface*> CairoSurfaceVector;
        void add(Widget* w);
        void remove(Widget* w);

        virtual void setVisible(bool visible) = 0;
        virtual void destroy() = 0;
        virtual int exec() = 0;
        virtual void setTitle(string title) = 0;
        virtual void setSize(int width, int height) = 0;
        virtual void setBackgroundColor(int red, int green, int blue) = 0;
        virtual void setPosition(int xpos, int ypos) = 0;
        virtual void setIconify(bool state) = 0;
        virtual string getTitle() = 0;
        virtual int getWidth() = 0;
        virtual int getHeight() = 0;
        virtual int getPosX() = 0;
        virtual int getPosY() = 0;
        virtual void raise() = 0;
        virtual void lower() = 0;

        Ktk::Signal<Event*> OnDraw;
        Ktk::Signal<Event*> OnMouseOver;
        Ktk::Signal<Event*> OnMouseOut;
        Ktk::Signal<Event*> OnMouseMove;
        Ktk::Signal<Event*> OnMove;
        Ktk::Signal<Event*> OnClose;
        Ktk::Signal<Event*> OnResize;
    protected:
    private:

    };

} // Ktk namespace

#endif // FRAMEBASE_H
