#include "..header/Flimsy.h"

using namespace std;

Flimsy::Flimsy(Equipment* obj) : EquipmentDecorator(obj) {}

string Flimsy::getDescription() {
			return "Flimsy " + e->getDescription() + "\nThis weapon is flimsy, so it has a little more attack power.";
}

int Flimsy::getDefense() {
			return 0; //Not implemented yet
}

int Flimsy::getDamage() {
			return e->getDamage() + 2;
}
