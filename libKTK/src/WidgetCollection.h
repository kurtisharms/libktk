#ifndef WIDGETCOLLECTION_H
#define WIDGETCOLLECTION_H
#include "Ktk.h"
#include "Widget.h"

namespace Ktk
{

class WidgetCollection
{
    public:
        WidgetCollection();
        virtual ~WidgetCollection();
        void add(Ktk::Widget* w);
        void remove(Ktk::Widget* w);
        void drawPass();
        void draw();
        void drawFinal();
        void drawAll();
    protected:
        vector<Ktk::Widget*> WidgetVector;
    private:
};

} // Ktk namespace

#endif // WIDGETCOLLECTION_H
