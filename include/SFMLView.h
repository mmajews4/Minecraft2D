#ifndef SFMLVIEW_H
#define SFMLVIEW_H

#include <SFML/Graphics.hpp>
#include "World.h"
#include "Player.h"
#include "Equipment.h"


class SFMLView {

    World &world;
    Player &player;
    Equipment &eq;

    int window_width, window_height;    // In pixels
    int width, height;                  // In blocks

    // Calculates block position on window relative to the player
    // sets the calculated position 
    template <typename T>
    void setBlockPosition(T &block, int col, int row);
    
    // Renders very part of a game
    void renderWorld(sf::RenderWindow &);
    void renderPlayer(sf::RenderWindow &) const;
    void renderEq(sf::RenderWindow &) const;
    void renderMenu(sf::RenderWindow &) const;

public:

    SFMLView(World &, Player &, Equipment &);

    // Simple getters
    int getWindowHeight() const;
    int getWindowWidth() const;
    

    void display(sf::RenderWindow &);

};


#endif