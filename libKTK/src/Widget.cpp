#include "Widget.h"

namespace Ktk
{

    Widget::Widget()
    {
        values.zindex = 0;
        srand((unsigned)time(0));
        values.widgetId = rand();
    }


    Widget::Widget(int xpos, int ypos, int width, int height)
    {
        values.zindex = 0;
        srand((unsigned)time(0));
        values.widgetId = rand();

        values.xpos = xpos;
        values.ypos = ypos;
        values.width = width;
        values.height = height;
    }

    Widget::~Widget()
    {
        //dtor
    }

    void Widget::draw_call(cairo_t *crPTR)
    {
        similar_surface = cairo_surface_create_similar( cairo_get_target(crPTR), CAIRO_CONTENT_COLOR, getWidth(), getHeight());
        this->OnDrawCall();
    }

    void Widget::setDrawContext(cairo_t *crPTR)
    {
        widget_context = crPTR;
    }

    cairo_t* Widget::getDrawContext()
    {
        return widget_context;
    }

    int Widget::getId()
    {
        return values.widgetId;
    }

    void Widget::setZIndex(int i)
    {
        values.zindex = i;
    }

    int Widget::getZIndex()
    {
        return values.zindex;
    }

    void Widget::setPosition(int xpos, int ypos)
    {
        values.xpos = xpos;
        values.ypos = ypos;
    }

    void Widget::setXPosition(int xpos)
    {
        values.xpos = xpos;
    }

    void Widget::setYPosition(int ypos)
    {
        values.ypos = ypos;
    }

    void Widget::setSize(int width, int height)
    {
        values.width = width;
        values.height = height;
    }

    void Widget::setWidth(int width)
    {
        values.width = width;
    }

    void Widget::setHeight(int height)
    {
        values.height = height;
    }

    int Widget::getXPosition()
    {
        return values.xpos;
    }

    int Widget::getYPosition()
    {
        return values.ypos;
    }

    int Widget::getWidth()
    {
        return values.width;
    }

    int Widget::getHeight()
    {
        return values.height;
    }

    cairo_t* Widget::createCairoContext()
    {
        return cairo_create(similar_surface);
    }

    void Widget::OnMouseOverCall() {   }

    void Widget::OnMouseOutCall() {   }

    void Widget::OnMouseMoveCall() {   }

    void Widget::OnFocusCall() {   }

    void Widget::OnBlurCall() {   }




} // Ktk namespace
