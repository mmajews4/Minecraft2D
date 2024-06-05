#include "Controller.h"

using namespace std;

Controller::Controller(World &w, Player &p) : world(w), player(p)
{
    velocity = 0;
}


float Controller::getGameSpeed() const
{
    return GAME_SPEED;
}


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
    Block* block = new Dirt();
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
    Block* block = new Dirt();
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
}


// Break block:
// - calculates position of click on map
// - checks if block is in range
// - checks if block is visible to player
// - reads type of block
// - waits amount of updated determined by the type of block 
// - breaks the block
// - adds it to the inventory
void Controller::breakBlock(int mouse_col, int mouse_row)
{
    // I could declare every type of block adn write "Block* block = &dirt;" but that would be pointless so just delare class in the place of the block;
    Block* block = new Dirt();
    static int updates_passed = 0;
    static int last_clicked_block_col = -1;
    static int last_clicked_block_row = -1;

    // - calculates position of click on map
    double block_col = (mouse_col - player.getWinPosCol())/block->getSize() + player.getPositionCol();
    double block_row = (mouse_row - player.getWinPosRow() - player.getHeight())/block->getSize() + player.getPositionRow();

    // distance realative to center of player
    double dist_to_player_col = player.getPositionCol() + 0.5 - block_col;
    double dist_to_player_row = player.getPositionRow() - 1 - block_row;
    double dist_to_player = sqrt(dist_to_player_col*dist_to_player_col + dist_to_player_row*dist_to_player_row);

    // - checks if block is in range
    if(dist_to_player > BLOCK_RANGE) return;

    // - checks if block is visible to player
    // form now we'll need intagers to check blocks on map
    block_col = floor(block_col);
    block_row = floor(block_row);
    // checks if block is not outsise of the world
    if(block_col < 0 || block_col >= world.getWidth() || block_row < 0 || block_row >= world.getHeight()) return;
    // checks in the world
    if(!(dist_to_player_col > 0 && world.getBlock(block_col + 1, block_row) == A)
    && !(dist_to_player_col < 0 && world.getBlock(block_col - 1, block_row) == A)
    && !(dist_to_player_row > 0 && world.getBlock(block_col, block_row + 1) == A)
    && !(dist_to_player_row < 0 && world.getBlock(block_col, block_row - 1) == A)) return;

    // - reads type of block
    switch(world.getBlock(block_col, block_row)){
        case A:
            break;
        case D:
            block = new Dirt();
            break;
        case G:
            block = new Grass();
            break;
        case W:
            block = new Wood();
            break;
        case L:
            block = new Leaves();
            break;
        case S:
            block = new Stone();
            break;
        case C:
            block = new Chest();
            break;
        case T:
            block = new Crafting();
            break;
    }

    // - waits amount of updated determined by the type of block 
    if(last_clicked_block_col != block_col || last_clicked_block_row != block_row) 
        updates_passed = 0;
    else 
        updates_passed++;

    if(updates_passed >= block->getBreakeTime())
    {
        // - breaks the block        
        world.setBlock((int)block_col, (int)block_row, A);
    }
    last_clicked_block_col = block_col;
    last_clicked_block_row = block_row;
}


// Updates currnet state of the game:
// - checks collisions
// - calculates gravity
// - moves player
void Controller::update()
{
    calculateGravity();
}
