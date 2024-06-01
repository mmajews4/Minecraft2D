#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <cmath>
#include "World.h"
#include "Player.h"

enum Dir { LEFT, RIGHT };

class Controller 
{
    const int BLOCK_SIZE = 100;
    const double GAME_SPEED = 0.015;
    const double G_CONST = 0.05;    // Gravitational constant in blocks/game_speed^2
    const double JUMP_STARTING_VELOCITY = -0.3;
    const double MOVE_RATE = 0.1;   // how many blocks player goes every update

    World &world;
    Player &player;

    double velocity; // with coordinates as the rest of the board

    // - checks if after move, player isn't out of board
    // - checks if after move, player isn't in the block
    // - returns 0 if there was no collision and 1 if it happened
    bool checkCollision(Dir dir) const;

    // Moves the player according to gravity laws
    void calculateGravity();

public:
    Controller(World &, Player &);

    float getGameSpeed() const;

    // Makes player jump
    void jump();

    // moves player
    void movePlayer(Dir);

    // Updates currnet state of the game:
    // - checks collisions
    // - calculates gravity
    // - moves player
    void update();
};

#endif
