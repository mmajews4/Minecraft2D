#include "../../include/Blocks/Chest.h"

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