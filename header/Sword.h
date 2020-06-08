#ifndef SWORD_H
#define SWORD_H

#include "Equipment.h"

using namespace std;

//CONCRETE COMPONENT

class Sword : public Equipment {
	public:
		string getDescription() {
			return "Sword: the tried-and-true weapon!\nThis weapon has consistent, high damage output.";
		}

		int getDefense() {
			return 0; //Not implemented yet
		}

		int getDamage() {
			return 5;
		}
};
#endif
