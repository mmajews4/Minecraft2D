#include "World.h"

// colors for easier to read debug display
// ANSI escape codes for colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define DARK_GREEN "\033[38;5;22m"
#define YELLOW  "\033[33m"
#define WHITE   "\033[37m"
#define GREY    "\033[38;5;244m"
#define BROWN   "\033[38;5;94m"
#define DARK_BROWN "\033[38;5;52m"
#define BOLD    "\033[1m"


using namespace std;

// A-air D-dirt G-grass W-wood L-leaves S-stone C-chest T-craftingTable 
World::World()
{
    width = 30;
    height = 15;

    map.resize(height, vector<BlockSign>(width));

    // Set world map
    // Map for testing
    map.assign({{A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A},
                {A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A},
                {D, D, D, D, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A},
                {D, D, D, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A},
                {D, D, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A},
                {D, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A},
                {D, D, D, D, D, D, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A},
                {D, D, D, D, D, D, D, D, A, A, A, A, A, A, A, A, A, A, A, A, A, D, D, D, D, D, D, D, D, D},
                {D, D, D, D, D, D, D, D, D, D, D, D, A, A, A, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D},
                {D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D},
                {D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D},
                {D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D},
                {D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D},
                {D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D},
                {D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D}});
/*
    map.assign({{A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A},
                {A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A},
                {A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, L, L, L, A, A, A},
                {A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, L, L, W, L, L, A, A},
                {G, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, L, L, W, L, L, A, A},
                {D, G, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, W, A, A, A, A},
                {D, D, G, G, G, G, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, W, A, A, A, A},
                {D, D, D, D, D, D, G, G, A, A, A, A, A, A, A, A, T, A, C, A, A, G, G, G, G, G, G, G, G, G},
                {D, D, D, D, D, D, D, D, G, G, G, G, A, A, A, G, G, G, G, G, G, D, D, D, D, D, D, D, D, D},
                {S, S, S, S, D, D, D, D, D, D, D, D, G, G, G, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D},
                {S, S, S, S, S, S, S, S, S, S, D, D, D, D, D, D, D, D, D, D, S, S, S, S, S, S, S, S, S, S},
                {S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S},
                {S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S},
                {S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S},
                {S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S}});
*/
}


int World::getWidth() const
{
    return width;
}

int World::getHeight() const
{
    return height;
}

BlockSign World::getBlock(int col, int row) const
{
    if(col < 0 || col >= width || row < 0 || row >= height) return A;
    return map[row][col];
}


void World::setBlock(int col, int row, BlockSign block)
{
    if(!(col < 0 || col >= width || row < 0 || row > height)) map[row][col] = block;
}


void World::debugDisplayWorld() const
{
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            cout << " " << BOLD;
            switch(getBlock(col, row)){
                case A:
                    cout << WHITE << "A";
                    break;
                case D:
                    cout << BROWN << "D";
                    break;
                case G:
                    cout << GREEN << "G";
                    break;
                case W:
                    cout << DARK_BROWN << "W";
                    break;
                case L:
                    cout << DARK_GREEN << "L";
                    break;
                case S:
                    cout << GREY << "S";
                    break;
                case C:
                    cout << RED << "C";
                    break;
                case T:
                    cout << YELLOW << "T";
                    break;
            }
            cout << RESET;
        }
        cout << endl;
    }
    cout << endl;
}

