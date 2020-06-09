#include "../Character/Character.h"
#include "../Equipment/header/EquipmentDecorator.h"
#include "../Graphics/header/actionGui.h"

class BattleVisitor
{
    public:
        BattleVisitor(Character*,Character*, Graphics *);
	int getHealth(Character* Creature);
        void userInput(char input, Character* Attacker, Character* Target);
        void doDamage(Character* Attacker, Character* Target);
        void runAway();
        void doBattle();
	void BattleMenu();
    protected:
	Character * Player;
	Character * Enemy;
	Graphics * actWin;
	int run = 1;
};
