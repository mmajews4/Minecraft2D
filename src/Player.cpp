#include "Player.h"

using namespace std;

Player::Player(double pc, double pr)
{
    Block block;
    height = 2*block.getSize();
    width = block.getSize();
    position_row = pr;
    position_col = pc;
    window_position_col = (800-block.getSize())/2;
    window_position_row = 600/2+block.getSize();
    move_rate = 0.1; // how many blocks player goes every update
    setTexture("assets/textures/Player.png");
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

void Player::move(Dir dir)
{
    if(dir == LEFT) position_col = position_col - move_rate;
    if(dir == RIGHT) position_col = position_col + move_rate;
    
}

// Display button on screen
void Player::draw(sf::RenderWindow &window)
{
    // Get font
    GameFont font;

    // Create block to display
    sf::RectangleShape player_view(sf::Vector2f(width, height));
    player_view.setTexture(&texture);
    player_view.setPosition(window_position_col, window_position_row);

    window.draw(player_view);
}