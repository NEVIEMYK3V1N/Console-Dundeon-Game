#include "wall.h"
#include <iostream>

Wall::Wall(char notation, int index) : BlockedCell{} {
    this->notation = notation;
    this->index = index;
}

char Wall::render_cell() {
    return this->notation;
}
