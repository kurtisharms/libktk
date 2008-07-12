#include "Widget.h"

namespace Ktk
{

    Widget::Widget()
    {
        zindex = 0;
        srand((unsigned)time(0));
        widgetId = rand();
    }

    Widget::~Widget()
    {
        //dtor
    }

    void Widget::draw_call(cairo_t *crPTR)
    {
        cr = crPTR;
        this->draw();
    }

    int Widget::getId()
    {
        return widgetId;
    }

    void Widget::setZIndex(int i)
    {
        zindex = i;
    }

    int Widget::getZIndex()
    {
        return zindex;
    }





} // Ktk namespace
