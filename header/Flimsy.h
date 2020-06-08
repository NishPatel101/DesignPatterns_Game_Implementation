#ifndef FLIMSY_H
#define FLIMSY_H

#include "EquipmentDecorator.h"

using namespace std;

//CONCRETE DECORATOR

class Flimsy : public EquipmentDecorator {
	public:
		Flimsy(Equipment* obj) : EquipmentDecorator(obj) {}

		string getDescription() {
			return "Flimsy " + e->getDescription() + "\nThis weapon is flimsy, so it has a little more attack power.";
		}

		int getDefense() {
			return 0; //Not implemented yet
		}

		int getDamage() {
			return e->getDamage() + 2;
		}
};
#endif

