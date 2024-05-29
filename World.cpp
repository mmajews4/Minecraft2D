#include "World.h"

// colors for easier to read debug display
// ANSI escape codes for colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define LIGHT_GREEN "\033[38;5;154m"
#define YELLOW  "\033[33m"
#define WHITE   "\033[37m"
#define GREY    "\033[38;5;244m"
#define BROWN   "\033[38;5;94m"
#define DARK_BROWN "\033[38;5;52m"


using namespace std;

World::World()
{
    width = 30;
    height = 15;

    map.resize(height, vector<Field>(width));

    // Set world map
    map.assign({{A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A},
                {A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A},
                {A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A},
                {A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A},
                {A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A},
                {A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A},
                {D, D, D, D, D, D, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A},
                {D, D, D, D, D, D, D, D, A, A, A, A, A, A, A, A, A, A, A, A, A, D, D, D, D, D, D, D, D, D},
                {D, D, D, D, D, D, D, D, D, D, D, D, A, A, A, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D},
                {D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D},
                {D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D},
                {D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D},
                {D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D},
                {D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D},
                {D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D}});
}


int World::getWidth() const
{
    return width;
}

int World::getHeight() const
{
    return height;
}

Field World::getBlock(int col, int row) const
{
    return map[row][col];
}


void World::setBlock(int col, int row, Field block)
{
    map[row][col] = block;
}

void World::debugDisplayWorld() const
{
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            cout << " ";
            switch(map[row][col]){
                case A:
                    cout << WHITE << "A" << RESET;
                    break;
                case D:
                    cout << BROWN << "D" << RESET;
                    break;
                case G:
                    cout << LIGHT_GREEN << "G" << RESET;
                    break;
                case W:
                    cout << DARK_BROWN << "W" << RESET;
                    break;
                case L:
                    cout << GREEN << "L" << RESET;
                    break;
                case S:
                    cout << GREY << "S" << RESET;
                    break;
                case C:
                    cout << RED << "C" << RESET;
                    break;
                case T:
                    cout << YELLOW << "T" << RESET;
                    break;
            }
        }
        cout << endl;
    }
    cout << endl;
}

