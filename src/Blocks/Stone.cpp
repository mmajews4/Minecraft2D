#include "../../include/Blocks/Stone.h"

Stone::Stone(int col, int row) : Block()
{
    setTexture("assets/textures/stone.jpg");
    setPosition(col, row);
}

Stone::Stone() : Block()
{
    setTexture("assets/textures/stone.jpg");
}


int Stone::getBreakeTime() const
{
    return BREAK_TIME;
}

BlockSign Stone::getBlockSign() const
{
    return BLOCK_SIGN;
}