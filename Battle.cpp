#include "Battle.h"

        /* Constructors */
Battle::Battle() { }
Battle::Battle()(Character* player, Character* enemy) {
        //logic go here;
}
        
//I don't think we need these?        
//	/* Variables */
//        Battle::getHealth();
//        Battle::getDamage();
//  /* Pure Virtual Functions */
        virtual void battle(Character* player, Character* enemy) = 0;
