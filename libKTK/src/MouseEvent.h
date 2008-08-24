#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H
#include "Ktk.h"
#include "Event.h"

namespace Ktk
{

class MouseEvent: public Ktk::Event
{
    public:
        /** Default constructor */
        MouseEvent();
        /** Default destructor */
        virtual ~MouseEvent();
    protected:
    private:
};

} // Ktk namespace

#endif // MOUSEEVENT_H
