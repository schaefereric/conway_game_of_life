#pragma once

struct flexible_array {
    unsigned int size_x; // Width of Array
    unsigned int size_y; // Height of Array

    int* pAry; // Pointer to array on heap

    int getSingleIndex(unsigned int ix, unsigned int iy) const;  // Takes two index numbers (x and y) and returns single array index number

    flexible_array(unsigned int ix, unsigned int iy);

    flexible_array();

    ~flexible_array();

    void reInitialize(unsigned int ix, unsigned int iy);

    int getItem(unsigned int ix, unsigned int iy) const;

    void setItem(unsigned int ix, unsigned int iy, int input);

    unsigned int getSizeX() const;

    unsigned int getSizeY() const;

    void clearArray();

    void traverse();

    void printMatrix();

};
