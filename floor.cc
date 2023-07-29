#include "floor.h"
#include <memory>
#include <vector>
#include <fstream>
#include <string>

/*
class Floor {
   int num_stairway;
   int num_potions;
   int num_gold;
   int num_enemy;
   int floor_level;
   int width;
   int height;
   std::vector<std::unique_ptr<Entity>> entities_on_floor;
   std::vector<std::unique_ptr<Cell>> map;
   std::vector<std::unique_ptr<ChamberInterior>> chambers_on_floor;

   std::vector<playerWalkableCell*> player_cells;

   ChamberInterior* choose_random_chamber();

   readFromFile(std::string file_name);
 protected:
   bool enemy_movable;
 public:
   void spawn_all_player(PC* pc);
   void spawn_all_stairway();
   void spawn_all_potion();
   void spawn_all_gold();
   void spawn_all_enemy();
   void render_map();
   void move_all_entities();

   Floor();
};
*/

// getters
int Floor::get_num_stairway() {
    return this->num_stairway;
}
int Floor::get_num_potions() {
    return this->num_potions;
}
int Floor::get_num_gold() {
    return this->num_gold;
}
int Floor::get_num_enemy() {
    return this->num_enemy;
}
int Floor::get_floor_level() {
    return this->floor_level;
}
int Floor::get_width() {
    return this->width;
}
int Floor::get_height() {
    return this->height;
}

Entity* Floor::get_entity_at_index(int index) {
    // NEEDED - error check range
    return (this->entities_on_floor[index]).get();
}
Cell* Floor::get_cell_at_index(int index) {
    // NEEDED - error check range
    return (this->map[index]).get();
}
ChamberInterior* Floor::get_chamber_at_index(int index) {
    // NEEDED - error check range
    return (this->chambers_on_floor[index]).get();
}

// setters
void Floor::set_num_stairway(int num_stairway) {
    this->num_stairway = num_stairway;
}
void Floor::set_num_potions(int num_potions) {
    this->num_potions = num_potions;
}
void Floor::set_num_gold(int num_gold) {
    this->num_gold = num_gold;
}
void Floor::set_num_enemy(int num_enemy) {
    this->num_enemy = num_enemy;
}
void Floor::set_floor_level(int floor_level) {
    this->floor_level = floor_level;
}
void Floor::set_width(int width) {
    this->width = width;
}
void Floor::set_height(int height) {
    this->height = height;
}


Floor::Floor(std::string file_name, int num_stairway, int num_potions,
                int num_gold, int num_enemy, int floor_level, PC* pc)
    : num_stairway {num_stairway}, num_potions {num_potions}, num_gold {num_gold}, 
        num_enemy {num_enemy}, floor_level {floor_level}, pc_on_floor{pc} {
    this->entities_on_floor = {};
    this->map = {};
    this->chambers_on_floor = {};
    this->width = 0;
    this->height = 0;
    this->readFromFile(file_name);

    //this->player_cells = {};
}

void Floor::emplace_cell(std::unique_ptr<Cell> cell) {
    (this->map).emplace_back(cell);
}

void Floor::emplace_entity(std::unique_ptr<Entity> entity) {
    (this->entities_on_floor).emplace_back(entity);
}
