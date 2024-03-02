#include "logic.hpp"

// {NW, N, NE, E, SE, S, SW, W};

Vector2 getMooreNeighborhoodCoordinate(int ix, int iy, moore_direction direction) {
    Vector2 temp = { 0,0 };

    switch (direction) {
    case NW:
        temp.x = static_cast<float> (ix - 1);
        temp.y = static_cast<float> (iy - 1);
        break;                      
    case N:                         
        temp.x = static_cast<float> (ix);
        temp.y = static_cast<float> (iy - 1);
        break;                      
    case NE:                        
        temp.x = static_cast<float> (ix + 1);
        temp.y = static_cast<float> (iy - 1);
        break;                      
    case E:                         
        temp.x = static_cast<float> (ix + 1);
        temp.y = static_cast<float> (iy);
        break;                      
    case SE:                        
        temp.x = static_cast<float> (ix + 1);
        temp.y = static_cast<float> (iy + 1);
        break;                      
    case S:                         
        temp.x = static_cast<float> (ix);
        temp.y = static_cast<float> (iy + 1);
        break;                      
    case SW:                        
        temp.x = static_cast<float> (ix - 1);
        temp.y = static_cast<float> (iy + 1);
        break;                      
    case W:                         
        temp.x = static_cast<float> (ix - 1);
        temp.y = static_cast<float> (iy);
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

        Vector2 tempPos = getMooreNeighborhoodCoordinate(ix, iy, tempDirection);

        // if tempPos is outside of the grid, do not count a neighbor and continue for loop
        if (tempPos.x < 0 || tempPos.y < 0) {
            continue;
        } 
        // prevent arithmetic overflow
        if (tempPos.x >= arrayRef->getSizeX() || tempPos.y >= arrayRef->getSizeY()) {
            continue;
        }

        // count neighbor
        if (arrayRef->getItem(static_cast<int>(tempPos.x), static_cast<int>(tempPos.y)) == true) {
            numberOfNeighbors++;
        }
    }

    return numberOfNeighbors;
}

// Returns TRUE if this square lives in the next generation, or returns FALSE if this square dies in the next generation
bool decideNewStateOfSquare(unsigned int ix, unsigned int iy, flexible_array* arrayRef) {
    
    int numberOfNeighbors = getNumberOfNeighbors(ix, iy, arrayRef); 

    // The game rules:
    if (arrayRef->getItem(ix, iy) == false) {
        if (numberOfNeighbors == 3) {
            return true;
        }
        else return false;
    }
    if (arrayRef->getItem(ix, iy) == true) {
        if (numberOfNeighbors < 2) {
            return false;
        }
        if (numberOfNeighbors == 2 || numberOfNeighbors == 3) {
            return true;
        }
        if (numberOfNeighbors > 3) {
            return false;
        }
        else return false;
    }
    else return false;
    
}

// Applies the game rules on the gridArray ONCE! 
void applyGameRulesOnArray_SecondArrayMethod(flexible_array* arrayRef) {
    /*
    * VERY STUPID IDEA !!!!
    * 1. initialize new flexible-array
    * 2. iterate over gridArray and save results directly to new array
    * 3. deallocate old array pointer and move new array pointer to old array
    */

    flexible_array newArray(arrayRef->getSizeX(), arrayRef->getSizeY());

    for (unsigned int index_y = 0; index_y < arrayRef->getSizeY(); index_y++) {
        for (unsigned int index_x = 0; index_x < arrayRef->getSizeX(); index_x++) {

            bool square = decideNewStateOfSquare(index_x, index_y, arrayRef);

            if (square) {
                newArray.setItem(index_x, index_y, true);
            }
            else if (!square) {
                newArray.setItem(index_x, index_y, false);
            }
            else {
                newArray.setItem(index_x, index_y, true);
                // todo: error handling
            }
        }
    }

    // Change old array pointer with new array pointer
    arrayRef->swapPointers(newArray.pAry);
}

void applyGameRulesOnArray_VectorMethod(flexible_array* arrayRef) {
    /* 
    * Better (?) idea:
    * 1. std::vector<vector2> -> save positions of squares that live/die
    * 2. apply saved positions to array
    */

    std::vector<Vector2> listOfAliveSquares;
    Vector2 tempVec;

    // Iterate over array and save position of squares that will live in the following generation
    for (unsigned int index_y = 0; index_y < arrayRef->getSizeY(); index_y++) {
        for (unsigned int index_x = 0; index_x < arrayRef->getSizeX(); index_x++) {

            bool tempBool = decideNewStateOfSquare(index_x, index_y, arrayRef);

            if (tempBool) {
                tempVec.x = static_cast<float>(index_x);
                tempVec.y = static_cast<float>(index_y);
                listOfAliveSquares.push_back(tempVec);
            }
        }
    }

    // Wipe Array
    arrayRef->clearArray();

    // Apply new squares
    for (auto i : listOfAliveSquares) {
        arrayRef->setItem(static_cast<unsigned int>(i.x), static_cast<unsigned int>(i.y), true);
    }

}