#ifndef AXE_H
#define AXE_H

#include "Equipment.h"

#include <time.h>

using namespace std;

//CONCRETE COMPONENT

class Axe : Equipment {
	public:
		string getDescription() {
			return "Axe: a heavy but effective weapon for combat!\nThis weapon does lower base damage than the sword but can potentially land a critical blow.";
		}
		
		int getDefense() {
			return 0; //Not implemented yet
		}

		int getDamage() {
			//Axe has base damage of 3 with a 1/10 chance of critical (7) damage
			srand(time(NULL));
			int x = rand() % 10 + 1;
			if (x == 5)
				return 7;
			else
				return 3;
		}
};
#endif
