#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <SFML/Graphics.hpp>
#include "GameFont.h"

enum BlockState { PLACED, EQ };

class Block {

    int size;
    int left_offset;
    int top_offset;
    int text_offset;
    int text_size;
    std::string text;

    sf::Texture texture;
    BlockState state;

    public:

    Block();

    // checks if click cooridinates are on button
    bool inRange(int col, int row) const;

    int getSize() const;
    void setSize(int s);

    void setTexture(std::string);
    void setPosition(int col, int row);

    // Display on screen
    void draw(sf::RenderWindow &);
};

#endif