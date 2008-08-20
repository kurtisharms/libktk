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
        // To set the fontface, we must pass a char* to caro_select_font_face() in the second argument
        // We therefore create a temporary "fontFace" variable to hold the converted value from c++ type std::string
        //char* fontFace = new char [options.fontFace.size()+1];
        //strcpy (fontFace, options.fontFace.c_str());
        // To set the font text, we likewise have to make a temporary char* variable
        //char* buttonText = new char[options.text.size()+1];
        //strcpy (buttonText, options.text.c_str());

        cairo_set_source_rgb(cr, 0.5, 0.5, 0.5);
        cairo_rectangle(cr, getXPosition(), getYPosition(), getWidth(), getHeight());
        cairo_fill(cr);

        Label* l = new Label();
        l->setTextPadding(options.padding);
        l->setPosition(getXPosition(),getYPosition());
        l->setSize(getWidth(),getHeight());
        l->setText(options.text);
        l->setFontFace(options.fontFace);
        l->setFontSize(options.fontSize);
        l->draw_call(cr);

        /*cairo_select_font_face (cr, fontFace, (options.italicFont) ? CAIRO_FONT_SLANT_ITALIC : CAIRO_FONT_SLANT_NORMAL,
                                (options.boldFont) ? CAIRO_FONT_WEIGHT_BOLD : CAIRO_FONT_WEIGHT_NORMAL);
        cairo_set_font_size (cr, getFontSize());

        cairo_move_to (cr, getXPosition() + getTextPadding(), getYPosition() + getFontSize() + getTextPadding());
        cairo_text_path (cr, buttonText);
        cairo_set_source_rgb (cr, 0, 0, 0);
        cairo_fill_preserve (cr);
        cairo_set_source_rgb (cr, 0, 0, 0);
        cairo_set_line_width (cr, 1);
        cairo_stroke (cr);*/
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
