#include "../header/EquipmentDecorator.h"

using namespace std;

EquipmentDecorator::EquipmentDecorator(Equipment* obj) : e(obj) {}

string EquipmentDecorator::getDescription() {
			return e->getDescription();
}
		
int EquipmentDecorator::getDefense() {
			return 0; //Not implemented yet
}
		
int EquipmentDecorator::getDamage() {
			return e->getDamage();
}
