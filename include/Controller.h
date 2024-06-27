#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <cmath>
#include <vector>
#include "World.h"
#include "Player.h"
#include "Equipment.h"


class Controller 
{
//    const int BLOCK_SIZE = 100;
    const double GAME_SPEED = 0.025;

    World &world;
    Player &player;
    Equipment &eq;

    vector<Entity*> entities;

public:
    Controller(World &, Player &, Equipment &);

    float getGameSpeed() const;

    void spawnZombie();

    // Updates currnet state of the game:
    // - checks collisions
    // - calculates gravity
    // - moves player
    void update();
};

#endif
