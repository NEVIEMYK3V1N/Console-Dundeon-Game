#include "game.h"
#include <memory>
#include <vector>

Game::Game(int num_floors, int num_players, CmdInterpreter* cmdInt) : num_players{num_players}, num_floors{num_floors}, cmdInt{cmdInt} {
    this->curr_floor = 0;
    this->game_on = true;
    this->pc = std::make_unique<PC> ();
    this->all_floors = {};
}

void Game::generate_floor(std::string file_name, int num_stairway, int num_potions, int num_gold, int num_enemy) {
    int floor_length = (this->all_floors).size();
    Floor *floor = new Floor (file_name, num_stairway, num_potions, num_gold, num_enemy, floor_length, *(this->pc));
    (this->all_floors).emplace_back(make_unique<Floor> (*floor));
}

void Game::load_floor(std::string file_name) {
    int floor_length = (this->all_floors).size();
    Floor *floor = new Floor (file_name, *(this->pc));
    (this->all_floors).emplace_back(make_unique<Floor> (*floor));
}
