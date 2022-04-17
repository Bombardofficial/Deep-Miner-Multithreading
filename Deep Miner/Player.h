#pragma once
#include <string>
#include "Miner.h"
#include "reverse_miner.h"
#include "threetype_miner.h"
#include "third_miner.h"
class Player
{
public:
    std::string name;
    //Cast* cast;
    //int cast; //
    Miner* miner;
    Player(std::string name) : name(name), miner(NULL) {}
    //virtual Spell* chooseAttack() = 0;
    virtual void chooseCast() = 0;
    virtual string richtung() = 0;
    //void decreaseHealth(int amount);
    //bool hasDied();

    
};

