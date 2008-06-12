#ifndef FRAMEBASE_H
#define FRAMEBASE_H
#include "Ktk.h"

namespace Ktk
{

    class FrameBase
    {
    public:
        FrameBase();
        virtual ~FrameBase();
    protected:
    private:
    public:
        template <class WidgetType>
        void add(WidgetType *w)
        {
            cout << "hi" << w <<endl;
        }
        template <class WidgetType>
        void remove(WidgetType *w)
        {
        }
    };

} // Ktk namespace

#endif // FRAMEBASE_H
