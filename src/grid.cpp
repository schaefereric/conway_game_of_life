#include "grid.hpp"

// Reads array and draws the entire array on screen
void drawArrayGrid(gamestate_t& gamestate) {

    Color square_color;

    for (unsigned int y_index = 0; y_index < gamestate.gridArray.getSizeY(); y_index++) { // Column
        for (unsigned int x_index = 0; x_index < gamestate.gridArray.getSizeX(); x_index++) { // Item per Column

            // determine color of square
            // Value Table -> flexible_array.hpp

            int item = gamestate.gridArray.getItem(x_index, y_index);

            switch (item) {
            case 0:
                square_color = WHITE;
                break;
            case 1:
                square_color = GREEN;
                break;
            case 2:
                square_color = BLUE;
                break;
            case 3:
                square_color = DARKBLUE;
                break;
            default:
                square_color = WHITE;
                break;
            }

            // draw (colored) squares
            DrawRectangle((gamestate.squareSize * x_index) + gamestate.gridOrigin_x,
                          (gamestate.squareSize * y_index) + gamestate.gridOrigin_y,
                          gamestate.squareSize,
                          gamestate.squareSize,
                          square_color);

            // draw grid outlines
            if (gamestate.drawRectangleOutline) {
                DrawRectangleLines((gamestate.squareSize * x_index) + gamestate.gridOrigin_x,
                                   (gamestate.squareSize * y_index) + gamestate.gridOrigin_y,
                                   gamestate.squareSize,
                                   gamestate.squareSize,
                                   BLACK);
            }
            
        }
    }
}

void rasterizeCircle_JeskoMethod(int mx, int my, int r, int input, gamestate_t* gamestateRef) {
    int t1 = r / 16;
    int t2 = 0;
    int x = r;
    int y = 0;
    while (x >= y)
    {
        gamestateRef->gridArray.setItem(mx + x, my + y, input);
        gamestateRef->gridArray.setItem(mx + x, my - y, input);
        rasterizeCircle_fill_Y_Axis(mx + x, my + y,
            my - y, input, gamestateRef);

        gamestateRef->gridArray.setItem(mx - x, my + y, input);
        gamestateRef->gridArray.setItem(mx - x, my - y, input);
        rasterizeCircle_fill_Y_Axis(mx - x, my + y,
            my - y, input, gamestateRef);

        gamestateRef->gridArray.setItem(mx + y, my + x, input);
        gamestateRef->gridArray.setItem(mx + y, my - x, input);
        rasterizeCircle_fill_Y_Axis(mx + y, my + x,
            my - x, input, gamestateRef);

        gamestateRef->gridArray.setItem(mx - y, my + x, input);
        gamestateRef->gridArray.setItem(mx - y, my - x, input);
        rasterizeCircle_fill_Y_Axis(mx - y, my + x,
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
} // todo: invalid index handling

void rasterizeCircle_fill_Y_Axis(int x, int y1, int y2, int input, gamestate_t* gamestateRef) {
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
        gamestateRef->gridArray.setItem(x, i, input);
    }
}


int getRandomBool() {
    static unsigned int valuePool;
    static unsigned int counter = 0;

    if (counter == 0 || counter == 31) {
        counter = 0;

        std::random_device rd;

        std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count()
            +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());

        std::mt19937 gen(seed);

        std::mt19937::result_type n;

        while ((n = gen()) > std::mt19937::max() -
            (std::mt19937::max() - 5) % 6)
        {
        }

        valuePool = n;
    }

    counter++;
    return (valuePool & (1 << counter)) != 0;
}

void rasterizeCircle_random(int mx, int my, int r, gamestate_t* gamestateRef) {

    static int previous_mx = 0;
    static int previous_my = 0;

    /*if (previous_mx == mx || previous_my == my) {
        return;
    }*/

    previous_mx = mx;
    previous_my = my;

    int t1 = r / 16;
    int t2 = 0;
    int x = r;
    int y = 0;

    while (x >= y)
    {
        gamestateRef->gridArray.setItem(mx + x, my + y, getRandomBool());
        gamestateRef->gridArray.setItem(mx + x, my - y, getRandomBool());
        rasterizeCircle_fill_Y_Axis(mx + x, my + y,
            my - y, getRandomBool(), gamestateRef);

        gamestateRef->gridArray.setItem(mx - x, my + y, getRandomBool());
        gamestateRef->gridArray.setItem(mx - x, my - y, getRandomBool());
        rasterizeCircle_fill_Y_Axis(mx - x, my + y,
            my - y, getRandomBool(), gamestateRef);

        gamestateRef->gridArray.setItem(mx + y, my + x, getRandomBool());
        gamestateRef->gridArray.setItem(mx + y, my - x, getRandomBool());
        rasterizeCircle_fill_Y_Axis(mx + y, my + x,
            my - x, getRandomBool(), gamestateRef);

        gamestateRef->gridArray.setItem(mx - y, my + x, getRandomBool());
        gamestateRef->gridArray.setItem(mx - y, my - x, getRandomBool());
        rasterizeCircle_fill_Y_Axis(mx - y, my + x,
            my - x, getRandomBool(), gamestateRef);

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

void shuffleGrid(gamestate_t* gamestateRef) {
    for (unsigned int y_index = 0; y_index < gamestateRef->gridArray.getSizeY(); y_index++) {
        for (unsigned int x_index = 0; x_index < gamestateRef->gridArray.getSizeX(); x_index++) {
            gamestateRef->gridArray.setItem(x_index, y_index, getRandomBool());
        }
    }
}