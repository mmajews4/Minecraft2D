#ifndef WOOD_H
#define WOOD_H

#include "../Block.h"

class Wood : public Block {

    const int BREAK_TIME = 12;
    const BlockSign BLOCK_SIGN = W;

public:
    Wood(int col, int row);
    Wood();

    virtual int getBreakeTime() const;
    virtual BlockSign getBlockSign() const;
};

#endif