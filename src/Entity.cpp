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

void Entity::setDimensions(int w, int h)
{
    width = w;
    height = h;
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
    cout << "Jump" << endl;

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
    cout << "Move: " << dir << endl;

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
    cout << position_col + MOVE_RATE + 1 << " < " << world.getWidth() << endl;
    cout << " Pos: (" << position_col << "," << position_row << ")" << endl;
    // checks if after move, player isn't out of board
    if((position_col - MOVE_RATE < 0 && dir == LEFT)
    || (position_col + MOVE_RATE + 1 >= world.getWidth() && dir == RIGHT)) return true;

    cout << "Move collsion 1" << endl;

    // checks if after move, player isn't in the block
    if((world.getBlock(floor(position_col - MOVE_RATE), floor(position_row - 0.01)) != A && dir == LEFT)
    || (world.getBlock(floor(position_col + MOVE_RATE + 1), floor(position_row - 0.01)) != A && dir == RIGHT)
    || (world.getBlock(floor(position_col - MOVE_RATE), floor(position_row - 1.01)) != A && dir == LEFT)
    || (world.getBlock(floor(position_col + MOVE_RATE + 1), floor(position_row - 1.01)) != A && dir == RIGHT)) return true;
        

    cout << "Move collsion 2" << endl;
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

    cout << "Jump collsion" << endl;

    return false;
}
/*

// Break block:
// - calculates position of click on map
// - checks if block is in range
// - checks if block is visible to player
// - reads type of block
// - waits amount of updated determined by the type of block 
// - breaks the block
// - adds it to the inventory
void Entity::breakBlock(int mouse_col, int mouse_row)
{
    // I could declare every type of block adn write "Block* block = &dirt;" but that would be pointless so just delare class in the place of the block;
    static int updates_passed = 0;
    static int last_clicked_block_col = -1;
    static int last_clicked_block_row = -1;

    // - calculates position of click on map
    double block_col = (mouse_col - window_position_col)/block->getSize() + position_col;
    double block_row = (mouse_row - window_position_row - height)/block->getSize() + position_row;

    // distance realative to center of player
    double dist_to_player_col = position_col + 0.5 - block_col;
    double dist_to_player_row = position_row - 1 - block_row;
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
            return;
        case D:
            block = &dirt;
            break;
        case G:
            block = &grass;
            break;
        case W:
            block = &wood;
            break;
        case L:
            block = &leaves;
            break;
        case S:
            block = &stone;
            break;
        case C:
            block = &chest;
            break;
        case T:
            block = &crafting;
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
        eq.pushItem(block);
    }
    last_clicked_block_col = block_col;
    last_clicked_block_row = block_row;
}


// Place block:
// - calculates position of click on map
// - checks if block is in range
// - check if there is no block at that place
// - take one item from active slot in an inveentory and read what have you taken
// - add that block to that place
void Entity::placeBlock(int mouse_col, int mouse_row)
{
    // - calculates position of click on map
    double block_col = (mouse_col - window_position_col)/block->getSize() + position_col;
    double block_row = (mouse_row - window_position_row - height)/block->getSize() + position_row;

    // distance realative to center of player
    double dist_to_player_col = position_col + 0.5 - block_col;
    double dist_to_player_row = position_row - 1 - block_row;
    double dist_to_player = sqrt(dist_to_player_col*dist_to_player_col + dist_to_player_row*dist_to_player_row);

    // - checks if block is in range
    if(dist_to_player > BLOCK_RANGE) return;

    // form now we'll need intagers to check blocks on map
    block_col = floor(block_col);
    block_row = floor(block_row);
    // checks if block is not outsise of the world
    if(block_col < 0 || block_col >= world.getWidth() || block_row < 0 || block_row >= world.getHeight()) return;

    // check if there is nothing in the place of the block
    if(world.getBlock(block_col, block_row) != A) return; 

    // check if we don't want to place it inside player
    if((block_col == floor(position_col)
    && (block_row == floor(position_row) ||  block_row == floor(position_row-1) ||  block_row == floor(position_row-1.9)))
    || (block_col == floor(position_col+1)
    && (block_row == floor(position_row) ||  block_row == floor(position_row-1) ||  block_row == floor(position_row-1.9))))
        return;

    // - take one item from active slot in an inveentory and read what have you taken
    Block* pulled_block = eq.pullItem();

    // - add that block to that place
    if(pulled_block != nullptr) {
        world.setBlock((int)block_col, (int)block_row, pulled_block->getBlockSign());
    }
}

*/
// Display button on screen
void Entity::draw(sf::RenderWindow &window)
{
    // Get font
    GameFont font;

    sf::Vector2u window_size = window.getSize();
    window_position_col = (window_size.x - width )/2;
    window_position_row = (window_size.y - height)/2;

    // Create block to display
    sf::RectangleShape entity_view(sf::Vector2f(width, height));
    entity_view.setTexture(&texture);
    entity_view.setPosition(window_position_col, window_position_row);

    window.draw(entity_view);
}