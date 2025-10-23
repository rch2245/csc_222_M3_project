#include "pch.h"
#include "Date.h"
#include <string>
#include <iostream>

// Constructor
Date::Date(int m, int d, int y)
{
    // Use setDate to validate and set the date
    setDate(m, d, y);
}

// Private helper function to validate date
bool Date::isValidDate(int m, int d, int y)
{
    // Check month validity
    if (m < 1 || m > 12)
        return false;

    // Check day validity
    if (d < 1 || d > lastDay(m, y))
        return false;

    // Year should be positive
    if (y < 1)
        return false;

    return true;
}

// Mutator function
void Date::setDate(int m, int d, int y)
{
    // Validate month first
    if (m < 1 || m > 12)
    {
        std::cout << "Month invalid" << std::endl;
        month = 1;
        day = 1;
        year = 1900;
        return;
    }

    // Validate day
    if (d < 1 || d > lastDay(m, y))
    {
        std::cout << "Day invalid" << std::endl;
        month = 1;
        day = 1;
        year = 1900;
        return;
    }

    // If all valid, set the date
    month = m;
    day = d;
    year = y;
}

// Leap year function (no parameters)
bool Date::isLeapYear() const
{
    return isLeapYear(year);
}

// Leap year function (with year parameter)
bool Date::isLeapYear(int year) const
{
    // A year is a leap year if:
    // 1. It is divisible by 4 AND not divisible by 100
    // OR
    // 2. It is divisible by 400
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

// Last day of month (no parameters)
int Date::lastDay() const
{
    return lastDay(month, year);
}

// Last day of month (with parameters)
int Date::lastDay(int month, int year) const
{
    switch (month)
    {
    case 1:  // January
    case 3:  // March
    case 5:  // May
    case 7:  // July
    case 8:  // August
    case 10: // October
    case 12: // December
        return 31;

    case 4:  // April
    case 6:  // June
    case 9:  // September
    case 11: // November
        return 30;

    case 2:  // February
        if (isLeapYear(year))
            return 29;
        else
            return 28;

    default:
        return 0; // Invalid month
    }
}

// Print format 1: 12/25/2021
std::string Date::printFormat1() const
{
    return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
}

// Print format 2: December 25, 2021
std::string Date::printFormat2() const
{
    std::string monthNames[] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    return monthNames[month] + " " + std::to_string(day) + ", " + std::to_string(year);
}

// Print format 3: 25 December 2021
std::string Date::printFormat3() const
{
    std::string monthNames[] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    return std::to_string(day) + " " + monthNames[month] + " " + std::to_string(year);
}

