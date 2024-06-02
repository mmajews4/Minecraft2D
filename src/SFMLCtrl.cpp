#include "SFMLCtrl.h"

SFMLCtrl::SFMLCtrl(Controller &c, SFMLView &v) : ctrl(c), view(v)
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
        else if (event.type == sf::Event::KeyPressed) {

        }   
    }

    // Measure the time elapsed since the last frame
    sf::Time dt = clock.restart();
    timeSinceLastDisplay += dt;

    // Check if it's time to update the display
    if (timeSinceLastDisplay >= displayInterval) 
    { 
        // Check for continuous key presses
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            ctrl.jump();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            ctrl.movePlayer(LEFT);
        }
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            ctrl.movePlayer(RIGHT);
        }

        ctrl.update();
        view.display(window);

        // Update game speed in case it changed
        displayInterval = sf::seconds(ctrl.getGameSpeed());

        // Reset the timer
        timeSinceLastDisplay = sf::Time::Zero;
    }

}