#pragma once

struct flexible_array {
    unsigned int size_x; // Width of Array
    unsigned int size_y; // Height of Array

    bool* pAry; // Pointer to array on heap

    // Takes two index numbers (x and y) and returns single array index number
    int getSingleIndex(unsigned int ix, unsigned int iy) const; 

    // Recommended constructor, enter field size in parameters
    flexible_array(unsigned int ix, unsigned int iy);

    // Default constructor, initializes array as 2*2 matrix
    flexible_array();

    // Destructor, deallocates memory on heap
    ~flexible_array();

    // Resize array
    void reInitialize(unsigned int ix, unsigned int iy);

    // Returns item at given index
    bool getItem(unsigned int ix, unsigned int iy) const;

    // Sets items at given index
    void setItem(unsigned int ix, unsigned int iy, bool input);

    // Returns array size_X
    unsigned int getSizeX() const;

    // Returns array size_Y
    unsigned int getSizeY() const;

    // Initialize array with zeros
    void clearArray();


    // ------------------------------------------------------------
    // Scary Pointer Functions!

    bool* returnPointerToNewArray();

    bool* returnPointerToNewArray(unsigned int ix, unsigned int iy);

    void swapPointers(bool* newArray);


    // -----------------------------------------------------------   
    // DEPRECATED DEBUG FUNCTIONS !!! ONLY WORKS WITH INTEGERS !!!
  
    // Prints a countinuous list of all items in the array
    void traverse() const;

    // Assuming the array is storing bools, a square matrix is printed, displaying zeros/false as O and ones/true as X
    void printMatrix() const;

};
