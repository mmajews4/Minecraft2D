#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameFont.h"
#include "Dirt.h"
#include "Button.h"

using namespace std;

struct Slot {
    Button button;
    Block* block;
    int num_of_items;
    bool active;
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

    Dirt dirt;

public:

    Equipment();

    // Adds given item to eq
    void pushItem(Block*);

    // Pulls given item from eq
    // - return 1 if item is in eq
    // - return 0 if requested item is not in eq
    bool pullItem(Block*);

    // Display on screen
    void display(sf::RenderWindow &);
};

#endif