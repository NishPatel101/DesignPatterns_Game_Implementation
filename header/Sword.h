#ifndef SWORD_H
#define SWORD_H

#include "Equipment.h"

using namespace std;

//CONCRETE COMPONENT

class Sword : public Equipment {
	public:
		string getDescription();

		int getDefense();

		int getDamage();
};
#endif
