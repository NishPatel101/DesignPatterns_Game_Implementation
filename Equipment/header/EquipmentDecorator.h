#ifndef EQUIPMENTDECORATOR_H
#define EQUIPMENTDECORATOR_H

#include "Equipment.h"

using namespace std;

//DECORATOR

class EquipmentDecorator : public Equipment {
	protected:
		Equipment* e;
	public:
		EquipmentDecorator(Equipment*);

		string getDescription();
		
		int getDefense();
		
		int getDamage();
};
#endif
