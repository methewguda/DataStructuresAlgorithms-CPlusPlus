/**
@file Polynomial.h
Assignment: 05
@author Guda:Methew:A00381751:csc34134
@version 1.0
@brief an univariate Polynomial class which calculates the degree of a
polynomial, gets the coefficient, evaluates the polynimails at certain value,
sets the coefficient and prints the polynimial equation.
@due date Tuesday, May 27, 2014
@date Tuesday, May 27, 2014
*/

/*
Author self-assessment statement:
This program is complete and working according to spcecifications,
according to the best of my knowledge.
*/

#ifndef POLYNOMIAL
#define POLYNOMIAL

#include <iostream>
#include <vector>

using std::cout;
using std::vector;


class Polynomial
{
    /**<
    an univariate Polynomial class which calculates the degree of a
    polynomial, gets the coefficient, evaluates the polynimails at certain value,
    sets the coefficient and prints the polynimial equation.
    */
public:
    Polynomial();
    /**<
    Default constructor for polynomial class 
    */

    ~Polynomial();
    /**<
    this is a destructor for Date class
    */

    int degree() const;
    /**<
    returns the degree of the polynomial.
    @return int retrun degree of a polynomial
    */

    double getCoefficient(int power) const;
    /**<
    returns the coefficient of the xpower term.
    @return double returns the coefficient
    @param power an positive integer
    @pre
    -# powere must be a positive integer
    */

    double evaluateAt(double x) const;
    /**<
    returns the coefficient of the xpower term.
    @return double returns the evaluate value
    @param x an positive double value
    @pre
    -# x must be a positive double value
    */

    void print() const;
    /**<
    print the polynomial equation
    @return void
    */

    void setCoefficient(const double& newCoefficient, const int& power);
    /**<
    replaces the coefficient of the xpower term with newCoefficient.
    @return void
    @param newCoefficient a constant double variable
    @param power a constant int variable
    @pre
    -# newCoefficient must be constant and positive double
    -# power must be constant and positive integer
    */

private:
    vector<double> polynomial;
};

#endif