// File: NumberArray.h
// Author: CSC 223 Student
// Date: October 22, 2025
// 
// Description:
//     Header file for the NumberArray class. This class manages a dynamically
//     allocated array of floating-point numbers with operations for storing,
//     retrieving, and calculating statistical values.
// 
// Class Design:
//     - Separates interface (header) from implementation (.cpp file)
//     - Uses dynamic memory allocation for flexible array sizing
//     - Provides bounds checking for all array operations
//     - Includes statistical methods (min, max, average)

#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

class NumberArray
{
private:
    int size;                                    // Size of the array
    double* array;                               // Pointer to dynamically allocated array
    static const int MAX_SIZE = 10;              // Default array size
    static const double DEFAULT_VALUE;           // Default return value for invalid access

public:
    // Constructor: NumberArray
    // Creates a NumberArray object with the specified size (or default size).
    // Dynamically allocates memory for the array and initializes all elements to 0.0.
    // Parameters: size - number of elements in the array (default: 10)
    // Preconditions: size should be a positive integer
    // Postconditions: Memory is allocated and all elements initialized to 0.0
    NumberArray(int size = MAX_SIZE);
    
    // Destructor: ~NumberArray
    // Releases the dynamically allocated memory for the array and prints
    // a message confirming destructor execution.
    // Postconditions: Memory is deallocated and message displayed
    ~NumberArray();
    
    // Function: setNumber
    // Stores a value in the specified array element with bounds checking.
    // Parameters: index - array position (0 to size-1), value - number to store
    // If index is invalid, displays error message and doesn't modify array
    void setNumber(int index, double value);
    
    // Function: getNumber
    // Retrieves the value from the specified array element with bounds checking.
    // Parameters: index - array position (0 to size-1)
    // Returns: array value if valid, or DEFAULT_VALUE (10000.0) if invalid
    // If index is invalid, displays error message
    double getNumber(int index);
    
    // Function: getMinimum
    // Finds and returns the smallest value in the array.
    // Calculated on-demand to reflect current array contents.
    // Returns: minimum value, or 0.0 if array is empty
    double getMinimum();
    
    // Function: getMaximum
    // Finds and returns the largest value in the array.
    // Calculated on-demand to reflect current array contents.
    // Returns: maximum value, or 0.0 if array is empty
    double getMaximum();
    
    // Function: getAverage
    // Calculates and returns the arithmetic mean of all values in the array.
    // Calculated on-demand to reflect current array contents.
    // Returns: average value, or 0.0 if array is empty
    double getAverage();
    
    // Function: printArray
    // Displays all array elements on a single line, separated by spaces.
    // Values are formatted with 1 decimal place.
    void printArray();
};

#endif

