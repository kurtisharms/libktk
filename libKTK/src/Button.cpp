#include "Button.h"

namespace Ktk
{

    Button::Button()
    {
        //ctor
    }

    Button::~Button()
    {
        //dtor
    }

    void Button::draw()
    {
        cairo_set_source_rgb(cr, 0.5, 0.5, 0.5);
        cairo_rectangle(cr, 40, 40, 60, 40);
        cairo_fill(cr);

        cairo_select_font_face (cr, "Arial", CAIRO_FONT_SLANT_NORMAL,
                                CAIRO_FONT_WEIGHT_NORMAL);
        cairo_set_font_size (cr, 20.0);

        cairo_move_to (cr, 50, 50);
        cairo_text_path (cr, "void");
        cairo_set_source_rgb (cr, 0, 0, 0);
        cairo_fill_preserve (cr);
        cairo_set_source_rgb (cr, 0, 0, 0);
        cairo_set_line_width (cr, 1);
        cairo_stroke (cr);

    }

} // Ktk namespace
