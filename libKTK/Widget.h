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
    protected:
        int widgetId;
    private:
    };

} // Ktk namespace

#endif // WIDGET_H
