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


void BattleVisitor::userInput(std::string input, Character* Attacker, Character* Target)
{
    if(input == "Attack")//a is what I assume we are using for Attack? Not sure yet.
    {
        doDamage(Attacker, Target);
    }
    else if (input == "RUN")
    {
        runAway();
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
void BattleVisitor::doBattle()
{
    while((Player->getHealth() >= 1 && Enemy->getHealth() >= 1) && (run == 1))
    {
        userInput( BattleMenu(), Player, Enemy); //Waiting on GUI for cin alternative
        userInput("Attack", Enemy, Player);//to simulate the Enemy Attack
        doDamage(Player, Enemy);
        doDamage(Enemy, Player);
    }
    if(Player->getHealth() < 1)
    {
      //gameover!
    }	
    else
    {
      //Victory!
    }
}



//======================================================================================





std::string BattleVisitor::BattleMenu()
{
    WINDOW *w;
    //char list[2][7] = {"Attack", "Run"};
    char item[2];
    std::vector<std::string>menuList;
    menuList.push_back("Attack");
    menuList.push_back("Run");
    //int ch, i = 0, width = 3;
    int userInput;
    int i;//dont knoe what it is

    w = newwin( actWin->getWinY()/4, actWin->getWinX()/5, actWin->getStartPosY() + actWin->getWinY()/2, actWin->getStartPosX() + actWin->getWinX()/2 ); // create a new window
    box( w, 0, 0 ); // sets default borders for the window
   
// now print all the menu items and highlight the first one
    //for( i=0; i<2; i++ ) 
    for(i = 0; i < menuList.size(); i++)
    {
        if( i == 0 ) 
            wattron( w, A_STANDOUT ); // highlights the first item.
        else
            wattroff( w, A_STANDOUT );
        sprintf(item, "%-2s",  menuList[i]);
        //mvwprintw( w, i+1, 2, "%s", item );
	mvwprintw(w, i+1,2,"%s",menuList[i]);
    }
 
    wrefresh( w ); // update the terminal screen
 
    i = 0;
    noecho(); // disable echoing of characters on the screen
    keypad( w, TRUE ); // enable keyboard input for the window.
    curs_set( 0 ); // hide the default screen cursor.
     
       // get the input
    //while(( ch = wgetch(w)) != '\n')
    while(1)
    { 
        userInput = wgetch(w);
        // right pad with spaces to make the items appear with even width.
        //sprintf(item, "%-7s",  list[i]); 
        //mvwprintw( w, i+1, 2, "%s", item ); 
        // use a variable to increment or decrement the value based on the input.
        switch(userInput) 
	{
            case KEY_UP:
                i--;
                i = ( i<0 ) ? 1 : i;
                break;
            case KEY_DOWN:
                i++;
                i = ( i>1 ) ? 0 : i;
	    case 10:
		return menuList[i];
                break;
        }
        // now highlight the next item in the list.
        wattron( w, A_STANDOUT );
            
        sprintf(item, "%-2s",  menuList[i]);
        mvwprintw( w, i+1, 2, "%s", item);
        wattroff( w, A_STANDOUT );
    }
}



