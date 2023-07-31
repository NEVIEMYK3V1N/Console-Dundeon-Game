#include "pc.h"

using namespace std;

PC::PC(int atk, int def, int hp, int hp_max, string faction, int tile_ID) :
    atk{atk}, def{def}, hp{hp}, hp_max{hp_max}, gold{0}, sym{'@'}, 
    faction{faction}, tile_ID{tile_ID}, can_miss{false}, merchant_status{true} {};
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

int PC::get_tile_ID() const {
    return tile_ID;
}

int PC::get_gold() const {
    return gold;
}

char PC::get_sym() const {
    return sym;
}

void PC::mod_gold(int val) {
    gold += val;
}

void PC::set_tile_ID(int val) {
    tile_ID = val;
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
    hp = 0;
    return false;
}

shade::shade(int tile_ID) :
    PC {25, 25, 125, 125, "shade", tile_ID} {};
shade::~shade() {};


drow::drow(int tile_ID) :
    PC {25, 15, 150, 150, "drow", tile_ID} {};
drow::~drow() {};


vampire::vampire(int tile_ID) :
    PC {25, 25, 50, -1, "vampire", tile_ID} {};
vampire::~vampire() {};

troll::troll(int tile_ID) :
    PC {25, 15, 120, 120, "troll", tile_ID} {};
troll::~troll() {};


goblin::goblin(int tile_ID) :
    PC {15,20, 110, 110, "goblin", tile_ID} {};
goblin::~goblin() {};


PotionEffect::PotionEffect(int val, string type, PC* player) :
    PC{-1, -1, -1, -1, "", -1}, val{val}, type{type}, player{player} {};
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

int PotionEffect::get_tile_ID() const {
    return player->get_tile_ID();
}

int PotionEffect::get_gold() const {
    return player->get_gold();
}

char PotionEffect::get_sym() const {
    return player->get_sym();
}

void PotionEffect::mod_gold(int val) {
    player->mod_gold(val);
}

void PotionEffect::set_tile_ID(int val) {
    player->set_tile_ID(val);
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
