#include <cell.h>

// needed to change
// #include <pc.h>
class PC {};
//

class playerWalkableCell : public Cell {
 protected:
    player_walkable = true;
    bool open_to_player;
    PC* player_on_cell;
};
