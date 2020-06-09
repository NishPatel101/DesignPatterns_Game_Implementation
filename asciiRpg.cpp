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
//--------------------------------
#include "GameBoard/gameBoard.h"
#include "PlayerController/playerController.h"
//--------------------------------
#include "FileRead/fileReader.h"
//=====================================
#include "BattleVisitor/BattleVisitor.h"
//=====================================
#include "Character/Character.h"
#include "Equipment/header/Equipment.h"
#include "Equipment/header/Axe.h"
#include "Equipment/header/Deadly.h"
#include "Equipment/header/EquipmentDecorator.h"
#include "Equipment/header/Flimsy.h"
#include "Equipment/header/Mighty.h"
#include "Equipment/header/Sword.h"





void battleMenu();

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
    std::vector<std::string> temp;
    refresh();
    printw("%d,%d",yMax,xMax);
    refresh();

    //setup logo window
    temp = file.loadVector("Images/logo1.txt");
    Graphics * logoWin = new ImagesGui(temp.size()+2,xMax/3,0,xMax/3, temp);
    allWin.push_back(logoWin);
    refresh();
    //setup world window
    temp = file.loadVector("Images/map1.txt");
    Graphics * worldWin = new WorldGui(yMax/2, xMax/2, logoWin->getWinY()+1,0,temp);
    allWin.push_back(worldWin);
    refresh();
    //setp up action window
    Graphics * actionWin = new ActionGui(yMax/2,xMax/2,logoWin->getWinY()+1, xMax/2+1);
    allWin.push_back(actionWin);
    refresh();
    //set up debug/log/chat
    int y = logoWin->getWinY() + worldWin->getWinY() + 1;
    Graphics * chatWin = new TextGui(yMax - y,xMax, y, 0);
    allWin.push_back(chatWin);
    refresh();

    //GameBoard set up
    GameBoard * gameBoard = new GameBoard(temp);
    gameBoard->setGuiObject(worldWin);
    //gameBoard->updateGuiMap();
    
    //create the composite graphics window
    
    Graphics * gameWin = new WindowGui(allWin);
    gameWin->draw();
    
    int d = getch();
    gameBoard->updateGuiMap();
    gameWin->draw();
    int e = getch();
    Equipment* wep = new Sword();
    Character * player = new Character("Programmer",69,wep);
    Character * enemy = new Character("CarpelTunnel",40,wep);

    BattleVisitor * fight = new BattleVisitor(player,enemy,actionWin);
    fight->doBattle();

    char z = getch();
    endwin();
    return 0;
}
