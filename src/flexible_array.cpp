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
    pAry = new int[ix * iy];
    clearArray();
    logErrors = false;
}

// Default constructor, initializes array as 3*3 matrix
flexible_array::flexible_array() { 
    size_x = 2;
    size_y = 2;
    pAry = new int[3 * 3];
    clearArray();
    logErrors = false;
}

// Destructor, deallocates memory on heap
flexible_array::~flexible_array() {
    delete[] pAry;
}

// Resize array
void flexible_array::reInitialize(unsigned int ix, unsigned int iy) {
    if (ix == 0 || iy == 0) {
        if (logErrors) {
            std::cerr << "flexible_array::reInitialize: ERROR: Size cannot be zero!" << "\n";
        }
        
        return;
    }

    delete[] pAry;
    size_x = ix;
    size_y = iy;
    pAry = new int[ix * iy];
    clearArray();
}

// Returns item at given index
int flexible_array::getItem(unsigned int ix, unsigned int iy) const {
    if (ix >= size_x || iy >= size_y) {
        if (logErrors) {
            std::cerr << "flexible_array::getItem: ERROR: Invalid index!" << "\n";
        }
        
        return 0;
    }

    return pAry[getSingleIndex(ix, iy)];
}

// Sets items at given index
void flexible_array::setItem(unsigned int ix, unsigned int iy, int input) {
    if (ix > size_x - 1 || iy > size_y - 1) {
        if (logErrors) {
            std::cerr << "flexible_array::setItem: ERROR: Invalid index!" << "\n";
        }
        
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
            setItem(i, j, 0);
        }
    }
}

int* flexible_array::returnPointerToNewArray() {
    return new int[size_x * size_y];
}

int* flexible_array::returnPointerToNewArray(unsigned int ix, unsigned int iy) {
    return new int[ix * iy];
}

void flexible_array::swapPointers(int* newArray) {
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
            if (getItem(i, j) == 0) {
                std::cout << "O ";
            }
            else if (getItem(i, j) == 1) {
                std::cout << dye::green("X ");
            }
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}