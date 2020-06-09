#ifndef __WINLOSE_H__
#define __WINLOSE_H__

#include "Battle.h"

class WinLose {
    public:
        /* Constructors */
        WinLose();
        
        /* Logic */
        void checkHealth();
        
        /* Pure Virtual Functions */
        virtual void battle(Character* player, Character* enemy) = 0;
};

#endif //__WINLOSE_H__
