//#include "floor.h"

#ifndef CELL_H
#define CELL_H

class Floor;

class Cell {
  Floor* root_floor;
 protected:
  //int pos_row;
  //int pos_col;
  int index;
  char notation;
  //int cell_type;
  bool player_walkable;
  bool entity_spawnable;
 public:
  virtual char render_cell() = 0;

  // getters
  Floor* get_root_floor();
  int get_index();
  char get_notation();
  bool get_player_walkable();
  bool get_entity_spawnable();
  bool get_player_walkable();
  bool get_entity_spawnable();

  // setters
  void set_root_floor(Floor* root_floor);
  void set_index(int index);
  void set_notation(char notation);
};

#endif
