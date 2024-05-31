#include "SFMLView.h"

#include <iostream>

SFMLView::SFMLView(World &w, Player &p) : world(w), player(p)
{
    window_width = 600, window_height = 600;
    height = world.getHeight();
    width = world.getWidth();
}


int SFMLView::getWindowHeight() const
{
    return window_height;
}

int SFMLView::getWindowWidth() const
{
    return window_width;
}


void SFMLView::renderWorld(sf::RenderWindow &window) const
{
    Dirt dirt;

    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){

            switch(world.getBlock(col, row)){
                case A:
                    break;
                case D:
                    dirt.setPosition(col*dirt.getSize(), row*dirt.getSize());
                    dirt.draw(window);
                    break;
                case G:

                    break;
                case W:

                    break;
                case L:

                    break;
                case S:

                    break;
                case C:

                    break;
                case T:

                    break;
            }
        }
    }
}


void SFMLView::renderPlayer(sf::RenderWindow &window) const
{
    player.draw(window);
}


void SFMLView::renderEq(sf::RenderWindow &window) const
{

}


void SFMLView::renderMenu(sf::RenderWindow &window) const
{

}


void SFMLView::display(sf::RenderWindow &window) const 
{
    // clear the window with black color
    window.clear(sf::Color(200, 200, 255));

    // Render all objects on screen
    renderWorld(window);
    renderPlayer(window);
    renderEq(window);
    renderMenu(window);
    
    // Display the content
    window.display();
}