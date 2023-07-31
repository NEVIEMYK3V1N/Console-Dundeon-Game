// input output
#include "blockedCell.h"
#include "cell.h"
#include "chamberInterior.h"
#include "cmdInterpreter.h"
#include "entitySpawnable.h"
#include "floor.h"
#include "game.h"
#include "entity.h"
#include "npc.h"
#include "pc.h"
#include "playerWalkableCell.h"
#include "doorway.h"
#include "passage.h"
#include "floorTile.h"
#include "voidCell.h"
#include "wall.h"

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <cmath>
#include <sstream>

// constants for all maps
const char WALL_HORIZONTAL = '-';
const char WALL_VERTICAL = '|';
const char VOID_CELL = ' ';
const char FLOOR_TILE = '.';
const char DOORWAY = '+';
const char PASSAGE = '#';

const char STAIRWAY = '\\';

const char PLAYER = '@';

// constants for rendering map
const char ENEMY_HUMAN_RENDER = 'H';
const char ENEMY_DWARF_RENDER = 'W';
const char ENEMY_ELF_RENDER = 'E';
const char ENEMY_ORC_RENDER = 'O';
const char ENEMY_MERCHANT_RENDER = 'M';
const char ENEMY_DRAGON_RENDER = 'D';
const char ENEMY_HALFLING_RENDER = 'L';
const char POTION_RENDER = 'P';
const char GOLD_RENDER = 'G';

bool is_char_enemy (char c) {
    return (c == ENEMY_HUMAN_RENDER || 
            c == ENEMY_DWARF_RENDER ||
            c == ENEMY_ELF_RENDER ||
            c == ENEMY_ORC_RENDER || 
            c == ENEMY_MERCHANT_RENDER || 
            c == ENEMY_DRAGON_RENDER ||
            c == ENEMY_HALFLING_RENDER);
}

// colors for rendering
const std::string BLUE_TEXT = "\033[34m";
const std::string YELLOW_TEXT = "\033[33m";
const std::string GREEN_TEXT = "\033[32m";
const std::string RED_TEXT = "\033[31m";
const std::string RESET_TEXT = "\033[0m";

// constants for reading exising map
// The translation of numbers to items is as follows: 
// 0 - RH, 1 - BA, 2 - BD, 3 - PH, 4 - WA, 5 - WD, 6 - normal gold pile, 7 - small hoard, 8 - merchant hoard, 9 - dragon hoard.
const char RH = '0';
const char BA = '1';
const char BD = '2';
const char PH = '3';
const char WA = '4';
const char WD = '5';
const char NGP = '6';
const char SH = '7';
const char MH = '8';
const char DH = '9';

const int NGP_VAL = 2;
const int SH_VAL = 1;
const int MH_VAL = 4;
const int DH_VAL = 6;

const char STAIRWAY = '\\';
const char ENEMY_HUMAN_RENDER = 'H';
const char ENEMY_DWARF_RENDER = 'W';
const char ENEMY_ELF_RENDER = 'E';
const char ENEMY_ORC_RENDER = 'O';
const char ENEMY_MERCHANT_RENDER = 'M';
const char ENEMY_DRAGON_RENDER = 'D';
const char ENEMY_HALFLING_RENDER = 'L';

const int NUM_PLAYERS = 1;
const int NUM_FLOORS = 1;
const int DEFAULT_WIDTH = 79;
const int DEFAULT_HEIGHT = 25;
const int DEFAULT_CHAMBER_ON_FLOOR = 5;

const int ARG_NUM_FILENAME = 1;


bool read_entity_map_file(Game* game, std::string file_name, int map_width, int map_height, int num_floors) {
    std::ifstream f(file_name);
    std::string s;
    int index = 0;
    bool contain_entity = false;
    bool contain_player = false;
    std::vector<dragon*> unbounded_drags = {};
    PC* pc = game->get_pc();

    for (int numf = 0; numf < num_floors; numf++) {
        Floor* floor = new Floor(pc, map_height, map_width);
        for (int h = 0; h < map_height; h++) {
            std::getline(std::cin, s);
            int len = s.length();
            for (int w = 0; w < map_width; w++) {
                char c = s[w];
                if (c == WALL_HORIZONTAL || WALL_VERTICAL) {
                    Wall *wall = new Wall(c, index);
                    floor->emplace_cell(make_unique<Wall> (*wall));
                    index++;
                } 
                else if (c == VOID_CELL) {
                    VoidCell *vc = new VoidCell(c, index);
                    floor->emplace_cell(make_unique<VoidCell> (*vc));
                    index++;
                }
                else if (c == FLOOR_TILE) {
                    FloorTile *ft = new FloorTile(c, index);
                    floor->emplace_cell(make_unique<FloorTile> (*ft));
                    index++;
                }
                else if (c == DOORWAY) {
                    Doorway *dw = new Doorway(c, index);
                    floor->emplace_cell(make_unique<Doorway> (*dw));
                    index++;
                }
                else if (c == PASSAGE) {
                    Passage *psg = new Passage(c, index);
                    floor->emplace_cell(make_unique<Passage> (*psg));
                    index++;
                }
                else if (c == RH) {
                    potionHP *pot = new potionHP(true, index);
                    //FloorTile *ft = new FloorTile(c, index);
                    //ft->set_entity_on_index(dynamic_cast<Entity*> (pot));
                    //floor->emplace_cell(make_unique<FloorTile> (*ft));
                    //floor->emplace_entity(make_unique<Entity> (*pot));
                    //contain_entity = true;
                    //index++;
                    read_in_entity(floor, pot, c, index, contain_entity);
                }
                else if (c == BA) {
                    potionAtk *pot = new potionAtk(true, index);
                    read_in_entity(floor, pot, c, index, contain_entity);
                }
                else if (c == BD) {
                    potionDef *pot = new potionDef(true, index);
                    read_in_entity(floor, pot, c, index, contain_entity);
                }
                else if (c == PH) {
                    potionHP *pot = new potionHP(false, index);
                    read_in_entity(floor, pot, c, index, contain_entity);
                }
                else if (c == WA) {
                    potionAtk *pot = new potionAtk(false, index);
                    read_in_entity(floor, pot, c, index, contain_entity);
                }
                else if (c == WD) {
                    potionDef *pot = new potionDef(false, index);
                    read_in_entity(floor, pot, c, index, contain_entity);
                }
                else if (c == NGP) {
                    treGround *normal_pile_gold = new treGround(NGP_VAL, index);
                    read_in_entity(floor, normal_pile_gold, c, index, contain_entity);
                }
                else if (c == SH) {
                    treGround *small_hoard = new treGround(SH_VAL, index);
                    read_in_entity(floor, small_hoard, c, index, contain_entity);
                }
                else if (c == MH) {
                    treGround *merchant_hoard = new treGround(MH_VAL, index);
                    read_in_entity(floor, merchant_hoard, c, index, contain_entity);
                }

                // need change
                else if (c == DH) {
                    
                }

                else if (c == PLAYER) {
                    PC* pc = new shade(index);
                    FloorTile *ft = new FloorTile(c, index);
                    ft->set_player_on_cell(pc);
                    floor->emplace_cell(make_unique<FloorTile> (*ft));
                    floor->set_pc_on_floor(pc);
                    game->set_pc(pc);
                    contain_player = true;
                    index++;
                }
                else if (c == STAIRWAY) {
                    Stairway *stw = new Stairway();
                    read_in_entity(floor, stw, c, index, contain_entity);
                }
                else if (c == ENEMY_HUMAN_RENDER) {
                    human *hm = new human(index);
                    read_in_entity(floor, hm, c, index, contain_entity);
                }
                else if (c == ENEMY_DWARF_RENDER) {
                    dwarf *dw = new dwarf(index);
                    read_in_entity(floor, dw, c, index, contain_entity);
                }
                else if (c == ENEMY_ELF_RENDER) {
                    elf *ef = new elf(index);
                    read_in_entity(floor, ef, c, index, contain_entity);
                }
                else if (c == ENEMY_ORC_RENDER) {
                    orcs *oc = new orcs(index);
                    read_in_entity(floor, oc, c, index, contain_entity);
                }
                else if (c == ENEMY_MERCHANT_RENDER) {
                    merchant *mr = new merchant(index);
                    read_in_entity(floor, mr, c, index, contain_entity);
                }
                else if (c == ENEMY_HALFLING_RENDER) {
                    halfling *hf = new halfling(index);
                    read_in_entity(floor, hf, c, index, contain_entity);
                }

                // need change
                else if (c == ENEMY_DRAGON_RENDER) {
                    dragon *dr = new dragon(index);
                    read_in_entity(floor, dr, c, index, contain_entity);
                    unbounded_drags.emplace_back(dr);
                }
            }
        }
        
        for (int i = 0; i < unbounded_drags.size(); i++) {
            bool top = true;
            bool left = true;
            bool right = true;
            bool bottom = true;

            int index = unbounded_drags[i]->get_tile_ID();

            // the top of map
            if (index < floor->get_width()) {
                top = false;
            }
            // the left of map
            if (index % floor->get_width() == 0) {
                left = false;
            }
            // the right of map
            if (index & floor->get_width() == floor->get_width() - 1) {
                right = false;
            }
            // the bottom of map
            if (index + floor->get_width() >= floor->get_num_cells()) {
                bottom = false;
            }

            for (int h = -1; h <= 1; h++) {
                for (int w = -1; w <= 1; w++) {
                    if (!top && h == -1) {
                        continue;
                    }
                    if (!left && w == -1) {
                        continue;
                    }
                    if (!right && w == 1) {
                        continue;
                    }
                    if (!bottom && h == 1) {
                        continue;
                    }

                    int target_index = index + h * floor->get_height() + w;
                    treDragon* target_dh = dynamic_cast<treDragon*>(floor->get_cell_at_index(target_index));
                    if (target_dh && !(target_dh->dragon)) {
                        target_dh->dragon = unbounded_drags[i];
                        unbounded_drags[i]->hoard = target_dh;
                        break;
                    }
                }
            }
        }
        
        game->emplace_floor(std::make_unique<Floor>(floor));
    }
    return (contain_player || contain_entity);
}


/*void read_empty_map_file(Floor* floor, std::string file_name) {
    std::ifstream f(file_name);
    std::string s;
    int max_width = 0;
    int file_height = 0;
    int index = 0;
    bool contain_entity = false;
    bool contain_player = false;
    while(true) {
        std::getline(std::cin, s);
        int len = s.length();
        if (len == 0) {
            break;
        }
        if (len > max_width) {
            max_width = len;
        }
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if (c == WALL_HORIZONTAL || WALL_VERTICAL) {
                Wall *wall = new Wall(c, index);
                floor->emplace_cell(make_unique<Wall> (*wall));
                index++;
            } 
            else if (c == VOID_CELL) {
                VoidCell *vc = new VoidCell(c, index);
                floor->emplace_cell(make_unique<VoidCell> (*vc));
                index++;
            }
            else if (c == FLOOR_TILE) {
                FloorTile *ft = new FloorTile(c, index);
                floor->emplace_cell(make_unique<FloorTile> (*ft));
                index++;
            }
            else if (c == DOORWAY) {
                Doorway *dw = new Doorway(c, index);
                floor->emplace_cell(make_unique<Doorway> (*dw));
                index++;
            }
            else if (c == PASSAGE) {
                Passage *psg = new Passage(c, index);
                floor->emplace_cell(make_unique<Passage> (*psg));
                index++;
            }
        }
        file_height++;
    }
    floor->set_width(max_width);
    floor->set_height(file_height);
}
*/

void read_in_entity(Floor* floor, Entity* entity, char &c, int &index, bool &contain_entity) {
    FloorTile *ft = new FloorTile(c, index);
    ft->set_entity_on_cell(entity);
    ft->set_open_to_entity(false);
    floor->emplace_cell(make_unique<FloorTile> (*ft));
    floor->emplace_entity(make_unique<Entity> (*entity));
    contain_entity = true;
    index++;
}

void render_map(Floor* floor) {
    int width = floor->get_width();
    int height = floor->get_height();
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            Cell* cell = floor->get_cell_at_index(w + h * height);
            char c = cell->render_cell();
            if (c == PLAYER || c == STAIRWAY) {
                std::cout << BLUE_TEXT;
            } else if (c == GOLD_RENDER) {
                std::cout << YELLOW_TEXT;
            } else if (c == POTION_RENDER) {
                std::cout << GREEN_TEXT;
            } else if (is_char_enemy(c)) {
                std::cout << RED_TEXT;
            }
            std::cout << c;
            std::cout << std::endl << RESET_TEXT;
        }
    }
    // NEED - render the character information below
}

void determine_chambers(Floor* floor, int num_chambers = 6) {
    int curr_chamber = 0;

    for (int i = 0; i < num_chambers; i++) {
        ChamberInterior *ci = new ChamberInterior(i, floor);
        floor->emplace_chamber(make_unique<ChamberInterior>(*ci));
    }

    for(int h = 0; h < floor->get_height(); h++) {
        for(int w = 0; w < floor->get_width(); w++) {
            Cell* curr_cell = floor->get_cell_at_index(h * floor->get_height() + w);
            if (is_top_left_unchecked_wall(floor, curr_cell)) {
                Wall* tl_wall = dynamic_cast<Wall*>(curr_cell);
                if (tl_wall->get_has_chamber()) {
                    continue;
                }
                tl_wall->set_has_chamber(true);
                EntitySpawnable* tl_spawnable = dynamic_cast<EntitySpawnable*> (floor->get_cell_at_index((h + 1) * floor->get_height() + w + 1));
                tl_spawnable->set_root_chamber(floor->get_chamber_at_index(curr_chamber));
                floor->get_chamber_at_index(curr_chamber)->emplace_entityspawnable(tl_spawnable);
                find_all_cell_in_chamber(floor, tl_spawnable, floor->get_chamber_at_index(curr_chamber));
                curr_chamber++;
            }
        }
    }
}

bool is_top_left_unchecked_wall(Floor* floor, Cell* cell) {
    if (cell->get_notation() == WALL_VERTICAL) {
        int index = cell->get_index();
        if (index % floor->get_width() == floor->get_width() - 1) {
            return false;
        }
        if (index % floor->get_width() == 0) {
            return false;
        }

        int right_cell_index = index + 1;
        int bottom_cell_index = index + floor->get_height();
        int br_cell_index = index + floor->get_height() + 1;

        int num_cells = floor->get_num_cells();
        if (right_cell_index < num_cells && bottom_cell_index < num_cells && br_cell_index < num_cells) {
            return (floor->get_cell_at_index(right_cell_index)->get_notation() == WALL_HORIZONTAL &&
                    floor->get_cell_at_index(bottom_cell_index)->get_notation() == WALL_VERTICAL &&
                    dynamic_cast<EntitySpawnable*> (floor->get_cell_at_index(br_cell_index)) &&
                    !dynamic_cast<Wall*> (floor->get_cell_at_index(right_cell_index))->get_has_chamber() &&
                    !dynamic_cast<Wall*> (floor->get_cell_at_index(bottom_cell_index))->get_has_chamber() &&
                    !dynamic_cast<EntitySpawnable*> (floor->get_cell_at_index(br_cell_index))->get_root_chamber());
        }
    }
    return false;
}

void find_all_cell_in_chamber(Floor* floor, Cell* top_left, ChamberInterior* chamber) {
    int ori_index = top_left->get_index();
    int f_height = floor->get_height();
    int f_width = floor->get_width();

    bool top = true;
    bool left = true;
    bool right = true;
    bool bottom = true;

    // the top of map
    if (ori_index < floor->get_width()) {
        top = false;
    }
    // the left of map
    if (ori_index % floor->get_width() == 0) {
        left = false;
    }
    // the right of map
    if (ori_index & floor->get_width() == floor->get_width() - 1) {
        right = false;
    }
    // the bottom of map
    if (ori_index + floor->get_width() >= floor->get_num_cells()) {
        bottom = false;
    }

    for (int h = -1; h <= 1; h++) {
        for (int w = -1; w <= 1; w++) {
            if (h == 0 && w == 0) {
                continue;
            }
            //skip diagonal
            if ((h == -1 && w == -1) ||
                (h == -1 && w == 1) ||
                (h == 1 && w == -1) ||
                (h == 1 && w == 1)) {
                continue;
            }
            if (!top && h == -1) {
                continue;
            }
            if (!left && w == -1) {
                continue;
            }
            if (!right && w == 1) {
                continue;
            }
            if (!bottom && h == 1) {
                continue;
            }

            int curr_index = ori_index + h * f_height + w;
            Cell* curr_cell = floor->get_cell_at_index(curr_index);

            EntitySpawnable* casted_curr_cell = dynamic_cast<EntitySpawnable*> (curr_cell);
            if (casted_curr_cell->get_entity_on_cell() && dynamic_cast<Stairway> (casted_curr_cell->get_entity_on_cell())) {
                chamber->set_has_stairway(true);
                continue;
            }
            if (casted_curr_cell && casted_curr_cell->get_root_chamber()) {
                casted_curr_cell->set_root_chamber(chamber);
                chamber->emplace_entityspawnable(casted_curr_cell);
                find_all_cell_in_chamber(floor, curr_cell, chamber);
            } else {
                Wall* casted_curr_wall = dynamic_cast<Wall*> (curr_cell);
                if (casted_curr_wall) {
                    if (!casted_curr_wall->get_has_chamber()) {
                        casted_curr_wall->set_has_chamber(true);
                    }
                }
            }
        }
    }
    return;
}

// calculate damage using attacker's atk value and defender's def value
int calculate_dmg(int atk, int def) {
    double numerator = 100;
    double def_src = 100 + def;
    int dmg = ceil((numerator / def_src) * atk);
    return dmg;
}


// process available NPC action
void process_NPC_action(NPC* npc, Floor* floor) {
    int row = floor->get_width();
    int ID = npc->get_tile_ID();
    int ID_max = floor->get_num_cells() - 1;
    vector<Cell*> adj_tiles;

    // find every adjacent cell that a player can be on
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            int ID_curr = ID + i * row + j;
            if (ID_curr < 0 || ID_curr > ID_max || ID_curr == ID) {
                continue;
            }
            Cell* cell_curr = floor->get_cell_at_index(ID_curr);
            if (cell_curr->get_player_walkable()) {
                adj_tiles.push_back(cell_curr);
            }
        }
    }

    // find if any adjacent cell has a player present and attack if there are
    int atk_left = 1;
    for (int i = 0; i < adj_tiles.size(); ++i) {
        PlayerWalkableCell* casted = dynamic_cast<PlayerWalkableCell*>(adj_tiles[i]);
        PC* player = casted->get_player_on_cell();
        if (player != nullptr) {
            // if merchant and not aggro
            if (npc->get_sym() == 'M' || player->get_merch_stat() == true) { break;} 
            int atk = npc->get_atk();
            int def = player->get_def();
            int dmg = calculate_dmg(atk, def);
            // elf ability
            if (npc->get_sym() == 'E' && player->get_faction() != "drow") {
                atk_left ++;
            }
            while (atk_left > 0) {
                // 50% chance of hitting the player
                srand(time(0));
                int hit = rand() % 2;
                if (hit == 0) {
                    cout << npc->get_sym() << " attacks the player but missed! " << endl;
                } else {
                    // orcs ability
                    if (npc->get_sym() == 'O' && player->get_faction() == "goblin") {
                        dmg *= 1.5;
                    }
                    // halfling ability
                    if (npc->get_sym() == 'L') {
                        srand(time(0));
                        int affect = rand() % 2;
                        if (affect == 1) {
                            player->set_miss(true);
                        }
                    }

                    if (!player->mod_hp(-dmg)) {
                        // if this occurs it means the player is killed! do what you need to do for I/O and dtor
                    } else {
                        cout << npc->get_sym() << " attacks the player and deals " << dmg << " damage! " << endl;
                    }
                }
                --atk_left;
            }
            return;
        }  
    }

    // move NPC if no player adjacent
    vector<EntitySpawnable*> available_tile;
    for (int i = 0; i < adj_tiles.size(); ++i) {
        if (adj_tiles[i]->get_entity_spawnable()) {
            EntitySpawnable* casted = dynamic_cast<EntitySpawnable*>(adj_tiles[i]);
            // check if tile is empty
            if (casted->get_open_to_entity()) {
                available_tile.push_back(casted);
            }
        }
    }
    int options = available_tile.size();
    // if no move is available for NPC
    if (options == 0) {
        return;
    }
    srand(time(0));
    int chosen = rand() % options;
    int new_ID = available_tile[chosen]->get_index();
    EntitySpawnable* curr_tile = dynamic_cast<EntitySpawnable*>(floor->get_cell_at_index(npc->get_tile_ID()));
    curr_tile->set_entity_on_cell(nullptr);
    curr_tile->set_open_to_entity(true);
    npc->set_tile_ID(new_ID);
    available_tile[chosen]->set_entity_on_cell(npc);
    available_tile[chosen]->set_open_to_entity(false);
}


int main(int argc, char *argv[]) {
    std::string filename;
    // if a file argument is provided
    if (argc > 1) {
        filename = argv[1];
    } else {
        filename = "empty.txt";
    }
    
    int num_floors = NUM_FLOORS;
    int num_players = NUM_PLAYERS;
    int map_height = DEFAULT_HEIGHT;
    int map_width = DEFAULT_WIDTH;
    int num_chambers = DEFAULT_CHAMBER_ON_FLOOR;

    Game* game = nullptr;
    PC* pc = nullptr;

    game = new Game(num_floors, num_players);
    bool need_random_gen = read_entity_map_file(game, filename, map_width, map_height, num_floors);
    for (int i = 0; i < num_floors; i++) {
        Floor* curr_floor = game->get_floor_at(i);
        int chamber_index = 0;
        while (chamber_index < num_chambers) {
            for (int h = 0; h < curr_floor->get_height(); h++) {
                for (int w = 0; w < curr_floor->get_width(); w++) {
                    Cell* curr_cell = curr_floor->get_cell_at_index(h * curr_floor->get_height() + w);
                    if(is_top_left_unchecked_wall(curr_floor, curr_cell)) {
                        ChamberInterior* curr_chamber = new ChamberInterior(chamber_index, curr_floor);
                        find_all_cell_in_chamber(curr_floor, curr_cell, curr_chamber);
                        curr_floor->emplace_chamber(std::make_unique<ChamberInterior>(curr_chamber));
                        chamber_index++;
                    }
                }
            }
        }
    }

    if (need_random_gen) {
        for (int i = 0; i < num_floors; i++) {
            
        }
    }
    
    string cmd;
    cout << "Welcome to CC3K! Please enter the faction that you'd like to play." << endl;
    while (true) {
        cin >> cmd;
        if (cmd == "s") {
            // call shade ctor and attach to game
            break;
        } else if (cmd == "d") {

            break;
        } else if (cmd == "v") {

            break;
        } else if (cmd == "g") {
        
            break;
        } else if (cmd == "t") {

            break;
        } else {
            cout << "your command is not valid, please enter a valid faction" << endl;
        }
    }
    

}