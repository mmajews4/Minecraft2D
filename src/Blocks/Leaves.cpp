#include "../../include/Blocks/Leaves.h"

Leaves::Leaves(int col, int row) : Block()
{
    setTexture("assets/textures/leaves.jpg");
    setPosition(col, row);
}

Leaves::Leaves() : Block()
{
    setTexture("assets/textures/leaves.jpg");
}


int Leaves::getBreakeTime() const
{
    return BREAK_TIME;
}

BlockSign Leaves::getBlockSign() const
{
    return BLOCK_SIGN;
}