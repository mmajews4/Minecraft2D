#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Array2D.h"
#include "Button.h"
#include "World.h"
#include "Controller.h"
#include "Equipment.h"
#include "SFMLView.h"
#include "SFMLCtrl.h"


using namespace std;

int main() {

    World world;
    Equipment eq;
    Player player(10, 6, world, eq);
    vector<Entity*> entities;
    Controller ctrl(world, player, eq, entities);
    SFMLView view(world, player, eq, entities);
    SFMLCtrl win_ctrl(ctrl, view, player, eq);

    sf::RenderWindow window(sf::VideoMode(view.getWindowWidth(), view.getWindowHeight()), "Minecreft2D");

    while (window.isOpen()) {
        win_ctrl.run(window);
    }

    return 0;
}
