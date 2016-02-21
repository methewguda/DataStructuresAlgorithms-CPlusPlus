/*
include and using section
*/
#include <iostream>         //For access to input output stream
#include <iomanip>          //For access to input output manipulators
#include "Date.h"           //For access to Date header file

using namespace std;

/*
function defination section
*/

//defination section for constructors 
Date::Date()
{

}

Date::Date(int y)
{
    if (y > 0)
    {
        year = y;
        month = 1;
        day = 1;
    }
    else
    {
        year = 2014;
        month = 1;
        day = 1;
    }
}

Date::Date(int y, int m)
{
    if (y > 0 && m <= 12)
    {
        year = y;
        month = m;
        day = 1;
    }
    else
    {
        year = 2014;
        month = 1;
        day = 1;
    }
}

Date::Date(int y, int m, int d)
{
    int value = daysInMonth(m,y);

    if (y > 0 && m <= 12 && d <= value)
    {
        year = y;
        month = m;
        day = d;
    }
    else
    {
        year = 2014;
        month = 1;
        day = 1;
    }
}

Date::~Date(){}

//defination section for set function
bool Date::set (int y, int m, int d)
{
    int value = daysInMonth(m,y);

    if (y > 0 && m <= 12 && d <= value)
    {
        year = y;
        month = m;
        day = d;
    }

    return false;
}

//defination section for print function
void Date::print () const
{
    cout << year << "-" 
        << setw(2) << setfill('0') << month << "-" 
        << setw(2) << setfill('0') << day;
}

//defination section for getYear function
int Date::getYear() const
{
    return year;
}

//defination section for getMonth function
int Date::getMonth() const
{
    return month;
}

//defination section for getDay function
int Date::getDay() const 
{
    return day;
}

//defination section for isLeapYear function
bool Date::isLeapYear(int y)
{
    if ((y % 4 == 0 && y % 100 != 0) || ( y % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//defination section for dayInMonth function
int Date::daysInMonth(int m, int y)
{
    if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        return 30;
    }
    else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        return 31;
    }
    else if (m == 2)
    {
        bool value = isLeapYear(y);

        if (value != 0)
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    else
    {
        return 0;
    }
}

//defination section for equal function
bool Date::equals(Date other) const
{
    if(getYear() == other.getYear() && getMonth() == other.getMonth() && getDay() == other.getDay())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//defination section for before function
bool Date::before(Date other) const
{
    if (getYear() > other.getYear())
    {
        return false;
    }
    else
    {
        if (getMonth() <= other.getMonth())
        {
            if (getDay() < other.getDay())
            {
                return true;
            }
            else
            {
                return false;
            }

        }
        else
        {
            return false;
        }
    }
}