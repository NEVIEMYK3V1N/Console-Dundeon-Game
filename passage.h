#include "playerWalkableCell.h"

class Passage : public PlayerWalkableCell {
 public:
   void render_cell() override;
   
   Passage(char notation, int index);
};
