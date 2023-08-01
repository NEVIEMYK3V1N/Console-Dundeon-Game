#ifndef PC_H
#define PC_H

#include <iostream>
#include <string>

using namespace std;

class NPC;

class PC {
protected:
    int atk, def, hp, hp_max, gold, tile_ID;
    char sym;
    string faction;
    bool can_miss, merchant_status;

public:
    PC(int atk, int def, int hp, int hp_max, string faction, int tile_ID);
    virtual ~PC();
    virtual int get_atk() const;
    virtual int get_def() const;
    virtual int get_hp() const;
    virtual bool get_merch_stat() const;
    virtual bool get_miss() const;
    virtual string get_faction() const;
    virtual int get_tile_ID() const;
    virtual int get_gold() const;
    virtual char get_sym() const;
    virtual void mod_gold(int val);
    virtual void set_tile_ID(int val);
    virtual void set_miss(bool val);
    virtual void set_merch_stat(bool val);
    virtual bool mod_hp(int val);
};


class shade: public PC {
public:
    shade(int tile_ID);
    ~shade();
};


class drow: public PC {
public:
    drow(int tile_ID);
    ~drow();
};


class vampire: public PC {
public:
    vampire(int tile_ID);
    ~vampire();
};


class troll: public PC {
public:
    troll(int tile_ID);
    ~troll();
};


class goblin: public PC {
public:
    goblin(int tile_ID);
    ~goblin();
};

// decorator pattern
// Abstract 
class PotionEffect: public PC {
protected:
    int val;
    string type;
    PC* player; // unique ptr

public:
    PotionEffect(int val, string type, PC* player);
    virtual ~PotionEffect();
    virtual int get_atk() const override;
    virtual int get_def() const override;
    int get_hp() const override;
    bool get_merch_stat() const override;
    bool get_miss() const override;
    string get_faction() const override;
    int get_tile_ID() const override;
    int get_gold() const override;
    char get_sym() const override;
    void mod_gold(int val) override;
    void set_tile_ID(int val) override;
    void set_miss(bool val) override;
    void set_merch_stat(bool val) override;
    bool mod_hp(int val) override;
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

#endif
