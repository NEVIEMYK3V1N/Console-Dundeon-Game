#include "wall.h"
#include <iostream>

Wall::Wall(char notation, int index) : BlockedCell{}, notation{notation}, index{index} {}

void Wall::render_cell() {
    std::cout << this->notation;
}
