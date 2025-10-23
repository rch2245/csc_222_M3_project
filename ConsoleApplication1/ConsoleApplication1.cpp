#include "NumberArray.h"
#include "Date.h"
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

// Date class demonstration
void testDateClass()
{
    std::cout << "\n========================================" << std::endl;
    std::cout << "      DATE CLASS DEMONSTRATION" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    // Test default constructor
    std::cout << "Test default constructor: ";
    Date date1;
    std::cout << date1.printFormat1() << std::endl;
    std::cout << std::endl;
    
    // Test constructor with valid date
    std::cout << "Test constructor with valid date: ";
    Date date2(2, 28, 2009);
    std::cout << date2.printFormat1() << std::endl;
    std::cout << std::endl;
    
    // Test constructor with invalid month
    std::cout << "Test constructor with invalid month (45, 2, 2009): ";
    Date date3(45, 2, 2009);
    std::cout << date3.printFormat1() << std::endl;
    std::cout << std::endl;
    
    // Test constructor with invalid day (Feb 29 in non-leap year)
    std::cout << "Test constructor with invalid day (2/29/2009): ";
    Date date4(2, 29, 2009);
    std::cout << date4.printFormat1() << std::endl;
    std::cout << std::endl;
    
    // Test setDate with bad month
    std::cout << "Test setDate with bad month (13): ";
    Date date5;
    date5.setDate(13, 1, 2009);
    std::cout << date5.printFormat1() << std::endl;
    std::cout << std::endl;
    
    // Test setDate with bad day (April 31)
    std::cout << "Test setDate with bad day (4, 31, 2009): ";
    Date date6;
    date6.setDate(4, 31, 2009);
    std::cout << date6.printFormat1() << std::endl;
    std::cout << std::endl;
    
    // Test for leap year with bad date (Feb 29, 2009)
    std::cout << "Test for leap year with bad date (2/29/2009): ";
    Date date7(2, 29, 2009);
    std::cout << date7.printFormat1() << std::endl;
    std::cout << std::endl;
    
    // Test for leap year with good date (Feb 29, 2008)
    std::cout << "Test for leap year with good date (2/29/2008): ";
    Date date8(2, 29, 2008);
    std::cout << date8.printFormat1() << std::endl;
    std::cout << std::endl;
    
    // Test the print formats
    std::cout << "Test the print formats:" << std::endl;
    std::cout << std::endl;
    std::cout << date8.printFormat2() << std::endl;
    std::cout << date8.printFormat3() << std::endl;
    std::cout << std::endl;
    
    // Additional tests
    std::cout << "----- Additional Tests -----" << std::endl;
    std::cout << std::endl;
    
    // Test accessors
    Date date9(12, 25, 2021);
    std::cout << "Testing accessors for date: " << date9.printFormat1() << std::endl;
    std::cout << "Month: " << date9.getMonth() << std::endl;
    std::cout << "Day: " << date9.getDay() << std::endl;
    std::cout << "Year: " << date9.getYear() << std::endl;
    std::cout << std::endl;
    
    // Test leap year functions
    std::cout << "Is 2008 a leap year? " << (date8.isLeapYear() ? "Yes" : "No") << std::endl;
    std::cout << "Is 2009 a leap year? " << (date2.isLeapYear() ? "Yes" : "No") << std::endl;
    std::cout << "Is 2000 a leap year? " << (date9.isLeapYear(2000) ? "Yes" : "No") << std::endl;
    std::cout << "Is 1900 a leap year? " << (date9.isLeapYear(1900) ? "Yes" : "No") << std::endl;
    std::cout << std::endl;
    
    // Test last day of month
    std::cout << "Last day of February 2008: " << date8.lastDay() << std::endl;
    std::cout << "Last day of February 2009: " << date2.lastDay() << std::endl;
    std::cout << "Last day of December 2021: " << date9.lastDay() << std::endl;
    std::cout << "Last day of April 2021: " << date9.lastDay(4, 2021) << std::endl;
    std::cout << std::endl;
    
    // Test all three print formats for different dates
    std::cout << "Christmas 2021 in three formats:" << std::endl;
    std::cout << "Format 1: " << date9.printFormat1() << std::endl;
    std::cout << "Format 2: " << date9.printFormat2() << std::endl;
    std::cout << "Format 3: " << date9.printFormat3() << std::endl;
    std::cout << std::endl;
    
    std::cout << "Date class demonstration complete!\n" << std::endl;
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
        std::cout << "2. Date Class Demonstration" << std::endl;
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
