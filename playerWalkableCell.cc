#include "playerWalkableCell.h"

// getter
bool get_open_to_player() {
    return this->open_to_player;
}
PC* get_player_on_cell() {
    return this->player_on_cell;
}

// setter
void set_open_to_player(bool open_to_player) {
    this->open_to_player = open_to_player;
}
void set_player_on_cell(PC* player_on_cell) {
    this->player_on_cell = player_on_cell;
}

PlayerWalkableCell::PlayerWalkableCell(PC* player_on_cell, bool open_to_player) : player_on_cell{player_on_cell}, open_to_player{open_to_player}{
    this->player_walkable = true;   
}

//PlayerWalkableCell::PlayerWalkableCell(bool open_to_player) : open_to_player{open_to_player}{
//    this->player_walkable = true;   
//}

PlayerWalkableCell::PlayerWalkableCell() {
    this->player_walkable = true;
    this->open_to_player = true;
}

PC* PlayerWalkableCell::get_player_on_cell() {
    return this->player_on_cell;
}
