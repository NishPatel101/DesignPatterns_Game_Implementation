#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__
#include <vector>
#include <string>
#include "../PlayerController/playerController.h"
#include "../Graphics/header/graphics.h"
#include "../Graphics/header/worldGui.h"

class PlayerController;
class GameBoard
{
    public:
	GameBoard();
	void loadMap(std::vector<std::string>);
	
	//coupling hard
	void setGuiObject(Graphics*);
	void updateGuiMap();
	
	//character movement
	void mvPlayer(int);
    protected:
	std::vector<std::string>gameMap;
        PlayerController * player;
	PlayerController * enemy;
	Graphics * world;
};
#endif // __GAMEBOARD_H__

