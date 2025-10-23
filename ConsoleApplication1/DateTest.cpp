#include "Date.h"
#include <iostream>

int main()
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
    
    return 0;
}

