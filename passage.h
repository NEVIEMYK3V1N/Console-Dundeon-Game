#include <playerWalkableCell.h>

class Passage : public PlayerWalkableCell {
 protected:
    entity_spawnable = false;
 public:
    void render_cell() override;
};
