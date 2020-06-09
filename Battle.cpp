#include "Battle.h"

        /* Constructors */
Battle::Battle() { }
        
//I don't think we need these?        
//	/* Variables */
//        Battle::getHealth();
//        Battle::getDamage();
//  /* Pure Virtual Functions */
        virtual void doBattle(Character* player, Character* enemy) = 0;
