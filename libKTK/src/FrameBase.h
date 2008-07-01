#ifndef FRAMEBASE_H
#define FRAMEBASE_H
#include "Ktk.h"
#include "Widget.h"

namespace Ktk
{

    class FrameBase
    {
    public:
        FrameBase();
        virtual ~FrameBase();
        vector<Ktk::Widget*> WidgetList;
        void add(Widget* w);
        void remove(Widget* w);

        boost::signal<void ()> OnDraw;
        boost::signal<void ()> OnMouseOver;
        boost::signal<void ()> OnMouseOut;
        boost::signal<void ()> OnMouseMove;
        boost::signal<void ()> OnMove;
        boost::signal<void ()> OnClose;
        boost::signal<void ()> OnResize;
    protected:
    private:

    };

} // Ktk namespace

#endif // FRAMEBASE_H
