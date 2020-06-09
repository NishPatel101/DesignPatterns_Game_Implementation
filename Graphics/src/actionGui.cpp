#include "../header/actionGui.h"

ActionGui::ActionGui(int height, int width, int posY, int posX) : Graphics()
{
    winY = height;
    winX = width;
    startPosY = posY;
    startPosX = posX;
    
    win = newwin(winY, winX, startPosY, startPosX);
    box(win,0,0);
}

void ActionGui::draw()
{
    mvwprintw(win,1,1,"%s","I'm Mr. Meeseeks, look at me!");

    wrefresh(win);  
}

void ActionGui::setMap(std::vector<std::string> temp)
{
    map = temp;
}


