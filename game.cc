#include "game.h"
#include <memory>
#include <vector>

// getters
int Game::get_num_players() {
    return this->num_players;
}
int Game::get_num_floors() {
    return this->num_floors;
}
int Game::get_curr_floor() {
    return this->curr_floor;
}
bool Game::get_game_on() {
    return this->game_on;
}
CmdInterpreter* Game::get_cmdInt() {
    return this->cmdInt;
}

PC* Game::get_pc_at(int index = 0) {
    // NEED - error check range
    return (this->pc[index]).get();
}
Floor* Game::get_floor_at(int index = 0) {
    // NEED - error check range
    return (this->all_floors[index]).get();
}

// setters
void Game::set_num_players(int num_players) {
    this->num_players = num_players;
}
void Game::set_num_floors(int num_floors) {
    this->num_floors = num_floors;
}
void Game::set_curr_floor(int curr_floor) {
    this->curr_floor = curr_floor;
}
void Game::set_game_on(bool game_on) {
    this->game_on = game_on;
}
void Game::set_cmdInt(CmdInterpreter* cmdInt) {
    this->cmdInt = cmdInt;
}

Game::Game(int num_floors, int num_players, CmdInterpreter* cmdInt) : num_players{num_players}, num_floors{num_floors}, cmdInt{cmdInt} {
    this->curr_floor = 0;
    this->game_on = true;
    PC* new_pc = new PC();
    this->pc = std::make_unique<PC> (new_pc);
    //for (int i = 0; i < num_players; i++) {
    //    PC* pc = new PC();
    //    (this->pc).emplace_back(std::make_unique<PC> (pc));
    //}
    this->all_floors = {};
}

void Game::generate_floor(std::string file_name, int num_stairway, int num_potions, int num_gold, int num_enemy) {
    int floor_length = (this->all_floors).size();
    Floor *floor = new Floor (file_name, num_stairway, num_potions, num_gold, num_enemy, floor_length, (this->pc).get());
    (this->all_floors).emplace_back(std::make_unique<Floor> (*floor));
}

//void Game::load_floor(std::string file_name) {
//    int floor_length = (this->all_floors).size();
//    Floor *floor = new Floor (file_name, (this->pc).get());
//    (this->all_floors).emplace_back(std::make_unique<Floor> (*floor));
//}

