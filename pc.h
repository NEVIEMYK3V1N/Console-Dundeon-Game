#include <iostream>
#include <string>
#include "npc.h"

using namespace std;

class PC {
    protected:
    int atk, def, hp, hp_max, gold;
    char sym;
    string faction;
    bool can_miss;

    public:
    PC(int atk, int def, int hp, int hp_max, string faction);
    virtual ~PC();
    string get_faction();
    bool get_miss();
    void move_pos();
    virtual void attack();
    virtual bool take_damage(int dmg);
};


class shade: public PC {
    public:
    shade();
    ~shade();
};


class drow: public PC {
    public:
    drow();
    ~drow();
};


class vampire: public PC {
    public:
    vampire();
    ~vampire();
};


class troll: public PC {
    public:
    troll();
    ~troll();
};


class goblin: public PC {
    public:
    goblin();
    ~goblin();
};

