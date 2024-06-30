#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include "World.h"
#include "Player.h"
#include "Zombie.h"
#include "Equipment.h"

enum GameState {RUNNING, PLAYER_KILLED};

class Controller 
{
//    const int BLOCK_SIZE = 100;
    const double GAME_SPEED = 0.025;
    const int ZOMBIE_SPAWN_CHANCE = 500; // 1 in how many game updates zombie can spawn
    GameState state;

    World &world;
    Player &player;
    Equipment &eq;

    vector<Entity*> &entities;

public:
    Controller(World &, Player &, Equipment &, vector<Entity*> &en);

    float getGameSpeed() const;
    GameState getGameState() const;
    void setGameState(GameState);

    // Spawns zombie based on given chanse
    void spawnZombie();

    // - Make zombie move towards Player
    // - Jump over 1 block
    // - Hurt player if he touches him
    // - Take demage if player hits him
    // - Die if no health
    void updateZombies();

    // After mouse button click:
    // - checks if it is in range of any enemies
    // - if yes, take damage to entity
    void hitEntity(int col, int row);

    // Updates currnet state of the game:
    // - checks collisions
    // - calculates gravity
    // - moves player
    // - checks if player died
    void update();
};

#endif
