#include "Player.h"

using namespace std;

Player::Player(double pc, double pr, World &w, Equipment &e) : Entity(pc, pr, w), wrld(w), eq(e)
{
    setTexture(texture);
}


// Break block:
// - calculates position of click on map
// - checks if block is in range
// - checks if block is visible to player
// - reads type of block
// - waits amount of updated determined by the type of block 
// - breaks the block
// - adds it to the inventory
void Player::breakBlock(int mouse_col, int mouse_row)
{
    // I could declare every type of block adn write "Block* block = &dirt;" but that would be pointless so just delare class in the place of the block;
    static int updates_passed = 0;
    static int last_clicked_block_col = -1;
    static int last_clicked_block_row = -1;

    // - calculates position of click on map
    double block_col = (mouse_col - getWinPosCol())/block->getSize() + getPositionCol();
    double block_row = (mouse_row - getWinPosRow() - getHeight())/block->getSize() + getPositionRow();

    // distance realative to center of player
    double dist_to_player_col = getPositionCol() + 0.5 - block_col;
    double dist_to_player_row = getPositionRow() - 1 - block_row;
    double dist_to_player = sqrt(dist_to_player_col*dist_to_player_col + dist_to_player_row*dist_to_player_row);

    // - checks if block is in range
    if(dist_to_player > BLOCK_RANGE) return;

    // - checks if block is visible to player
    // form now we'll need intagers to check blocks on map
    block_col = floor(block_col);
    block_row = floor(block_row);
    // checks if block is not outsise of the world
    if(block_col < 0 || block_col >= wrld.getWidth() || block_row < 0 || block_row >= wrld.getHeight()) return;
    // checks in the world
    if(!(dist_to_player_col > 0 && wrld.getBlock(block_col + 1, block_row) == A)
    && !(dist_to_player_col < 0 && wrld.getBlock(block_col - 1, block_row) == A)
    && !(dist_to_player_row > 0 && wrld.getBlock(block_col, block_row + 1) == A)
    && !(dist_to_player_row < 0 && wrld.getBlock(block_col, block_row - 1) == A)) return;

    // - reads type of block
    switch(wrld.getBlock(block_col, block_row)){
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
        wrld.setBlock((int)block_col, (int)block_row, A);
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
void Player::placeBlock(int mouse_col, int mouse_row)
{
    // - calculates position of click on map
    double block_col = (mouse_col - getWinPosCol())/block->getSize() + getPositionCol();
    double block_row = (mouse_row - getWinPosRow() - getHeight())/block->getSize() + getPositionRow();

    // distance realative to center of player
    double dist_to_player_col = getPositionCol() + 0.5 - block_col;
    double dist_to_player_row = getPositionRow() - 1 - block_row;
    double dist_to_player = sqrt(dist_to_player_col*dist_to_player_col + dist_to_player_row*dist_to_player_row);

    // - checks if block is in range
    if(dist_to_player > BLOCK_RANGE) return;

    // form now we'll need intagers to check blocks on map
    block_col = floor(block_col);
    block_row = floor(block_row);
    // checks if block is not outsise of the world
    if(block_col < 0 || block_col >= wrld.getWidth() || block_row < 0 || block_row >= wrld.getHeight()) return;

    // check if there is nothing in the place of the block
    if(wrld.getBlock(block_col, block_row) != A) return; 

    // check if we don't want to place it inside player
    if((block_col == floor(getPositionCol())
    && (block_row == floor(getPositionRow()) ||  block_row == floor(getPositionRow()-1) ||  block_row == floor(getPositionRow()-1.9)))
    || (block_col == floor(getPositionCol()+1)
    && (block_row == floor(getPositionRow()) ||  block_row == floor(getPositionRow()-1) ||  block_row == floor(getPositionRow()-1.9))))
        return;

    // - take one item from active slot in an inveentory and read what have you taken
    Block* pulled_block = eq.pullItem();

    // - add that block to that place
    if(pulled_block != nullptr) {
        wrld.setBlock((int)block_col, (int)block_row, pulled_block->getBlockSign());
    }
}


/*
Player::Player(double pc, double pr, World &w, Equipment &e) : world(w), eq(e)
{
    Block* block = new Dirt();
    height = 2*block->getSize();
    width = block->getSize();
    position_row = pr;
    position_col = pc;
    window_position_col = (1000 - width)/2;
    window_position_row = (600 - height)/2;
    setTexture("assets/textures/Player.png");
}

int Player::getHeight() const
{
    return height;
}
int Player::getWidth() const
{
    return width;
}
double Player::getPositionRow() const
{
    return position_row;
}
double Player::getPositionCol() const
{
    return position_col;
}
double Player::getWinPosRow() const
{
    return window_position_row;
}
double Player::getWinPosCol() const
{
    return window_position_col;
}

void Player::setPosition(double col, double row)
{
    position_row = row;
    position_col = col;
}

void Player::setPlayerDimensions(int w, int h)
{
    width = w;
    height = h;
}


void Player::setTexture(string file_name)
{
    if (!texture.loadFromFile(file_name)) {
        cerr << "Unable to load texture" << endl;
        return;
    }
}





// Display button on screen
void Player::draw(sf::RenderWindow &window)
{
    // Get font
    GameFont font;

    sf::Vector2u window_size = window.getSize();
    window_position_col = (window_size.x - width )/2;
    window_position_row = (window_size.y - height)/2;

    // Create block to display
    sf::RectangleShape player_view(sf::Vector2f(width, height));
    player_view.setTexture(&texture);
    player_view.setPosition(window_position_col, window_position_row);

    window.draw(player_view);
}
*/