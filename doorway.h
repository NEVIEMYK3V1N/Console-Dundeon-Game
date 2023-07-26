#include <playerWalkableCell.h>

class Doorway : public PlayerWalkableCell {
 protected:
    entity_spawnable = false;
 public:
    void render_cell() override;
};
