#include <iostream>
#include <string>

using namespace std;

class PC {
    protected:
    int atk, def, hp, hp_max, gold;
    char sym;
    string faction;
    bool can_miss, merchant_status;

    public:
    PC(int atk, int def, int hp, int hp_max, string faction);
    virtual ~PC();
    int get_atk() const;
    int get_def() const;
    int get_hp() const;
    bool get_merch_stat() const;
    string get_faction() const;
    void set_miss(bool val);
    void set_merch_stat(bool val);
    bool mod_hp(int val);
    void move_pos();
    virtual void attack();
    virtual void unique_ability();
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
    bool allergy;
    public:
    vampire();
    ~vampire();
    void unique_ability() override;
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

