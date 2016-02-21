// ---------- LLDriver.cpp ----------------------------------------------- //
// Messing around with the LL type
// Mark Young
// Spring 2014
// ----------------------------------------------------------------------- //

#include <iostream>
#include <stdexcept>
#include "LL.hpp"
#include "utilities.h"
using namespace std;
using Scobey::Pause;

int main()
{
    cout << "\n\n"
        << "Messing around with LL (linked lists)....\n\n";

    // create lists
    LL<int> list1;
    LL<int>list2;

    // print lists
    cout << "\tlist1 == " << list1 << endl;
    cout << "\tlist2 == " << list2 << endl << endl;
    Pause();

    // get some data
    cout << "\tlist1.size() == " << list1.size() << endl;
    cout << "\tlist2.empty() == " << list2.empty() << endl;
    cout << "\t\t(where 0 == false and 1 == true)\n\n";
    Pause();

    // populate the lists
    cout << "Adding elements...\n";
    list1.push_front(28);
    list1.push_front(99);
    list1.push_front(32);
    list2.push_back(77);
    list2.push_back(421);
    cout << "\tlist1 == " << list1 << endl;
    cout << "\tlist2 == " << list2 << endl << endl;
    Pause();

    // get some data
    cout << "\tlist1.size() == " << list1.size() << endl;
    cout << "\tlist2.empty() == " << list2.empty() << endl;
    cout << "\t\t(where 0 == false and 1 == true)\n\n";
    Pause();

    // get some more data
    try
    {
        cout << "Some elements of the lists...\n";
        cout << "\tlist1.at(0) == " << list1.at(0) << endl;
        cout << "\tlist2.at(1) == " << list2.at(1) << endl;
        cout << "\tlist1.at(2) == " << list1.at(2) << endl;
        cout << "\tlist2.at(3) == " << list2.at(3) << endl;
        cout << "\tlist1.at(4) == " << list1.at(4) << endl << endl;
    }
    catch (const range_error& e)
    {
        cerr << "--- ERROR --- " << e.what() << " ---\n\n";
    }
    Pause();

    // copy constructor
    cout << "Making a copy of list1 in list3...\n";
    LL<int> list3(list1);
    cout << "\tlist1 == " << list1 << endl;
    cout << "\tlist3 == " << list3 << endl << endl;
    Pause();

    // adding elements
    cout << "Adding elements to list3 and changing list1...\n";
    list3.push_back(42);
    list3.push_front(100);
    list1.at(1) = -5;
    cout << "\tlist1 == " << list1 << endl;
    cout << "\tlist3 == " << list3 << endl << endl;
    Pause();

    // another list, for assignment
    cout << "Creating another list...\n";
    LL<int> list4;
    cout << "\tlist2 == " << list2 << endl;
    cout << "\tlist4 == " << list4 << endl << endl;
    Pause();

    // assignment
    cout << "Assigning to list4 from list2...\n";
    list4 = list2;
    cout << "\tlist2 == " << list2 << endl;
    cout << "\tlist4 == " << list4 << endl << endl;
    Pause();

    // adding elements
    cout << "Changing an element of list4 and adding to list2...\n";
    list4.at(1) = 7;
    list2.push_front(-7);
    cout << "\tlist2 == " << list2 << endl;
    cout << "\tlist4 == " << list4 << endl << endl;
    Pause();

    // swapping
    cout << "Before swapping list3 and list4...\n";
    cout << "\tlist3 == " << list3 << endl;
    cout << "\tlist4 == " << list4 << endl << endl;
    Pause();
    cout << "After swapping list3 and list4...\n";
    list3.swap(list4);
    cout << "\tlist3 == " << list3 << endl;
    cout << "\tlist4 == " << list4 << endl << endl;
    Pause();

    // prints multiple words into the string
    LL<string> list5;
    list5.push_front("Methew");
    list5.push_back("Guda");
    cout << "\tlist5 == " << list5 << endl << endl;
    Pause();
}