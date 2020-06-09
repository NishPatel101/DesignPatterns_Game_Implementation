#include "../header/worldGui.h"

WorldGui::WorldGui(int height, int width, int posY, int posX, std::vector<std::string>tempMap) : Graphics()
{
    winY = height;
    winX = width;
    startPosY = posY;
    startPosX = posX;
    setMap(tempMap);
    win = newwin(height, width, posY, posX);
    box(win,0,0);
};

void WorldGui::draw()
{
    int row, col;
    char * c;
    for(row = 0; row < 20; row++)
    {
        for(col = 0; col < 20; col++)
        {
            c = &map[row].at(col);
            mvwprintw(win, row + 1, col + 1, "%c", *c);
        }
    }
    wrefresh(win);  
}

void WorldGui::setMap(std::vector<std::string> temp)
{
    map = temp;
}


