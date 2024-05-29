#ifndef WORLD_H
#define WORLD_H

#include "Array2D.h"
#include <iostream>
#include <vector>

using namespace std;

// Filed so tthat it doesn't colide with block name
// A-air D-dirt G-grass W-wood L-leaves S-stone C-chest T-craftingTable 
enum Field { A, D, G, W, L, S, C, T };

class World {

    int width, height;

    vector<vector<Field>> map;

public:

    World();

    int getWidth() const;
    int getHeight() const;
    Field getBlock(int col, int row) const;
    void setBlock(int col, int row, Field block);

    // Display contents of a world on console
    void debugDisplayWorld() const;
};


#endif
