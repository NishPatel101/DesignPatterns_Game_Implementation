#include "gameBoard.h"

GameBoard::GameBoard()
{

}

void GameBoard::loadMap(std::vector<std::string>map)
{
    gameMap = map;
}

void GameBoard::Display()
{
    //update visual board
}

void GameBoard::mvPlayer(std::string mv)
{
    switch(mv)
    {
        case: "up"
	     if(gameMap[x+1][y] == " ")
	     {
		     //move up
		     //notify();
	     }
	     break;
        case: "right"
	     if(gameMap[x][y+1] == " ")
	     {
		     //move up
		     notify();
	     }
	     break;
        case: "down"
	     if(gameMap[x-1][y] == " ")
	     {
		     //move up
		     //notify();
	     }
	     break;
        case: "left"
	     if(gameMap[x][y-1] == " ")
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

void Attach(Observer* obs) 
{
     	observerList.push_back(obs); 
}
void Detach(Observer* obs)
{
    observerList.erase(std::remove(observerList.begin(), observerList.end(), obs));
}

void Notify()
{
    for (auto* o : observerList) 
    {
        o->Update(*this);
    }
}


