#ifndef __USERINPUT_H__
#define __USERINPUT_H__

#include "Battle.h"

class UserInput : public Battle {
    public:
    char tempUserInput;
    UserInput() : Battle(){};
    virtual void doBattle(Character* player, Character* enemy);
};

#endif //__USERINPUT_H__
