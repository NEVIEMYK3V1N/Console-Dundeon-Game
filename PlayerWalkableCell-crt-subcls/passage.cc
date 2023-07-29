#include "passage.h"
#include <iostream>

Passage::Passage(char notation, int index) : PlayerWalkableCell{} {
    this->entity_spawnable = false;
    this->notation = notation;
    this->index = index; 
}

char Passage::render_cell() {
    if (this->player_on_cell) {
        return this->player_on_cell->get_sym();
    } else {
        return this->notation;
    }   
}
