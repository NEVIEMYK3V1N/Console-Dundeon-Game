#include "floor.h"
#include "cmdInterpreter.h"
#include <memory>
#include <vector>

// needed to change
// #include <pc.h>
class PC{};
// ===========

class Game {
    int num_players;
    int num_floors;
    int curr_floor;
    bool game_on;
    CmdInterpreter* cmdInt;
    std::vector<std::unique_ptr<PC>> pc;
    std::vector<std::unique_ptr<Floor>> all_floors;
 public:
    void generate_floor(std::string file_name, int num_stairway, int num_potions,
                        int num_gold, int num_enemy);
    void load_floor(std::string file_name);

    Game();
    //~Game();
    //Game(const Game &other);
    //Game &operator=(const Game &other);
    //Game(const Game &&other);
    //Game &operator= (const Game &&other);

    // getters
    int get_num_players();
    int get_num_floors();
    int get_curr_floor();
    bool get_game_on();
    CmdInterpreter* get_cmdInt();

    PC* get_pc_at(int index = 0);
    Floor* get_floor_at(int index = 0);

    // setters
    void set_num_players(int num_players);
    void set_num_floors(int num_floors);
    void set_curr_floor(int curr_floor);
    void set_game_on(bool game_on);
    void set_cmdInt(CmdInterpreter* cmdInt);

};

