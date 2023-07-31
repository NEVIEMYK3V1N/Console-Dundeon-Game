#ifndef FLOOR_H
#define FLOOR_H

#include <memory>
#include <memory>
#include <vector>
#include <string>
#include "cell.h"
#include "chamberInterior.h"

class ChamberInterior;
class Entity;
class PC;

class Floor {
  int num_stairway;
  int num_potions;
  int num_gold;
  int num_enemy;
  int floor_level;
  int width;
  int height;
  //std::vector<PC*> pc_on_floor;
  PC* pc_on_floor;
  std::vector<std::unique_ptr<Entity>> entities_on_floor;
  std::vector<std::unique_ptr<Cell>> map;
  std::vector<std::unique_ptr<ChamberInterior>> chambers_on_floor;

  //std::vector<playerWalkableCell*> player_cells;

  //ChamberInterior* choose_random_chamber();

  //void readFromFile(std::string file_name);
 protected:
  bool enemy_movable;
 public:
  //void spawn_all_player(PC* pc);
  //void spawn_all_stairway();
  //void spawn_all_potion();
  //void spawn_all_gold();
  //void spawn_all_enemy();
  //void render_map();
  //void move_all_entities();

  Floor(PC* pc, int height, int width, int floor_level, int num_stairway = 0, int num_potions = 0, int num_gold = 0, int num_enemy = 0);

  void emplace_cell(std::unique_ptr<Cell> cell);
  void emplace_entity(std::unique_ptr<Entity> entity);
  void emplace_chamber(std::unique_ptr<ChamberInterior> ci);

  int get_num_cells();

  // getters
  int get_num_stairway();
  int get_num_potions();
  int get_num_gold();
  int get_num_enemy();
  int get_floor_level();
  int get_width();
  int get_height();
  PC* get_pc_on_floor();

  int get_num_chambers();

  Entity* get_entity_at_index(int index);
  Cell* get_cell_at_index(int index);
  ChamberInterior* get_chamber_at_index(int index);

  // setters
  void set_num_stairway(int num_stairway);
  void set_num_potions(int num_potions);
  void set_num_gold(int num_gold);
  void set_num_enemy(int num_enemy);
  void set_floor_level(int floor_level);
  void set_width(int width);
  void set_height(int height);
  void set_pc_on_floor(PC* pc_on_floor);
};

#endif
