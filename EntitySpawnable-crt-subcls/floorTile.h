#include <entitySpawnable.h>

class FloorTile : public EntitySpawnable {
 public:
    void render_cell() override;

    FloorTile (ChamberInterior* root_chamber, char notation, int index);
};
