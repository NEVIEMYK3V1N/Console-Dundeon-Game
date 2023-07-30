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

void read_entity_map_file(Floor* floor, std::string file_name, int map_width, int map_height, int num_floors) {
    std::ifstream f(file_name);
    std::string s;
    int index = 0;
    bool contain_entity = false;
    bool contain_player = false;
    for (int numf = 0; numf < num_floors; numf++) {
        for (int h = 0; h < map_height; h++) {
            std::getline(std::cin, s);
            int len = s.length();
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
                else if (c == RH) {
                    potionHP *pot = new potionHP(10);
                    //FloorTile *ft = new FloorTile(c, index);
                    //ft->set_entity_on_index(dynamic_cast<Entity*> (pot));
                    //floor->emplace_cell(make_unique<FloorTile> (*ft));
                    //floor->emplace_entity(make_unique<Entity> (*pot));
                    //contain_entity = true;
                    //index++;
                    read_in_entity(floor, pot, c, index, contain_entity);
                }
                else if (c == BA) {
                    potionAtk *pot = new potionAtk(5);
                    read_in_entity(floor, pot, c, index, contain_entity);
                }
                else if (c == BD) {
                    potionDef *pot = new potionDef(5);
                    read_in_entity(floor, pot, c, index, contain_entity);
                }
                else if (c == PH) {
                    potionHP *pot = new potionHP(-10);
                    read_in_entity(floor, pot, c, index, contain_entity);
                }
                else if (c == WA) {
                    potionAtk *pot = new potionAtk(-5);
                    read_in_entity(floor, pot, c, index, contain_entity);
                }
                else if (c == WD) {
                    potionDef *pot = new potionDef(-5);
                    read_in_entity(floor, pot, c, index, contain_entity);
                }
                // unfinished ======================================

                // NEED FROM WILLIAM - CONSTRUCTOR OF EACH ITEM
                else if (c == NGP) {
                    treGround * normal_pile_gold = new treGround();
                    read_in_entity(floor, normal_pile_gold, c, index, contain_entity);
                }
                else if (c == SH) {

                }
                else if (c == MH) {

                }
                else if (c == DH) {
                    Dragonhou.
                }
                else if (c == PLAYER)
            }
        }
    }
}

void read_empty_map_file(Floor* floor, std::string file_name) {
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

void read_in_entity(Floor* floor, Entity* entity, char &c, int &index, bool &contain_entity) {
    FloorTile *ft = new FloorTile(c, index);
    ft->set_entity_on_index(entity);
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
            if (is_top_left_wall(floor, curr_cell)) {
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

bool is_top_left_wall(Floor* floor, Cell* cell) {
    if (cell->get_notation() == WALL_VERTICAL) {
        int index = cell->get_index();
        int right_cell_index = index + 1;
        int bottom_cell_index = index + floor->get_height();
        int br_cell_index = index + floor->get_height() + 1;

        int num_cells = floor->get_num_cells();
        if (right_cell_index < num_cells && bottom_cell_index < num_cells && br_cell_index < num_cells) {
            return (dynamic_cast<Wall*> (floor->get_cell_at_index(right_cell_index)) &&
                    dynamic_cast<Wall*> (floor->get_cell_at_index(bottom_cell_index)) &&
                    dynamic_cast<EntitySpawnable*> (floor->get_cell_at_index(br_cell_index)));
        }
    }
    return false;
}

void find_all_cell_in_chamber(Floor* floor, Cell* top_left, ChamberInterior* chamber) {
    int ori_index = top_left->get_index();
    int f_height = floor->get_height();
    int f_width = floor->get_width();

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
