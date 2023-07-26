#include <playerWalkableCell.h>
#include <chamberInterior.h>
#include <vector>

// needed to change
// #include <entity.h>
class Entity{};
//=========

class EntitySpawnable : public PlayerWalkableCell {
 protected:
    entity_spawnable = true;
    bool open_to_entity;
    ChamberInterior* root_chamber;
    std::vector<Entity*> entity_on_cell;
};