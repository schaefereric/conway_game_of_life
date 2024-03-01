#include "flexible_array.hpp"

#include <iostream>
#include "color.hpp"

// Takes two index numbers (x and y) and returns single array index number
int flexible_array::getSingleIndex(unsigned int ix, unsigned int iy) const  
{
    return ix + size_x * iy;
}

// Recommended constructor, enter field size in parameters
flexible_array::flexible_array(unsigned int ix, unsigned int iy) {
    size_x = ix;
    size_y = iy;
    pAry = new bool[ix * iy];
    clearArray();
}

// Default constructor, initializes array as 2*2 matrix
flexible_array::flexible_array() { 
    size_x = 2;
    size_y = 2;
    pAry = new bool[2 * 2];
    clearArray();
}

// Destructor, deallocates memory on heap
flexible_array::~flexible_array() {
    delete[] pAry;
}

// Resize array
void flexible_array::reInitialize(unsigned int ix, unsigned int iy) {
    if (ix == 0 || iy == 0) {
        std::cerr << "flexible_array::reInitialize: ERROR: Size cannot be zero!" << "\n";
        return;
    }

    delete[] pAry;
    size_x = ix;
    size_y = iy;
    pAry = new bool[ix * iy];
    clearArray();
}

// Returns item at given index
bool flexible_array::getItem(unsigned int ix, unsigned int iy) const {
    if (ix >= size_x || iy >= size_y) {
        std::cerr << "flexible_array::getItem: ERROR: Invalid index!" << "\n";
        return 0;
    }

    return pAry[getSingleIndex(ix, iy)];
}

// Sets items at given index
void flexible_array::setItem(unsigned int ix, unsigned int iy, bool input) {
    if (ix > size_x - 1 || iy > size_y - 1) {
        std::cerr << "flexible_array::setItem: ERROR: Invalid index!" << "\n";
        return;
    }

    pAry[getSingleIndex(ix, iy)] = input;
}

// Returns array size_X
unsigned int flexible_array::getSizeX() const {
    return size_x;
}

// Returns array size_Y
unsigned int flexible_array::getSizeY() const {
    return size_y;
}

// Initialize array with zeros
void flexible_array::clearArray() {
    for (unsigned int i = 0; i < size_x; i++) {
        for (unsigned int j = 0; j < size_y; j++) {
            setItem(i, j, false);
        }
    }
}

bool* flexible_array::returnPointerToNewArray() {
    return new bool[size_x * size_y];
}

bool* flexible_array::returnPointerToNewArray(unsigned int ix, unsigned int iy) {
    return new bool[ix * iy];
}

void flexible_array::swapPointers(bool* newArray) {
    delete[] pAry;
    pAry = newArray;
}

// -----------------------------------------------------------
// 
// DEPRECATED DEBUG FUNCTIONS !!! ONLY WORKS WITH INTEGERS !!!
//
// 
// Prints a countinuous list of all items in the array
void flexible_array::traverse() const { 
    for (unsigned int i = 0; i < size_x; i++) {
        for (unsigned int j = 0; j < size_y; j++) {
            std::cout << "X: " << i
                      << " Y: " << j
                      << " Item: " << getItem(i, j)
                      << "\n";
        }
    }
    std::cout << std::endl;
}

// Assuming the array is storing bools, a square matrix is printed, displaying zeros/false as O and ones/true as X
void flexible_array::printMatrix() const { 
    for (unsigned int i = 0; i < size_x; i++) {
        for (unsigned int j = 0; j < size_y; j++) {
            if (getItem(i, j) == false) {
                std::cout << "O ";
            }
            else if (getItem(i, j) == true) {
                std::cout << dye::green("X ");
            }
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}