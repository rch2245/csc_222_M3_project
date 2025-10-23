#include "NumberArray.h"
#include <iostream>
#include <iomanip>
#include <random>

// Function to test NumberArray class
void testNumberArray()
{
    std::cout << "\n========================================" << std::endl;
    std::cout << "   NUMBER ARRAY CLASS DEMONSTRATION" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    // Set precision for output
    std::cout << std::fixed << std::setprecision(1);
    
    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(1.0, 100.0);
    
    std::cout << "----- Test constructors -----" << std::endl;
    
    // Test default constructor
    NumberArray defaultArray;
    std::cout << "From default constructor: Array of size 10" << std::endl;
    defaultArray.printArray();
    std::cout << std::endl;
    
    // Test constructor with parameters
    NumberArray paramArray(15);
    std::cout << "From constructor with parameters: Array of size 15" << std::endl;
    paramArray.printArray();
    std::cout << std::endl;
    
    std::cout << "----- Test mutator -----" << std::endl;
    
    // Fill array with random numbers
    for (int i = 0; i < 15; i++)
    {
        paramArray.setNumber(i, dis(gen));
    }
    
    std::cout << "Array filled with numbers:" << std::endl;
    paramArray.printArray();
    std::cout << std::endl;
    
    // Test out of bounds index
    std::cout << "Trying to set a number with an out of bounds index (20):" << std::endl;
    paramArray.setNumber(20, 99.9);
    std::cout << std::endl;
    
    std::cout << "----- Test accessors -----" << std::endl;
    
    // Test valid access
    std::cout << "Access item at index 5: " << paramArray.getNumber(5) << std::endl;
    std::cout << std::endl;
    
    // Test out of bounds access
    std::cout << "Access item at index 20 (out of bounds): " << paramArray.getNumber(20) << std::endl;
    std::cout << std::endl;
    
    // Test minimum, maximum, and average
    std::cout << "The minimum value in the array is: " << paramArray.getMinimum() << std::endl;
    std::cout << "The maximum value in the array is: " << paramArray.getMaximum() << std::endl;
    std::cout << "The average of the values in the array is: " << paramArray.getAverage() << std::endl;
    std::cout << std::endl;
    
    std::cout << "NumberArray demonstration complete!\n" << std::endl;
    
    // Destructors will be called automatically when objects go out of scope
}

// Placeholder for future Date class demonstration
void testDateClass()
{
    std::cout << "\n========================================" << std::endl;
    std::cout << "      DATE CLASS DEMONSTRATION" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    std::cout << "Date class not yet implemented." << std::endl;
    std::cout << "This will be added in a future project.\n" << std::endl;
}

// Main function with menu system
int main()
{
    int choice;
    
    do
    {
        // Display menu
        std::cout << "\n============================================" << std::endl;
        std::cout << "      CSC 223 M3 PROJECT MENU" << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << "1. NumberArray Class Demonstration" << std::endl;
        std::cout << "2. Date Class Demonstration (Future)" << std::endl;
        std::cout << "3. Exit Program" << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << "Enter your choice (1-3): ";
        std::cin >> choice;
        
        // Validate input
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "\nInvalid input! Please enter a number between 1 and 3.\n" << std::endl;
            continue;
        }
        
        // Process menu choice
        switch (choice)
        {
        case 1:
            testNumberArray();
            break;
            
        case 2:
            testDateClass();
            break;
            
        case 3:
            std::cout << "\nThank you for using the CSC 223 M3 Project!" << std::endl;
            std::cout << "Exiting program...\n" << std::endl;
            break;
            
        default:
            std::cout << "\nInvalid choice! Please enter a number between 1 and 3.\n" << std::endl;
            break;
        }
        
    } while (choice != 3);
    
    return 0;
}
