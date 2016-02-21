///////////////////////////////////////////////////////////////////////
// identification section
///////////////////////////////////////////////////////////////////////
/**
@file count_return.cpp
Assignment: 03
@author Guda:Methew:A00381751:CSCI2341
Description: This is a coin change machine. User input the amount
between $0.01 and $4.99. This machine will count and print how many
coin changes may needed.
@due date: Tuesday, 20 May 2014
@date: Tuesday, 20 May 2014
@version 1.0
*/

///////////////////////////////////////////////////////////////////////
// self-assessment section
///////////////////////////////////////////////////////////////////////
/*
Author self-assessment statement:
This program is complete and working according to spcecifications,
according to the best of my knowledge. However there is an issuue
if the user enter an amount greater than about $21 million, 
the program may end.
*/

///////////////////////////////////////////////////////////////////////
// includes and usings section
///////////////////////////////////////////////////////////////////////
#include <iostream>     //For access to input output stream
#include <iomanip>      //For access to input output manipulators
#include "utilities.h"  //For access to utilities packege

using namespace std;
using namespace Scobey;

///////////////////////////////////////////////////////////////////////
// constants section
///////////////////////////////////////////////////////////////////////
const double TOONIE  = 2.00;
const double LOONIE  = 1.00;
const double QUARTER = 0.25;
const double DIME    = 0.10;
const double NICKEL  = 0.05;


///////////////////////////////////////////////////////////////////////
// function prototypes section
///////////////////////////////////////////////////////////////////////

bool GetAmount
(
    double& amount     // out
);
/**<
 *  Gets the amount in dollars and cents (less than $5.00) from the user.
 *  @return <tt>true</tt> if the amount entered is positive; 
            <tt>false<tt> otherwise.
 *  @param  amount  the variable the amount entered is to be returned in.
 *  @pre    cin is not in a fail state.
 *  @post
 *   -# amount is a multiple of 0.01 (1 cent)
 *   -# cin is empty
 *   -# amount has been set to a value between 0.01 and 4.99 
          and <tt>true</tt> is returned
 *      OR amount is a value &lt;= 0.00 and <tt>false</tt> has been returned
 */

double roundTo
(
    double amount,  // in
    double factor   // in
);
/**<
 *  Returns amount rounded off to the nearest multiple of factor.
 *  @return amount rounded off to the nearest integer multiple of factor.
 *  @param  amount  the amount to be rounded off.
 *  @param  factor  the number to find a multiple of.
 *  @pre    factor != 0.0
 *  @post   no side effects
 */

void ShowChange
(
    double amount   // in
);
/**<
 *  Prints a table showing the amount of coins required 
 *  to make the given amount in change.
 *  @param  amount  the amount of change to be made.
 *  @pre    none
 *  @post   a table has been printed as follows:
 *   - a title showing the amount to make change for (in dollars)
 *   - a line each for toonies, loonies, quarters, dimes, and nickels,
 *     showing the face value of the coin (in dollars),
 *     the number of that coin required,
 *     and the total value of those coins, and
 *   - a message reminding the user that change amounts are rounded 
 *     to the nearest 5 cents.
 */

void GetAndShowCoins
(
    double coinValue,   // in
    int&   coinCount,   // out
    double& amount      // in-out
);
/**<
 *  Calculates how many coins of the given value are required for change,
 *  and prints one line of a table showing the amount of coins required
 *  to make the given amount in change.
 *  @param  coinValue  the value of the coin to be used in making change.
 *  @param  coinCoint  a variable to hold the number of coins required.
 *  @param  amount     a variable tracking the amount of change required.
 *  @pre
 *   -# coinValue > 0.00
 *   -# amount >= 0.00
 *  @post
 *   -# coinCount has been set to the number of coinValue coins required 
 *      to make change for amount.
 *   -# amount has been reduced by the value of those coins.
 *   -# a formatted line has been printed
 *      showing the face value of the coin (in dollars),
 *      the number of that coin required,
 *      and the total value of those coins.
 */

void GetCoins
(
    double coinValue,   // in
    int&   coinCount,   // out
    double& amount      // in-out
);
/**<
 *  Calculates how many coins of the given value are required for change.
 *  @param  coinValue  the value of the coin to be used in making change
 *  @param  coinCoint  a variable to hold the number of coins required
 *  @param  amount     a variable tracking the amount of change required
 *  @pre
 *   -# coinValue > 0.00
 *   -# amount >= 0.00
 *  @post
 *   -# coinCount has been set to the number of coinValue coins 
 *      required to make change for amount
 *   -# amount has been reduced by the value of those coins
 */

void ShowCoins
(
    double coinValue,   // in
    int    coinCount    // in
);
/**<
 *  Prints one line of a table showing the amount of coins required
 *  to make the given amount in change
 *  @param  coinValue  the value of the coin used in making change
 *  @param  coinCoint  the number of coins used
 *  @pre
 *   -# coinValue > 0.00
 *  @post   a formatted line has been printed showing
 *      - the face value of the coin (in dollars),
 *      - the number of that coin required,
 *      - and the total value of those coins.
 */


///////////////////////////////////////////////////////////////////////
// main function
///////////////////////////////////////////////////////////////////////

int main()
{
    DisplayOpeningScreen(
        "Guda:Methew:A00381751:csc34134",
        "A03: Coin Change Machine",11, 11);

    cout << endl << endl;

    cout << "This program reports how much of each coin you neeed in order "
         << "to make up a \ngiven amount of change. The amount must be "
         << "between $0.01 and $4.99 inclusive." << endl << endl;

    Pause();
    cout << endl << endl;

    cout << "Enter 0 or a negative amount to quit." << endl << endl;

    double amount;

    ReadDouble("Enter the amount of change required: $", amount);

    while (amount > 0.00)
    {
        ShowChange(amount);

        cout << "Enter 0 or a negative amount to quit." << endl << endl;
        ReadDouble("Enter the amount of change required: $", amount);
    }

    Pause();
}

///////////////////////////////////////////////////////////////////////
// function definitions section
///////////////////////////////////////////////////////////////////////
/*
defination for GetAmout function
*/
bool GetAmount(double& amount)
{
    if (amount >= 0.01 && amount <= 4.99)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
defination for roundTo function
*/
double roundTo (double amount, double factor)
{
    cout << setprecision(2) << fixed;
    return (floor((amount/factor) + 0.5)) * factor;
}

/*
defination for ShowChange function
*/
void ShowChange(double amount)
{
    GetAmount(amount);

    while (GetAmount(amount)!=true)
    {
        cout << endl;
        cout << "I'm afraid the amount must be less than $5.00.\n"
             << "Please try again." << endl << endl;

        ReadDouble("Enter the amount of change required: $", amount);
    }

    int coinCount;

    cout << fixed << endl;
    cout << "Change for $" << setprecision (2) << amount << endl;
    cout << "----------------" << endl << endl;

    double countAmount = roundTo(amount, 0.05);

    GetAndShowCoins(TOONIE, coinCount, countAmount);
    GetAndShowCoins(LOONIE, coinCount, countAmount);
    GetAndShowCoins(QUARTER, coinCount, countAmount);
    GetAndShowCoins(DIME, coinCount, countAmount);
    GetAndShowCoins(NICKEL, coinCount, countAmount);

    cout << setw(26) << right <<"-----" << endl;
    cout << setw(26) << right << roundTo(amount, 0.05) << endl << endl;

    cout << "(Reminder: change amounts are rounded to nearest "
         << "multiple of 5 cents.)" << endl << endl;
}

/*
defination for GetAndShowCoins function
*/
void GetAndShowCoins(double coinValue, int& coinCount, double& amount)
{
    GetCoins(coinValue, coinCount, amount);
    ShowCoins (coinValue, coinCount);
}

/*
defination for GetCoins function
*/
void GetCoins(double coinValue, int& coinCount, double& amount)
{
    coinCount = (int)(amount / coinValue);
    amount = amount - (coinValue * coinCount);
}

/*
defination for ShowCoins function
*/
void ShowCoins(double coinValue, int coinCount)
{
    cout << fixed;
    cout << setw(6) << right << "$" << setprecision (2) << coinValue
         << setw(6) << right << coinCount 
         << setw(6) << right << "$" << (coinValue * coinCount)<< endl;
}