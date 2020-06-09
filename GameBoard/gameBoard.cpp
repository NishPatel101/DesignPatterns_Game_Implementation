#include "gameBoard.h"

GameBoard::GameBoard()
{

}

void GameBoard::loadMap(std::vector<std::string> map)
{
    gameMap = map;
}

void GameBoard::mvPlayer(int c)
{
    int x = player->getPosY();
    int y = player->getPosY();
    switch(c)
    {
        case 1:
	    if(gameMap[x+1].at(y) == ' ');
	    { 
		     //move up
		     //notify();
	    }
	    break;
	case 2:
	    if(gameMap[x].at(y+1) == ' ')
	    {
		     //move up
		    // notify();
	    }
	    break;
        case 3:
	    if(gameMap[x-1].at(y) == ' ')
	    {
		     //move up
		     //notify();
	    }
	    break;
	case 4:
	    if(gameMap[x].at(y-1) == ' ')
	    {
		     //move up
		     //notify();
	    }
	    break;
        default:
	     //invalid move
	    break;
    }
}

//WORLDGUI STUFF
void GameBoard::setGuiObject(Graphics* gui)
{
    world = gui;
}

void GameBoard::updateGuiMap()
{
    world->setMap(gameMap);
}

