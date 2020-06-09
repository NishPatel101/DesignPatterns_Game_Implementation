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
#include "Graphics/header/textGui.h"
#include "fileReader.h"

int main(int argc, char**argv)
{
    FileReader file;
    std::vector<Graphics*>allWin;

    initscr();
    noecho();
    cbreak();
    refresh();

    int yMax, xMax;
    getmaxyx(stdscr,yMax,xMax);
    std::vector<std::string> temp = file.loadVector("Images/map1.txt");
    refresh();
    
    //setup logo window
    temp = file.loadVector("Images/logo1.txt");
    Graphics * logoWin = new ImagesGui(temp.size()+2,xMax/3,0,xMax/3, temp);
    allWin.push_back(logoWin);
    //setup world window
    temp = file.loadVector("Images/map1.txt");
    Graphics * worldWin = new WorldGui(yMax/2, xMax/2, logoWin->getWinY(),0,temp);
    allWin.push_back(worldWin);
    //setp up action window
    Graphics * actionWin = new ActionGui(yMax/2,xMax/2,logoWin->getWinY(), xMax/2+1);
    allWin.push_back(actionWin);

    //set up debug/log/chat
    int y = logoWin->getWinY() + worldWin->getWinY() + 1;
    Graphics * chatWin = new TextGui(yMax - y,xMax, y, 0);
    allWin.push_back(chatWin);

    //create the composite graphics window
    
    Graphics * gameWin = new WindowGui(allWin);
    gameWin->draw();

    sleep(4);
    int d = getch();
    
    endwin();
    return 0;
}
