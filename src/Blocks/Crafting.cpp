#include "../../include/Blocks/Crafting.h"

Crafting::Crafting() : Block()
{
    setTexture("assets/textures/crafting.jpg");
}


int Crafting::getBreakeTime() const
{
    return BREAK_TIME;
}

BlockSign Crafting::getBlockSign() const
{
    return BLOCK_SIGN;
}