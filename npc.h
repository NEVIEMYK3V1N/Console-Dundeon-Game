#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "pc.h"

using namespace std;

//playable character class forward declaration
class PC;

class NPC {
    protected:
    int atk, def, hp;
    char sym;
    string faction;

    public:
    NPC(int atk, int def, int hp, char sym, string faction);
    ~NPC();
    int get_atk();
    int get_def();
    virtual void set_action();
    virtual int attack(PC& player);
    virtual bool mod_hp(int dmg);
    virtual void death_drop();
};

class human: public NPC {
    public:
    human();
    ~human();
    void death_drop() override;
};

class dwarf: public NPC {
    public:
    dwarf();
    ~dwarf();
    int attack(PC& player) override;
};

class elf: public NPC {
    public:
    elf();
    ~elf();
    int attack(PC& player) override;
};

class orcs: public NPC {
    public:
    orcs();
    ~orcs();
    int attack(PC& player) override;
};

class merchant: public NPC {
    public:
    merchant();
    ~merchant();
    void death_drop() override;
};

class halfling: public NPC {
    public:
    halfling();
    ~halfling();
    int attack(PC& player) override;
};

class dragon: public NPC {
    public:
    dragon();
    ~dragon();
};

