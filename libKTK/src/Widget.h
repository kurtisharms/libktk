#ifndef WIDGET_H
#define WIDGET_H
#include "Ktk.h"

namespace Ktk
{

    class Widget
    {
    public:
        Widget();
        virtual ~Widget();
        virtual void draw() = 0;
        int getId();

        boost::signal<void ()> OnDraw;
        boost::signal<void ()> OnMouseOver;
        boost::signal<void ()> OnMouseOut;
        boost::signal<void ()> OnMouseMove;
        boost::signal<void ()> OnFocus;
        boost::signal<void ()> OnBlur;
    protected:
        int widgetId;
    private:
    };

} // Ktk namespace

#endif // WIDGET_H
