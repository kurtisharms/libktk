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
            for (int i=0; i<WidgetList.size(); i++) {
            //for (vector<Widget*>::iterator it = WidgetList.begin(); it!=WidgetList.end(); ++it) {
                iw = WidgetList[i];
                if(iw->getId() == w->getId())
                {
                    WidgetList.erase(WidgetList.begin() + i);
                }
            }
         }

} // Ktk namespace
