#include "SFMLCtrl.h"

SFMLCtrl::SFMLCtrl(Controller &c, SFMLView &v, Player &p, Equipment &e) : ctrl(c), view(v), player(p), eq(e)
{
    displayInterval = sf::seconds(ctrl.getGameSpeed());
    timeSinceLastDisplay = sf::Time::Zero;
}


// Function handles keyboard actions
void SFMLCtrl::run(sf::RenderWindow &window)
{
    sf::Event event;
    sf::Clock clock;

    while(window.pollEvent(event))
    {

        // If asked, close window
        if(event.type == sf::Event::Closed) {
            window.close();
        }
        // One time key press
/*        else if (event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::W) {
                ctrl.jump();
            }
        }   
        
*/       // Handle mouse wheel scrolling
        if (event.type == sf::Event::MouseWheelScrolled)
        {
            if (event.mouseWheelScroll.delta > 0)
            {
                eq.scroll(LEFT);
            }
            else if (event.mouseWheelScroll.delta < 0)
            {
                eq.scroll(RIGHT);
            }
        }
    }

    // Measure the time elapsed since the last frame
    sf::Time dt = clock.restart();
    timeSinceLastDisplay += dt;

    // Check if it's time to update the display
    if (timeSinceLastDisplay >= displayInterval) 
    { 
        // Check for continuous key presses
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.move(LEFT);
        }
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.move(RIGHT);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player.jump();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            player.breakBlock(mouse_pos.x, mouse_pos.y);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            player.placeBlock(mouse_pos.x, mouse_pos.y);
        }

        ctrl.update();
        view.display(window);

        // Update game speed in case it changed
        displayInterval = sf::seconds(ctrl.getGameSpeed());

        // Reset the timer
        timeSinceLastDisplay = sf::Time::Zero;
    }

}