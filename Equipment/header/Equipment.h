#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>

using namespace std;

//COMPONENT

class Equipment {
        public:
                Equipment() {};

                virtual string getDescription() = 0;
                virtual int getDefense() = 0;
                virtual int getDamage() = 0;
};
#endif
