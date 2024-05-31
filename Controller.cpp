#include "Controller.h"

using namespace std;

Controller::Controller(World &w) : world(w)
{
    game_speed = 0.05;
}


float Controller::getGameSpeed() const
{
    return game_speed;
}


// - checks if after move, player isn't out of board
// - checks if after move, player isn't in the block
// - returns 0 if there was no collision and 1 if it happened
bool Controller::checkCollision() const
{

    return false;
}
