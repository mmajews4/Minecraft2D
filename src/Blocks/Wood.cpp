#include "../../include/Blocks/Wood.h"

Wood::Wood() : Block()
{
    setTexture("assets/textures/wood.jpg");
}


int Wood::getBreakeTime() const
{
    return BREAK_TIME;
}

BlockSign Wood::getBlockSign() const
{
    return BLOCK_SIGN;
}