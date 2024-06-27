#include "Zombie.h"

using namespace std;

Zombie::Zombie(double pc, double pr, World &w) : Entity(pc, pr, w), wrld(w)
{
    setTexture(texture);
}
