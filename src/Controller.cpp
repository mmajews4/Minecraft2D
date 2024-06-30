#include "Controller.h"

using namespace std;

Controller::Controller(World &w, Player &p, Equipment &e, vector<Entity*> &en) : world(w), player(p), eq(e), entities(en)
{
//    velocity = 0;
//    block = &dirt; // Any block just to take its size
}


float Controller::getGameSpeed() const
{
    return GAME_SPEED;
}

void Controller::spawnZombie()
{
    // Generacja losowej liczby
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> chance(0, ZOMBIE_SPAWN_CHANCE);

    int zombie_spawn_chance = chance(rng);
    if(zombie_spawn_chance == 1)
    {
        entities.push_back(new Zombie(10, 6, world));
    }
}


// - Make zombie move towards Player
// - Jump over 1 block
// - Hurt player if he touches him
// - Take demage if player hits him
// - Die if no health
void Controller::updateZombies()
{
    // check for every zombie
    for(auto& zombie: entities)
    {
        // - Make zombie move towards Player
        // - Jump over 1 block
        if(player.getPositionCol() < zombie->getPositionCol())
        {
            zombie->move(LEFT);
            if(zombie->checkMoveCollision(LEFT)) zombie->jump();
        } else {
            zombie->move(RIGHT);
            if(zombie->checkMoveCollision(RIGHT)) zombie->jump();
        }

        // - Hurt player if he touches him
        if((zombie->getPositionCol() >= player.getPositionCol() && zombie->getPositionCol() <= player.getPositionCol()+1)
        || (zombie->getPositionRow() >= player.getPositionRow() && zombie->getPositionRow() <= player.getPositionRow()+2))
        {
            player.takeDamage();
        }
    }
}


// Updates currnet state of the game:
// - checks collisions
// - calculates gravity
// - moves player
void Controller::update()
{
    player.calculateGravity();
    spawnZombie();
    updateZombies();

    for(auto& entity: entities)
    {
        entity->calculateGravity();
    }
}
