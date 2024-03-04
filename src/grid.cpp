#include "grid.hpp"

// Reads array and draws the entire array on screen
void drawArrayGrid(gamestate_t& gamestate) {

    Color square_color;

    for (unsigned int y_index = 0; y_index < gamestate.gridArray.getSizeY(); y_index++) { // Column
        for (unsigned int x_index = 0; x_index < gamestate.gridArray.getSizeX(); x_index++) { // Item per Column

            // determine color of square
            // true -> green, false -> white
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
        gamestateRef.gridArray.setItem(x, y, 1);
    }

    if (gamestateRef.paintbrush_mode == ERASE) {
        gamestateRef.gridArray.setItem(x, y, 0);
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
        gamestateRef.gridArray.setItem(x, y, 1);
    }

    if (mode_overwrite == ERASE) {
        gamestateRef.gridArray.setItem(x, y, 0);
    }
}

void usePaintbrushWithRadius(gamestate_t& gamestateRef) {
    unsigned int x = getArrayXFromMousePosition(gamestateRef);
    unsigned int y = getArrayYFromMousePosition(gamestateRef);

    if (gamestateRef.paintbrush_mode == PAINT) {
        fillCircle_JeskoMethod(x, y, gamestateRef.brushRadius, 1, gamestateRef);
    }

    if (gamestateRef.paintbrush_mode == ERASE) {
        fillCircle_JeskoMethod(x, y, gamestateRef.brushRadius, 0, gamestateRef);
    }
    
}

void fillCircle_JeskoMethod(int mx, int my, int r, int input, gamestate_t & gamestateRef) {
    int t1 = r / 16;
    int t2 = 0;
    int x = r;
    int y = 0;
    while (x >= y)
    {
        gamestateRef.gridArray.setItem(mx + x, my + y, input);
        gamestateRef.gridArray.setItem(mx + x, my - y, input);
              fillCircle_fillInBetween(mx + x, my + y, 
                                               my - y, input, gamestateRef);

        gamestateRef.gridArray.setItem(mx - x, my + y, input);
        gamestateRef.gridArray.setItem(mx - x, my - y, input);
              fillCircle_fillInBetween(mx - x, my + y,
                                               my - y, input, gamestateRef);

        gamestateRef.gridArray.setItem(mx + y, my + x, input);
        gamestateRef.gridArray.setItem(mx + y, my - x, input);
              fillCircle_fillInBetween(mx + y, my + x, 
                                               my - x, input, gamestateRef);

        gamestateRef.gridArray.setItem(mx - y, my + x, input);
        gamestateRef.gridArray.setItem(mx - y, my - x, input);
              fillCircle_fillInBetween(mx - y, my + x, 
                                               my - x, input, gamestateRef);

        y = y + 1;
        t1 = t1 + y;
        t2 = t1 - x;
        if (t2 >= 0)
        {
            t1 = t2;
            x = x - 1;
        }
    }
}

void fillCircle_fillInBetween(int x, int y1, int y2, int input, gamestate_t& gamestateRef) {
    if (y1 == y2) {
        return;
    }

    // we assume that y1 is the bigger number. if not, swap values
    if (y2 > y1) {
        int buffer = y2;
        y2 = y1;
        y1 = buffer;
    }

    for (int i = y2 + 1; i < y1; i++) {
        gamestateRef.gridArray.setItem(x, i, input);
    }
}
