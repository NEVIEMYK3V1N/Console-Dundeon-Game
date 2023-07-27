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
    virtual void attack(PC& player);
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
    void attack(PC& player) override;
};

class elf: public NPC {
    public:
    elf();
    ~elf();
    void attack(PC& player) override;
};

class orcs: public NPC {
    public:
    orcs();
    ~orcs();
    void attack(PC& player) override;
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
    void attack(PC& player) override;
};

class dragon: public NPC {
    public:
    dragon();
    ~dragon();
};

