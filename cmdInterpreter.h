#ifndef CMDINTERPRETER_H
#define CMDINTERPRETER_H

#include "game.h"
#include <string>
#include <memory>
#include <vector>

class PC;

class CmdInterpreter {
    std::unique_ptr<Game> game;
 public:
    void move_player(std::string direction);
    void use_potion(std::string direction);
    void attack_dir(std::string direction);
    void instantiate_player_race(std::string race);
    void switch_enemy_movement();
    void restart_game();
    void quit_game();

    void print_board();
    void start_game(int num_floors, int num_players);

    // getters
    Game* get_game();
};

#endif
