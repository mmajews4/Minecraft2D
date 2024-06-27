#include "../../include/Blocks/Stone.h"

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