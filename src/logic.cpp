#include "logic.hpp"

// {NW, N, NE, E, SE, S, SW, W};

Vector2 getMooreNeighborhoodCoordinate(int ix, int iy, moore_direction direction) {
    Vector2 temp = { 0,0 };

    switch (direction) {
    case NW:
        temp.x = ix - 1;
        temp.y = iy - 1;
        break;
    case N:
        temp.x = ix;
        temp.y = iy - 1;
        break;
    case NE:
        temp.x = ix + 1;
        temp.y = iy - 1;
        break;
    case E:
        temp.x = ix + 1;
        temp.y = iy;
        break;
    case SE:
        temp.x = ix + 1;
        temp.y = iy + 1;
        break;
    case S:
        temp.x = ix;
        temp.y = iy + 1;
        break;
    case SW:
        temp.x = ix - 1;
        temp.y = iy + 1;
        break;
    case W:
        temp.x = ix - 1;
        temp.y = iy;
        break;
    }

    return temp;
}

int getNumberOfNeighbors(unsigned int ix, unsigned int iy, flexible_array* arrayRef)
{
    int numberOfNeighbors = 0;

    for (int i = 0; i < 8; i++) {
        moore_direction tempDirection;

        switch (i) {
        case 0:
            tempDirection = NW;
            break;
        case 1:
            tempDirection = N;
            break;
        case 2:
            tempDirection = NE;
            break;
        case 3:
            tempDirection = E;
            break;
        case 4:
            tempDirection = SE;
            break;
        case 5:
            tempDirection = S;
            break;
        case 6:
            tempDirection = SW;
            break;
        case 7:
            tempDirection = W;
            break;
        }

        Vector2 newPos = getMooreNeighborhoodCoordinate(ix, iy, tempDirection);

        // if newPos is outside of the grid, do not count a neighbor and continue for loop
        if (newPos.x < 0 || newPos.y < 0) {
            continue;
        } 

        if (arrayRef->getItem(newPos.x, newPos.y) == 1) {
            numberOfNeighbors++;
        }
    }

    return numberOfNeighbors;
}

// Returns TRUE if this square lives in the next generation, or returns FALSE if this square dies in the next generation
bool decideNewStateOfSquare(unsigned int ix, unsigned int iy, flexible_array* arrayRef) {
    
    int numberOfNeighbors = getNumberOfNeighbors(ix, iy, arrayRef); 

    // The game rules:
    if (arrayRef->getItem(ix, iy) == 0) {
        if (numberOfNeighbors == 3) {
            return true;
        }
        else return false;
    }
    if (arrayRef->getItem(ix, iy) == 1) {
        if (numberOfNeighbors < 2) {
            return false;
        }
        if (numberOfNeighbors == 2 || numberOfNeighbors == 3) {
            return true;
        }
        if (numberOfNeighbors > 3) {
            return false;
        }
    }
    else return false;
    
}

// Applies the game rules on the gridArray ONCE! 
void applyGameRulesOnArray(flexible_array* arrayRef) {
    /*
    *  VERY STUPID IDEA !!!!
    * 1. initialize new flexible-array
    * 2. iterate over gridArray and save results directly to new array
    * 3. deallocate old array pointer and move new array pointer to old array
    *
    * 
    * Better (?) idea:
    * 1. std::vector<std::pair<int, int>> -> save positions of squares that live/die
    * 2. apply saved positions to array
    * 
    */

    flexible_array newArray(arrayRef->getSizeX(), arrayRef->getSizeY());

    for (int index_y = 0; index_y < arrayRef->getSizeY(); index_y++) {
        for (int index_x = 0; index_x < arrayRef->getSizeX(); index_x++) {

            bool square = decideNewStateOfSquare(index_x, index_y, arrayRef);

            if (square) {
                newArray.setItem(index_x, index_y, 1);
            }
            else if (!square) {
                newArray.setItem(index_x, index_y, 0);
            }
            else {
                newArray.setItem(index_x, index_y, 1);
                // todo: error handling
            }
        }
    }

    // Change old array pointer with new array pointer
    arrayRef->exchangePointers(newArray.pAry);
}