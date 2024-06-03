#ifndef WORLD_H
#define WORLD_H

#include "Array2D.h"
#include <iostream>
#include <vector>
#include "Dirt.h"

using namespace std;

// A-air D-dirt G-grass W-wood L-leaves S-stone C-chest T-craftingTable 

class World {

    int width, height;

    vector<vector<BlockSign>> map;

public:

    World();

    int getWidth() const;
    int getHeight() const;
    BlockSign getBlock(int col, int row) const;
    void setBlock(int col, int row, BlockSign block);

    // Display contents of a world on console
    void debugDisplayWorld() const;
};


#endif
