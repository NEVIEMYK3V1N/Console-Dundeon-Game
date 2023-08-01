#include "game.h"

Game::Game(int num_floors, int num_players) : num_players{num_players}, num_floors{num_floors} {
    this->curr_floor = 0;
    this->game_on = true;
    this->all_floors;
}

// deletes subsequent floors
Game::~Game() {
    for(int i = 0; i < (this->all_floors).size(); i++) {
        delete this->all_floors[i];
    }
}

void Game::emplace_floor(Floor* floor) {
    this->all_floors.emplace_back(floor);
}

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

Floor* Game::get_floor_at(int index) {
    // error checking - out of bound index
    if (index >= this->all_floors.size()) {
        return nullptr;
    }
    return (this->all_floors[index]);
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
