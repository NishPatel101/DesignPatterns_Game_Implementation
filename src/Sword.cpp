#include "..header/Sword.h"

using namespace std;

string Sword::getDescription() {
			return "Sword: the tried-and-true weapon!\nThis weapon has consistent, high damage output.";
}

int Sword::getDefense() {
			return 0; //Not implemented yet
}

int Sword::getDamage() {
			return 5;
}
