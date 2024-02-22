#pragma once

#include "flexible_array.hpp"
#include "raylib.h"
#include "gamestate_t.hpp"

void drawArrayGrid(gamestate_t& gamestate) {

    Color square_color;

    for (unsigned int y_index = 0; y_index < gamestate.gridArray.getSizeY(); y_index++) { // Column
        for (unsigned int x_index = 0; x_index < gamestate.gridArray.getSizeX(); x_index++) { // Item per Column

            // determine color of square
            if (gamestate.gridArray.getItem(x_index, y_index) == 1) {
                square_color = GREEN;
            }

            else {
                square_color = WHITE;
            }


            // draw (colored) squares
            DrawRectangle((gamestate.squareSize * x_index) + gamestate.gridOrigin_x,
                          (gamestate.squareSize * y_index) + gamestate.gridOrigin_y,
                           gamestate.squareSize,
                           gamestate.squareSize,
                           square_color);

            // draw grid lines
            DrawRectangleLines((gamestate.squareSize * x_index) + gamestate.gridOrigin_x,
                               (gamestate.squareSize * y_index) + gamestate.gridOrigin_y,
                                gamestate.squareSize,
                                gamestate.squareSize,
                                BLACK);
        }
    }
}