#include "Button.h"

namespace Ktk
{

    Button::Button()
    {
        options.fontFace = "Arial";

    }

    Button::~Button()
    {
        //dtor
    }

    void Button::OnDrawCall()
    {
        cairo_t*  cr = createCairoContext();

        Label* l = new Label();
        l->setTextPadding(options.padding);
        l->setPosition(0,0);
        l->setSize(getWidth(),getHeight());
        l->setText(options.text);
        l->setFontFace(options.fontFace);
        l->setFontSize(options.fontSize);
        l->draw_call(cr);

        destroyCairoContext(cr);
    }

    void Button::setText(std::string text)
    {
        options.text = text;
    }

    void Button::setFontFace(std::string fontFace)
    {
        options.fontFace = fontFace;
    }

    void Button::setItalic(bool var)
    {
        options.italicFont = var;
    }

    void Button::setBold(bool var)
    {
        options.boldFont = var;
    }

    void Button::setFontSize(double fontSize)
    {
        options.fontSize = fontSize;
    }

    void Button::setTextPadding(double padding)
    {
        options.padding = padding;
    }

    std::string Button::getFontFace()
    {
        return options.fontFace;
    }

    bool Button::getItalic()
    {
        return options.italicFont;
    }

    bool Button::getBold()
    {
        return options.boldFont;
    }

    double Button::getFontSize()
    {
        return options.fontSize;
    }

    double Button::getTextPadding()
    {
        return options.padding;
    }

} // Ktk namespace
