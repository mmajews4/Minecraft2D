#include "SFMLView.h"

#include <iostream>

SFMLView::SFMLView(World &w, Player &p, Equipment &e, Controller &c, vector<Entity*> &en) : world(w), player(p), eq(e), ctrl(c), entities(en)
{
    window_width = 1000, window_height = 600;
    height = world.getHeight();
    width = world.getWidth();
    killed_flag = 0;
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
    int pos_col = (col - player.getPositionCol())* block->getSize() + player.getWinPosCol();
    // need to offset that because I want player coordinates to be his legs not head
    int pos_row = (row - player.getPositionRow())* block->getSize() + player.getWinPosRow() + player.getHeight();
    block->setPosition(pos_col, pos_row);
}


// Calculates entity position on window relative to the player
// sets the calculated position 
template <typename T>
void SFMLView::setEntityPosition(T &entity, double col, double row)
{
    Dirt block;
    double pos_col = (col - player.getPositionCol())* block.getSize() + player.getWinPosCol();
    // need to offset that because I want player coordinates to be his legs not head
    double pos_row = (row - player.getPositionRow())* block.getSize() + player.getWinPosRow();
    entity->setWinPosition(pos_col, pos_row);
}


void SFMLView::renderWorld(sf::RenderWindow &window)
{
    Block* block = nullptr;


    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){

            switch(world.getBlock(col, row)){
                case A:
                    continue;
                case D:
                    block = &dirt;
                    break;
                case G:
                    block = &grass;
                    break;
                case W:
                    block = &wood;
                    break;
                case L:
                    block = &leaves;
                    break;
                case S:
                    block = &stone;
                    break;
                case C:
                    block = &chest;
                    break;
                case T:
                    block = &crafting;
                    break;
            }
            setBlockPosition(block, col, row);
            block->draw(window);
        }
    }
}


void SFMLView::renderEntities(sf::RenderWindow &window)
{
    player.draw(window);

    for(const auto& entity: entities)
    {
        setEntityPosition(entity, entity->getPositionCol(), entity->getPositionRow());
        entity->draw(window);
    }

    player.displayHelath(window);
}


void SFMLView::renderEq(sf::RenderWindow &window)
{
    eq.display(window);
}


void SFMLView::renderDeathMessage(sf::RenderWindow &window)
{
    if(ctrl.getGameState() == PLAYER_KILLED) 
    {
        killed_flag = 200;
        ctrl.setGameState(RUNNING);
    }
    if(killed_flag > 0) 
    {
        // Display Death message
        sf::Text text_view;
        text_view.setPosition(300, 225);
        text_view.setFont(font.font);
        text_view.setStyle(sf::Text::Bold);
        text_view.setFillColor(sf::Color::White);
        text_view.setOutlineThickness(8);
        text_view.setOutlineColor(sf::Color::Red);
        text_view.setCharacterSize(80);
        text_view.setString("You Died!");
        window.draw(text_view);

        killed_flag--;
    }
}


void SFMLView::display(sf::RenderWindow &window)
{
    // clear the window with black color
    window.clear(sf::Color(200, 200, 255));

    // Render all objects on screen
    renderWorld(window);
    renderEntities(window);
    renderEq(window);
    renderDeathMessage(window);
    
    // Display the content
    window.display();
}