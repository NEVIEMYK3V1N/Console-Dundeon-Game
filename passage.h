#ifndef PASSAGE_H
#define PASSAGE_H

#include "playerWalkableCell.h"

class Passage : public PlayerWalkableCell {
 public:
   char render_cell() override;
   
   Passage(char notation, int index);
};

#endif
