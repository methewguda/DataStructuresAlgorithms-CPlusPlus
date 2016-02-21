#include "Date.h"
#include <iostream>
using std::cout;

#include "utilities.h"
using Scobey::Pause;

void testEquals(const Date& d1, const Date& d2, const string& expect);
void testBefore(const Date& d1, const Date& d2, const string& expect);

int main()
{
    Date d1;
    Date d2(2000);
    Date d3(2010, 4);
    Date d4(1900, 11, 7);
    Date d5(-213, 30, 85);  // used in setter tests below

    //cout << "Constructor & Print Tests:";
    //cout << "\n\tShould be 2014-01-01: "; d1.print();
    //cout << "\n\tShould be 2000-01-01: "; d2.print();
    //cout << "\n\tShould be 2010-04-01: "; d3.print();
    //cout << "\n\tShould be 1900-11-07: "; d4.print();
    //cout << "\n\n";

    //Pause();

    //cout << "Getter Tests:";
    //cout << "\n\tShould be 1900: "      << d4.getYear();
    //cout << "\n\tShould be   11:   "    << d4.getMonth();
    //cout << "\n\tShould be    7:    "   << d4.getDay();
    //cout << "\n\tShould be 2010: "      << d3.getYear();
    //cout << "\n\n";

    //Pause();

    //cout << "Leap Year Tests:";
    //cout << "\n\tShould be 1: " << Date::isLeapYear(1960);
    //cout << "\n\tShould be 0: " << Date::isLeapYear(1962);
    //cout << "\n\tShould be 0: " << Date::isLeapYear(1900);
    //cout << "\n\tShould be 1: " << Date::isLeapYear(2000);
    //cout << "\n\n";

    //Pause();

    //cout << "Month Tests:";
    //cout << "\n\tShould be 31: " << Date::daysInMonth(1);
    //cout << "\n\tShould be 29: " << Date::daysInMonth(2, 1960);
    //cout << "\n\tShould be 28: " << Date::daysInMonth(2, 1963);
    //cout << "\n\tShould be 28: " << Date::daysInMonth(2);
    //cout << "\n\tShould be 31: " << Date::daysInMonth(3);
    //cout << "\n\tShould be 30: " << Date::daysInMonth(4);
    //cout << "\n\tShould be 31: " << Date::daysInMonth(5);
    //cout << "\n\tShould be 30: " << Date::daysInMonth(6);
    //cout << "\n\tShould be 31: " << Date::daysInMonth(7);
    //cout << "\n\tShould be 31: " << Date::daysInMonth(8);
    //cout << "\n\tShould be 30: " << Date::daysInMonth(9);
    //cout << "\n\tShould be 31: " << Date::daysInMonth(10);
    //cout << "\n\tShould be 30: " << Date::daysInMonth(11);
    //cout << "\n\tShould be 31: " << Date::daysInMonth(12);
    //cout << "\n\tDon't care(!): " << Date::daysInMonth(13);
    //cout << "\n\n";

    //Pause();

    //cout << "Setter Tests:";
    //d1.set(1904, 10, 10);
    //cout << "\n\tShould be 1904-10-10: "; d1.print();
    //d1.set(1905, 11, 40);
    //cout << "\n\tShould be 1904-10-10: "; d1.print();
    //d1.set(1906, 15, 11);
    //cout << "\n\tShould be 1904-10-10: "; d1.print();
    //d1.set(1907, 3, 31);
    //cout << "\n\tShould be 1907-03-31: "; d1.print();
    //d1.set(1908, 4, 31);
    //cout << "\n\tShould be 1907-03-31: "; d1.print();
    //d1.set(1909, 2, 29);
    //cout << "\n\tShould be 1907-03-31: "; d1.print();
    //d1.set(1912, 2, 29);
    //cout << "\n\tShould be 1912-02-29: "; d1.print();
    //d1.set(d4.getYear(), d4.getMonth(), d4.getDay());
    //cout << "\n\tShould be 1900-11-07: "; d1.print();
    //cout << "\nSetter + Constructor Test:";
    //cout << "\n\tShould be 2014-01-01: "; d5.print();
    //cout << "\n\n";

    //Pause();

    //cout << "Equals Tests:";
    //testEquals(Date(1950, 10, 10), Date(1950, 10, 10), "true");
    //testEquals(Date(1950, 10, 20), Date(1950, 10, 15), "false");
    //testEquals(Date(1950,  9, 20), Date(1950, 10, 20), "false");
    //testEquals(Date(1950, 10, 20), Date(1951, 10, 20), "false");
    //cout << "\n\n";

    //Pause();

    cout << "Before Tests:";
    testBefore(Date(1950, 10, 10), Date(1950, 10, 10), "false");
    testBefore(Date(1950, 10, 10), Date(1950, 10,  9), "false");
    testBefore(Date(1950, 10, 10), Date(1950,  9, 11), "false");
    testBefore(Date(1950, 10, 10), Date(1850, 11, 11), "false");
    testBefore(Date(1950, 10, 15), Date(1950, 10, 20), "true");
    testBefore(Date(1950, 10, 20), Date(1950, 11, 10), "true");
    testBefore(Date(1950, 10, 20), Date(1951,  5,  1), "true");
    cout << "\n\n";

    Pause();
}

void testEquals(const Date& d1, const Date& d2, const string& expect)
{
    cout << "\n\t";
    d1.print();
    cout << " equals ";
    d2.print();
    cout << " should be " << expect << ": ";
    cout << (d1.equals(d2) ? "true" : "false");
}

void testBefore(const Date& d1, const Date& d2, const string& expect)
{
    cout << "\n\t";
    d1.print();
    cout << " before ";
    d2.print();
    cout << " should be " << expect << ": ";
    cout << (d1.before(d2) ? "true" : "false");
}
