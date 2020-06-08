#ifndef EQUIPMENTDECORATOR_H
#define EQUIPMENTDECORATOR_H

#include "Equipment.h"

using namespace std;

//DECORATOR

class EquipmentDecorator : public Equipment {
	protected:
		Equipment* e;
	public:
		EquipmentDecorator(Equipment* obj) : e(obj) {}

		string getDescription() {
			return e->getDescription();
		}
		
		int getDefense() {
			return 0; //Not implemented yet
		}
		
		int getDamage() {
			return e->getDamage();
		}
};
#endif
