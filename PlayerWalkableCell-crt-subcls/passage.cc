#include "passage.h"
#include <iostream>

Passage::Passage(char notation, int index) : PlayerWalkableCell{}, notation {notation}, index{index} {
    this->entity_spawnable = false;
}

void Passage::render_cell() {
    std::cout << this->notation;
}
