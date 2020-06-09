#include "../header/Mighty.h"

using namespace std;

Mighty::Mighty(Equipment* obj) : EquipmentDecorator(obj) {}

string Mighty::getDescription() {
		return "Mighty " + e->getDescription() + "\nThis weapon is mighty, so it has more attack power.";
}

int Mighty::getDefense() {
		return 0; //Not implemented yet
}

int Mighty::getDamage() {
		return e->getDamage() + 3;
}
