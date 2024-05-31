#ifndef SFMLVIEW_H
#define SFMLVIEW_H

#include <SFML/Graphics.hpp>
#include "World.h"


class SFMLView {

    World &world;

    int window_width, window_height;    // In pixels
    int width, height;                  // In blocks
    
    // Renders very part of a game
    void renderWorld(sf::RenderWindow &) const;
    void renderPlayer(sf::RenderWindow &) const;
    void renderEq(sf::RenderWindow &) const;
    void renderMenu(sf::RenderWindow &) const;

public:

    SFMLView(World &);

    // Simple getters
    int getWindowHeight() const;
    int getWindowWidth() const;
    

    void display(sf::RenderWindow &) const;

};


#endif