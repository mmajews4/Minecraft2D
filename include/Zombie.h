#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Entity.h"

class Zombie : public Entity {

    std::string texture = "assets/textures/Zombie.png";

    World &wrld;

public:

    Zombie(double pc, double pr, World &w);

};

#endif