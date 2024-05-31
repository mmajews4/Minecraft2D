#ifndef SFMLCTRL_H
#define SFMLCTRL_H

#include "Controller.h"
#include "SFMLView.h"

class SFMLCtrl {

    Controller &ctrl;
    SFMLView &view;

    sf::Time displayInterval;
    sf::Time timeSinceLastDisplay;

public:
    SFMLCtrl(Controller &, SFMLView &);

    // Function handles keyboard actions
    void run(sf::RenderWindow &);

};

#endif