// ---------- TestPolynomial3.cpp  ---------------------------------------- //
// A program to test overloaded output and the "Big 3" for Polynomial
//
// Mark Young
// Spring 2014
//
// Don't modify this file!
// (except to comment out bits that you haven't created the code for yet)
// ------------------------------------------------------------------------ //

#include <iostream>
#include <fstream>
#include "Polynomial.h"
#include "utilities.h"
using namespace std;
using Scobey::Pause;

const string FILE_NAME = "TestPolynomialOutput.txt";

int main()
{
    cout << "\n\n"
        << "Testing Polynomial Big-3\n\n";

    Polynomial p;
    p.setCoefficient(9, 0);
    p.setCoefficient(-1, 2);
    p.setCoefficient(4, 5);
    p.setCoefficient(7, 3);
    cout << "\nFirst Polynomial:\n\t"
        << "p == " << p << "\n\n";
    Pause();

    Polynomial q;
    q.setCoefficient(2, 2);
    q.setCoefficient(5, 1);
    q.setCoefficient(-4, 0);
    cout << "\nSecond Polynomial:\n\t"
        << "q == " << q << "\n\n";
    Pause();

    Polynomial pc(p);
    cout << "\nCopied Polynomial:\n\t"
        << "pc == " << pc << "\n\n";
    Pause();

    pc.setCoefficient(0, 0);
    p.setCoefficient(3, 2);
    cout << "\nModified Polynomial Copies:\n\t"
        << "p == " << p << "\n\t"
        << "pc == " << pc << "\n\n";
    Pause();

    Polynomial pa;
    pa = p;
    cout << "\nAssigned Polynomial:\n\t"
        << "p == " << p << "\n\t"
        << "pa == " << pa << "\n\n";
    Pause();

    pa.setCoefficient(1, 1);
    p.setCoefficient(0, 5);
    cout << "\nModified Polynomial Assignments:\n\t"
        << "p == " << p << "\n\t"
        << "pa == " << pa << "\n\n";
    Pause();

    cout << "\nBefore swapping p and q:\n\t"
        << "p == " << p << "\n\t"
        << "q == " << q << "\n\n";
    Pause();

    p.swap(q);
    cout << "\nAfter swapping p and q:\n\t"
        << "p == " << p << "\n\t"
        << "q == " << q << "\n\n";
    Pause();

    cout << "\nWriting polynomials to file:\n\t";
    ofstream fout(FILE_NAME);
    if (!fout)
    {
        cerr << "Could not open '" << FILE_NAME << "' for output.\n\n";
        exit(1);
    }
    fout << "The penultimate Polynomials are:\n\t"
        << p << "\n\t"
        << q << "\n\t"
        << pc << "\n\t"
        << pa << "\n\n";
    fout.close();
    cout << "Done!\n\t"
        << "See '" << FILE_NAME << "' for the results.\n\n";
    Pause();

    cout << "\nCascading Assignment:\n\t";
    pa = pc = p;
    cout << "pa == " << pa << "\n\t"
        << "pc == " << pc << "\n\t"
        << "p = " << p << "\n\n";
    Pause();
}

