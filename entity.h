#include <iostream>
#include <string>
#include "pc.h"

using namespace std;

class entity {
protected:
    int tile_ID;
    bool gold, pot, NPC;
public:
    entity(bool gold, bool pot, bool NPC, int tile_ID);
    virtual ~entity();
    bool is_gold() const;
    bool is_pot() const;
    bool is_NPC() const;
    int get_tile_ID() const;
    void set_tile_ID(int val);
    virtual char get_sym() const = 0;
};



class item : public entity {
public:
    item(bool gold, bool pot, bool NPC, int tile_ID);
    virtual ~item();
    virtual PC* consume_item(PC* player) = 0;
};

class potion: public item {
protected:
    int val;
    string pot_type;

public:
    potion(int val, bool eff, string pot_type, int tile_ID);
    ~potion();
    void is_drow(const PC* player);
    char get_sym() const override;
};

class potionHP: public potion {
public:
    potionHP(bool eff, int tile_ID, int val = 10);
    ~potionHP();
    PC* consume_item (PC* player) override;
};
class potionAtk: public potion {
public:
    potionAtk(bool eff, int tile_ID, int val = 5);
    ~potionAtk();
    PC* consume_item (PC* player) override;
};

class potionDef: public potion {
public:
    potionDef(bool eff, int tile_ID, int val = 5);
    ~potionDef();
    PC* consume_item (PC* player) override;
};


class treasure: public item {
protected:
    int val;
    string size;
    bool dragon;
public:
    treasure(int val, int tile_ID, string size, bool dragon);
    ~treasure();
    bool dragon_alive() const;
    void set_dragon(bool val);
    PC* consume_item (PC* player) override;
};

class treGround: public treasure {
public:
    treGround(int val, int tile_ID, string size);
    ~treGround();
};

class treDragon: public treasure {
public:
    treDragon(int val, int tile_ID);
    ~treDragon();
};

