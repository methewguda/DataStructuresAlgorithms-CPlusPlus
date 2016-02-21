/**
@file LL.hpp
Assignment: 10
@author Guda:Methew:A00381751:csc34134
@version 1.0
@brief This is a revised version of LL class. LL class is templated. It has
also a print code to print LL of strings.
@due date Thursday, June 12, 2014
@date Thursday, June 12, 2014
*/

/*
Author self-assessment statement:
This program is complete and working according to spcecifications,
according to the best of my knowledge.
*/

/*
Header Guard
*/
#ifndef HPP
#define HPP

/*
include & using section
*/
#include <iostream>     //for access to input/output stream
#include <stdexcept>    //for access to standard exception
#include <sstream>      //for access to string stream

using std::ostream;     //for access to standard output stream class

template<typename base_type>
struct LLNode
{
    base_type data;
    LLNode<base_type>*   next;
};
/**<
Templated LLNode struture for a Polynomial Equation.
Contains a base_type data and a pointer to the LLNode
*/

template<typename base_type>
class LL
{
    /**<
    Revised Templated LL class  with BIG 3.5, Observers, Mutators &
    a friend function.
    */
public:
    LL();
    /**<
    Default constructor for Templated LL Class
    @post
    -# sets the head to nullptr
    */

    //**********Big 3.5 Section**********//
    LL
        (
        const LL& src           //in
        );
    /**<
    Copy constructor for polynomial class
    @param src constant Polynomial object
    @pre
    - src must be constatnt and referrenced
    @post
    - copy the nodes from src node
    */

    LL& operator=
        (
        LL src                  //in/out
        );
    /**<
    This = operator assign a LL object to another object
    @return Polynomial a Polynomial type object
    @param src a LL type object
    @pre
    - src must be LL type object
    @post
    -# swap the object with src by using swap()
    -# retrun the swapped object
    */

    ~LL();
    /**<
    this is a destructor for LL class
    @post
    -deletes the head of the Node
    */

    void swap
        (
        LL& other               //in/out
        );
    /**<
    This method swaps between two LL objects
    @return void
    @param other a referrenced LL type object
    @pre
    - other must be a LL type object
    @post
    -swaps the other object and head by using swap method from
    standard namespace
    */

    //**********Observers Section**********//
    int size() const;
    /**<
    this method returns the size of LLNode
    @return int counter that estimates the size of LLNode
    @post
    - method must be constatnt
    */

    bool empty() const;
    /**<
    this method returns if the node is empty or not
    @return boolean true if the node is empty or false if not
    @post
    - method must be constant
    */
    const base_type& at
        (
        int p                   //in
        ) const;
    /**<
    This Method return the value of given position
    @retun base_type
    @param p an integer variable
    @pre
    -# p must be integer value
    -# method must be constatnt
    @post
    -# returns the data from the pointer
    -# if data doesn't exists throws an exception
    -# has only read only access
    */

    //**********Mutators Section**********//
    void push_front
        (
        base_type e             //in
        );
    /**<
    Push the data at the front of the list
    @return void
    @param e base_type data
    @pre
    - data must be base_type
    @post
    - add the data at the front of the list
    */

    void push_back
        (
        base_type e             //in
        );
    /**<
    Push the data at the back of the list
    @return void
    @param e base_type data
    @pre
    - data must be base_type
    @post
    - add the data at the back of the list
    */

    base_type& at
        (
        int p                   //in
        );
    /**<
    This Method return the value of given position
    @retun base_type
    @param p an integer variable
    @pre
    - p must be integer value
    @post
    -# returns the data from the pointer
    -# if data doesn't exists throws an exception
    -# has only read & write access
    */

    //**********Friends Section**********//
    template<typename base_type>
    friend ostream& operator<<
        (
        ostream& out,                   //out
        const LL<base_type>& list       //in
        );
    /**<
    This Templated << operator prints out the LLNode List
    @return out a referrenced ostream tyoe object
    @param out a referrenced ostream tyoe object
    @param list a constant referrenced type LLNode object
    @pre
    -# operator<< must be friend
    -# out must be an ostream object
    -# list must be constant referrenced base_type object
    @post
    - returns the LLNode List as ostream object
    */

private:
    LLNode<base_type>* head;
};

/*
End of Header Guard
*/
#endif

//**********Definition Section***********//

template<typename base_type>
LLNode <base_type>* CopyNodes(LLNode<base_type>* srcNode)
{
    if (srcNode == nullptr) return nullptr;
    LLNode<base_type>* copy = new LLNode<base_type>;
    copy->data = srcNode->data;
    copy->next = CopyNodes(srcNode->next);
    return copy;
}
/**<
This method copies the nodes from a LLNode object
@return copy a PolyNode type pointer
@param srcNode PolyNode type pointer
@pre
- srcNode must be a LLNode type pointer
@post
- copy all the elements from srcNode pointer to another pointer
*/

template<typename base_type>
void DeleteNodes(LLNode<base_type>* cur) 
{
    if (cur != nullptr) 
    {
        LLNode<base_type>
            * temp = cur;
        cur = cur->next;
        delete temp;
    }
}
/**<
This method deletes the nodes from a LLNode object
@return void
@param cur LLNode type pointer
@pre
- cur must be a LLNode type pointer
@post
- if cur is not nullpointer then delete all the elements from cur pointer
*/

// Definition Section for Helper Method
std::string intToString(int n)
{
    std::ostringstream out;
    out << n;
    return out.str();
}
/**<
This method takes an integer value and returns the strings
@return string string value
@param n integer variable
@post
- retuns the value from ostringstream
*/

//Definition Section for Default Constructor
template<typename base_type>
LL<base_type>::LL()
{
    head = nullptr;
}

//**********Defination Section for BIG 3.5**********//

//Defination Section for Copy Constructor
template<typename base_type>
LL<base_type>::LL(const LL<base_type>& src)
{
    head = CopyNodes(src.head);
}

//Defination Section for Assignment Operator
template<typename base_type>
LL<base_type>& LL<base_type>::operator=(LL<base_type> src)
{
    this->swap(src);
    return *this;
}

//Defination Section for Desstructor
template<typename base_type>
LL<base_type>::~LL()
{
    DeleteNodes(head);
}

// Defination Section for Swap Method
template<typename base_type>
void LL<base_type>::swap(LL<base_type>& other)
{
    std::swap(head, other.head);
}

//**********Definition for Observers Section**********//

//Defination Section for Size Method
template<typename base_type>
int LL<base_type>::size() const
{
    int count = 0;
    for(LLNode<base_type>* cur = head; cur != nullptr; cur = cur->next)
        ++count;
    return count;
}

//Defination Section for Empty Method
template<typename base_type>
bool LL<base_type>::empty() const
{
    return head == nullptr;
}

//Defination Section for at Method
template<typename base_type>
const base_type& LL<base_type>::at(int p) const
{
    LLNode* cur = head;
    for (int i = 0; i < p; ++i)
    {
        if (cur == nullptr)
            throw std::range_error("Invalid index: " + intToString(p));
        cur = cur->next;
    }
    return cur->data;
}

//**********Defination Section for Mutators**********//

//Defination Section for push_front method
template<typename base_type>
void LL<base_type>::push_front(base_type e)
{
    LLNode<base_type>* cur = head;
    head = new LLNode<base_type>;
    head->data = e;
    head->next = cur;
}

//Defination Section for push_back method
template<typename base_type>
void LL<base_type>::push_back(base_type e)
{
    if (head == nullptr)
    {
        push_front(e);
    }
    else
    {
        LLNode<base_type>* cur = head; 
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = new LLNode<base_type>;
        cur->next->data = e;
        cur->next->next = nullptr;
    }
}

//Defination Section for at method
template<typename base_type>
base_type& LL<base_type>::at(int p)
{
    LLNode<base_type>* cur = head;
    for (int i = 0; i < p; ++i)
    {
        if (cur == nullptr)
            throw std::range_error("Invalid index: " + intToString(p));
        cur = cur->next;
    }
    return cur->data;
}

//***************************************************//

//Defination Section for friends function
template<typename base_type>
ostream& operator<<(ostream& out, const LL<base_type>& list)
{
    LLNode<base_type>* cur = list.head;    // friends can do this!
    out << "[";
    if (cur != nullptr)
    {
        while (cur->next != nullptr)
        {
            out << cur->data << ", ";
            cur = cur->next;
        }
        out << cur->data;
    }
    out << "]";
    return out;
}