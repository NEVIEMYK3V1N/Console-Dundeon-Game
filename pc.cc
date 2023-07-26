#include "pc.h"

using namespace std;

PC::PC(int atk, int def, int hp, int hp_max, string faction) :
    atk{atk}, def{def}, hp{hp}, hp_max{hp_max}, gold{0}, sym{'@'}, 
    faction{faction}, can_miss{false} {};
PC::~PC() {};

string PC::get_faction() {
    return faction;
}

bool PC::get_miss() {
    return can_miss;
}

shade::shade() :
    PC {25, 25, 125, 125, "shade"} {};
shade::~shade() {};


drow::drow() :
    PC {25, 15, 150, 150, "drow"} {};
drow::~drow() {};


vampire::vampire() :
    PC {25, 25, 50, -1, "vampire"} {};
vampire::~vampire() {};


troll::troll() :
    PC {25, 15, 120, 120, "troll"} {};
troll::~troll() {};


goblin::goblin() :
    PC {15,20, 110, 110, "goblin"} {};
goblin::~goblin() {};
