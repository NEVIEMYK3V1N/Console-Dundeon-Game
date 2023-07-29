#include "entitySpawnable.h"

EntitySpawnable::EntitySpawnable(ChamberInterior* root_chamber) : PlayerWalkableCell{}, root_chamber{root_chamber} {
    this->open_to_entity = true;
    this->entity_on_cell = {};
    this->entity_spawnable = true;
}

EntitySpawnable::EntitySpawnable(ChamberInterior* root_chamber, std::vector<Entity*> entity_on_cell, bool open_to_entity) 
    : PlayerWalkableCell{}, open_to_entity{open_to_entity}, root_chamber{root_chamber}, entity_on_cell{entity_on_cell} {
    this->entity_spawnable = true;
}

// getters
bool EntitySpawnable::get_open_to_entity() {
    return this->open_to_entity;
}
ChamberInterior* EntitySpawnable::get_root_chamber() {
    return this->root_chamber;
}
Entity* EntitySpawnable::get_entity_on_index(int index = 0) {
    // error checkin - range NEED
    return this->entity_on_cell[index];
}
    // Entity* get_entity_on_cell_at(int index = 0);

// setters
void EntitySpawnable::set_open_to_entity(bool open_to_entity) {
    this->open_to_entity = open_to_entity
}
void EntitySpawnable::set_root_chamber(ChamberInterior* root_chamber) {
    this->root_chamber = root_chamber;
}
void EntitySpawnable::set_entity_on_index(Entity* entity, int index = 0) {
    // error checkin - range NEED
    this->entity_on_cell = entity;
}
    // void set_entity_on_cell_at(Entity* entity, int index = 0);
