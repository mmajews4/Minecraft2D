#ifndef GRASS_H
#define GRASS_H

#include "../Block.h"

class Grass : public Block {

    const int BREAK_TIME = 7;
    const BlockSign BLOCK_SIGN = G;

public:
    Grass();

    virtual int getBreakeTime() const;
    virtual BlockSign getBlockSign() const;
};

#endif