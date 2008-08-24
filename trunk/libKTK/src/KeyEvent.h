#ifndef KEYEVENT_H
#define KEYEVENT_H
#include "Ktk.h"
#include "Event.h"

namespace Ktk
{

class KeyEvent: public Ktk::Event
{
    public:
        /** Default constructor */
        KeyEvent();
        /** Default destructor */
        virtual ~KeyEvent();
    protected:
    private:
};

} // Ktk namespace

#endif // KEYEVENT_H
