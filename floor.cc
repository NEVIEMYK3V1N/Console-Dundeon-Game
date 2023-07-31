#include "floor.h"

Floor::Floor(PC* pc, int height, int width, int floor_level, int num_stairway, int num_potions, int num_gold, int num_enemy)
    : num_stairway{num_stairway}, num_potions{num_potions}, num_gold{num_gold}, num_enemy{num_enemy}, floor_level{floor_level},
      width{width}, height{height}, pc_on_floor{pc} {
    this->entities_on_floor = {};
    this->map = {};
    this->chambers_on_floor = {};
}

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
    // return (this->entities_on_floor[index]).get();
    return this->entities_on_floor[index];
}
Cell* Floor::get_cell_at_index(int index) {
    // NEEDED - error check range
    // return (this->map[index]).get();
    return this->map[index];
}
ChamberInterior* Floor::get_chamber_at_index(int index) {
    // NEEDED - error check range
    // return (this->chambers_on_floor[index]).get();
    return this->chambers_on_floor[index];
}

int Floor::get_num_chambers() {
    return (this->chambers_on_floor).size();
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

//void Floor::emplace_cell(std::unique_ptr<Cell> cell) {
//    (this->map).emplace_back(cell);
//}

void Floor::emplace_cell(Cell* cell) {
    (this->map).emplace_back(cell);
}

//void Floor::emplace_entity(std::unique_ptr<Entity> entity) {
//   (this->entities_on_floor).emplace_back(entity);
//}

void Floor::emplace_entity(Entity* entity) {
   (this->entities_on_floor).emplace_back(entity);
}

//void Floor::emplace_chamber(std::unique_ptr<ChamberInterior> ci) {
//    (this->chambers_on_floor).emplace_back(ci);
//}

void Floor::emplace_chamber(ChamberInterior* ci) {
    (this->chambers_on_floor).emplace_back(ci);
}

int Floor::get_num_cells() {
    return this->height * this->width;
}

PC* Floor::get_pc_on_floor() {
    return this->pc_on_floor;
}

void Floor::set_pc_on_floor(PC* pc_on_floor) {
    this->pc_on_floor = pc_on_floor;
}

Floor::~Floor() {
    for (int i = 0; i < this->entities_on_floor.size(); i++) {
        free(this->entities_on_floor[i]);
    }
    for (int i = 0; i < this->map.size(); i++) {
        free(this->map[i]);
    }
    for (int i = 0; i < this->chambers_on_floor.size(); i++) {
        free(this->chambers_on_floor[i]);
    }
}