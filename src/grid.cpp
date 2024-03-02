#include "grid.hpp"

// Reads array and draws the entire array on screen
void drawArrayGrid(gamestate_t& gamestate) {

    Color square_color;

    for (unsigned int y_index = 0; y_index < gamestate.gridArray.getSizeY(); y_index++) { // Column
        for (unsigned int x_index = 0; x_index < gamestate.gridArray.getSizeX(); x_index++) { // Item per Column

            // determine color of square
            // true -> green, false -> white
            if (gamestate.gridArray.getItem(x_index, y_index) == true) {
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

// Reverting the drawArrayGrid function to get coordinates of square at mouse cursor position
unsigned int getArrayXFromMousePosition(gamestate_t& gamestateRef) {
    float temp;

    temp = (gamestateRef.mousePosition.x - gamestateRef.gridOrigin_x) / gamestateRef.squareSize;

    return static_cast<unsigned int> (std::floor(temp));
}

unsigned int getArrayYFromMousePosition(gamestate_t& gamestateRef) {
    float temp;

    temp = (gamestateRef.mousePosition.y - gamestateRef.gridOrigin_y) / gamestateRef.squareSize;

    return static_cast<unsigned int> (std::floor(temp));
}

// The actual "paintbrush"
// gamestateRef.paintbrush_mode determines whether to paint or erase
void use_paintbrush(gamestate_t& gamestateRef) {
    unsigned int x = getArrayXFromMousePosition(gamestateRef);
    unsigned int y = getArrayYFromMousePosition(gamestateRef);

    // Return if mouse position is outside of grid
    if (x >= gamestateRef.gridArray.getSizeX() || y >= gamestateRef.gridArray.getSizeY()) {
        return;
    }

    if (gamestateRef.paintbrush_mode == PAINT) {
        gamestateRef.gridArray.setItem(x, y, true);
    }

    if (gamestateRef.paintbrush_mode == ERASE) {
        gamestateRef.gridArray.setItem(x, y, false);
    }
}

// Paintbrush_mode is overwritten via parameter
void use_paintbrush(gamestate_t& gamestateRef, enum paintbrush_mode_t mode_overwrite) {
    unsigned int x = getArrayXFromMousePosition(gamestateRef);
    unsigned int y = getArrayYFromMousePosition(gamestateRef);


    if (x >= gamestateRef.gridArray.getSizeX() || y >= gamestateRef.gridArray.getSizeY()) {
        return;
    }

    if (mode_overwrite == PAINT) {
        gamestateRef.gridArray.setItem(x, y, true);
    }

    if (mode_overwrite == ERASE) {
        gamestateRef.gridArray.setItem(x, y, false);
    }
}