#ifndef __PLAYERCONTROLLER_H__
#define __PLAYERCONTROLLER_H__

#include "gameBoard.h"

class PlayerController
{
     public:
	     PlayerController();
	     void mvUp();
	     void mvRight();
	     void mvDown();
	     void mvLeft();
	     int getMv();

     private:
	 int localPosX,localPosY;


}
