#include "../../include/Blocks/Chest.h"

Chest::Chest(int col, int row) : Block()
{
    setTexture("assets/textures/chest.jpg");
    setPosition(col, row);
}

Chest::Chest() : Block()
{
    setTexture("assets/textures/chest.jpg");
}


int Chest::getBreakeTime() const
{
    return BREAK_TIME;
}

BlockSign Chest::getBlockSign() const
{
    return BLOCK_SIGN;
}