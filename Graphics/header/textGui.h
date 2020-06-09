#ifndef __TEXTGUI_H__
#define __TEXTGUI_H__
#include "graphics.h"

class TextGui : public Graphics
{
    public:
        TextGui(int winY, int winX, int startPosY, int startPosX);
        virtual void draw();
        void setMap(std::vector<std::string>);
    private:
        WINDOW* win;
        std::vector<std::string>map;
};
#endif //__TEXTGUI_H__
