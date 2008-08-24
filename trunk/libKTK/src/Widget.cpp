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
        parent_context = crPTR;
        //widget_surface = cairo_surface_create_similar( cairo_get_target(crPTR), CAIRO_CONTENT_COLOR, getWidth(), getHeight());
        this->OnDrawCall();
    }

    cairo_t* Widget::getDrawContext()
    {
        return widget_context;
    }

    cairo_surface_t* Widget::getDrawSurface()
    {
        return widget_surface;
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
        widget_surface = cairo_surface_create_similar( cairo_get_target(parent_context), CAIRO_CONTENT_COLOR, getWidth(), getHeight());
        widget_context = cairo_create(widget_surface);
       cairo_set_source_rgb (widget_context, 1, 1, 1);
        cairo_paint (widget_context);
        //cairo_rectangle(widget_context, getXPosition(), getYPosition(), getWidth(), getHeight());
        //cairo_clip(widget_context);
        return widget_context;
    }

    void Widget::destroyCairoContext(cairo_t* crPTR)
    {
        cairo_set_source_surface(parent_context,widget_surface,getXPosition(),getYPosition());
        cairo_paint (parent_context);
        //cairo_reset_clip (crPTR);
    }

    void Widget::OnMouseOverCall() {   }

    void Widget::OnMouseOutCall() {   }

    void Widget::OnMouseMoveCall() {   }

    void Widget::OnFocusCall() {   }

    void Widget::OnBlurCall() {   }




} // Ktk namespace
