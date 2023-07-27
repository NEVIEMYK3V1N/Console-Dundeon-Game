#include <floor.h>

class Cell {
    Floor* root_floor;
 protected:
    //int pos_row;
    //int pos_col;
    char notation;
    int cell_type;
    bool player_walkable;
    bool entity_spawnable;
    int index_in_map;
 public:
    virtual void render_cell() const = 0;
};


