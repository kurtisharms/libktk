#include "Signal.h"

namespace Ktk
{

    Signal::Signal()
    {
        //ctor
    }

    Signal::~Signal()
    {
        //dtor
    }

    void Signal::connect(func funcPtr)
    {
        funcVector.push_back(funcPtr);
    }

    void Signal::disconnect(func funcPtr)
    {
        for (unsigned int i=0; i<funcVector.size(); i++)
        {
            if (funcVector[i] == funcPtr)
            {
                funcVector.erase(funcVector.begin() + i);
            }
        }
    }


    void Signal::raise()
    {
        vector<func>::iterator it;
        for (it=funcVector.begin() ; it < funcVector.end(); it++)
        {
            (*it)();
        }
    }

    void Signal::clear()
    {
        funcVector.clear();
    }

    bool Signal::isEmpty()
    {
        return (funcVector.empty()) ? true : false;
    }

    Signal& Signal::operator+=(func funcPtr)
    {
        connect(funcPtr);
        return *this;
    }

    Signal& Signal::operator-=(func funcPtr)
    {
        disconnect(funcPtr);
        return *this;
    }



} // Ktk namespace
