#ifndef SFMLVIEW_H
#define SFMLVIEW_H

#include <SFML/Graphics.hpp>
#include "World.h"
#include "Player.h"
#include "Zombie.h"
#include "Equipment.h"
#include "Controller.h"


class SFMLView {

    World &world;
    Player &player;
    Equipment &eq;
    Controller &ctrl;
    vector<Entity*> &entities;
    GameFont font;

    Dirt dirt;
    Grass grass;
    Stone stone;
    Wood wood;
    Leaves leaves;
    Chest chest;
    Crafting crafting;

    int window_width, window_height;    // In pixels
    int width, height;                  // In blocks
    int killed_flag;

    // Calculates block position on window relative to the player
    // sets the calculated position 
    template <typename T>
    void setBlockPosition(T &block, int col, int row);

    // Calculates entity position on window relative to the player
    // sets the calculated position 
    template <typename T>
    void setEntityPosition(T &entity, double col, double row);
    
    // Renders very part of a game
    void renderWorld(sf::RenderWindow &);
    void renderEntities(sf::RenderWindow &);
    void renderEq(sf::RenderWindow &);
    void renderDeathMessage(sf::RenderWindow &);

public:

    SFMLView(World &, Player &, Equipment &, Controller &, vector<Entity*> &en);

    // Simple getters
    int getWindowHeight() const;
    int getWindowWidth() const;
    

    void display(sf::RenderWindow &);

};


#endif