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

        Ktk::Signal OnDraw;
        Ktk::Signal OnMouseOver;
        Ktk::Signal OnMouseOut;
        Ktk::Signal OnMouseMove;
        Ktk::Signal OnMove;
        Ktk::Signal OnClose;
        Ktk::Signal OnResize;
    protected:
    private:

    };

} // Ktk namespace

#endif // FRAMEBASE_H
