#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {

    std::string texture = "assets/textures/Player.png";

    //    const int BLOCK_SIZE = 100;
    const double BLOCK_RANGE = 3.5;

    double velocity; // with coordinates as the rest of the board

    World &wrld;
    Equipment &eq;
    
    Dirt dirt;
    Grass grass;
    Wood wood;
    Leaves leaves;
    Stone stone;
    Chest chest;
    Crafting crafting;
    Block* block;

public:

    Player(double pc, double pr, World &w, Equipment &e);

    // Break block:
    // - checks if block is in range
    // - reads type of block
    // - waits amount of updated determined by the type of block 
    // - breaks the block
    // - adds it to the inventory
    void breakBlock(int mouse_col, int mouse_row);

    
    // Place block:
    // - calculates position of click on map
    // - checks if block is in range
    // - check if there is no block at that place
    // - take one item from active slot in an inveentory and read what have you taken
    // - add that block to that place
    void placeBlock(int mouse_col, int mouse_row);
/*
    int height;
    int width;
    double position_row;
    double position_col;
    int window_position_row;
    int window_position_col;
    double move_rate;s

    sf::Texture texture;

    World &world;
    Equipment &eq;

public:

    // initial position
    Player(double pc, double pr, World &w, Equipment &e);

    int getHeight() const;
    int getWidth() const;
    double getPositionRow() const;
    double getPositionCol() const;
    double getWinPosRow() const;
    double getWinPosCol() const;
    void setPosition(double col, double row);
    void setPlayerDimensions(int w, int h);

    void setTexture(std::string);

    // Display on screen
    void draw(sf::RenderWindow &);

    */
};

#endif