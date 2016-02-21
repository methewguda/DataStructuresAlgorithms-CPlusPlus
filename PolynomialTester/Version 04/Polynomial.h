/**
@file Polynomial.h
Assignment: 09
@author Guda:Methew:A00381751:csc34134
@version 1.0
@brief an univariate Polynomial class which calculates the degree of a
polynomial, gets the coefficient, evaluates the polynimails at certain value,
sets the coefficient and prints the polynimial equation. This class also the
the BIG 3.5 section and the << operator.
@due date Tuesday, June 10, 2014
@date Tuesday, June 10, 2014
*/

/*
Author self-assessment statement:
This program is complete and working according to spcecifications,
according to the best of my knowledge.
*/

/*
Header Guard
*/
#ifndef POLYNOMIAL
#define POLYNOMIAL

/*
include & using section
*/
#include <iostream>     //for access to input/output stream

using std::cout;        //for access to standard output stream
using std::ostream;     //for access to standard output stream class

struct PolyNode;
/**<
PolyNode struture for a Polynomial Equation.
Contain a double coefficient variable, an integer variable and a pointer
*/

void addNode
    (
    PolyNode*& cur,     //in/out
    double c,           //in
    int p               //in
    );
/**<
adds a node with coefficient c and power p in front of the one
cur is currently pointing at
@return void
@param cur a referenced PolyNode object
@param c a double type value for coefficient
@param p a integer value for power
@pre
-# cur must be a reference PolyNode type object
-# c must be double vale
-# p must be integer value
@post
-# adds a node with coefficient c and power p in front 
of the one cur is currently pointing at.
-# if cur has the nullptr then it will add the coefficient & the power
in front of Poly node else it will add it to the next ponter
*/

void removeNode
    (
    PolyNode*& cur,     //in/out
    int p               //in
    );
/**<
removes the node with power p at or after the 
node cur is currently pointing at.
@return void
@param cur a referenced PolyNode object
@param p a integer value for power
@pre
-# cur must be a reference PolyNode type object
-# p must be integer value
@post
-# removes the node with power p at or after the 
node cur is currently pointing at.
-# If there is no node with power p, the list remains unchanged.
*/

void changeNode
    (
    PolyNode*& cur,    //in/out
    int p,             //in
    double c           //in
    );
/**<
changes the coefficient of the node with power p at or after the
node cur is currently pointing at. 
@return void
@param cur a referenced PolyNode object
@param c a double type value for coefficient
@param p a integer value for power
@pre
-# cur must be a reference PolyNode type object
-# c must be double vale
-# p must be integer value
@post
-# if cur is null or less than p, in which case we add the
new node in front of cur
-# if cur->power is equal to p, in which case we change *cur's
coefficient to c.
-# else this fucntion uses the recurssion
*/

PolyNode* CopyNodes
    (
    PolyNode* srcNode
    );
/**<
This fucntion copies the nodes from a PolyNode object
@return copy a PolyNode type pointer
@param srcNode PolyNode type pointer
@pre
- srcNode must be a PolyNode type pointer
@post
- copy all the elements from srcNode pointer to another pointer
*/
void DeleteNodes
    (
    PolyNode* cur
    );
/**<
This fucntion deletes the nodes from a PolyNode object
@return void
@param cur PolyNode type pointer
@pre
- cur must be a PolyNode type pointer
@post
- if cur is not nullpointer then delete all the elements from cur pointer
*/
class Polynomial
{
    /**<
    an univariate Polynomial class which calculates the degree of a
    polynomial, gets the coefficient, evaluates the polynimails at certain
    value, sets the coefficient and prints the polynimial equation. This
    class also the the BIG 3.5 section and the << operator.
    */
public:
    Polynomial();
    /**<
    Default constructor for polynomial class
    @post
    -# sets the head to nullptr
    */

    //The BIG 3.5 section
    Polynomial
        (
        const Polynomial& src
        );
    /**<
    Copy constructor for polynomial class
    @param src constant Polynomial object
    @post
    - sets the head to nullptr.
    */
    ~Polynomial();
    /**<
    this is a destructor for polynomial class
    @post
    -deletes the head of the Node
    */
    Polynomial& operator=
        (
        Polynomial src
        );
    /**<
    This = operator assign a Polynomial object to another object
    @return Polynomial a Polynomial type object
    @param src a Polynomial type object
    @pre
    - src must be polynomial type object
    @post
    -# swap the object with src by using swap()
    -# retrun the swapped object
    */
    void swap
        (
        Polynomial& other
        );
    /**<
    This fucntion swaps between two Polynomial objects
    @return void
    @param other a referrenced Polynomial type object
    @pre
    - other must be a Polynomial type object
    @post
    -swaps the other object and head by using swap function from
    standard namespace
    */

    int degree() const;
    /**<
    returns the degree of the polynomial.
    @return int retrun degree of a polynomial
    */

    double getCoefficient
        (
        int power                       //in
        ) const;
    /**<
    returns the coefficient of the xpower term.
    @return double returns the coefficient
    @param power an positive integer
    @pre
    -# powere must be a integer
    */

    double evaluateAt
        (
        double x                        //in
        ) const;
    /**<
    returns the coefficient of the xpower term.
    @return double returns the evaluate value
    @param x an positive double value
    @pre
    -# x must be a double value
    */

    void print() const;
    /**<
    print the polynomial equation
    @return void
    @post
    -prints the polynomial equation
    */

    void setCoefficient
        (
        const double& newCoefficient,   //in
        const int& power                //in
        );
    /**<
    replaces the coefficient of the xpower term with newCoefficient.
    @return void
    @param newCoefficient a constant double variable
    @param power a constant int variable
    @pre
    -# newCoefficient must be constant and positive double
    -# power must be constant and positive integer
    @post
    -# if head is a null pointer then add the node
    -# if the new coefficient is 0.00 then remove the node
    -# else change the node to new coefficient and power
    */

    friend ostream& operator<<
        (
        ostream& out,                   //out
        const Polynomial& list          //in
        );
    /**<
    This << operator prints out the Polynomial List
    @return out a referrenced ostream tyoe object
    @param out a referrenced ostream tyoe object
    @param list a constant referrenced type Polynomial object
    @pre
    -# operator<< must be friend
    -# out must be an ostream object
    -# list must be constant referrenced type object
    @post
    - returns the polynomial equation as ostream object
    */

private:
    /*
    head is an instance variable of PolyNode structure
    */
    PolyNode* head;
};
/*
End of header guard
*/
#endif