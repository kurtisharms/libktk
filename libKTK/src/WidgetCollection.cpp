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
            WidgetVector[i]->drawPass();
        }
}

void WidgetCollection::draw()
{
        for (unsigned int i=0; i<WidgetVector.size(); i++)
        {
            WidgetVector[i]->draw();
        }
}

void WidgetCollection::drawFinal()
{
        for (unsigned int i=0; i<WidgetVector.size(); i++)
        {
            WidgetVector[i]->drawFinal();
        }
}

void WidgetCollection::drawAll()
{
        for (unsigned int i=0; i<WidgetVector.size(); i++)
        {
            WidgetVector[i]->drawPass();
        }

                for (unsigned int i=0; i<WidgetVector.size(); i++)
        {
            WidgetVector[i]->draw();
        }

                for (unsigned int i=0; i<WidgetVector.size(); i++)
        {
            WidgetVector[i]->drawFinal();
        }
}

} // Ktk namespace
