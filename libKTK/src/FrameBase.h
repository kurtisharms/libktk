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
    protected:
    private:

    };

} // Ktk namespace

#endif // FRAMEBASE_H
