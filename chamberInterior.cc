#include "chamberInterior.h"
#include <vector>

/*
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

    // getters
    int get_chamber_id();
    int get_num_entities();
    bool has_stairway();
    EntitySpawnable* get_tile_at(int index);
    Floor* get_root_floor();

    // setters
    void set_chamber_id(int chamber_id);
    void set_num_entities(int num_entities);
    void set_has_stairway(bool has_stairway);
    void set_tile_at(int index, EntitySpawnable* tile);
    void set_root_floor();
};
*/

// getters
int ChamberInterior::get_chamber_id() {
    return this->chamber_id;
}
int ChamberInterior::get_num_entities() {
    return this->num_entities;
}
bool ChamberInterior::has_stairway() {
    return this->has_stairway;
}
EntitySpawnable* ChamberInterior::get_tile_at(int index) {
    // need error cheching for range - tbi
    return this->interior_tiles[index];
}
Floor* ChamberInterior::get_root_floor() {
    return this->root_floor;
}

// setters
void ChamberInterior::set_chamber_id(int chamber_id) {
    this->chamber_id = chamber_id;
}
void ChamberInterior::set_num_entities(int num_entities) {
    this->num_entities;
}
void ChamberInterior::set_has_stairway(bool has_stairway) {
    this->has_stairway = has_stairway;
}
void ChamberInterior::set_tile_at(EntitySpawnable* tile, int index) {
    // need error cheching for range - tbi
    this->interior_tiles[index] = tile;
}
void ChamberInterior::set_root_floor(Floor* root_floor) {
    this->root_floor = root_floor;
}