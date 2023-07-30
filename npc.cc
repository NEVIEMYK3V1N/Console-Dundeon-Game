#include "npc.h"

using namespace std;

NPC::NPC(int atk, int def, int hp, char sym, string faction, int tile_ID) :
    entity {false, false, true, tile_ID}, 
    atk{atk}, def{def}, hp{hp}, sym{sym}, faction{faction}, tile_ID{tile_ID} {};
NPC::~NPC() {};

int NPC::get_atk() const {
    return atk;
}

int NPC::get_def() const {
    return def;
}

char NPC::get_sym() const {
    return sym;
}

int NPC::attack(PC& player) {
    srand(time(0));
    int hit = rand() % 2;
    if (hit == 0) {
        return 0;
    }
    double numerator = 100;
    double def_src = 100 + player.get_def();
    int dmg = ceil((numerator / def_src) * get_atk());
    player.mod_hp(-dmg);
    return dmg;
};	

bool NPC::mod_hp(int dmg) {
    hp += dmg;
    if (hp > 0) {
        return true;
    }
    return false;
}


human::human(int tile_ID) :
    NPC {20, 20, 140, 'H', "human", tile_ID} {};
human::~human() {};


dwarf::dwarf(int tile_ID) : 
    NPC {20, 30, 100, 'W', "dwarf", tile_ID} {};
dwarf::~dwarf() {};

int dwarf::attack(PC& player) {
    if (player.get_faction() == "vampire") {
        player.unique_ability();
    }
    return NPC::attack(player);
}


elf::elf(int tile_ID) : 
    NPC {30, 10, 140, 'E', "elf", tile_ID} {};
elf::~elf() {};

int elf::attack(PC& player) {
    int ret_val = NPC::attack(player);
    if (player.get_faction() != "drow") {
        NPC::attack(player);
        return ret_val * 2;
    }
    return ret_val;
}


orcs::orcs(int tile_ID) :
    NPC {30, 25, 180, 'O', "orcs", tile_ID} {};
orcs::~orcs() {};

int orcs::attack(PC& player) {
    srand(time(0));
    int hit = rand() % 2;
    if (hit == 0) {
        return 0;
    }
    double numerator = 100;
    double def_src = 100 + player.get_def();
    int dmg = ceil((numerator / def_src) * get_atk());
    if (player.get_faction() == "goblin") {
        dmg *= 1.5;
    }
    player.mod_hp(-dmg);
    return dmg;
}


merchant::merchant(int tile_ID) : 
    NPC {70, 5, 30, 'M', "merchant", tile_ID} {};
merchant::~merchant() {};

halfling::halfling(int tile_ID) :
    NPC {15, 20, 100, 'L', "halfling", tile_ID} {};
halfling::~halfling() {};

int halfling::attack(PC& player) {
    srand(time(0));
    int affect_player = rand() % 2;
    if (affect_player == 1) {
        player.set_miss(true);
    }
    return NPC::attack(player);
}


dragon::dragon(int tile_ID, int treasure_tile_ID) :
    NPC {20, 20, 150,'D', "dragon", tile_ID}, treasure_tile_ID{treasure_tile_ID} {};
dragon::~dragon() {};

int dragon::get_treasure_tild_ID() const {
    return treasure_tile_ID;
}
