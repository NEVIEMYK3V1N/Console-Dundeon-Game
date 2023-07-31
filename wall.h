#ifndef WALL_H
#define WALL_H

#include "blockedCell.h"

class Wall : public BlockedCell {
    bool has_chamber;
 public:
    char render_cell() override;

    Wall(char notation, int index, bool has_chamber = false);

    // getters
    bool get_has_chamber();

    // setters
    void set_has_chamber(bool has_chamber);
};

#endif
