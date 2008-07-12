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
        void draw_call(cairo_t *crPTR);
        virtual void draw() = 0;
        int getId();
        void setZIndex(int i);
        int getZIndex();

        Ktk::Signal<Event*> OnDraw;
        Ktk::Signal<Event*> OnMouseOver;
        Ktk::Signal<Event*> OnMouseOut;
        Ktk::Signal<Event*> OnMouseMove;
        Ktk::Signal<Event*> OnFocus;
        Ktk::Signal<Event*> OnBlur;

        bool operator <(Widget* right)
        {
            if (this->getZIndex() < right->getZIndex()) return true;
            return false;
        }
    protected:
        int widgetId;
        int zindex;
        cairo_t *cr;
    private:
    };

} // Ktk namespace

#endif // WIDGET_H
