#pragma once

// Flexible_array
// Two dimensional array which is allocated on the heap
// Initialize array size via constructor parameters and access items via getItem(x, y)
// or set items via setItem(x, y, input)

// Value Table
//   0 = Square is false              (Color = White)
//   1 = Square is true               (Color = Green)
//   2 = Square is false but selected (Color = Blue)
//   3 = Square is true  but selected (Color = Blue)

struct flexible_array {
    unsigned int size_x; // Width of Array
    unsigned int size_y; // Height of Array

    int* pAry; // Pointer to array on heap, Do Not Touch!

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
    int getItem(unsigned int ix, unsigned int iy) const;

    // Sets items at given index
    void setItem(unsigned int ix, unsigned int iy, int input);

    // Returns array size_X
    unsigned int getSizeX() const;

    // Returns array size_Y
    unsigned int getSizeY() const;

    // Initialize array with zeros
    void clearArray();


    // ------------------------------------------------------------
    // Scary Pointer Functions!

    int* returnPointerToNewArray();

    int* returnPointerToNewArray(unsigned int ix, unsigned int iy);

    void swapPointers(int* newArray);


    // ------------------------------------------------------------
    // Debugging

    bool logErrors;


    // -----------------------------------------------------------   
    // DEPRECATED DEBUG FUNCTIONS !!! ONLY WORKS WITH INTEGERS !!!
  
    // Prints a countinuous list of all items in the array
    void traverse() const;

    // Assuming the array is storing bools, a square matrix is printed, displaying zeros/false as O and ones/true as X
    void printMatrix() const;

};
