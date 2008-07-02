#ifndef SIGNAL_H
#define SIGNAL_H
#include "Ktk.h"
#include "Event.h"

namespace Ktk
{

    class Signal
    {
    public:
        Signal();
        virtual ~Signal();
        typedef void (*func)();
    protected:
        vector<func> funcVector;
    public:
        void connect(func funcPtr);
        void disconnect(func funcPtr);
        void raise();
        void clear();
        bool isEmpty();
        Signal& operator+=(func funcPtr);
        Signal& operator-=(func funcPtr);
    };

} // Ktk namespace

#endif // SIGNAL_H
