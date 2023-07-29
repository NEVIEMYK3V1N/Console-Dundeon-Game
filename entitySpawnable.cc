#include "entitySpawnable.h"

class EntitySpawnable : public PlayerWalkableCell {
 protected:
    bool open_to_entity;
    ChamberInterior* root_chamber;
    std::vector<Entity*> entity_on_cell;
 public:
    EntitySpawnable(ChamberInterior* root_chamber);
    EntitySpawnable(ChamberInterior* root_chamber, std::vector<Entity*> entity_on_cell, bool open_to_entity);
};

EntitySpawnable::EntitySpawnable(ChamberInterior* root_chamber) : PlayerWalkableCell{}, root_chamber{root_chamber} {
    this->open_to_entity = true;
    this->entity_on_cell = {};
}

EntitySpawnable::EntitySpawnable(ChamberInterior* root_chamber, std::vector<Entity*> entity_on_cell, bool open_to_entity) 
    : PlayerWalkableCell{}, open_to_entity{open_to_entity}, root_chamber{root_chamber}, entity_on_cell{entity_on_cell}
    {}

Entity* EntitySpawnable::get_entity_on_index(int index) {
    return this->entity_on_cell[index];
}
