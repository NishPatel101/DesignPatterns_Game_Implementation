#include "Battle.h"

        /* Constructors */
Battle::Battle() { }
        
        /* Pure Virtual Functions */
        virtual void doBattle(Character* player, Character* enemy) = 0;
