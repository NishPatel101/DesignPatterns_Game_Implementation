#include <ncurses.h>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <string>

#include "Graphics/header/graphics.h"
#include "Graphics/header/windowGui.h"
#include "Graphics/header/worldGui.h"
#include "Graphics/header/actionGui.h"
#include "Graphics/header/imagesGui.h"
#include "fileReader.h"

int main(int argc, char**argv)
{
    FileReader file;
    initscr();
    noecho();
    cbreak();
    refresh();

    int yMax, xMax;
    getmaxyx(stdscr,yMax,xMax);
    std::vector<std::string> temp = file.loadVector("Images/map1.txt");
    refresh();
    

    
    Graphics * worldWin = new WorldGui(yMax/2, xMax/2,0,0,temp);
    Graphics * actionWin = new ActionGui(yMax/2,xMax/2,0, xMax/2+1);
    Graphics * gameWin = new WindowGui(worldWin,actionWin);
    gameWin->draw();

    sleep(4);
    int d = getch();
    
    endwin();
    return 0;
}
