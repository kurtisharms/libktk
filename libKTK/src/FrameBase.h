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
        void add(Widget* w);
        void remove(Widget* w);

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
