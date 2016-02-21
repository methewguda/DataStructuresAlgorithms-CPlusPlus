/**
@file Date.h
Assignment: 04
@author Guda:Methew:A00381751:csc34134
@version 1.0
@brief A date consists of a year, a month, and a day, which can be
represented with integer values. then prints out the date to cout
in the YYYY-MM-DD (SI) format.
@due date Thursday, May 22, 2014
@date Thursday, May 22, 2014
*/

/*
Author self-assessment statement:
This program is complete and working according to spcecifications,
according to the best of my knowledge. I have problem with the last
part of the program where before(Date other) checks the two date and
return whether that comparsion is true or false. last two values do
not return according to specification.
*/

// include guard beginning -- prevent double definition of class Date
#ifndef DATE_H
#define DATE_H

class Date
{
    /**<
    this class consists of a year, a month, and a day, which can be
    represented with integer values. then prints out the date to cout
    in the YYYY-MM-DD (SI) format, calculate Leap Year, calculate days
    in a month, compare two dates.
    */

public:

    Date();
    /**<
    this is a default constructor for Date class
    @post
    -# <tt> year </tt> is initialized to 2014
    -# <tt> month </tt> is initialized to 01
    -# <tt> day </tt> is initialized to 01
    */

    Date(int y);
    /**<
    this is a constructor for Date class with one parameter
    @param y integer variable to pass year value
    @pre
    -# <tt> y </tt> has to be a positive integer variable
    @post
    -# <tt> year </tt> is initialized with passed value
    -# <tt> month </tt> is initialized to 01
    -# <tt> day </tt> is initialized to 01
    */

    Date(int y, int m);
    /**<
    this is a constructor for Date class with two parameter
    @param y integer variable to pass year value
    @param m integer variable to pass month value
    @pre
    -# <tt> y </tt> has to be a positive integer variable
    -# <tt> m </tt> has to be a positive integer variable
    @post
    -# <tt> year </tt> is initialized with passed value
    -# <tt> month </tt> is initialized with passed value
    -# <tt> day </tt> is initialized to 01
    */

    Date(int y, int m, int d);
    /**<
    this is a constructor for Date class with three parameter
    @param y integer variable to pass year value
    @param m integer variable to pass month value
    @param d integer variable to pass day value
    @pre
    -# <tt> y </tt> has to be a positive integer variable
    -# <tt> m </tt> has to be a positive integer variable
    -# <tt> d </tt> has to be a positive integer variable
    @post
    -# <tt> year </tt> is initialized with passed value
    -# <tt> month </tt> is initialized with passed value
    -# <tt> day </tt> is initialized with passed value
    */

    ~Date();
    /**<
    this is a destructor for Date class
    */

    bool set(int y, int m, int d);
    /**<
    sets the date to the given values
    @return <tt> true </tt> if they are appropriate,
    <tt> false </tt> if they're not
    @param y sets the value of year
    @param m sets the value of month
    @param d sets the value of day
    @pre
    -# <em> y </em> contains a positive integer a parameter
    -# <em> m </em> contains a positive integer a parameter
    -# <em> d </em> contains a positive integer a parameter
    @post
    -# <em> y </em> sets the value of the year
    -# <em> m </em> sets the value of the month
    -# <em> d </em> sets the value of the day
    */

    void print() const;
    /**<
    prints the date to cout in the YYYY-MM-DD (SI) format
    @return <tt> void </tt>
    @post
    -print the date in the YYYY-MM-DD (SI) format to console window.
    */

    int getYear() const;
    /**<
    returns the year
    @return <tt> year </tt>
    @post
    -retun the value of the year in YYYY format.
    */

    int getMonth() const;
    /**<
    returns the month
    @return <tt> month </tt>
    @post
    -return the value of the month in MM format. 
    A positive integer from 1 to 12. value does not exceed 12.
    */

    int getDay() const;
    /**<
    returns the day
    @return <tt> day </tt>
    @post
    -return the value of the day in DD format. 
    A positive integer from 1 to 31. value does not exceed 31.
    */

    bool equals(Date other) const;
    /**<
    Calculate that given two dates are equal or not
    @return <tt> true </tt> if given dates are equal,
    <tt> false </tt> if given dates are not  equal
    @param other a Date type object
    @pre
    -# object has to be Date type
    -# obect has to be constant
    @post
    -# compare two dates and return <tt> true </tt> if given dates are equal,
    <tt> false </tt> if given dates are not  equal
    */

    bool before(Date other) const;
    /**<
    Claculate that first date is the before date of the second date or not.
    @return <tt> true </tt> if first date is before date of second date,
    <tt> false </tt> if first date isnot before date of second date.
    @param other a Date type object
    @pre
    -# object has to be Date type
    -# obect has to be constant
    @post
    -# compare two dates and return <tt> true </tt> if first date is 
    before date of second date, <tt> false </tt> if first date is not 
    before date of second date.
    */

    static bool isLeapYear(int y);
    /**<
    return that is the year is leap year or not
    @return <tt> 1 </tt> if the year is leap year,
    <tt> 0 </tt>  if the year is not leap year
    @param y an positive integer variable
    @pre
    -# <tt> y </tt> has to be a positive integer variable
    -# function has to be a static function
    @post
    -# return <tt> 1 </tt> if the year is leap year,
    <tt> 0 </tt>  if the year is not leap year
    */

    static int daysInMonth(int m, int y = 0);
    /**<
    return the number of the days in a specific month
    @return int the number of days in a month
    @param m an positive integer variable
    @param y an positive integer variable
    @pre
    -# <tt> m </tt> has to be a positive integer variable
    -# <tt> y </tt> is initialized to 0
    -# function has to be a static function
    @post
    -# calculate nad return the number of days in a month
    */

private:

    //private variables to handle year, month & day of a date
    int year;
    int month;
    int day;
};

// end of the include guard
#endif 