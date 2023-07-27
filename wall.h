#include "blockedCell.h"

class Wall : public BlockedCell {
 public:
    void render_cell() override;
};