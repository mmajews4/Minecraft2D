#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Array2D.h"
#include "Button.h"
#include "Dirt.h"
#include "World.h"
#include "Controller.h"
#include "SFMLView.h"
#include "SFMLCtrl.h"


using namespace std;

int main() {
    
    Dirt dirt(100, 100);

    World world;
    Player player(10, 6);
    Controller ctrl(world, player);
    SFMLView view(world, player);
    SFMLCtrl win_ctrl(ctrl, view);


    world.debugDisplayWorld();


    sf::RenderWindow window(sf::VideoMode(800, 600), "Minecreft2D");

    while (window.isOpen()) {
        win_ctrl.run(window);
    }

    return 0;
}
