#include <cell.h>

class BlockedCell : public Cell {
 protected:
    player_walkable = false;
    entity_spawnable = false;
};
