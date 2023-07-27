#include "pc.h"

using namespace std;

PC::PC(int atk, int def, int hp, int hp_max, string faction) :
    atk{atk}, def{def}, hp{hp}, hp_max{hp_max}, gold{0}, sym{'@'}, 
    faction{faction}, can_miss{false} {};
PC::~PC() {};

int PC::get_atk() {
    return atk;
}

int PC::get_def() {
    return def;
}

int PC::get_hp() {
    return hp;
}

string PC::get_faction() {
    return faction;
}

void PC::set_miss(bool val) {
    can_miss = val;
}

bool PC::mod_hp(int val) {
    hp += val;
    if (hp > hp_max) {
        hp = hp_max;
    }
    if (hp > 0) {
        return true;
    } 
    return false;
}

void PC::unique_ability() {};

shade::shade() :
    PC {25, 25, 125, 125, "shade"} {};
shade::~shade() {};


drow::drow() :
    PC {25, 15, 150, 150, "drow"} {};
drow::~drow() {};


vampire::vampire() :
    PC {25, 25, 50, -1, "vampire"}, allergy{false} {};
vampire::~vampire() {};

void vampire::unique_ability() {
    allergy = true;
}


troll::troll() :
    PC {25, 15, 120, 120, "troll"} {};
troll::~troll() {};


goblin::goblin() :
    PC {15,20, 110, 110, "goblin"} {};
goblin::~goblin() {};
