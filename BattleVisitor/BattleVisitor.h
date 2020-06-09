#include "../Character/Character.h"
#include "../Equipment/header/EquipmentDecorator.h"

class BattleVisitor
{
    public:
        BattleVisitor(Character*,Character*);
	int getHealth(Character* Creature);
        void userInput(char input, Character* Attacker, Character* Target);
        void doDamage(Character* Attacker, Character* Target);
        void runAway();
        void doBattle(Character* Player, Character* Enemy);
    protected:
	Character * Player;
	Character * Enemy;
	int run = 1;
};
