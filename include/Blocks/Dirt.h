#ifndef DIRT_H
#define DIRT_H

#include "../Block.h"

class Dirt : public Block {

    const int BREAK_TIME = 5;
    const BlockSign BLOCK_SIGN = D;

public:
    Dirt(int col, int row);
    Dirt();

    virtual int getBreakeTime() const;
    virtual BlockSign getBlockSign() const;
};

#endif