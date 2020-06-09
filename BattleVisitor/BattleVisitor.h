#include "../Character/Character.h"
#include "../Equipment/header/EquipmentDecorator.h"
#include "../Graphics/header/actionGui.h"
#include <string>
#include <vector>

class BattleVisitor
{
    public:
        BattleVisitor(Character*,Character*, Graphics *);
	int getHealth(Character* Creature);
        void userInput(std::string input, Character* Attacker, Character* Target);
        void doDamage(Character* Attacker, Character* Target);
        void runAway();
        void doBattle();
	std::string BattleMenu();
    protected:
	Character * Player;
	Character * Enemy;
	Graphics * actWin;
	int run = 1;
};
