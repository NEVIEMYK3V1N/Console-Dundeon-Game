#include "floorTile.h"

FloorTile::FloorTile (ChamberInterior* root_chamber, char notation, int index)
    : EntitySpawnable{root_chamber}, notation{notation}, index{index} {}

void FloorTile::render_cell() {
    std::cout << this->notation;
}


    