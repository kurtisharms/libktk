#ifndef LABEL_H
#define LABEL_H
#include "Ktk.h"
#include "Widget.h"

namespace Ktk
{

    class Label: public Ktk::Widget
    {
    public:
        Label();
        virtual ~Label();
        virtual void OnDrawCall();

        void setText(std::string text);
        void setFontFace(std::string fontFace);
        void setItalic(bool var);
        void setBold(bool var);
        void setFontSize(double fontSize);
        void setTextPadding(double padding);
        void setBackgroundColor(double red, double green, double blue);

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
            bool paintBG;
            double bg_red;
            double bg_green;
            double bg_blue;
        } options_t;

        options_t options;
    private:
    };

} // Ktk namespace

#endif // LABEL_H
