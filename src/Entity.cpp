#include "Entity.h"

Entity::Entity(double pc, double pr, World &w) : world(w)
{
    Dirt block;
    height = 2*block.getSize();
    width = block.getSize();
    position_row = pr;
    position_col = pc;
    window_position_col = (1000 - width)/2;
    window_position_row = (600 - height)/2;
    velocity = 0;
    resetHelath();
}

int Entity::getHeight() const
{
    return height;
}
int Entity::getWidth() const
{
    return width;
}
double Entity::getPositionRow() const
{
    return position_row;
}
double Entity::getPositionCol() const
{
    return position_col;
}
double Entity::getWinPosRow() const
{
    return window_position_row;
}
double Entity::getWinPosCol() const
{
    return window_position_col;
}

void Entity::setPosition(double col, double row)
{
    position_row = row;
    position_col = col;
}

void Entity::setWinPosition(double col, double row)
{
    window_position_row = row;
    window_position_col = col;
}

void Entity::setDimensions(int w, int h)
{
    width = w;
    height = h;
}

void Entity::resetHelath()
{
    health = MAX_HEALTH;
}

void Entity::takeDamage()
{
    health = health - damage;
}

void Entity::setDamage(double d)
{
    damage = d;
}


void Entity::setTexture(string file_name)
{
    if (!texture.loadFromFile(file_name)) {
        cerr << "Unable to load texture" << endl;
        return;
    }
}


// Moves the player according to gravity laws
void Entity::calculateGravity()
{
    if(checkJumpCollision() == 0)
    {
        if(velocity < MAX_VELOCITY) velocity = velocity + G_CONST;
        position_row = position_row + velocity;
    }
    else 
    {
        velocity = 0;
    }
}


// Makes player jump
void Entity::jump()
{
    // if there is block between any point under player's legs and he isn't already jumping
    if((world.getBlock(floor(position_col), ceil(position_row - 0.8)) != A
    ||  world.getBlock(floor(position_col + 1), ceil(position_row - 0.8)) != A
    ||  (int)position_row + 1 == world.getHeight()) // player must be able to get out if he fals at the edge of the world, 
    &&  velocity == 0)                                    // at least before there aren't implemented kill mechanics
        velocity = JUMP_STARTING_VELOCITY;
}


// Moves player a determianed amount in chosen direction every update 
void Entity::move(Dir dir)
{
    if(checkMoveCollision(dir) == 0)
    {
        if(dir == LEFT) position_col = position_col - MOVE_RATE;
        if(dir == RIGHT) position_col = position_col + MOVE_RATE;
    }
}


// - checks if after move, player isn't out of board
// - checks if after move, player isn't in the block
// - returns 0 if there was no collision and 1 if it happened
bool Entity::checkMoveCollision(Dir dir) const
{
    // checks if after move, player isn't out of board
    if((position_col - MOVE_RATE < 0 && dir == LEFT)
    || (position_col + MOVE_RATE + 1 >= world.getWidth() && dir == RIGHT)) return true;

    // checks if after move, player isn't in the block
    if((world.getBlock(floor(position_col - MOVE_RATE), floor(position_row - 0.01)) != A && dir == LEFT)
    || (world.getBlock(floor(position_col + MOVE_RATE + 1), floor(position_row - 0.01)) != A && dir == RIGHT)
    || (world.getBlock(floor(position_col - MOVE_RATE), floor(position_row - 1.01)) != A && dir == LEFT)
    || (world.getBlock(floor(position_col + MOVE_RATE + 1), floor(position_row - 1.01)) != A && dir == RIGHT)) return true;

    return false;
}


// - checks if after move, player isn't out of board
// - checks if after move, player isn't in the block
// - returns 0 if there was no collision and 1 if it happened
bool Entity::checkJumpCollision() const
{
    // checks if after move, player isn't out of board
    if((position_row + velocity - 2 <= 0 && signbit(velocity) == true)
    || (position_row + velocity + 0.01 >= world.getHeight() && signbit(velocity) == false)) return true;
    //                                        /\ so that he cant go under the map
    // checks if after move, player isn't in the block; \/ so that player can fit into 1x1 hole
    if((world.getBlock(floor(position_col + 0.04), floor(position_row + velocity - 2.01))  != A && signbit(velocity) == true)
    || (world.getBlock(floor(position_col + 0.04), floor(position_row + velocity + 0.01)) != A && signbit(velocity) == false)
    || (world.getBlock(floor(position_col + 0.96), floor(position_row + velocity - 2.01))  != A && signbit(velocity) == true)
    || (world.getBlock(floor(position_col + 0.96), floor(position_row + velocity + 0.01)) != A && signbit(velocity) == false)) return true;

    return false;
}


// Display button on screen
void Entity::draw(sf::RenderWindow &window)
{
    // Get font
    GameFont font;

    // Create block to display
    sf::RectangleShape entity_view(sf::Vector2f(width, height));
    entity_view.setTexture(&texture);
    entity_view.setPosition(window_position_col, window_position_row);

    window.draw(entity_view);
}