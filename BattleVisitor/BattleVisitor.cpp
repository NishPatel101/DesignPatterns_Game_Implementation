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
    WINDOW *menuWin;
    menuWin = newwin( actWin->getWinY()/4, actWin->getWinX()/5, actWin->getStartPosY() + actWin->getWinY()/2, actWin->getStartPosX() + actWin->getWinX()/2 ); // create a new window
    box( menuWin, 0, 0 ); // sets default borders for the window

    refresh();
    wrefresh(menuWin);

    keypad(menuWin, true);

    std::string choices[2] = {"attack", "run"};
    int choice;
    int highlight = 0;

    while(1)
    {
        for(int i = 0; i< 2; i++)
        {
            if(i == highlight)
	    {
                wattron(menuWin, A_REVERSE);
	    }
	    mvwprintw(menuWin, i+1, 1, choices[i].c_str());
            wattroff(menuWin, A_REVERSE);
        }
        choice = wgetch(menuWin);

        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if(highlight == -1)
		{
                    highlight = 0;
		}
		break;

	    case KEY_DOWN:
                highlight++;
                if(highlight ==2)
	        {
                    highlight = 1;
	        }
                break;

            default:
                break;
        }
        if(choice == 10)
	{
            break;
        } 
   }
    mvwprintw(menuWin,3,1,"%s",choices[highlight].c_str());
    wrefresh(menuWin);
    return choices[highlight];
}



