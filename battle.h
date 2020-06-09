#ifndef __BATTLE_H__
#define __BATTLE_H__

#include "Equipment.h"
#include "Character.h"

/*
Character:
priv:
string name
int health

prot:
equipment* e;
*/


class Battle {    
    public:
        /* Constructors */
        Battle();
        Battle(Character* player, Character* enemy);
        
	/* Variables */
        getHealth();
        getDamage();
        
        /* Pure Virtual Functions */
        virtual void battle(Character* player, Character* enemy) = 0;
};

#endif //__BATTLE_H__
