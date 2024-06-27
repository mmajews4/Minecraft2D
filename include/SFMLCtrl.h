#ifndef SFMLCTRL_H
#define SFMLCTRL_H

#include "Controller.h"
#include "SFMLView.h"
#include "Equipment.h"

#include "World.h"

class SFMLCtrl {

    Controller &ctrl;
    Player &player;
    Equipment &eq;
    SFMLView &view;

    sf::Time displayInterval;
    sf::Time timeSinceLastDisplay;

public:
    SFMLCtrl(Controller &, SFMLView &,  Player &, Equipment &);

    // Function handles keyboard actions
    void run(sf::RenderWindow &);

};

#endif