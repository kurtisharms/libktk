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
        WidgetVector.push_back(w);
    }

    void FrameBase::remove(Widget* w)
    {
        Widget* iw;
        for (unsigned int i=0; i<WidgetVector.size(); i++)
        {
            iw = WidgetVector[i];
            if (iw->getId() == w->getId())
            {
                WidgetVector.erase(WidgetVector.begin() + i);
            }
        }
    }

    void FrameBase::passEvent(Event* ev)
    {
    }

} // Ktk namespace
