#include "Player.h"

using namespace std;

Player::Player(double pc, double pr)
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