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

int main()
{
    Frame *window = new Frame("hi there!",400,200,200,50);
    window->setVisible(1);
    window->setTitle("It Works!");
    window->setPosition(150,150);
    window->setIconify(true);
    Button *b = new Button();

    Event* x = new Event();
    b->OnMouseMove.connect(fun);
    b->OnMouseMove += ending;
    b->OnMouseMove.raise(x);
    cout << "Waiting..." <<endl;
    b->OnMouseMove -= fun;
    b->OnMouseMove.raise(x);

    window->add(b);
    window->remove(b);
    return window->exec();
}


/*
class test {
public:
    string title;
    void init();
    void hi();
};
void test::hi()
{
    int i = 20;
    cout << "hi! " << i <<endl;
    title = "BBBBBBBBB";
}
void test::init()
{
    int b = 10;
    title = "AAAAAA";
    boost::thread thrd(boost::bind(&test::hi,this));
    cout << "finished (hi) function and joined thread!" << endl;
    cout << title <<endl;
}
*/


