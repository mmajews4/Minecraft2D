#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <cmath>
#include "World.h"
#include "Player.h"
#include "Equipment.h"


class Controller 
{
    const int BLOCK_SIZE = 100;
    const double BLOCK_RANGE = 3.5;
    const double GAME_SPEED = 0.025;
    const double G_CONST = 0.04;    // Gravitational constant in blocks/game_speed^2
    const double JUMP_STARTING_VELOCITY = -0.32;
    const double MAX_VELOCITY = 0.32;
    const double MOVE_RATE = 0.1;   // how many blocks player goes every update

    double velocity; // with coordinates as the rest of the board

    World &world;
    Player &player;
    Equipment &eq;

    Dirt dirt;
    Grass grass;
    Wood wood;
    Leaves leaves;
    Stone stone;
    Chest chest;
    Crafting crafting;
    Block* block;

    // - checks if after move, player isn't out of board
    // - checks if after move, player isn't in the block
    // - returns 0 if there was no collision and 1 if it happened
    bool checkMoveCollision(Dir dir) const;
    bool checkJumpCollision() const;

    // Moves the player according to gravity laws
    void calculateGravity();

public:
    Controller(World &, Player &, Equipment &);

    float getGameSpeed() const;

    // Makes player jump
    void jump();

    // Moves player a determianed amount in chosen direction every update 
    void movePlayer(Dir);

    // Break block:
    // - checks if block is in range
    // - reads type of block
    // - waits amount of updated determined by the type of block 
    // - breaks the block
    // - adds it to the inventory
    void breakBlock(int mouse_col, int mouse_row);

    
    // Place block:
    // - calculates position of click on map
    // - checks if block is in range
    // - check if there is no block at that place
    // - take one item from active slot in an inveentory and read what have you taken
    // - add that block to that place
    void placeBlock(int mouse_col, int mouse_row);


    // Updates currnet state of the game:
    // - checks collisions
    // - calculates gravity
    // - moves player
    void update();
};

#endif
