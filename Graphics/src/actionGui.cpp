#include "../header/actionGui.h"

ActionGui::ActionGui(int height, int width, int posY, int posX) : Graphics()
{
    winY = height;
    winX = width;
    startPosY = posY;
    startPosX = posX;
    
    win = newwin(winY, winX, startPosY, startPosX);
    box(win,0,0);
    map.push_back(" ");
    map.push_back(" ");
}

void ActionGui::draw()
{
    mvwprintw(win,1,1,"Player Name:%s", "Programmer");
    mvwprintw(win,2,1,"HP:%s", map[0].c_str());
    mvwprintw(win,1,10,"Enemy Name:%s", "carpeltunnel");
    mvwprintw(win,2,10,"HP:%s",map[1].c_str());
    
    wrefresh(win);  
}

void ActionGui::setMap(std::vector<std::string> temp)
{
    map = temp;
    draw();
}



