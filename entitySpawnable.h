#ifndef ENTITYSPAWNABLE_H
#define ENTITYSPAWNABLE_H

#include "playerWalkableCell.h"
//#include "chamberInterior.h"
#include <vector>

class ChamberInterior;
class Entity;

class EntitySpawnable : public PlayerWalkableCell {
 protected:
   bool open_to_entity;
   ChamberInterior* root_chamber;
   //std::vector<Entity*> entity_on_cell;
   Entity* entity_on_cell;
 public:
  //EntitySpawnable(ChamberInterior* root_chamber);
  //EntitySpawnable(ChamberInterior* root_chamber, std::vector<Entity*> entity_on_cell, bool open_to_entity);
  //EntitySpawnable(ChamberInterior* root_chamber, Entity* entity_on_cell, bool open_to_entity);
  EntitySpawnable(ChamberInterior* root_chamber = nullptr, Entity* entity_on_cell = nullptr, bool open_to_entity = true);

  // getters
  bool get_open_to_entity();
  ChamberInterior* get_root_chamber();
  Entity* get_entity_on_cell();  
  //Entity* get_entity_on_index(int index = 0);  
    // Entity* get_entity_on_cell_at(int index = 0);

  // setters
  void set_open_to_entity(bool open_to_entity);
  void set_root_chamber(ChamberInterior* root_chamber);
  void set_entity_on_cell(Entity* entity);
  //void set_entity_on_index(Entity* entity, int index = 0);
    // void set_entity_on_cell_at(Entity* entity, int index = 0);
};

#endif
