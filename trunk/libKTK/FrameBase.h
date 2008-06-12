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
    protected:
    private:
    public:
        template <class WidgetType>
        void add(WidgetType *w)
        {
            Widget *x = (Widget*) w;
            WidgetList.push_back(x);
            /*for (int i=0; i<WidgetList.size(); i++) {
                Widget* p = WidgetList[i];
                p->draw();
            }*/
        }

        template <class WidgetType>
        void remove(WidgetType *w)
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
    };

} // Ktk namespace

#endif // FRAMEBASE_H
