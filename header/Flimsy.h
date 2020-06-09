#ifndef FLIMSY_H
#define FLIMSY_H

#include "EquipmentDecorator.h"

using namespace std;

//CONCRETE DECORATOR

class Flimsy : public EquipmentDecorator {
	public:
		Flimsy(Equipment*);

		string getDescription();

		int getDefense();

		int getDamage();
};
#endif
