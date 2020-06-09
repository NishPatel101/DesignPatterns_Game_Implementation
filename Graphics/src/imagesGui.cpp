#include "../header/imagesGui.h"

ImagesGui::ImagesGui(int height, int width, int posY, int posX, std::vector<std::string>map) : Graphics()
{
    winY = height;
    winX = width;
    startPosY = posY;
    startPosX = posX;
    
    win = newwin(height, width, posY, posX);
    box(win,0,0);
    setMap(map);
};

void ImagesGui::draw()
{
    int row, col;
    char * c;
    for(row = 0; row < map.size(); row++)
    {
        for(col = 0; col < map[row].size(); col++)
        {
            c = &map[row].at(col);
            mvwprintw(win, row + 1, col + 1, "%c", *c);
        }
    }
    wrefresh(win);  
}

void ImagesGui::setMap(std::vector<std::string> temp)
{
    map = temp;
}


