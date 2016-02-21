/**
@file: interest01.cpp
Assignment: 01
@author Guda:Methew:A00381751:CSCI2341
Description: create a program that calculates how long it'll take to repay
a consumer loan, and how much interest will be charged on that loan.
@due date: Wednesday, 14 May 2014
@date: Tuesday, May 13, 2014
@version 1.0
*/

/*
Author self-assessment statement:
This program is complete and working according to spcecifications,
according to the best of my knowledge.
*/

#include<iostream>     //For access to input output stream

using namespace std;   //For access to statnderd input/output stream

int main()
{
    cout << "Guda:Methew:A00381751:CSCI2341" << endl
         << "A01:Interest payments on loans" << endl << endl;

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

    cout << endl << endl
         << "Press enter to continue...";
    cin.ignore(100, '\n');
    cout << endl << endl;
    /*
    pause for user to press Enter
    */

    double loanAmount = 0.00;
    double annualInterestRate = 0.00;
    double monthlyPaymentAmount = 0.00;
    /*
    decleared and initialized variables to read loan information from user
    */

    cout << "Enter amount of the loan: $";
    cin >> loanAmount;
    cin.ignore(100, '\n');
    /*
    prompts for user to read loan amount
    */

    cout << "Enter the annual interest rate (in %): ";
    cin >> annualInterestRate;
    cin.ignore(100, '\n');
    /*
    prompts for user to read annual interest rate
    */

    cout << "Enter your monthly payment: $";
    cin >> monthlyPaymentAmount;
    cin.ignore(100, '\n');
    /*
    prompts for user to read monthly payment amount
    */

    cout << endl << endl
         << "Press enter to continue...";
    cin.ignore(100, '\n');
    cout << endl << endl;
    /*
    pause for user to press Enter
    */

    double monthlyInterestRate = (annualInterestRate / 12);
    /*
    decleared and initialized variable to calculate monthly interest rate
    */

    cout << "Loan Amount:     $" << loanAmount << endl;
    cout << "Monthly Payment: $" << monthlyPaymentAmount << endl;
    cout << "Annual Interest:  " << annualInterestRate << "%" << endl;
    cout << "Monthly Interest: " << monthlyInterestRate << "%" << endl;

    cout << endl << endl
        << "Press enter to continue...";
    cin.ignore(100, '\n');
    cout << endl << endl;
    /*
    pause for user to press Enter
    */

    int month = 0;
    double interestCharged = ((monthlyInterestRate / 100) * loanAmount);
    double totalInterestCharged = 0.00;
    /*
    decleared and initialized variables to count months, 
    calculate interest charged and total amount of interest will be charged
    */

    while (interestCharged > 0)
    {
        month++;
        cout << "Month " << month << ", amount owed $" << loanAmount
             << ", interset Charged $" << interestCharged << endl;

        totalInterestCharged +=interestCharged;
        loanAmount = (loanAmount + interestCharged - monthlyPaymentAmount);
        interestCharged = ((monthlyInterestRate / 100) * loanAmount);
    }

    cout << endl << endl
        << "Press enter to continue...";
    cin.ignore(100, '\n');
    cout << endl << endl;
    /*
    pause for user to press Enter
    */

    cout << "Loan paid off in " << month << " months." << endl;
    cout << "Total interest paid was " << totalInterestCharged << "." << endl;

    cout << endl << endl
         << "Press enter to finish...";
    cin.ignore(100, '\n');
    cout << endl;
    /*
    pause for user to press Enter
    */

    return 0;
}