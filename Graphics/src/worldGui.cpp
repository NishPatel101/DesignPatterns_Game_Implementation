#include "../header/worldGui.h"

WorldGui::WorldGui(int height, int width, int posY, int posX, std::vector<std::vector>map) : Graphics()
{
    winY = height;
    winX = width;
    startPosY = posY;
    startPosX = posX
    
    win = newwin(winY, winX, startPosY, startPosX);
    box(win,0,0);
    setMap(map);
};

virtual void WorldGui::draw()
{
    int row, col;
    char * c;
    for(row = 0; row < 30; row++)
    {
        for(col = 0; col < 60; col++)
        {
            c = &map[row].at(col);
            mvwprintw(win, row + 1, col + 30, "%c", *c);
        }
    }
    wrefresh(win);  
}

void WorldGui::setMap(std::vector<std::string> temp)
{
    map = temp;
}


