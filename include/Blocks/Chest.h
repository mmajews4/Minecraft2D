#ifndef CHEST_H
#define CHEST_H

#include "../Block.h"

class Chest : public Block {

    const int BREAK_TIME = 30;
    const BlockSign BLOCK_SIGN = C;

public:
    Chest(int col, int row);
    Chest();

    virtual int getBreakeTime() const;
    virtual BlockSign getBlockSign() const;
};

#endif