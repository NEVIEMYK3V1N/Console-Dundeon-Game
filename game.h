/* @author: Kevin Yang
   @purpose: This is a concrete class, representing the current game being played
             This class possess ownership over all its floors and subsequent objects
*/

// include guard
#ifndef GAME_H
#define GAME_H

#include "floor.h"
#include <memory>
#include <vector>

class Game {
    int num_players;
    int num_floors;
    int curr_floor;
    bool game_on;
    std::vector<Floor*> all_floors;
 public:
   // Constructor: initialize a basic game
   //    client required to generate floors on the games
   Game(int num_floors, int num_players);

   // Destructor: deletes all memory used by floors in all_floors
   ~Game();
   
   // adds the floor to the back of all_floors
   //    game takes over ownership of this floor, client can no longer free
   void emplace_floor(Floor* floor);

   // getters
   int get_num_players();
   int get_num_floors();
   int get_curr_floor();
   bool get_game_on();
   Floor* get_floor_at(int index = 0);

   // setters
   void set_num_players(int num_players);
   void set_num_floors(int num_floors);
   void set_curr_floor(int curr_floor);
   void set_game_on(bool game_on);
};

#endif
