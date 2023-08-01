#include "floorTile.h"

FloorTile::FloorTile (char notation, int index, ChamberInterior* root_chamber)
    : EntitySpawnable{root_chamber} {
        this->notation = notation;
        this->index = index;
    }

char FloorTile::render_cell() {
    if (this->player_on_cell) {
        return this->player_on_cell->get_sym();
    }
    if (this->entity_on_cell) {
        //std::cerr << this->index << ": has entity";
        //std::cerr << this->index << ": has entity";
        return this->entity_on_cell->get_sym();
    } else {
        return this->notation;
    }   
}

