// input output
#include "blockedCell.h"
#include "cell.h"
#include "chamberInterior.h"
#include "cmdInterpreter.h"
#include "entitySpawnable.h"
#include "floor.h"
#include "game.h"
#include "item.h"
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

void read_from_file(Floor* floor, std::string file_name) {
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
            /*
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
            // unfinished 
            else if (c == NGP) {
                treGround * normal_pile_gold = new treGround();
                read_in_entity(floor, normal_pile_gold, c, index, contain_entity);
            }
            else if (c == SH) {

            }
            else if (c == MH) {

            }
            else if (c == DH) {

            }
            else if (c == @)
            */
        }
        file_height++;
    }
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
