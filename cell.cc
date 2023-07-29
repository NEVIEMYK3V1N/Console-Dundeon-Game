#include "cell.h"

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
   virtual void render_cell() const = 0;
};

Floor* Cell::get_floor() {
    return this->root_floor;
}

void Cell::set_floor(Floor* new_floor) {
    this->root_floor = new_floor;   
}