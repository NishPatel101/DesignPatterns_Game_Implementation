#ifndef __USERINPUT_H__
#define __USERINPUT_H__

#include "Battle.h"
#include "Battle.h"

class UserInput {
    protected:
    char tempUserInput;
    
    public:
        /* Constructors */
        UserInput();
        UserInput(char input);
        
        /* Logic */
        void performAction();
        
        /* Pure Virtual Functions */
        virtual void battle(Character* player, Character* enemy) = 0;
};

#endif //__USERINPUT_H__
