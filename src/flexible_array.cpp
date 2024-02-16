#include "flexible_array.hpp"

#include <iostream>
#include "color.hpp"


int flexible_array::getSingleIndex(unsigned int ix, unsigned int iy) const  // Takes two index numbers (x and y) and returns single array index number
{
    return ix + size_x * iy;
}

flexible_array::flexible_array(unsigned int ix, unsigned int iy) { // Enter field size in parameters
    size_x = ix;
    size_y = iy;
    pAry = new int[ix * iy];
    clearArray();
}

flexible_array::flexible_array() { // Fallback constructor
    size_x = 2;
    size_y = 2;
    pAry = new int[2 * 2];
    clearArray();
}


flexible_array::~flexible_array() {
    delete[] pAry;
}

void flexible_array::reInitialize(unsigned int ix, unsigned int iy) {
    if (ix == 0 || iy == 0) {
        std::cerr << "flexible_array::reInitialize: ERROR: Size cannot be zero!" << "\n";
        return;
    }

    delete[] pAry;
    size_x = ix;
    size_y = iy;
    pAry = new int[ix * iy];
    clearArray();
}

int flexible_array::getItem(unsigned int ix, unsigned int iy) const {
    if (ix >= size_x || iy >= size_y) {
        std::cerr << "flexible_array::getItem: ERROR: Invalid index!" << "\n";
        return 0;
    }

    return pAry[getSingleIndex(ix, iy)];
}

void flexible_array::setItem(unsigned int ix, unsigned int iy, int input) {
    if (ix > size_x - 1 || iy > size_y - 1) {
        std::cerr << "flexible_array::setItem: ERROR: Invalid index!" << "\n";
        return;
    }

    pAry[getSingleIndex(ix, iy)] = input;
}

unsigned int flexible_array::getSizeX() const {
    return size_x;
}

unsigned int flexible_array::getSizeY() const {
    return size_y;
}

void flexible_array::clearArray() {
    for (unsigned int i = 0; i < size_x; i++) {
        for (unsigned int j = 0; j < size_y; j++) {
            setItem(i, j, 0);
        }
    }
}

void flexible_array::traverse() { // Prints a countinuous list of all items in the array
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

void flexible_array::printMatrix() { // Assuming the matrix is storing bools, a square matrix is printed, displaying zeros/false as O and ones/true as X
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