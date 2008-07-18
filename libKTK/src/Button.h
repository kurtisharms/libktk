#ifndef BUTTON_H
#define BUTTON_H
#include "Ktk.h"
#include "Widget.h"

namespace Ktk
{

    class Button: public Ktk::Widget
    {
    public:
        Button();
        virtual ~Button();
        virtual void draw();

        void setText(std::string text);
        void setFontFace(std::string fontFace);
        void setItalic(bool var);
        void setBold(bool var);
        void setFontSize(double fontSize);
        void setTextPadding(double padding);

        std::string getText();
        std::string getFontFace();
        bool getItalic();
        bool getBold();
        double getFontSize();
        double getTextPadding();


    protected:
        typedef struct options
        {
            std::string fontFace;
            bool boldFont;
            bool italicFont;
            double fontSize;
            std::string text;
            double padding;
        } options_t;

        options_t options;
    private:
    };

} // Ktk namespace

#endif // BUTTON_H
