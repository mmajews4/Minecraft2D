#include "Block.h"

using namespace std;

Block::Block()
{
    size = 100;
}


// checks if click cooridinates are on button
bool Block::inRange(int col, int row) const
{
    if(col >= left_offset && col < left_offset + size
    && row >= top_offset  && row < top_offset + size) return true;

    return false;
}


int Block::getSize() const
{
    return size;
}


void Block::setTexture(string file_name)
{
    if (!texture.loadFromFile(file_name)) {
        cerr << "Unable to load texture" << endl;
        return;
    }
}

void Block::setPosition(int col, int row)
{
    left_offset = col;
    top_offset = row;
}


// Draws block half the size of original
void Block::drawInEq(sf::RenderWindow &window)
{
//    left_offset = left_offset + size/2;
//    top_offset = top_offset + size/2;

    // Create block to display
    sf::RectangleShape block_view(sf::Vector2f(size/2, size/2));
    block_view.setTexture(&texture);
    block_view.setPosition(left_offset + size/5, top_offset + size/5);
    window.draw(block_view);
}

// Display button on screen
void Block::draw(sf::RenderWindow &window)
{
    // Get font
//    GameFont font;

    // Create block to display
    sf::RectangleShape block_view(sf::Vector2f(size, size));
    block_view.setTexture(&texture);
    block_view.setPosition(left_offset, top_offset);
/*
    // Create a text to display number of items in inventory
    sf::Text text_view;
    text_view.setFont(font.font);
    text_view.setStyle(sf::Text::Bold);
    text_view.setFillColor(sf::Color(255, 255, 255));
    text_view.setCharacterSize(text_size);
    text_view.setString(text);
    text_view.setPosition(left_offset + text_offset, top_offset + text_offset);


    if(state == EQ) window.draw(text_view);
*/    window.draw(block_view);
}