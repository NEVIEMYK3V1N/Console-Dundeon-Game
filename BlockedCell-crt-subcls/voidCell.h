#include "blockedCell.h"

class VoidCell : public BlockedCell {
 public:
    char render_cell() override;
    
    VoidCell(char notation, int index);
};
