#include "npc.h"

using namespace std;

NPC::NPC(int atk, int def, int hp, char sym, string faction) :
    atk{atk}, def{def}, hp{hp}, sym{sym}, faction{faction} {};
NPC::~NPC() {};


