#include <floor.h>
#include <cmdInterpreter.h>
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
                        int num_gold, int num_enemy, int floor_level, PC* pc);
    void load_floor(std::string file_name, PC* pc);
};

