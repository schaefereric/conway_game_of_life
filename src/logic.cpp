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
    default:
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
        default:
            return -1;
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

        // count neighbor if this square is true
        if (arrayRef->getItem(static_cast<int>(tempPos.x), static_cast<int>(tempPos.y)) == 1) {
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
        else return false;
    }
    else return false;
    
}

void applyGameRulesOnArray(flexible_array* arrayRef) {

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
    
    // TODO: OPTIMIZE FOLLOWING LINES
    // It is unnecessary to wipe the entire array and only apply the new squares
    // 
    // Wipe Array 
    arrayRef->clearArray();

    // Apply new squares
    for (auto i : listOfAliveSquares) {
        arrayRef->setItem(static_cast<unsigned int>(i.x), static_cast<unsigned int>(i.y), 1);
    }

}
