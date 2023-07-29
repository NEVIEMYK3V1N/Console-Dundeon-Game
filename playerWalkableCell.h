#include "cell.h"

// needed to change
// #include <pc.h>
class PC {};
//

class PlayerWalkableCell : public Cell {
 protected:
    bool open_to_player;
    PC* player_on_cell;
 public:
    PlayerWalkableCell(PC* player_on_cell, bool open_to_player);
    // PlayerWalkableCell(bool open_to_player);
    PlayerWalkableCell();
};
