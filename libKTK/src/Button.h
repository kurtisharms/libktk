#ifndef BUTTON_H
#define BUTTON_H
#include "Ktk.h"
#include "Widget.h"

namespace Ktk
{

    class Button: public Ktk::Widget
    {
    public:
        Button();
        virtual ~Button();
        virtual void draw();

    protected:
    private:
    };

} // Ktk namespace

#endif // BUTTON_H
