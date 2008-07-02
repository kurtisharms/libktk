#include "FrameBase.h"

namespace Ktk
{

    FrameBase::FrameBase()
    {
        //ctor
    }

    FrameBase::~FrameBase()
    {
        //dtor
    }
    void FrameBase::add(Widget* w)
    {
        WidgetList.push_back(w);
    }

    void FrameBase::remove(Widget* w)
    {
        Widget* iw;
        for (unsigned int i=0; i<WidgetList.size(); i++)
        {
            iw = WidgetList[i];
            if (iw->getId() == w->getId())
            {
                WidgetList.erase(WidgetList.begin() + i);
            }
        }
    }

} // Ktk namespace
