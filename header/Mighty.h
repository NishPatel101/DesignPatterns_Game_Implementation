#ifndef MIGHTY_H
#define MIGHTY_H

#include "EquipmentDecorator.h"

using namespace std;

//CONCRETE DECORATOR

class Mighty : public EquipmentDecorator {
public:
	Mighty(Equipment* obj) : EquipmentDecorator(obj) {}

	string getDescription() {
		return "Mighty " + e->getDescription() + "\nThis weapon is mighty, so it has more attack power.";
	}

	int getDefense() {
		return 0; //Not implemented yet
	}

	int getDamage() {
		return e->getDamage() + 3;
	}
};
#endif
