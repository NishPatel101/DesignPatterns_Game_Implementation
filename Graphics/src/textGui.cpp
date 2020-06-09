#include "../header/textGui.h"

TextGui::TextGui(int height, int width, int posY, int posX) : Graphics()
{
    winY = height;
    winX = width;
    startPosY = posY;
    startPosX = posX;
    
    win = newwin(winY, winX, startPosY, startPosX);
    box(win,0,0);
    map.push_back(" ");
}

void TextGui::draw()
{
    mvwprintw(win,1,1,"%s",map[0].c_str());

    wrefresh(win);  
}

void TextGui::setMap(std::vector<std::string> temp)
{
    map[0] = "GGWP!";
    draw();
}


