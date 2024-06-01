#include "SFMLView.h"

#include <iostream>

SFMLView::SFMLView(World &w, Player &p) : world(w), player(p)
{
    window_width = 1000, window_height = 600;
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


// Calculates block position on window relative to the player
// sets the calculated position 
template <typename T>
void SFMLView::setBlockPosition(T &block, int col, int row)
{
    int pos_col = (col - player.getPositionCol())* block.getSize() + player.getWinPosCol();
    // need to offset that because I want player coordinates to be his legs not head
    int pos_row = (row - player.getPositionRow())* block.getSize() + player.getWinPosRow() + player.getHeight();
    block.setPosition(pos_col, pos_row);
}


void SFMLView::renderWorld(sf::RenderWindow &window)
{
    Dirt dirt;

    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){

            switch(world.getBlock(col, row)){
                case A:
                    break;
                case D:
                    setBlockPosition(dirt, col, row);
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


void SFMLView::display(sf::RenderWindow &window)
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