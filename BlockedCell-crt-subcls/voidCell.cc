#include "voidCell.h"
#include <iostream>

VoidCell::VoidCell(char notation, int index) : BlockedCell{}, notation{notation}, index{index} {}

void VoidCell::render_cell() {
    std::cout << this->notation;
}
