#include "../header/Character.hpp"

using namespace std;

Character::Character(string _name, int _health, Equipment* _e) {
	name = _name;
	health = _health;
	e = _e;
}

string Character::getName() {
	return name;
}

void Character::setName(string n) {
	name = n;
}

int Character::getHealth() {
	return health;
}

void Character::setHealth(int h) {
	health = h;
}

int Character::getDamage() {
	return e->getDamage();
}

void Character::takeDamage(int d) {
	health -= d;
}

void Character::addEquipment(Equipment* eq) {
	delete e;
	e = eq;
}
