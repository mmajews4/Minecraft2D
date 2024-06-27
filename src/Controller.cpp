#include "Controller.h"

using namespace std;

Controller::Controller(World &w, Player &p, Equipment &e) : world(w), player(p), eq(e)
{
//    velocity = 0;
//    block = &dirt; // Any block just to take its size
}


float Controller::getGameSpeed() const
{
    return GAME_SPEED;
}

/*
// Moves the player according to gravity laws
void Controller::calculateGravity()
{
    double position_row;

    if(checkJumpCollision() == 0)
    {
        if(velocity < MAX_VELOCITY) velocity = velocity + G_CONST;
        position_row = player.getPositionRow() + velocity;

        player.setPosition(player.getPositionCol(), position_row);
    }
    else 
    {
        velocity = 0;
    }
}


// Makes player jump
void Controller::jump()
{
    // if there is block between any point under player's legs and he isn't already jumping
    if((world.getBlock(floor(player.getPositionCol()), ceil(player.getPositionRow() - 0.8)) != A
    ||  world.getBlock(floor(player.getPositionCol() + 1), ceil(player.getPositionRow() - 0.8)) != A
    ||  (int)player.getPositionRow() + 1 == world.getHeight()) // player must be able to get out if he fals at the edge of the world, 
    &&  velocity == 0)                                    // at least before there aren't implemented kill mechanics
        velocity = JUMP_STARTING_VELOCITY;
}


// Moves player a determianed amount in chosen direction every update 
void Controller::movePlayer(Dir dir)
{
    double position_col;

    if(checkMoveCollision(dir) == 0)
    {
        if(dir == LEFT) position_col = player.getPositionCol() - MOVE_RATE;
        if(dir == RIGHT) position_col = player.getPositionCol() + MOVE_RATE;

        player.setPosition(position_col, player.getPositionRow());
    }
}


// - checks if after move, player isn't out of board
// - checks if after move, player isn't in the block
// - returns 0 if there was no collision and 1 if it happened
bool Controller::checkMoveCollision(Dir dir) const
{
    // We are moving in blocks so player height ald width looks like this:
    int player_width = player.getWidth()/block->getSize();

    // checks if after move, player isn't out of board
    if((player.getPositionCol() - MOVE_RATE < 0 && dir == LEFT)
    || (player.getPositionCol() + MOVE_RATE + player_width >= world.getWidth() && dir == RIGHT)) return true;

    // checks if after move, player isn't in the block
    if((world.getBlock(floor(player.getPositionCol() - MOVE_RATE), floor(player.getPositionRow() - 0.01)) != A && dir == LEFT)
    || (world.getBlock(floor(player.getPositionCol() + MOVE_RATE + player_width), floor(player.getPositionRow() - 0.01)) != A && dir == RIGHT)
    || (world.getBlock(floor(player.getPositionCol() - MOVE_RATE), floor(player.getPositionRow() - 1.01)) != A && dir == LEFT)
    || (world.getBlock(floor(player.getPositionCol() + MOVE_RATE + player_width), floor(player.getPositionRow() - 1.01)) != A && dir == RIGHT)) 
    return true;

    return false;
}


// - checks if after move, player isn't out of board
// - checks if after move, player isn't in the block
// - returns 0 if there was no collision and 1 if it happened
bool Controller::checkJumpCollision() const
{
    // We are moving in blocks so player height ald width looks like this:
    int player_height = player.getHeight()/block->getSize();

    // checks if after move, player isn't out of board
    if((player.getPositionRow() + velocity - player_height <= 0 && signbit(velocity) == true)
    || (player.getPositionRow() + velocity + 0.01 >= world.getHeight() && signbit(velocity) == false)) return true;
    //                                        /\ so that he cant go under the map
    // checks if after move, player isn't in the block; \/ so that player can fit into 1x1 hole
    if((world.getBlock(floor(player.getPositionCol() + 0.04), floor(player.getPositionRow() + velocity - player_height - 0.01))  != A && signbit(velocity) == true)
    || (world.getBlock(floor(player.getPositionCol() + 0.04), floor(player.getPositionRow() + velocity + 0.01)) != A && signbit(velocity) == false)
    || (world.getBlock(floor(player.getPositionCol() + 0.96), floor(player.getPositionRow() + velocity - player_height - 0.01))  != A && signbit(velocity) == true)
    || (world.getBlock(floor(player.getPositionCol() + 0.96), floor(player.getPositionRow() + velocity + 0.01)) != A && signbit(velocity) == false)) return true;

    return false;
}*/





// Updates currnet state of the game:
// - checks collisions
// - calculates gravity
// - moves player
void Controller::update()
{
    player.calculateGravity();
}
