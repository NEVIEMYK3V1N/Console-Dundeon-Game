#include "blockedCell.h"

class Wall : public BlockedCell {
 public:
    char render_cell() override;

    Wall(char notation, int index);
};