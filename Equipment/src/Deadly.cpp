#include "../header/Deadly.h"

using namespace std;

Deadly::Deadly(Equipment* obj) : EquipmentDecorator(obj) {}

string Deadly::getDescription() {
		return "Deadly " + e->getDescription() + "\nThis weapon is deadly, so it has a lot more attack power.";
}

int Deadly::getDefense() {
		return 0; //Not implemented yet
}

int Deadly::getDamage() {
		return e->getDamage() + 5;
}
