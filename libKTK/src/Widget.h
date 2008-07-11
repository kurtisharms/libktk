#ifndef WIDGET_H
#define WIDGET_H
#include "Ktk.h"
#include "CairoSurface.h"
#include "Signal.h"

namespace Ktk
{

    class Widget
    {
    public:
        Widget();
        virtual ~Widget();
        virtual void draw() = 0;
        int getId();

        Ktk::Signal<Event*> OnDraw;
        Ktk::Signal<Event*> OnMouseOver;
        Ktk::Signal<Event*> OnMouseOut;
        Ktk::Signal<Event*> OnMouseMove;
        Ktk::Signal<Event*> OnFocus;
        Ktk::Signal<Event*> OnBlur;
    protected:
        int widgetId;
    private:
    };

} // Ktk namespace

#endif // WIDGET_H
