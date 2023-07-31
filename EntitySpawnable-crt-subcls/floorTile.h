#ifndef FLOORTILE_H
#define FLOORTILE_H

#include "entitySpawnable.h"

class FloorTile : public EntitySpawnable {
 public:
    char render_cell() override;

    FloorTile (char notation, int index, ChamberInterior* root_chamber = nullptr);
};

#endif
