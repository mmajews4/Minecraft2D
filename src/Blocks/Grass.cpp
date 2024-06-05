#include "../../include/Blocks/Grass.h"

Grass::Grass(int col, int row) : Block()
{
    setTexture("assets/textures/grass.jpg");
    setPosition(col, row);
}

Grass::Grass() : Block()
{
    setTexture("assets/textures/grass.jpg");
}


int Grass::getBreakeTime() const
{
    return BREAK_TIME;
}

BlockSign Grass::getBlockSign() const
{
    return BLOCK_SIGN;
}