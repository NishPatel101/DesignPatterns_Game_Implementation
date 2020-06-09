#include "BattleVisitor.h"

BattleVisitor::BattleVisitor(Character * p, Character * e, Graphics* window)
{
    Player = p; 
    Enemy = e;
    actWin = window;
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
void BattleVisitor::BattleMenu()
{
    WINDOW *w;
    char list[5][7] = { "One", "Two", "Three", "Four", "Five" };
    char item[7];
    int ch, i = 0, width = 7;
 
    initscr(); // initialize Ncurses
    w = newwin( actWin->getWinY/5, actWin->getWinX/5, actWin->getStartPosY + getActWinY/2, actWin->getStartPosX + getActWinX/2 ); // create a new window
    box( w, 0, 0 ); // sets default borders for the window
     
// now print all the menu items and highlight the first one
    for( i=0; i<5; i++ ) {
        if( i == 0 ) 
            wattron( w, A_STANDOUT ); // highlights the first item.
        else
            wattroff( w, A_STANDOUT );
        sprintf(item, "%-7s",  list[i]);
        mvwprintw( w, i+1, 2, "%s", item );
    }
 
    wrefresh( w ); // update the terminal screen
 
    i = 0;
    noecho(); // disable echoing of characters on the screen
    keypad( w, TRUE ); // enable keyboard input for the window.
    curs_set( 0 ); // hide the default screen cursor.
     
       // get the input
    while(( ch = wgetch(w)) != 'q'){ 
         
                // right pad with spaces to make the items appear with even width.
            sprintf(item, "%-7s",  list[i]); 
            mvwprintw( w, i+1, 2, "%s", item ); 
              // use a variable to increment or decrement the value based on the input.
            switch( ch ) {
                case KEY_UP:
                            i--;
                            i = ( i<0 ) ? 4 : i;
                            break;
                case KEY_DOWN:
                            i++;
                            i = ( i>4 ) ? 0 : i;
                            break;
            }
            // now highlight the next item in the list.
            wattron( w, A_STANDOUT );
             
            sprintf(item, "%-7s",  list[i]);
            mvwprintw( w, i+1, 2, "%s", item);
            wattroff( w, A_STANDOUT );
    }
}



