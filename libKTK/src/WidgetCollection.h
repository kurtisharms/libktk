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
        void setSurface(cairo_t *crPTR);
        void draw();
        void sort();
    protected:
        vector<Ktk::Widget*> WidgetVector;
    private:
    };

} // Ktk namespace

#endif // WIDGETCOLLECTION_H
