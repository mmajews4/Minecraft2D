#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <SFML/Graphics.hpp>
#include "GameFont.h"

// For more readeable map
// A-air D-dirt G-grass W-wood L-leaves S-stone C-chest T-craftingTable 
enum BlockSign { A, D, G, W, L, S, C, T };
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

    virtual int getBreakeTime() const = 0;
    virtual BlockSign getBlockSign() const = 0;

    void setTexture(std::string);
    void setPosition(int col, int row);

    // Display on screen
    void draw(sf::RenderWindow &);
};

#endif