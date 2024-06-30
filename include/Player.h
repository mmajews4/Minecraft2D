#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {

    std::string texture = "assets/textures/Player.png";

    const double BLOCK_RANGE = 3.5;

    int health_bar_width; 
    int health_bar_height;
    int health_bar_offset;

    World &wrld;
    Equipment &eq;
    vector<Entity*> &entities;
    
    Dirt dirt;
    Grass grass;
    Wood wood;
    Leaves leaves;
    Stone stone;
    Chest chest;
    Crafting crafting;
    Block* block;

public:

    Player(double pc, double pr, World &w, Equipment &e, vector<Entity*> &en);

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


    // After mouse button click:
    // - checks if it is in range of any enemies
    // - if yes, take damage to entity
    void hitEntity(int col, int row);


    // Displays healtbar
    void displayHelath(sf::RenderWindow &window);
};

#endif