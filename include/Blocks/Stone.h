#ifndef STONE_H
#define STONE_H

#include "../Block.h"

class Stone : public Block {

    const int BREAK_TIME = 20;
    const BlockSign BLOCK_SIGN = S;

public:
    Stone();

    virtual int getBreakeTime() const;
    virtual BlockSign getBlockSign() const;
};

#endif