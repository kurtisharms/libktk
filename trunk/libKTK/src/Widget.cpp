#include "Widget.h"

namespace Ktk
{

    Widget::Widget()
    {
        srand((unsigned)time(0));
        widgetId = rand();
    }

    Widget::~Widget()
    {
        //dtor
    }

    int Widget::getId()
    {
        return widgetId;
    }





} // Ktk namespace
