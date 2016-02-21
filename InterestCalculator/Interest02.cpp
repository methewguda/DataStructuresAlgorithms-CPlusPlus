/**
@file: interest02.cpp
Assignment: 02
@author Guda:Methew:A00381751:CSCI2341
Description: create a program that calculates how long it'll take to repay
a consumer loan, and how much interest will be charged on that loan. This
program also how the payments are going to be paid on each year in table.
@due date: Thursday, 15 May 2014
@date: Thursday, May 15, 2014
@version revision 1.1
*/

/*
Author self-assessment statement:
This program is complete and working according to spcecifications,
according to the best of my knowledge. however the format of the loan
information may change if the data is greater than 99999.99.
It's because the data width is set to 8 according to the sample.
*/

#include <iostream>     //For access to input output stream
#include <iomanip>      //For access to input output manipulators
#include "utilities.h"

using namespace std;   //For access to statnderd input/output stream
using namespace Scobey;

int main()
{
    cout << "Guda:Methew:A00381751:CSC34134" << endl
        << "A02:Interest payments on loans" << endl << endl;

    cout << "This program calculates payments on a consumer loan." << endl
        << "You enter the amount of the loan, the annual interest" << endl
        << "rate, and theamount of the monthly payment. It reports" << endl
        << "month by month on how much interest you're charged, and" << endl
        << "the amount remaining on the loan. At the end it reports"<< endl
        << "how many months it took to repay the loan, and how much"<< endl
        << "interest you paid in total." << endl;
    /*
    author identification and brief description of the program.
    */

    cout << endl << endl;
    Pause();
    cout << endl;
    /*
    pause for user to press Enter
    */

    double initialLoanAmount;
    double annualInterestRate;
    double monthlyPaymentAmount;
    /*
    decleared and initialized variables to read loan information from user
    */

    ReadDouble("Enter amount of the loan: $", initialLoanAmount);
    /*
    prompts for user to read loan amount
    */

    ReadDouble("Enter the annual interest rate (in %): ", annualInterestRate);
    /*
    prompts for user to read annual interest rate
    */

    ReadDouble("Enter your monthly payment: $", monthlyPaymentAmount);
    /*
    prompts for user to read monthly payment amount
    */

    double monthlyInterestRate = (annualInterestRate / 12);
    /*
    decleared and initialized variable to calculate monthly interest rate
    */

    double loanAmount = initialLoanAmount;

    int month = 0;
    double interestCharged = ((monthlyInterestRate / 100) * loanAmount);
    double totalInterestCharged = 0.00;
    /*
    decleared and initialized variables to count months, 
    calculate interest charged and total amount of interest will be charged
    */

    while (interestCharged > 0)
    {
        cout << endl << endl;
        Pause();
        cout << endl;
        /*
        pause for user to press Enter
        */

        cout << fixed << setprecision(2);
        cout << "Loan Amount:     $"
             << right << setw (8) << initialLoanAmount << endl;
        cout << "Monthly Payment: $"
             << right << setw (8) << monthlyPaymentAmount << endl;
        cout << "Annual Interest:  " 
             << right << setw (8) << annualInterestRate << "%" << endl;
        cout << "Monthly Interest: "
             << right << setw (8) << monthlyInterestRate 
             << "%" << endl << endl;
        /*
        Loan Information
        */

        cout << right << setw (5) << "Month"
             << right << setw (15) << "Start Amount"
             << right << setw (15) << "Interest"
             << right << setw (15) << "Payment"
             << right << setw (15) << "End Amount" << endl;

        int i = 0;      // a counter to count 12 months

        while (i<12 && interestCharged >0)
        {
            i++;

            month++;

            cout << right << setw (5) << month
                 << right << setw (15) << loanAmount
                 << right << setw (15) << interestCharged
                 << right << setw (15) << monthlyPaymentAmount;

            loanAmount = (loanAmount + interestCharged - monthlyPaymentAmount);

            if (loanAmount < 0)
            {
                loanAmount = 0.00;
            }
            /**
            To avoid negetive value
            */

            cout << right << setw (15) << loanAmount << endl;

            totalInterestCharged +=interestCharged;

            interestCharged = ((monthlyInterestRate / 100) * loanAmount);
        }
        /**
        table showing how the payments are going that year
        */
    }

    cout << endl << endl;
    Pause();
    cout << endl;
    /*
    pause for user to press Enter
    */

    cout << "Loan paid off in " << month << " months." << endl;
    cout << "Total interest paid was " << totalInterestCharged << "." << endl;

    cout << endl << endl;
    Pause();
    cout << endl;
    /*
    pause for user to press Enter
    */

    return 0;
}