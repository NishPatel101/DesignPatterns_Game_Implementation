#include "Battle.h"
#include "WinLose.h"

WinLose::WinLose(){ }
        
        /* Logic */
void WinLose::checkHealth(){
    if(player.getHP() <= 0) {
      //cout "You Died" endl;
      //gameOver();
    }
    if(enemy.getHP() <= 0){
      //cout "Enemy Slain!" endl;
      //endBattle();
    }
}
