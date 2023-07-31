#ifndef DOORWAY_H
#define DOORWAY_H

#include "playerWalkableCell.h"

class Doorway : public PlayerWalkableCell {
 public:
  char render_cell() override;

  Doorway(char notation, int index);
};

#endif
