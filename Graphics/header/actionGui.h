#ifndef __ACTIONGUI_H__
#define __ACTIONGUI_H__
#include "graphics.h"

class ActionGui : public Graphics
{
    public:
        ActionGui(int winY, int winX, int startPosY, int startPosX);
        virtual void draw();
        virtual void setMap(std::vector<std::string>);
    private:
        WINDOW* win;
        std::vector<std::string>map;
};
#endif //__ACTIONGUI_H__
