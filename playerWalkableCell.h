#include "cell.h"

// needed to change
// #include <pc.h>
class PC {};
//

class PlayerWalkableCell : public Cell {
 protected:
   bool open_to_player;
   PC* player_on_cell;
 public:
   PlayerWalkableCell(PC* player_on_cell = nullptr, bool open_to_player = true);
   // PlayerWalkableCell(bool open_to_player);
   //PlayerWalkableCell();

   // getter
   bool get_open_to_player();
   PC* get_player_on_cell();
   
   // setter
   void set_open_to_player(bool open_to_player);
   void set_player_on_cell(PC* player_on_cell);
};
