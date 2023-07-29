#include "doorway.h"
#include <iostream>

Doorway::Doorway(char notation, int index) : PlayerWalkableCell{}, notation {notation}, index{index} {
    this->entity_spawnable = false;
}

void Doorway::render_cell() {
    std::cout << this->notation;
}
