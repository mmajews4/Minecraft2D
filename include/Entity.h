#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include "Equipment.h"


class Entity {

    int height;
    int width;
    double position_row;
    double position_col;
    int window_position_row;
    int window_position_col;
    double health;
    double damage;
    double move_rate;   // how many blocks entity goes every update

    sf::Texture texture;

    World &world;

//    const int BLOCK_SIZE = 100;
    const double G_CONST = 0.04;    // Gravitational constant in blocks/game_speed^2
    const double JUMP_STARTING_VELOCITY = -0.32;
    const double MAX_VELOCITY = 0.32;
    const double MAX_HEALTH = 20;

    double velocity; // with coordinates as the rest of the board

public:

    // initial position
    Entity(double pc, double pr, World &w);

    // Getters and setters
    int getHeight() const;
    int getWidth() const;
    double getPositionRow() const;
    double getPositionCol() const;
    double getWinPosRow() const;
    double getWinPosCol() const;
    void setPosition(double col, double row);
    void setWinPosition(double col, double row);
    void setDimensions(int w, int h);
    void setMoveRate(double);
    void resetHelath();
    void takeDamage(double);
    void setDamage(double);
    double getDamage() const;
    double getHealth() const;

    void setTexture(std::string);

    // - checks if after move, entity isn't out of board
    // - checks if after move, entity isn't in the block
    // - returns 0 if there was no collision and 1 if it happened
    bool checkMoveCollision(Dir dir) const;
    bool checkJumpCollision() const;

    // Moves the Entity according to gravity laws
    void calculateGravity();

    // Makes entity jump
    void jump();

    // Moves entity a determianed amount in chosen direction every update 
    void move(Dir);

    // Display on screen
    void draw(sf::RenderWindow &);
};

#endif