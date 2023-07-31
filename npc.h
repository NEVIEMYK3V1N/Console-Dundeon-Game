#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "pc.h"
#include "entity.h"

using namespace std;

//playable character class forward declaration
class PC;

class NPC: public Entity{
    protected:
    int atk, def, hp, tile_ID;
    char sym;
    string faction;

    public:
    NPC(int atk, int def, int hp, char sym, string faction, int tile_ID);
    ~NPC();
    int get_atk() const;
    int get_def() const;
    char get_sym() const override;
    virtual bool mod_hp(int dmg);
};

class human: public NPC {
    public:
    human(int tile_ID);
    ~human();
};

class dwarf: public NPC {
    public:
    dwarf(int tile_ID);
    ~dwarf();
};

class elf: public NPC {
    public:
    elf(int tile_ID);
    ~elf();
};

class orcs: public NPC {
    public:
    orcs(int tile_ID);
    ~orcs();
};

class merchant: public NPC {
    public:
    merchant(int tile_ID);
    ~merchant();
};

class halfling: public NPC {
    public:
    halfling(int tile_ID);
    ~halfling();
};

class dragon: public NPC {
    int treasure_tile_ID;
    public:
    dragon(int tile_ID, int treasure_tile_ID);
    ~dragon();
    int get_treasure_tild_ID() const {};
    void set_treasure_tild_ID(int val) {};
};

