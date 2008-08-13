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

    void WidgetCollection::drawPass()
    {
        for (unsigned int i=0; i<WidgetVector.size(); i++)
        {
            WidgetVector[i]->OnDrawPassCall();
        }
    }

    void WidgetCollection::draw()
    {
        for (unsigned int i=0; i<WidgetVector.size(); i++)
        {
            WidgetVector[i]->OnDrawCall();
        }
    }

    void WidgetCollection::drawFinal()
    {
        for (unsigned int i=0; i<WidgetVector.size(); i++)
        {
            WidgetVector[i]->OnDrawFinalCall();
        }
    }

    void WidgetCollection::drawAll()
    {
        for (unsigned int i=0; i<WidgetVector.size(); i++)
        {
            WidgetVector[i]->OnDrawPassCall();
        }

        for (unsigned int i=0; i<WidgetVector.size(); i++)
        {
            WidgetVector[i]->OnDrawCall();
        }

        for (unsigned int i=0; i<WidgetVector.size(); i++)
        {
            WidgetVector[i]->OnDrawFinalCall();
        }
    }

} // Ktk namespace
