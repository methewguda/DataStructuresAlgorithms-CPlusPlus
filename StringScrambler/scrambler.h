/**
@file scrambler.h
Assignment: 06
@author Guda:Methew:A00381751:csc34134
@version 1.0
@brief this program will take a string from user,
it will scramble the string, then it will unscramble the string.
@due date Sunday, June 1, 2014
@date Saturday, May 31, 2014
*/

/*
Author self-assessment statement:
This program is complete and working according to spcecifications,
according to the best of my knowledge.
*/


/*
include and using section
*/
#include <iostream>         //For access to input output stream
#include "utilities.h"      //For access to utilities package

using namespace std;
using namespace Scobey;

/*
protoype declaration section
*/

int mainMenu();
/**<
This fucntion is for to display the menu accroding to spcecifications
@return menu choice from user m.getChoice();
@post:
-# accepts possitve integer value from user
-# 1 to Quit from the program
-# 2 to start Scramble Text
-# 3 to start Unscramble Text
*/

string scrambleText(string userInput);
/**<
This fuction will scramble a string
@return scrambled text string type
@param userInput string type
@pre
-# userInput contains string type value
@post
-# scramble the values of the string recurssively
-# return the scrambled text
*/
string unscrambleText(string userInput);
/**<
This fuction will unscramble a string
@return unscrambled text string type
@param userInput string type
@pre
-# userInput contains string type value
@post
-# unscramble the values of the string recurssively
-# reverse process of <em>scambleText()</em>
-# return the unscrambled text
*/