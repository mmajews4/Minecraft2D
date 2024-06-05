#ifndef LEAVES_H
#define LEAVES_H

#include "../Block.h"

class Leaves : public Block {

    const int BREAK_TIME = 1;
    const BlockSign BLOCK_SIGN = L;

public:
    Leaves(int col, int row);
    Leaves();

    virtual int getBreakeTime() const;
    virtual BlockSign getBlockSign() const;
};

#endif