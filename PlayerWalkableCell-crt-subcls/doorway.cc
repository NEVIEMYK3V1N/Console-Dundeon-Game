#include "doorway.h"
#include <iostream>

Doorway::Doorway(char notation, int index) : PlayerWalkableCell{} {
    this->entity_spawnable = false;
    this->notation = notation;
    this->index = index;
}

char Doorway::render_cell() {
    if (this->player_on_cell) {
        return this->player_on_cell->get_sym();
    } else {
        return this->notation;
    }   
}
