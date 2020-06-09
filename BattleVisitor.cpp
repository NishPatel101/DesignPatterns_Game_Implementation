#include "BattleVisitor.h"

int BattleVisitor::getHealth(Character* Creature){
    return Creature->getHealth();
}
BattleVisitor::userInput(char input, Character* Creature){
char tempUserInput = input;
  if(tempUserInput = 'a')//a is what I assume we are using for Attack? Not sure yet.
    Creature.takeDamage(getDamage);
  else if (tempUserInput = 'r')
    break;
}
BattleVisitor::runAway(){
  //cout "You got away!";
  break;
}
BattleVisitor::doBattle(Character* Player, Character* Enemy){
    while(Player.getHealth() >= 1 && Enemy.getHealth() >= 1){
    userInput(cin input, Enemy); //Waiting on GUI for cin alternative
    userInput('a', Player);//to simulate the Enemy Attack
    doDamage(Enemy);
    doDamage(Player);
    }
    /*if(Player.getHealth < 1)
      //gameover!
     else
      //Victory!
    */
}
