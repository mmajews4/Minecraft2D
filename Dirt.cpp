#include "Dirt.h"

Dirt::Dirt(int col, int row) : Block()
{
    setTexture("textures/dirt.jpg");
    setPosition(col, row);
}