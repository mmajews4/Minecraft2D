#ifndef CRAFTING_H
#define CRAFTING_H

#include "../Block.h"

class Crafting : public Block {

    const int BREAK_TIME = 30;
    const BlockSign BLOCK_SIGN = T;

public:
    Crafting(int col, int row);
    Crafting();

    virtual int getBreakeTime() const;
    virtual BlockSign getBlockSign() const;
};

#endif