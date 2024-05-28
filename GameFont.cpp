#include "GameFont.h"

GameFont::GameFont()
{
    // Load the font
//   if (!font.loadFromFile("../arial.ttf")) {
        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Failed to load font." << std::endl;
            exit(EXIT_FAILURE);
        }
//    }
}