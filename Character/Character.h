#ifndef CHARACTER_H
#define CHARACTER_H

#include "Equipment.h"

using namespace std;

class Character {
        private:
                string name;
                int health;
        protected:
                Equipment* e;
        public:
                Character(string, int, Equipment*);

                string getName();
                void setName(string);

                int getHealth();
                void setHealth(int);

                int getDamage();

                void takeDamage(int);

                void addEquipment(Equipment*);
};
#endif
