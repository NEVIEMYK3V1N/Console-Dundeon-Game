#include "floor.h"
#include "entitySpawnable.h"
#include <vector>

// needed to change
// #include <treasure.h>
// #include <entity.h>
class Treasure {};
class Entity {};
// ===========

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
    void move_entity_in_chamber(Entity* entity);
};
