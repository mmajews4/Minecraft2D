#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Array2D.h"
#include "Button.h"
#include "Dirt.h"
#include "World.h"


using namespace std;

int main() {
    
    Dirt dirt(100, 100);

    World world;
    world.debugDisplayWorld();


    sf::RenderWindow window(sf::VideoMode(800, 600), "Basic SFML Window");

    while (window.isOpen()) {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Drawing
        window.clear();       // Clear the window

        dirt.draw(window);

        window.display();     // Display the contents of the window
    }


    return 0;
}
