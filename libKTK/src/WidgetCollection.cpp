#include "WidgetCollection.h"

namespace Ktk
{

    WidgetCollection::WidgetCollection()
    {
        //ctor
    }

    WidgetCollection::~WidgetCollection()
    {
        //dtor
    }

    void WidgetCollection::setSurface(cairo_t *crPTR)
    {
    }

    void WidgetCollection::add(Ktk::Widget* w)
    {
        WidgetVector.push_back(w);
    }

    void WidgetCollection::remove(Ktk::Widget* w)
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

    void WidgetCollection::draw()
    {
        for (unsigned int i=0; i<WidgetVector.size(); i++)
        {
            WidgetVector[i]->OnDrawCall();
        }
    }

    void WidgetCollection::sort()
    {
        std::sort(WidgetVector.begin(), WidgetVector.end());
    }

} // Ktk namespace
