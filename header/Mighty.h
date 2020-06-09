#ifndef MIGHTY_H
#define MIGHTY_H

#include "EquipmentDecorator.h"

using namespace std;

//CONCRETE DECORATOR

class Mighty : public EquipmentDecorator {
public:
	Mighty(Equipment*);

	string getDescription();

	int getDefense();

	int getDamage();
};
#endif
