#include "item.h"

using namespace std;

item::~item() {};


potion::potion(int val, string pot_type) :
    val{val}, pot_type{pot_type} {};
potion::~potion() {};

void potion::is_drow(const PC* player) {
    if (player->get_faction() == "drow") {
        val *= 1.5;
    }
}


potionHP::potionHP(int val) :
    potion{val, "HP"} {};
potionHP::~potionHP() {};

void potionHP::consume_item(PC* player) {
    is_drow(player);
    player->mod_hp(val);
}


potionAtk::potionAtk(int val) :
    potion{val, "atk"} {};
potionAtk::~potionAtk() {};

void potionAtk::consume_item(PC* player) {
    is_drow(player);
    player = new PotAtk(val, player);
}

potionDef::potionDef(int val) :
    potion{val, "def"} {};
potionDef::~potionDef() {};

void potionDef::consume_item(PC* player) {
    is_drow(player);
    player = new PotDef(val, player);
}


treasure::treasure(int val, string size) :
    val{val}, size{size} {};
treasure::~treasure() {};

