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
            if(event.key.code == sf::Keyboard::W) {

            }
            if(event.key.code == sf::Keyboard::A) {

            }
            if(event.key.code == sf::Keyboard::D) {

            }
        }   
    }

    // Measure the time elapsed since the last frame
    sf::Time dt = clock.restart();
    timeSinceLastDisplay += dt;

    // Check if it's time to update the display
    if (timeSinceLastDisplay >= displayInterval) 
    {       
        view.display(window);

        // Update game speed in case it changed
        displayInterval = sf::seconds(ctrl.getGameSpeed());

        // Reset the timer
        timeSinceLastDisplay = sf::Time::Zero;
    }

}