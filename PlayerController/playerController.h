#ifndef __PLAYERCONTROLLER_H__
#define __PLAYERCONTROLLER_H__

#include "../GameBoard/gameBoard.h"

class PlayerController
{
     public:
	     PlayerController();
	     void mvUp();
	     void mvRight();
	     void mvDown();
	     void mvLeft();
	     int getMv();
	     int getPosX();
	     int getPosY();


     private:
	 int localPosX,localPosY;


};
#endif //__PLAYERCONTROLLER_H__
