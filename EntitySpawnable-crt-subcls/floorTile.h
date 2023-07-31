#ifndef FLOORTILE_H
#define FLOORTILE_H

#include "entitySpawnable.h"
#include "pc.h"
#include "entity.h"

class FloorTile : public EntitySpawnable {
 public:
    char render_cell() override;

    FloorTile (char notation, int index, ChamberInterior* root_chamber = nullptr);
};

#endif
