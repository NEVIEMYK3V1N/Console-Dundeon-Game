#include "playerWalkableCell.h"

class Doorway : public PlayerWalkableCell {
 public:
   void render_cell() override;

   Doorway(char notation, int index);
};
