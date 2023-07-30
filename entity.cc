#include "entity.h"

using namespace std;


entity::entity(bool gold, bool pot, bool NPC, int tile_ID) :
    gold{gold}, pot{pot}, NPC{NPC}, tile_ID{tile_ID} {};
entity::~entity() {};

bool entity::is_gold() const {
    return gold;
}

bool entity::is_pot() const {
    return pot;
}

bool entity::is_NPC() const {
    return NPC;
}

int entity::get_tile_ID() const {
    return tile_ID;
}

void entity::set_tile_ID(int val) {
    tile_ID = val;
}


item::item(bool gold, bool pot, bool NPC, int tile_ID) :
    entity{gold, pot, NPC, tile_ID} {};
item::~item() {};


potion::potion(int val, bool eff, string pot_type, int tile_ID) :
    item{false, true, false, tile_ID}, val{val}, pot_type{pot_type} {
        if (!eff) {
            val = -val;
        }
    };
potion::~potion() {};

void potion::is_drow(const PC* player) {
    if (player->get_faction() == "drow") {
        val *= 1.5;
    }
}

char potion::get_sym() const {
    return 'P';
}

potionHP::potionHP(bool eff, int tile_ID, int val = 10) :
    potion{val, eff, "HP", tile_ID} {};
potionHP::~potionHP() {};

void potionHP::consume_item(PC* player) {
    is_drow(player);
    player->mod_hp(val);
}

potionAtk::potionAtk(bool eff, int tile_ID, int val) :
    potion{val, eff, "atk", tile_ID} {};
potionAtk::~potionAtk() {};

void potionAtk::consume_item(PC* player) {
    is_drow(player);
    player = new PotAtk(val, player);
}

potionDef::potionDef(bool eff, int tile_ID, int val) :
    potion{val, eff, "def", tile_ID} {};
potionDef::~potionDef() {};

void potionDef::consume_item(PC* player) {
    is_drow(player);
    player = new PotDef(val, player);
}


treasure::treasure(int val, int tile_ID, string size, bool dragon) :
    item{true, false, false, tile_ID}, val{val}, size{size}, dragon{dragon} {};
treasure::~treasure() {};

bool treasure::dragon_alive() const {
    return dragon;
}

void treasure::set_dragon(bool val) {
    dragon = val;
}

treGround::treGround(int val, int tile_ID, string size) :
    treasure{val, tile_ID, size, false} {};
treGround::~treGround() {};


treDragon::treDragon(int val, int tile_ID) :
    treasure{val, tile_ID, "dragon_hoard", true} {};
treDragon::~treDragon() {};
