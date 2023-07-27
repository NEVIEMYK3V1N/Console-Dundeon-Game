#include "cell.h"
#include "chamberInterior.h"
#include <memory>
#include <vector>
#include <string>

// needed to change
// #include <entity.h>
class Entity{};
//==============

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

   ChamberInterior* choose_random_chamber();

   void readFromFile(std::string file_name);
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
