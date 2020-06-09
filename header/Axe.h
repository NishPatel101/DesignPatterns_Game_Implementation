#ifndef AXE_H
#define AXE_H

#include "Equipment.h"

#include <time.h>

using namespace std;

//CONCRETE COMPONENT

class Axe : public Equipment {
	public:
		string getDescription();
		
		int getDefense();

		int getDamage();
};
#endif
