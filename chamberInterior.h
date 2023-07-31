//#include "floor.h"
#ifndef CHAMBERINTERIOR_H
#define CHAMBERINTERIOR_H

#include "entitySpawnable.h"
#include <vector>

class Floor;
class Treasure;
class Entity;

class ChamberInterior {
    int chamber_id;
    int num_entities;
    bool has_stairway;
    std::vector<EntitySpawnable*> interior_tiles;
    Floor* root_floor;
 public:
    void spawn_player_in_chamber(PC* pc);
    void spawn_stairway_in_chamber();
    void spawn_potion_in_chamber();
    void spawn_gold_in_chamber();
    void spawn_enemy_in_chamber(Treasure* treasure);
    void spawn_enemy_in_chamber();

    ChamberInterior(int chamber_id, Floor* root_floor, int num_entities = 0, bool has_stairway = false);

    void emplace_entityspawnable(EntitySpawnable* es);

    // getters
    int get_chamber_id();
    int get_num_entities();
    bool get_has_stairway();
    EntitySpawnable* get_tile_at(int index = 0);
    Floor* get_root_floor();

    // setters
    void set_chamber_id(int chamber_id);
    void set_num_entities(int num_entities);
    void set_has_stairway(bool has_stairway);
    void set_tile_at(EntitySpawnable* tile, int index = 0);
    void set_root_floor(Floor* root_floor);
};

#endif
