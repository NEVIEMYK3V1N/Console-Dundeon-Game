#include <iostream>
#include <string>

using namespace std;

class NPC;

class PC {
protected:
    int atk, def, hp, hp_max, gold;
    char sym;
    string faction;
    bool can_miss, merchant_status;

public:
    PC(int atk, int def, int hp, int hp_max, string faction);
    virtual ~PC();
    virtual int get_atk() const;
    virtual int get_def() const;
    virtual int get_hp() const;
    virtual bool get_merch_stat() const;
    virtual string get_faction() const;
    virtual void set_miss(bool val);
    virtual void set_merch_stat(bool val);
    virtual bool mod_hp(int val);
    virtual void move_pos();
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

// decorator pattern
// Abstract 
class PotionEffect: public PC {
protected:
    int val;
    string type;
    PC* player;

public:
    PotionEffect(int val, string type, PC* player);
    virtual ~PotionEffect();
    virtual int get_atk() const override;
    virtual int get_def() const override;
    int get_hp() const override;
    bool get_merch_stat() const override;
    string get_faction() const override;
    void set_miss(bool val) override;
    void set_merch_stat(bool val) override;
    bool mod_hp(int val) override;
    void move_pos() override;
    void attack() override;
    void unique_ability() override;
};


class PotAtk: public PotionEffect {
public:
    PotAtk(int val, PC* player);
    int get_atk() const override;
};

class PotDef: public PotionEffect {
public:
    PotDef(int val, PC* player);
    int get_def() const override;
};


