#include "GameFont.h"
#include "iostream"

GameFont::GameFont()
{
    // Load the font
//   if (!font.loadFromFile("../assets/fonts/arial.ttf")) {
        if (!font.loadFromFile("assets/fonts/arial.ttf")) {
            std::cerr << "Failed to load font." << std::endl;
            exit(EXIT_FAILURE);
        }
//    }
}