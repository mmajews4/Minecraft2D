#include "Player.h"

using namespace std;

Player::Player(double pc, double pr, World &w, Equipment &e, vector<Entity*> &en) : Entity(pc, pr, w), wrld(w), eq(e), entities(en)
{
    setTexture(texture);
    setDamage(5);
    setMoveRate(0.1);
    health_bar_width = getHealth() * 4.5;
    health_bar_height = 15;
    health_bar_offset = 5;
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
    double block_col = (mouse_col - getWinPosCol())/dirt.getSize() + getPositionCol();
    double block_row = (mouse_row - getWinPosRow() - getHeight())/dirt.getSize() + getPositionRow();

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
    double block_col = (mouse_col - getWinPosCol())/dirt.getSize() + getPositionCol();
    double block_row = (mouse_row - getWinPosRow() - getHeight())/dirt.getSize() + getPositionRow();

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


// - calculate position of clisk on map
// - check if entity was hit
// - if entity has no health, kill him
void Player::hitEntity(int mouse_col, int mouse_row)
{
    // - calculates position of click on map
    double hit_col = (mouse_col - getWinPosCol())/dirt.getSize() + getPositionCol();
    double hit_row = (mouse_row - getWinPosRow() - getHeight())/dirt.getSize() + getPositionRow();

    // distance realative to center of player
    double dist_to_player_col = getPositionCol() + 0.5 - hit_col;
    double dist_to_player_row = getPositionRow() - 1 - hit_row;
    double dist_to_player = sqrt(dist_to_player_col*dist_to_player_col + dist_to_player_row*dist_to_player_row);

    // - checks if entity is in range
    if(dist_to_player > BLOCK_RANGE/2) return;

    // check for every entity
    for(int iter = 0; iter < (int)entities.size(); iter++)
    {
        // - check if entity was hit
        if(entities[iter]->getPositionCol() <= hit_col && entities[iter]->getPositionCol() + 1 >= hit_col
        && entities[iter]->getPositionRow() >= hit_row && entities[iter]->getPositionRow() - 2 <= hit_row)
        {
            entities[iter]->takeDamage(getDamage());
            entities[iter]->jump();
        }

        // - if entity has no health, kill him
        if(entities[iter]->getHealth() <= 0)
        {
            delete entities[iter];
            entities.erase(entities.begin() + iter);
        }
    }
}


// Displays healtbar
void Player::displayHelath(sf::RenderWindow &window)
{
    // Create health bar outline
    sf::RectangleShape health_bar_outline(sf::Vector2f(health_bar_width + 2 * health_bar_offset, health_bar_height + 2 * health_bar_offset));
    health_bar_outline.setFillColor(sf::Color(100, 100, 100));
    health_bar_outline.setPosition(eq.getWinPositionCol() - health_bar_offset, eq.getWinPositionRow() - 4 * health_bar_offset - health_bar_height);
    window.draw(health_bar_outline);

    // Create health bar
    if(getHealth() <= 0) return;
    sf::RectangleShape health_bar(sf::Vector2f(getHealth() * 4.5, health_bar_height));
    health_bar.setFillColor(sf::Color::Red);
    health_bar.setPosition(eq.getWinPositionCol(), eq.getWinPositionRow() - 3 * health_bar_offset - health_bar_height);
    window.draw(health_bar);
}