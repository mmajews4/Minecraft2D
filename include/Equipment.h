#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameFont.h"
#include "World.h"
#include "Button.h"

using namespace std;

enum Dir { LEFT, RIGHT };

struct Slot {
    Button button;
    Block* block;
    int num_of_items;
};

class Equipment {

    int num_of_slots;
    int size;
    int outline;
    int left_offset;
    int top_offset;
    int text_offset;
    int text_size;
    string text;
    GameFont font;

    vector<Slot> slots;
    int active_slot;

    Dirt dirt;
    Grass grass;
    Wood wood;
    Leaves leaves;
    Stone stone;
    Chest chest;
    Crafting crafting;

public:

    Equipment();

    // Adds given item to eq
    void pushItem(Block*);

    // Pulls given item from eq
    // - returns block form active slot
    // - decrements form numeber of blocks and if number of blocks, deletes block from that slot
    Block* pullItem();

    // Changes active slot in given direction
    void scroll(Dir);

    // Display on screen
    void display(sf::RenderWindow &);
};

#endif