#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Block.h"


enum Dir { LEFT, RIGHT };

class Player {

    int height;
    int width;
    double position_row;
    double position_col;
    int window_position_row;
    int window_position_col;
    double move_rate;

    sf::Texture texture;

public:

    // initial position
    Player(double pc, double pr);

//    int getHeight() const;
//    int getWidth() const;
    double getPositionRow() const;
    double getPositionCol() const;
    double getWinPosRow() const;
    double getWinPosCol() const;
    void setPlayerDimensions(int w, int h);

    void setTexture(std::string);
    void move(Dir);

    // Display on screen
    void draw(sf::RenderWindow &);
};

#endif