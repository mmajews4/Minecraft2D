#include "../../include/Blocks/Dirt.h"

Dirt::Dirt() : Block()
{
    setTexture("assets/textures/dirt.jpg");
}


int Dirt::getBreakeTime() const
{
    return BREAK_TIME;
}

BlockSign Dirt::getBlockSign() const
{
    return BLOCK_SIGN;
}