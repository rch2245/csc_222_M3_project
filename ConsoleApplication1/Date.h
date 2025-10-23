#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{
private:
    int month;
    int day;
    int year;

    // Private helper function for validation
    bool isValidDate(int m, int d, int y);

public:
    // Constructors
    Date(int m = 1, int d = 1, int y = 1900);

    // Mutator
    void setDate(int m, int d, int y);

    // Accessors (inline simple functions)
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    // Leap year functions
    bool isLeapYear() const;
    bool isLeapYear(int year) const;

    // Last day of month functions
    int lastDay() const;
    int lastDay(int month, int year) const;

    // Print functions
    std::string printFormat1() const;  // 12/25/2021
    std::string printFormat2() const;  // December 25, 2021
    std::string printFormat3() const;  // 25 December 2021
};

#endif

