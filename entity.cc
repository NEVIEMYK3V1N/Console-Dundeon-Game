#include "entity.h"

using namespace std;


Entity::Entity(bool gold, bool pot, bool NPC, int tile_ID) :
    gold{gold}, pot{pot}, NPC{NPC}, tile_ID{tile_ID} {};
Entity::~Entity() {};

bool Entity::is_gold() const {
    return gold;
}

bool Entity::is_pot() const {
    return pot;
}

bool Entity::is_NPC() const {
    return NPC;
}

int Entity::get_tile_ID() const {
    return tile_ID;
}

void Entity::set_tile_ID(int val) {
    tile_ID = val;
}

Stairway::Stairway(int tile_ID) :
    Entity{false, false, false, tile_ID} {};
Stairway::~Stairway() {};

char Stairway::get_sym() const {
    return '\\';
}

item::item(bool gold, bool pot, bool NPC, int tile_ID) :
    Entity{gold, pot, NPC, tile_ID} {};
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

potionHP::potionHP(bool eff, int tile_ID, int val) :
    potion{val, eff, "HP", tile_ID} {};
potionHP::~potionHP() {};

PC* potionHP::consume_item(PC* player) {
    is_drow(player);
    player->mod_hp(val);
    return nullptr;
}

potionAtk::potionAtk(bool eff, int tile_ID, int val) :
    potion{val, eff, "atk", tile_ID} {};
potionAtk::~potionAtk() {};

PC* potionAtk::consume_item(PC* player) {
    is_drow(player);
    return new PotAtk(val, player);
}

potionDef::potionDef(bool eff, int tile_ID, int val) :
    potion{val, eff, "def", tile_ID} {};
potionDef::~potionDef() {};

PC* potionDef::consume_item(PC* player) {
    is_drow(player);
    return new PotDef(val, player);
}


Treasure::Treasure(int val, int tile_ID, string size, bool is_dragon) :
    item{true, false, false, tile_ID}, val{val}, size{size}, is_dragon{is_dragon} {};
Treasure::~Treasure() {};

bool Treasure::is_treDragon() const {
    return is_dragon;
}


PC* Treasure::consume_item(PC* player) {
    player->mod_gold(val);
    return nullptr;
}

char Treasure::get_sym() const {
    return 'G';
}

treGround::treGround(int val, int tile_ID, string size) :
    Treasure{val, tile_ID, size, false} {};
treGround::~treGround() {};


treDragon::treDragon(int val, int tile_ID) :
    Treasure{val, tile_ID, "dragon_hoard", true} {};
treDragon::~treDragon() {};

dragon* treDragon::get_guard() const {
    return guard;
}

void treDragon::set_guard(dragon* guard) {
    this->guard = guard;
}
