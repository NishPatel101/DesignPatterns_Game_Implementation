#include <ncurses.h>
#include "Graphics/header/graphics.h"
#include "Graphics/header/windowGui.h"
#include "Graphics/header/worldGui.h"
#include "Graphics/header/actionGui.h"
#include "fileReader.h"

int main(int argc, char**argv)
{
    FileReader file;
    initscr();
    noecho();
    cbreak();
    
    int yMax, xMax;
    getmaxyx(stdscr,yMax,xMax);

    Graphics * worldWin = new WorldGui(yMax/2,xMax/2,0,0, file.loadVector("map1.txt"));
    Graphics * actionWin = new ActionGui(yMax/2,xMax/2,0, xMax/2+1);
    
    Graphics * gameWin = new WindowGui(worldWin,actionWin);
    
    gameWin->draw();

    sleep(4);
    int c = getch();
    sleep(2);
    endwin();
    return 0;
}
