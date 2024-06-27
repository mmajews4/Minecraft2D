#ifndef CHEST_H
#define CHEST_H

#include "../Block.h"

class Chest : public Block {

    const int BREAK_TIME = 15;
    const BlockSign BLOCK_SIGN = C;

public:
    Chest();

    virtual int getBreakeTime() const;
    virtual BlockSign getBlockSign() const;
};

#endif