#include "pc.h"

using namespace std;

PC::PC(int atk, int def, int hp, int hp_max, string faction) :
    atk{atk}, def{def}, hp{hp}, hp_max{hp_max}, gold{0}, sym{'@'}, 
    faction{faction}, can_miss{false}, merchant_status{true} {};
PC::~PC() {};

int PC::get_atk() const {
    return atk;
}

int PC::get_def() const {
    return def;
}

int PC::get_hp() const {
    return hp;
}

bool PC::get_merch_stat() const {
    return merchant_status;
}

string PC::get_faction() const {
    return faction;
}

void PC::set_miss(bool val) {
    can_miss = val;
}

void PC::set_merch_stat(bool val) {
    merchant_status = val;
}

bool PC::mod_hp(int val) {
    hp += val;
    if ((faction != "vampire") && (hp > hp_max)) {
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


PotionEffect::PotionEffect(int val, string type, PC* player) :
    PC{-1, -1, -1, -1, ""}, val{val}, type{type}, player{player} {};
PotionEffect::~PotionEffect() {
    delete player;
}

int PotionEffect::get_atk() const {
    return player->get_atk();
}

int PotionEffect::get_def() const {
    return player->get_def();
}

int PotionEffect::get_hp() const {
    return player->get_hp();
}

bool PotionEffect::get_merch_stat() const {
    return player->get_merch_stat();
}

string PotionEffect::get_faction() const {
    return player->get_faction();
}

void PotionEffect::set_miss(bool val) {
    player->set_miss(val);
}

void PotionEffect::set_merch_stat(bool val) {
    player->set_merch_stat(val);
}

bool PotionEffect::mod_hp(int val) {
    return player->mod_hp(val);
}

void PotionEffect::move_pos() {
    player->move_pos();
}

void PotionEffect::attack() {
    player->attack();
}

void PotionEffect::unique_ability() {
    player->unique_ability();
}


PotAtk::PotAtk(int val, PC* player) :
    PotionEffect {val, "atk", player} {};

int PotAtk::get_atk() const {
    return val + player->get_atk();
}


PotDef::PotDef(int val, PC* player) :
    PotionEffect {val, "def", player} {};

int PotDef::get_def() const {
    return val + player->get_def();
}
