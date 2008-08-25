#ifndef FRAMEBASE_H
#define FRAMEBASE_H
#include "Ktk.h"
#include "Widget.h"
#include "WidgetCollection.h"
#include "Event.h"
#include "MouseEvent.h"
#include "KeyEvent.h"

namespace Ktk
{

    class FrameBase
    {
    public:
        FrameBase();
        virtual ~FrameBase();
        vector<Ktk::Widget*> WidgetVector;
        WidgetCollection* WidgetList;
        void add(Widget* w);
        void remove(Widget* w);

        Event* ev;
        MouseEvent* mev;
        KeyEvent* kev;

        virtual void setVisible(bool visible) = 0;
        virtual void destroy() = 0;
        virtual int exec() = 0;
        virtual void setTitle(string title) = 0;
        virtual void setSize(int width, int height) = 0;
        virtual void setBackgroundColor(float red, float green, float blue) = 0;
        virtual void setPosition(int xpos, int ypos) = 0;
        virtual void setIconify(bool state) = 0;
        virtual string getTitle() = 0;
        virtual int getWidth() = 0;
        virtual int getHeight() = 0;
        virtual int getPosX() = 0;
        virtual int getPosY() = 0;
        virtual void raise() = 0;
        virtual void lower() = 0;

        Ktk::Signal<Event*> OnDraw;
        Ktk::Signal<Event*> OnExpose;
        Ktk::Signal<MouseEvent*> OnMouseOver;
        Ktk::Signal<MouseEvent*> OnMouseOut;
        Ktk::Signal<MouseEvent*> OnMouseMove;
        Ktk::Signal<MouseEvent*> OnMouseDown;
        Ktk::Signal<MouseEvent*> OnMouseUp;
        Ktk::Signal<KeyEvent*> OnKeyDown;
        Ktk::Signal<KeyEvent*> OnKeyUp;
        Ktk::Signal<Event*> OnClose;
        Ktk::Signal<Event*> OnResize;

        void OnDrawCall(Event* ev);
        void OnExposeCall(Event* ev);
        void OnMouseOverCall(MouseEvent* ev);
        void OnMouseOutCall(MouseEvent* ev);
        void OnMouseMoveCall(MouseEvent* ev);
        void OnMouseDownCall(MouseEvent* ev);
        void OnMouseUpCall(MouseEvent* ev);
        void OnKeyDownCall(KeyEvent* ev);
        void OnKeyUpCall(KeyEvent* ev);
        void OnCloseCall(Event* ev);
        void OnResizeCall(Event* ev);


    protected:
    private:

    };

} // Ktk namespace

#endif // FRAMEBASE_H
