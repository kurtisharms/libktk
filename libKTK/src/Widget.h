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
        Widget(int xpos, int ypos, int width, int height);
        virtual ~Widget();
        void draw_call(cairo_t *crPTR);
        virtual void draw() = 0;
        virtual void drawPass();
        virtual void drawFinal();
        int getId();
        void setZIndex(int i);
        int getZIndex();

        virtual void setPosition(int xpos, int ypos);
        virtual void setXPosition(int xpos);
        virtual void setYPosition(int ypos);
        virtual void setSize(int width, int height);
        virtual void setWidth(int width);
        virtual void setHeight(int height);

        virtual int getXPosition();
        virtual int getYPosition();
        virtual int getWidth();
        virtual int getHeight();

        Ktk::Signal<Event*> OnDraw;
        Ktk::Signal<Event*> OnDrawPass;
        Ktk::Signal<Event*> OnDrawFinal;
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
        typedef struct values
        {
            int widgetId;
            int zindex;
            int xpos;
            int ypos;
            int width;
            int height;
        } values_t;
        values_t values;
        cairo_t *cr;
    private:
    };

} // Ktk namespace

#endif // WIDGET_H
