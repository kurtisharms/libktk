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

        void FrameBase::OnDrawCall(Event* ev)
        {
        }

        void FrameBase::OnExposeCall(Event* ev) {   }
        void FrameBase::OnMouseOverCall(MouseEvent* ev) {   }
        void FrameBase::OnMouseOutCall(MouseEvent* ev) {   }
        void FrameBase::OnMouseMoveCall(MouseEvent* ev) {   }
        void FrameBase::OnMouseDownCall(MouseEvent* ev) {   }
        void FrameBase::OnMouseUpCall(MouseEvent* ev) {   }
        void FrameBase::OnKeyDownCall(KeyEvent* ev) {   }
        void FrameBase::OnKeyUpCall(KeyEvent* ev) {   }
        void FrameBase::OnCloseCall(Event* ev) {   }
        void FrameBase::OnResizeCall(Event* ev) {   }

} // Ktk namespace
