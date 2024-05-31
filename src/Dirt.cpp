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