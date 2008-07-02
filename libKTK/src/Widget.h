#ifndef WIDGET_H
#define WIDGET_H
#include "Ktk.h"
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

        Ktk::Signal OnDraw;
        Ktk::Signal OnMouseOver;
        Ktk::Signal OnMouseOut;
        Ktk::Signal OnMouseMove;
        Ktk::Signal OnFocus;
        Ktk::Signal OnBlur;
    protected:
        int widgetId;
    private:
    };

} // Ktk namespace

#endif // WIDGET_H
