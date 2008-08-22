#include "Label.h"


namespace Ktk
{

    Label::Label()
    {
        options.paintBG = false;
        options.fontFace = "Arial";
    }

    Label::~Label()
    {
        //dtor
    }

    void Label::OnDrawCall()
    {
        cairo_t* cr = createCairoContext();
        cairo_rectangle(cr, getXPosition(), getYPosition(), getWidth(), getHeight());
        cairo_clip(cr);
        // To set the fontface, we must pass a char* to caro_select_font_face() in the second argument
        // We therefore create a temporary "fontFace" variable to hold the converted value from c++ type std::string
        char* fontFace = new char [options.fontFace.size()+1];
        strcpy (fontFace, options.fontFace.c_str());
        // To set the font text, we likewise have to make a temporary char* variable
        char* labelText = new char[options.text.size()+1];
        strcpy (labelText, options.text.c_str());

        if (options.paintBG)
        {
            cairo_set_source_rgb(cr, options.bg_red, options.bg_green, options.bg_blue);
            cairo_rectangle(cr, getXPosition(), getYPosition(), getWidth(), getHeight());
            cairo_fill(cr);
        }

        cairo_select_font_face (cr, fontFace, (options.italicFont) ? CAIRO_FONT_SLANT_ITALIC : CAIRO_FONT_SLANT_NORMAL,
                                (options.boldFont) ? CAIRO_FONT_WEIGHT_BOLD : CAIRO_FONT_WEIGHT_NORMAL);
        cairo_set_font_size (cr, getFontSize());


        cairo_move_to (cr, getXPosition() + getTextPadding(), getYPosition() + getFontSize() + getTextPadding());
        cairo_text_path (cr, labelText);
        cairo_set_source_rgb (cr, 0, 0, 0);
        cairo_fill_preserve (cr);
        cairo_set_source_rgb (cr, 0, 0, 0);
        cairo_set_line_width (cr, 1);
        cairo_stroke (cr);
        cairo_reset_clip (cr);
    }

    void Label::setText(std::string text)
    {
        options.text = text;
    }

    void Label::setFontFace(std::string fontFace)
    {
        options.fontFace = fontFace;
    }

    void Label::setItalic(bool var)
    {
        options.italicFont = var;
    }

    void Label::setBold(bool var)
    {
        options.boldFont = var;
    }

    void Label::setFontSize(double fontSize)
    {
        options.fontSize = fontSize;
    }

    void Label::setTextPadding(double padding)
    {
        options.padding = padding;
    }

    void Label::setBackgroundColor(double red, double green, double blue)
    {
        options.paintBG = true;
        red = options.bg_red;
        green = options.bg_green;
        blue = options.bg_blue;
    }

    std::string Label::getFontFace()
    {
        return options.fontFace;
    }

    bool Label::getItalic()
    {
        return options.italicFont;
    }

    bool Label::getBold()
    {
        return options.boldFont;
    }

    double Label::getFontSize()
    {
        return options.fontSize;
    }

    double Label::getTextPadding()
    {
        return options.padding;
    }


} // Ktk namespace
