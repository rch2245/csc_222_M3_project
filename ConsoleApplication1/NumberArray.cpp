#include "NumberArray.h"
#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <numeric>

// Define static const member - must be defined outside the class
const double NumberArray::DEFAULT_VALUE = 10000.0;

// Constructor
NumberArray::NumberArray(int size) : size(size)
{
    array = new double[size];
    // Initialize all elements to 0
    for (int i = 0; i < size; i++)
    {
        array[i] = 0.0;
    }
}

// Destructor
NumberArray::~NumberArray()
{
    std::cout << "The destructor is running" << std::endl;
    delete[] array;
}

// Store a number in any element of the array
void NumberArray::setNumber(int index, double value)
{
    if (index < 0 || index >= size)
    {
        std::cout << "The index is out of the bounds of the array, number not stored" << std::endl;
        return;
    }
    array[index] = value;
}

// Retrieve a number from any element of the array
double NumberArray::getNumber(int index)
{
    if (index < 0 || index >= size)
    {
        std::cout << "The Index is out of the bounds of the array, returning default" << std::endl;
        return DEFAULT_VALUE;
    }
    return array[index];
}

// Return the highest value stored in the array
double NumberArray::getMaximum()
{
    if (size == 0)
        return 0.0;
    
    double max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

// Return the lowest value stored in the array
double NumberArray::getMinimum()
{
    if (size == 0)
        return 0.0;
    
    double min = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
            min = array[i];
    }
    return min;
}

// Return the average of all the numbers stored in the array
double NumberArray::getAverage()
{
    if (size == 0)
        return 0.0;
    
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum / size;
}

// Print member function to display the values in the array
void NumberArray::printArray()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << std::fixed << std::setprecision(1) << array[i];
        if (i < size - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

