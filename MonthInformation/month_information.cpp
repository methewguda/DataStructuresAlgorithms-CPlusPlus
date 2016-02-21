/**
@file month_information.cpp
Assignment: 07
@author Guda:Methew:A00381751:csc34134
@version 1.0
@brief this program gives information about the months of the year
in western (Gregorian) calendar. It repeatedly asks for the name of
a month, then reports which month of the year it is, and how many 
days it has. For February it reports both the usual length and 
the leap year length.
@due date Wednesday, June 4, 2014
@date Wednesday, June 4, 2014
*/

/*
Author self-assessment statement:
This program is complete and working according to spcecifications,
according to the best of my knowledge.
*/

/*
include & using section
*/
#include <iostream>     //For access to input & output stream
#include <string>       //For access to string class
#include <stdexcept>    //For access to standard exception class
#include "utilities.h"  //For access to use utilities package

using namespace std;    //For access to using standard namespace
using namespace Scobey; //For access to using Scoobey namespace

/*
declaration section for prototypes
*/

int MonthNameToNumber(const string& name);
/**<
Returns the number of the month (1 to 12) named in the given string
@return month number a positive integer value
@param name constant and referenced string variable as month name
@pre
-# name contains the name of the month
-# value must be constant and referenced
@post
-# checks the month name
-# returns the month number
-# if the name is not inside the fuction, 
   then it throws an invalid argumant excception
*/

int daysInMonth(int month, bool isLeapYear);
/**<
Returns the number of days in the given month; 
for leap year if isLeapYear is true.
@return days number in month a positive integer value
@param month a positive intiger number that is returnde from 
       MonthNameToNumber method.
       isLeapYear a boolean value to decide weather is it leap year or not
@pre
-# month must be a positive integer value and between 1 to 12
-# isLeapYear must be a boolean value and defaults to false
@post
-# checks the months number
-# if the month number is 4 or 6 or 9 or 11, then it will return 30
-# else if the month number is 1 or 3 or 5 or 7 or 8 or 10 or 12,
   then it will return 31
-# else if the month number is 2, then will check is the leap year is 
   true or false
-# if the leap year is true it will return 29
-# else it will return 28
*/

/*
Main Function section
*/
int main ()
{
    string monthName;

    ReadString("Enter the name of a month: ", monthName);

    do
    {
        try
        {
            int monthValue = MonthNameToNumber(monthName);

            cout << endl << endl << monthName << " is month #" 
                << monthValue << " in our calendar." << endl;
            cout << "It has " ;

            int regularYear = daysInMonth(monthValue, false);
            int leapYear = daysInMonth(monthValue, true);

            if (regularYear != leapYear)
            {
                cout << regularYear
                    << " days in a regular year, and "
                    << leapYear
                    << " days in a leap year.";
            }
            else
            {
                cout << regularYear
                    << " days.";
            }

            cout<<endl << endl;
            cout << "Enter the name of a month, or press enter to quit: ";
            getline(cin, monthName);
        }
        catch(const invalid_argument& ia)
        {
            cerr << "\'" << ia.what() << "\' isn't the name of a month.";
            cout<< endl << endl;
            cout << "Enter the name of a month, or press enter to quit: ";
            getline(cin, monthName);
        }
    }while (!monthName.empty());

    Pause();
    return 0;
}
//end of main function section

/*
defination section for prototypes
*/

//definition for MonthNameToNumber method
int MonthNameToNumber(const string& name)
{
    if (name == "January")
    {
        return 1;
    }
    else if (name == "February")
    {
        return 2;
    }
    else if (name == "March")
    {
        return 3;
    }
    else if (name == "April")
    {
        return 4;
    }
    else if (name == "May")
    {
        return 5;
    }
    else if (name == "June")
    {
        return 6;
    }
    else if (name == "July")
    {
        return 7;
    }
    else if (name == "August")
    {
        return 8;
    }
    else if (name == "September")
    {
        return 9;
    }
    else if (name == "October")
    {
        return 10;
    }
    else if (name == "November")
    {
        return 11;
    }
    else if (name == "December")
    {
        return 12;
    }
    else
    {
        throw invalid_argument (name);
    }
}

//definition for daysInMonth method
int daysInMonth(int month, bool isLeapYear = false)
{
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7
        || month == 8 || month == 10 || month == 12)
    {
        return 31;
    }
    else if (month == 2)
    {
        if (isLeapYear != false)
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