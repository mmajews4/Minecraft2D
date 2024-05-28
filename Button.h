#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <SFML/Graphics.hpp>
#include "GameFont.h"

class Button {

    int width;
    int height;
    int outline;
    int left_offset;
    int top_offset;
    int text_left_offset;
    int text_top_offset;
    int text_size;
    std::string text;
    bool active;

    public:

    Button(int width_,
            int height_,
            int outline_,
            int left_offset_,
            int top_offset_,
            int text_left_offset_,
            int text_top_offset_, 
            int text_size_,
            std::string text_,
            bool active_);

    // checks if click cooridinates are on button
    bool inRange(int col, int row) const;

    // Display on screen
    void display(sf::RenderWindow &);
};

#endif