#pragma once

#include "flexible_array.hpp"


struct gamestate_class {
    flexible_array gridArray;

    int squareSize;
    int gridOrigin_x;
    int gridOrigin_y;

    int screenWidth;
    int screenHeight;


    gamestate_class();

};
