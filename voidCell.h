#include "blockedCell.h"

class VoidCell : public BlockedCell {
 public:
    void render_cell() override;
    
    VoidCell(char notation, int index);
};
