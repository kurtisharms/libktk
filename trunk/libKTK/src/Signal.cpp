#include "Signal.h"

namespace Ktk
{
    /*
        template<class TEvent>
        Signal<TEvent>::Signal()
        {
        }

        template<class TEvent>
        Signal<TEvent>::~Signal()
        {
        }

        template<class TEvent>
        void Signal<TEvent>::connect(func funcPtr)
        {
            funcVector.push_back(funcPtr);
        }

        template<class TEvent>
        void Signal<TEvent>::disconnect(func funcPtr)
        {
            for (unsigned int i=0; i<funcVector.size(); i++)
            {
                if (funcVector[i] == funcPtr)
                {
                    funcVector.erase(funcVector.begin() + i);
                }
            }
        }

        template<class TEvent>
        void Signal<TEvent>::raise()
        {
            //vector<func>::iterator it;
            //for (it=funcVector.begin() ; it < funcVector.end(); it++)
            //{
            //    (*it)();
            //}
        }

        template<class TEvent>
        void Signal<TEvent>::clear()
        {
            funcVector.clear();
        }

        template<class TEvent>
        bool Signal<TEvent>::isEmpty()
        {
            return (funcVector.empty()) ? true : false;
        }

        template<class TEvent>
        Signal<TEvent>& Signal<TEvent>::operator+=(func funcPtr)
        {
            connect(funcPtr);
            return *this;
        }

        template<class TEvent>
        Signal<TEvent>& Signal<TEvent>::operator-=(func funcPtr)
        {
            disconnect(funcPtr);
            return *this;
        }

    */

} // Ktk namespace
