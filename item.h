#include <iostream>
#include <string>
#include "pc.h"

using namespace std;

class item {
    public:
    virtual ~item();
    virtual void consume_item(PC* player) = 0;
};

class potion: public item {
    protected:
    int val;
    string pot_type;

    public:
    potion(int val, string pot_type);
    ~potion();
    void is_drow(const PC* player);
};

class potionHP: public potion {
    public:
    potionHP(int val);
    ~potionHP();
    void consume_item (PC* player) override;
};

class potionAtk: public potion {
    public:
    potionAtk(int val);
    ~potionAtk();
    void consume_item (PC* player) override;
};

class potionDef: public potion {
    public:
    potionDef(int val);
    ~potionDef();
    void consume_item (PC* player) override;
};


class treasure: public item {
protected:
    int val;
    string size;
public:
    treasure(int val, string size);
    ~treasure();
};

class treGround: public treasure {
    //treGround(int val, string size)
};


