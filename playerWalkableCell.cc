#include "playerWalkableCell.h"

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
