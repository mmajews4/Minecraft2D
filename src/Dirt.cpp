#include "Dirt.h"

Dirt::Dirt(int col, int row) : Block()
{
    setTexture("assets/textures/dirt.jpg");
    setPosition(col, row);
}

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