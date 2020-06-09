#include "BattleVisitor.h"

BattleVisitor::BattleVisitor(Character * p, Character * e)
{
    Player = p; 
    Enemy = e;
}

int BattleVisitor::getHealth(Character* Creature)
{
    return Creature->getHealth();
}


void BattleVisitor::userInput(char input, Character* Attacker, Character* Target)
{
    char tempUserInput = input;
    if(tempUserInput = 'a')//a is what I assume we are using for Attack? Not sure yet.
        doDamage(Attacker, Target);
    else if (tempUserInput = 'r')
    {
        
    }
}
void BattleVisitor::doDamage(Character* Attacker, Character* Target)
{
    int damage = Attacker->getDamage();
    Target->takeDamage(damage);
}
void BattleVisitor::runAway()
{
    //cout "You got away!";
    run = 0;
}
void BattleVisitor::doBattle(Character* Player, Character* Enemy)
{
    while((Player->getHealth() >= 1 && Enemy->getHealth() >= 1) && (run == 1))
    {
        userInput('a'/*cin input*/, Player, Enemy); //Waiting on GUI for cin alternative
        userInput('a', Enemy, Player);//to simulate the Enemy Attack
        doDamage(Player, Enemy);
        doDamage(Enemy, Player);
    }
   /* if(Player.getHealth < 1)
      //gameover!
    else
      //Victory!
    */
}


