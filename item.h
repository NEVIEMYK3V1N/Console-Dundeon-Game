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
    potionHP(int val);
    ~potionHP();
    public:
    void consume_item (PC* player) override;
};

class potionAtk: public potion {
    potionAtk(int val);
    ~potionAtk();
    public:
    void consume_item (PC* player) override;
};

class potionDef: public potion {
    potionDef(int val);
    ~potionDef();
    public:
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


