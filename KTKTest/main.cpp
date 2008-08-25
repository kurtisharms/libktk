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

void beline(KeyEvent* x)
{
  std::ofstream myfile;
  myfile.open ("/home/kurtis/Desktop/example.txt", ios::out | ios::app);
  myfile << "Writing this to a file: " << x->key << "\n";
  myfile.close();
}

int main()
{
    Frame *window = new Frame("hi there!",400,200,200,50);
    window->setVisible(1);
    window->setTitle("It Works!");
    window->setPosition(150,150);
    window->setIconify(true);
    window->OnKeyDown += beline;
    Button *b = new Button();

    Event* x = new Event();
    b->OnMouseMove += ending;
    b->OnMouseMove += fun;
    b->OnMouseMove.raise(x);
    cout << "Waiting..." <<endl;
    b->OnMouseMove -= fun;
    b->OnMouseMove.raise(x);

    b->setTextPadding(10);
    b->setPosition(200,60);
    b->setSize(50,50);
    b->setText("hi there!");
    b->setFontFace("Monospace");
    b->setFontSize(20.0);

    Label *l = new Label();
    l->setTextPadding(10);
    l->setPosition(1,1);
    l->setSize(50,50);
    l->setText("There is a house upon a door...");
    l->setFontFace("Arial");
    l->setFontSize(20.0);

    Label *l2 = new Label();
    l2->setTextPadding(10);
    l2->setPosition(280,60);
    l2->setSize(100,50);
    l2->setText("File");
    l2->setFontFace("Mono");
    l2->setFontSize(15.0);

    Label *l3 = new Label();
    l3->setTextPadding(10);
    l3->setPosition(0,100);
    l3->setSize(100,50);
    l3->setText("File");
    l3->setFontFace("Sans");
    l3->setFontSize(10.0);

    window->add(b);
    window->add(l);
    window->add(l2);
    window->add(l3);

    return window->exec();
}



