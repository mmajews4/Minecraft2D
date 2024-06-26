#ifndef CRAFTING_H
#define CRAFTING_H

#include "../Block.h"

class Crafting : public Block {

    const int BREAK_TIME = 15;
    const BlockSign BLOCK_SIGN = T;

public:
    Crafting();

    virtual int getBreakeTime() const;
    virtual BlockSign getBlockSign() const;
};

#endif