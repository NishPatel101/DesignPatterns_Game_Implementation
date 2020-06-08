#ifndef DEADLY_H
#define DEADLY_H

#include "EquipmentDecorator.h"

using namespace std;

//CONCRETE DECORATOR

class Deadly : public EquipmentDecorator {
public:
	Deadly(Equipment* obj) : EquipmentDecorator(obj) {}

	string getDescription() {
		return "Deadly " + e->getDescription() + "\nThis weapon is deadly, so it has a lot more attack power.";
	}

	int getDefense() {
		return 0; //Not implemented yet
	}

	int getDamage() {
		return e->getDamage() + 5;
	}
};
#endif

