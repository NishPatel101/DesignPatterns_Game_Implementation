#ifndef __BATTLE_H__
#define __BATTLE_H__

#include "Equipment.h"
#include "Character.h"

class Battle {    
    public:
        /* Constructors */
        Battle();

        /* Pure Virtual Functions */
        virtual void doBattle(Character* player, Character* enemy) = 0;
};

#endif //__BATTLE_H__
