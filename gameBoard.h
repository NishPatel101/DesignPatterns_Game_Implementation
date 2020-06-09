#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__
#include <vector>
#include <string>
#include "playerController.h"

class GameBoard
{
    publid:
	GameBoard();
	void loadMap(std::vector<std::string>map);
	void Display();
	void mvPlayer(std::string);
    protected:
	std::vector<std::string>gameMap;
        PlayerController * player;
	PlayerController * enemy;
	std::vector<class Observer*> observerList;
	void attach(Observer*);
	void detach(Observer*);
	void notify();
};
#endif // __GAMEBOARD_H__

