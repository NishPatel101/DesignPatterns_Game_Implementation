#ifndef DEADLY_H
#define DEADLY_H

#include "EquipmentDecorator.h"

using namespace std;

//CONCRETE DECORATOR

class Deadly : public EquipmentDecorator {
public:
	Deadly(Equipment*);

	string getDescription();

	int getDefense();

	int getDamage();
};
#endif
