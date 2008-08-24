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
        cairo_t* getDrawContext();
        cairo_surface_t* getDrawSurface();
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

        cairo_t* createCairoContext();
        void destroyCairoContext(cairo_t* crPTR);

        Ktk::Signal<Event*> OnDraw;
        Ktk::Signal<Event*> OnDrawPass;
        Ktk::Signal<Event*> OnDrawFinal;
        Ktk::Signal<Event*> OnMouseOver;
        Ktk::Signal<Event*> OnMouseOut;
        Ktk::Signal<Event*> OnMouseMove;
        Ktk::Signal<Event*> OnFocus;
        Ktk::Signal<Event*> OnBlur;

        virtual void OnDrawCall() = 0;
        virtual void OnMouseOverCall();
        virtual void OnMouseOutCall();
        virtual void OnMouseMoveCall();
        virtual void OnFocusCall();
        virtual void OnBlurCall();

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
        //cairo_t *cr;
        cairo_surface_t* widget_surface;
        cairo_t* parent_context;
        cairo_t* widget_context;
    private:
    };

} // Ktk namespace

#endif // WIDGET_H
