#include "Ktk.hpp"

using namespace Ktk;

void fun(Event* test)
{
    cout << "Fun function" <<endl;
}

void ending(Event* x)
{
    cout << "Ending function" <<endl;
}

void beline()
{
}

int main()
{
    Frame *window = new Frame("hi there!",400,200,200,50);
    window->setVisible(1);
    window->setTitle("It Works!");
    window->setPosition(150,150);
    window->setIconify(true);
    Button *b = new Button();

    Event* x = new Event();
    b->OnMouseMove += ending;
    b->OnMouseMove += fun;
    b->OnMouseMove.raise(x);
    cout << "Waiting..." <<endl;
    b->OnMouseMove -= fun;
    b->OnMouseMove.raise(x);

    b->setTextPadding(10);
    b->setPosition(0,0);
    b->setSize(50,50);
    b->setText("hi there!");
    b->setFontFace("Monospace");
    b->setFontSize(20.0);

    Label *l = new Label();
    l->setTextPadding(10);
    l->setPosition(200,60);
    l->setSize(50,50);
    l->setText("There is a house upon a door...");
    l->setFontFace("Arial");
    l->setFontSize(20.0);

    window->add(b);
    window->add(l);

    return window->exec();
}



