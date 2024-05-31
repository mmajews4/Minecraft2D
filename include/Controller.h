#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "World.h"

class Controller 
{
    World world;

    float game_speed;

    // - checks if after move, player isn't out of board
    // - checks if after move, player isn't in the block
    // - returns 0 if there was no collision and 1 if it happened
    bool checkCollision() const;


public:
    Controller(World &);

    float getGameSpeed() const;
};

#endif
