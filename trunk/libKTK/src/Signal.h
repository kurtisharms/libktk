#ifndef SIGNAL_H
#define SIGNAL_H
#include "Ktk.h"
#include "Event.h"

namespace Ktk
{
    template<class TEvent>
    class Signal
    {
        TEvent item;
    public:
        Signal()
        {
        }

        virtual ~Signal()
        {
        }

        typedef void (*func)(TEvent);

    protected:
        vector<func> funcVector;

    public:
        void connect(func funcPtr)
        {
            funcVector.push_back(funcPtr);
        }

        void disconnect(func funcPtr)
        {
            for (unsigned int i=0; i<funcVector.size(); i++)
            {
                if (funcVector[i] == funcPtr)
                {
                    funcVector.erase(funcVector.begin() + i);
                }
            }
        }

        void raise(TEvent ev)
        {
            for (unsigned int i=0; i<funcVector.size(); i++)
            {
                func funcPtr = funcVector[i];
                funcPtr(ev);
            }
        }

        void clear()
        {
            funcVector.clear();
        }

        bool isEmpty()
        {
            return (funcVector.empty()) ? true : false;
        }


        Signal& operator+=(func funcPtr)
        {
            connect(funcPtr);
            return *this;
        }

        Signal& operator-=(func funcPtr)
        {
            disconnect(funcPtr);
            return *this;
        }
    };

} // Ktk namespace



#endif // SIGNAL_H
