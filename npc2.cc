#include "npc.h"

using namespace std;

NPC::NPC(int atk, int def, int hp, char sym, string faction) :
    atk{atk}, def{def}, hp{hp}, sym{sym}, faction{faction} {};
NPC::~NPC() {};

int NPC::get_atk() {
    return atk;
}

int NPC::get_def() {
    return def;
}

void NPC::attack(PC& player) {
    srand(time(0));
    int hit = rand() % 2;
    if (hit == 0) {
        return;
    }
    double numerator = 100;
    double def_src = 100 + player.get_def();
    int dmg = ceil((numerator / def_src) * get_atk());
    player.mod_hp(-dmg);
};	

bool NPC::mod_hp(int dmg) {
    hp += dmg;
    if (hp > 0) {
        return true;
    }
    return false;
}


human::human() :
    NPC {20, 20, 140, 'H', "human"} {};
human::~human() {};


dwarf::dwarf() : 
    NPC {20, 30, 100, 'W', "dwarf"} {};
dwarf::~dwarf() {};

void dwarf::attack(PC& player) {
    NPC::attack(player);
    if (player.get_faction() == "vampire") {
        player.unique_ability();
    }
}


elf::elf() : 
    NPC {30, 10, 140, 'E', "elf"} {};
elf::~elf() {};

void elf::attack(PC& player) {
    NPC::attack(player);
    if (player.get_faction() != "drow") {
        NPC::attack(player);
    }
}


orcs::orcs() :
    NPC {30, 25, 180, 'O', "orcs"} {};
orcs::~orcs() {};

void orcs::attack(PC& player) {
    srand(time(0));
    int hit = rand() % 2;
    if (hit == 0) {
        return;
    }
    double numerator = 100;
    double def_src = 100 + player.get_def();
    int dmg = ceil((numerator / def_src) * get_atk());
    if (player.get_faction() == "goblin") {
        dmg *= 1.5;
    }
    player.mod_hp(-dmg);
}


void halfling::attack(PC& player) {
    NPC::attack(player);
    srand(time(0));
    int affect_player = rand() % 2;
    if (affect_player == 1) {
        player.set_miss(true);
    }
}
