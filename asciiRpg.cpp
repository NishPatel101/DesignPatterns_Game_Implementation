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
    
    battleMenu();
    endwin();
    return 0;
}

void battleMenu()
{    
    WINDOW *w;
    char list[5][7] = { "One", "Two", "Three", "Four", "Five" };
    char item[7];
    int ch, i = 0, width = 7;
 
    initscr(); // initialize Ncurses
    w = newwin( 10, 12, 1, 1 ); // create a new window
    box( w, 0, 0 ); // sets default borders for the window
     
// now print all the menu items and highlight the first one
    for( i=0; i<5; i++ ) {
        if( i == 0 ) 
            wattron( w, A_STANDOUT ); // highlights the first item.
        else
            wattroff( w, A_STANDOUT );
        sprintf(item, "%-7s",  list[i]);
        mvwprintw( w, i+1, 2, "%s", item );
    }
 
    wrefresh( w ); // update the terminal screen
 
    i = 0;
    noecho(); // disable echoing of characters on the screen
    keypad( w, TRUE ); // enable keyboard input for the window.
    curs_set( 0 ); // hide the default screen cursor.
     
       // get the input
    while(( ch = wgetch(w)) != 'q'){ 
         
                // right pad with spaces to make the items appear with even width.
            sprintf(item, "%-7s",  list[i]); 
            mvwprintw( w, i+1, 2, "%s", item ); 
              // use a variable to increment or decrement the value based on the input.
            switch( ch ) {
                case KEY_UP:
                            i--;
                            i = ( i<0 ) ? 4 : i;
                            break;
                case KEY_DOWN:
                            i++;
                            i = ( i>4 ) ? 0 : i;
                            break;
            }
            // now highlight the next item in the list.
            wattron( w, A_STANDOUT );
             
            sprintf(item, "%-7s",  list[i]);
            mvwprintw( w, i+1, 2, "%s", item);
            wattroff( w, A_STANDOUT );
    }
}
