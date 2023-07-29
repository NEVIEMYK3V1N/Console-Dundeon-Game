#include "playerWalkableCell.h"
//#include "chamberInterior.h"
#include <vector>

class ChamberInterior;

// needed to change
// #include <entity.h>
class Entity{};
//=========

class EntitySpawnable : public PlayerWalkableCell {
 protected:
   bool open_to_entity;
   ChamberInterior* root_chamber;
   //std::vector<Entity*> entity_on_cell;
   Entity* entity_on_cell;
 public:
  EntitySpawnable(ChamberInterior* root_chamber);
  //EntitySpawnable(ChamberInterior* root_chamber, std::vector<Entity*> entity_on_cell, bool open_to_entity);
  EntitySpawnable(ChamberInterior* root_chamber, Entity* entity_on_cell, bool open_to_entity);

  // getters
  bool get_open_to_entity();
  ChamberInterior* get_root_chamber();
  Entity* get_entity_on_index();  
  //Entity* get_entity_on_index(int index = 0);  
    // Entity* get_entity_on_cell_at(int index = 0);

  // setters
  void set_open_to_entity(bool open_to_entity);
  void set_root_chamber(ChamberInterior* root_chamber);
  void set_entity_on_index(Entity* entity);
  //void set_entity_on_index(Entity* entity, int index = 0);
    // void set_entity_on_cell_at(Entity* entity, int index = 0);
};
