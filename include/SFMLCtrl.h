#ifndef SFMLCTRL_H
#define SFMLCTRL_H

#include "Controller.h"
#include "SFMLView.h"
#include "Equipment.h"

class SFMLCtrl {

    Controller &ctrl;
    Equipment &eq;
    SFMLView &view;

    sf::Time displayInterval;
    sf::Time timeSinceLastDisplay;

public:
    SFMLCtrl(Controller &, SFMLView &, Equipment &);

    // Function handles keyboard actions
    void run(sf::RenderWindow &);

};

#endif