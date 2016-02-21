/** @file utilities.h
Header file corresponding to utilities.cpp and utilities.obj, and
containing specifications for the facilities in namespace Scobey.

@author P. %Scobey
@date Monday, July 15, 2013
@version 2013.0
*/

/**
@mainpage
This is the Fall, 2013 version of the documentation for the
instructor-supplied C++ utilities package to be used in CSCI 2341
and CSCI 2342. You will find here descriptions of some very useful
(time-saving) constant definitions, free functions, and classes.
It will take some time to become thoroughly familiar with all that
is available, but you will need to start using the package very soon
and you must continue to learn new facilities as the term progresses.
@section overview_sec Overview
There are three constant arrays containing names: one containing
300 first names for females, one containing 300 first names for males,
and one containing 100 family names, all ranked in the order of name
frequency as observed in the United States and reported on the Internet
at these sites:
-# www.census.gov/genealogy/names/dist.female.first
-# names.mongabay.com/male_names_alpha.htm
-# en.wikipedia.org/wiki/List_of_most_common_surnames

<b>The source code that makes use of this utilities package must include
the <tt>utilities.h</tt> header file, and link to the corresponding object
file (which is named <tt>utilities.obj</tt> under Windows, and
<tt>utilities.o</tt> under Linux, for example). Note as well that the
package is enclosed in <tt>namespace Scobey</tt>.</b>

The package contains features in four categories, as listed below.

-# Fifteen free functions:<br />
Note that each member of the Read* sequence of free functions
in the list above provides the same kind of service: it prompts
for, and then reads in, from the standard input, a single value
of the type suggested by the function name. Only ReadInt and
ReadDouble contain error checking, and each continues to prompt
the user for a value of the correct type until a value of that
type is entered by the user (a potential infinite loop).
   - ClearScreen
   - DisplayOpeningScreen (implemented as an inline function)
   - DisplayTextfile
   - gcd
   - isEven
   - isOdd
   - numberOfDigits
   - Pause
   - ReadChar
   - ReadDouble
   - ReadInt
   - ReadNextLine
   - ReadThisLine
   - ReadString
   - userSaysYes
-# Five utility classes:
   - Menu
   - OperationCounter
   - RandomGenerator
   - Stopwatch
   - TextItems
-# Eleven named constants:
   - CARD_DECK
   - DAYS_OF_THE_WEEK_LONG
   - DAYS_OF_THE_WEEK_SHORT
   - DEFAULT_PROGRAMMER_INFO
   - DEFAULT_PROGRAM_INFO
   - MONTHS_OF_THE_YEAR_LONG
   - MONTHS_OF_THE_YEAR_SHORT
   - NAMES_3CHAR
   - NAMES_FEMALE
   - NAMES_MALE
   - NAMES_FAMILY
-# One typedef (<em>deprecated</em>, since there should be no further need for this)
   - String80
*/

#ifndef UTILITIES_H
#define UTILITIES_H

#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using std::cout;
using std::string;
using std::vector;

/**
Contains one typedef, eleven named constants,
fifteen free functions, and  five utility classes.
*/
namespace Scobey
{

//************************************************************************
//Typedef Section

typedef char String80[81];
/**<
Provides a legacy C-string type for holding up to 80 characters of text.
*/

//
//
//************************************************************************
//Named Constant Section

const string CARD_DECK[] =
    { "AS", "2S", "3S", "4S", "5S", "6S", "7S",
      "8S", "9S", "TS", "JS", "QS", "KS",
      "AH", "2H", "3H", "4H", "5H", "6H", "7H",
      "8H", "9H", "TH", "JH", "QH", "KH",
      "AD", "2D", "3D", "4D", "5D", "6D", "7D",
      "8D", "9D", "TD", "JD", "QD", "KD",
      "AC", "2C", "3C", "4C", "5C", "6C", "7C",
      "8C", "9C", "TC", "JC", "QC", "KC"
    };
/**<
Provides 2-character representations of each of the fifty-two cards
in a standard deck of cards.
*/


const string DAYS_OF_THE_WEEK_LONG[] =
    { "Monday", "Tuesday",  "Wednesday", "Thursday",
      "Friday", "Saturday", "Sunday"
    };
/**<
Provides full names for days of the week.
*/


const string DAYS_OF_THE_WEEK_SHORT[] =
    { "Mon", "Tue",  "Wed", "Thu",
      "Fri", "Sat", "Sun"
    };
/**<
Provides 3-letter abbreviations for days of the week.
*/


const string DEFAULT_PROGRAM_INFO =
    "Descriptive text required here is specificed elsewhere.";
/**<
Provides a placeholder value for a program title or brief description.
*/


const string DEFAULT_PROGRAMMER_INFO =
    "Lastname:Firstname:A00123456:CSC?????";
/**<
Provides a placeholder value for programmer identification information.
*/


const string MONTHS_OF_THE_YEAR_LONG[] =
    { "January",   "February", "March",    "April",
      "May",       "June",     "July",     "August",
      "September", "October",  "November", "December"
    };
/**<
Provides full names for months of the year.
*/


const string MONTHS_OF_THE_YEAR_SHORT[] =
    { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
/**<
Provides 3-letter abbreviations for months of the year.
*/


const string NAMES_3CHAR[] =
    { "Ace", "Ali", "Amy", "Ann", "Art",
      "Ben", "Bob", "Cal", "Dan", "Del",
      "Don", "Dot", "Eva", "Eve", "Fay",
      "Gil", "Guy", "Hal", "Ian", "Jan",
      "Jim", "Jon", "Kay", "Ken", "Kim",
      "Liz", "Mac", "Min", "Nan", "Ora",
      "Pam", "Red", "Rex", "Rik", "Rip",
      "Rob", "Rod", "Rog", "Ron", "Roy",
      "Sal", "Sam", "Sue", "Tad", "Tim",
      "Tom", "Uma", "Val", "Wes", "Zig"
    };
/**<
Provides fifty 3-character first names, some male and some female,
in alphabetical order.
*/


const string NAMES_FAMILY[] =
    { "Smith", "Johnson", "Williams", "Brown", "Jones",
      "Miller", "Davis", "Garcia", "Rodriguez", "Wilson",
      "Martinez", "Anderson", "Taylor", "Thomas", "Hernandez",
      "Moore", "Martin", "Jackson", "Thompson", "White",
      "Lopez", "Le", "Gonzalez", "Harris", "Clark",
      "Lewis", "Robinson", "Walker", "Perez", "Hall",
      "Young", "Allen", "Sanchez", "Wright", "King",
      "Scott", "Green", "Baker", "Adams", "Nelson",
      "Hill", "Ramirez", "Campbell", "Mitchell", "Roberts",
      "Carter", "Phillips", "Evans", "Turner", "Torres",
      "Parker", "Collins", "Edwards", "Stewart", "Flores",
      "Morris", "Nguyen", "Murphy", "Rivera", "Cook",
      "Rogers", "Morgan", "Peterson", "Cooper", "Reed",
      "Bailey", "Bell", "Gomez", "Kelly", "Howard",
      "Ward", "Cox", "Diaz", "Richardson", "Wood",
      "Watson", "Brooks", "Bennett", "Gray", "James",
      "Reyes", "Cruz", "Hughes", "Price", "Myers",
      "Long", "Foster", "Sanders", "Ross", "Morales",
      "Powell", "Sullivan", "Russell", "Ortiz", "Jenkins",
      "Gutierrez", "Perry", "Butler", "Barnes", "Fisher"
    };
/**<
Provides 100 family names (surnames), ranked in order of frequency
as found in the United States of America.
*/


const string NAMES_FEMALE[] =
    { "Mary", "Patricia", "Linda", "Barbara", "Elizabeth", "Jennifer",
      "Maria", "Susan", "Margaret", "Dorothy", "Lisa", "Nancy",
      "Karen", "Betty", "Helen", "Sandra", "Donna", "Carol",
      "Ruth", "Sharon", "Michelle", "Laura", "Sarah", "Kimberly",
      "Deborah", "Jessica", "Shirley", "Cynthia", "Angela", "Melissa",
      "Brenda", "Amy", "Anna", "Rebecca", "Virginia", "Kathleen",
      "Pamela", "Martha", "Debra", "Amanda", "Stephanie", "Carolyn",
      "Christine", "Marie", "Janet", "Catherine", "Frances", "Ann",
      "Joyce", "Diane", "Alice", "Julie", "Heather", "Teresa",
      "Doris", "Gloria", "Evelyn", "Jean", "Cheryl", "Mildred",
      "Katherine", "Joan", "Ashley", "Judith", "Rose", "Janice",
      "Kelly", "Nicole", "Judy", "Christina", "Kathy", "Theresa",
      "Beverly", "Denise", "Tammy", "Irene", "Jane", "Lori",
      "Rachel", "Marilyn", "Andrea", "Kathryn", "Louise", "Sara",
      "Anne", "Jacqueline", "Wanda", "Bonnie", "Julia", "Ruby",
      "Lois", "Tina", "Phyllis", "Norma", "Paula", "Diana",
      "Annie", "Lillian", "Emily", "Robin", "Peggy", "Crystal",
      "Gladys", "Rita", "Dawn", "Connie", "Florence", "Tracy",
      "Edna", "Tiffany", "Carmen", "Rosa", "Cindy", "Grace",
      "Wendy", "Victoria", "Edith", "Kim", "Sherry", "Sylvia",
      "Josephine", "Thelma", "Shannon", "Sheila", "Ethel", "Ellen",
      "Elaine", "Marjorie", "Carrie", "Charlotte", "Monica", "Esther",
      "Pauline", "Emma", "Juanita", "Anita", "Rhonda", "Hazel",
      "Amber", "Eva", "Debbie", "April", "Leslie", "Clara",
      "Lucille", "Jamie", "Joanne", "Eleanor", "Valerie", "Danielle",
      "Megan", "Alicia", "Suzanne", "Michele", "Gail", "Bertha",
      "Darlene", "Veronica", "Jill", "Erin", "Geraldine", "Lauren",
      "Cathy", "Joann", "Lorraine", "Lynn", "Sally", "Regina",
      "Erica", "Beatrice", "Dolores", "Bernice", "Audrey", "Yvonne",
      "Annette", "June", "Samantha", "Marion", "Dana", "Stacy",
      "Ana", "Renee", "Ida", "Vivian", "Roberta", "Holly",
      "Brittany", "Melanie", "Loretta", "Yolanda", "Jeanette", "Laurie",
      "Katie", "Kristen", "Vanessa", "Alma", "Sue", "Elsie",
      "Beth", "Jeanne", "Vicki", "Carla", "Tara", "Rosemary",
      "Eileen", "Terri", "Gertrude", "Lucy", "Tonya", "Ella",
      "Stacey", "Wilma", "Gina", "Kristin", "Jessie", "Natalie",
      "Agnes", "Vera", "Willie", "Charlene", "Bessie", "Delores",
      "Melinda", "Pearl", "Arlene", "Maureen", "Colleen", "Allison",
      "Tamara", "Joy", "Georgia", "Constance", "Lillie", "Claudia",
      "Jackie", "Marcia", "Tanya", "Nellie", "Minnie", "Marlene",
      "Heidi", "Glenda", "Lydia", "Viola", "Courtney", "Marian",
      "Stella", "Caroline", "Dora", "Jo", "Vickie", "Mattie",
      "Terry", "Maxine", "Irma", "Mabel", "Marsha", "Myrtle",
      "Lena", "Christy", "Deanna", "Patsy", "Hilda", "Gwendolyn",
      "Jennie", "Nora", "Margie", "Nina", "Cassandra", "Leah",
      "Penny", "Kay", "Priscilla", "Naomi", "Carole", "Brandy",
      "Olga", "Billie", "Dianne", "Tracey", "Leona", "Jenny",
      "Felicia", "Sonia", "Miriam", "Velma", "Becky", "Bobbie",
      "Violet", "Kristina", "Toni", "Misty", "Mae", "Shelly",
      "Daisy", "Ramona", "Sherri", "Erika", "Katrina", "Claire"
    };
/**<
Provides 300 female first names, ranked in order of frequency as found
in the United States of America.
*/


const string NAMES_MALE[] =
    { "James", "John", "Robert", "Michael", "William", "David",
      "Richard", "Charles", "Joseph", "Thomas", "Christopher", "Daniel",
      "Paul", "Mark", "Donald", "George", "Kenneth", "Steven",
      "Edward", "Brian", "Ronald", "Anthony", "Kevin", "Jason",
      "Matthew", "Gary", "Timothy", "Jose", "Larry", "Jeffrey",
      "Frank", "Scott", "Eric", "Stephen", "Andrew", "Raymond",
      "Gregory", "Joshua", "Jerry", "Dennis", "Walter", "Patrick",
      "Peter", "Harold", "Douglas", "Henry", "Carl", "Arthur",
      "Ryan", "Roger", "Joe", "Juan", "Jack", "Albert",
      "Jonathan", "Justin", "Terry", "Gerald", "Keith", "Samuel",
      "Willie", "Ralph", "Lawrence", "Nicholas", "Roy", "Benjamin",
      "Bruce", "Brandon", "Adam", "Harry", "Fred", "Wayne",
      "Billy", "Steve", "Louis", "Jeremy", "Aaron", "Randy",
      "Howard", "Eugene", "Carlos", "Russell", "Bobby", "Victor",
      "Martin", "Ernest", "Phillip", "Todd", "Jesse", "Craig",
      "Alan", "Shawn", "Clarence", "Sean", "Philip", "Chris",
      "Johnny", "Earl", "Jimmy", "Antonio", "Danny", "Bryan",
      "Tony", "Luis", "Mike", "Stanley", "Leonard", "Nathan",
      "Dale", "Manuel", "Rodney", "Curtis", "Norman", "Allen",
      "Marvin", "Vincent", "Glenn", "Jeffery", "Travis", "Jeff",
      "Chad", "Jacob", "Lee", "Melvin", "Alfred", "Kyle",
      "Francis", "Bradley", "Jesus", "Herbert", "Frederick", "Ray",
      "Joel", "Edwin", "Don", "Eddie", "Ricky", "Troy",
      "Randall", "Barry", "Alexander", "Bernard", "Mario", "Leroy",
      "Francisco", "Marcus", "Micheal", "Theodore", "Clifford", "Miguel",
      "Oscar", "Jay", "Jim", "Tom", "Calvin", "Alex",
      "Jon", "Ronnie", "Bill", "Lloyd", "Tommy", "Leon",
      "Derek", "Warren", "Darrell", "Jerome", "Floyd", "Leo",
      "Alvin", "Tim", "Wesley", "Gordon", "Dean", "Greg",
      "Jorge", "Dustin", "Pedro", "Derrick", "Dan", "Lewis",
      "Zachary", "Corey", "Herman", "Maurice", "Vernon", "Roberto",
      "Clyde", "Glen", "Hector", "Shane", "Ricardo", "Sam",
      "Rick", "Lester", "Brent", "Ramon", "Charlie", "Tyler",
      "Gilbert", "Gene", "Marc", "Reginald", "Ruben", "Brett",
      "Angel", "Nathaniel", "Rafael", "Leslie", "Edgar", "Milton",
      "Raul", "Ben", "Chester", "Cecil", "Duane", "Franklin",
      "Andre", "Elmer", "Brad", "Gabriel", "Ron", "Mitchell",
      "Roland", "Arnold", "Harvey", "Jared", "Adrian", "Karl",
      "Cory", "Claude", "Erik", "Darryl", "Jamie", "Neil",
      "Jessie", "Christian", "Javier", "Fernando", "Clinton", "Ted",
      "Mathew", "Tyrone", "Darren", "Lonnie", "Lance", "Cody",
      "Julio", "Kelly", "Kurt", "Allan", "Nelson", "Guy",
      "Clayton", "Hugh", "Max", "Dwayne", "Dwight", "Armando",
      "Felix", "Jimmie", "Everett", "Jordan", "Ian", "Wallace",
      "Ken", "Bob", "Jaime", "Casey", "Alfredo", "Alberto",
      "Dave", "Ivan", "Johnnie", "Sidney", "Byron", "Julian",
      "Isaac", "Morris", "Clifton", "Willard", "Daryl", "Ross",
      "Virgil", "Andy", "Marshall", "Salvador", "Perry", "Kirk",
      "Sergio", "Marion", "Tracy", "Seth", "Kent", "Terrance",
      "Rene", "Eduardo", "Terrence", "Enrique", "Freddie", "Wade"
    };
/**<
A named constant containing 300 male first names, 6 per line,
ranked in order of frequency as found in the United States.
*/

//
//
//************************************************************************
//Free Function Section

void ClearScreen
(
    int numLines = 25 //in
);
/**<
Clears the screen (the default output stream, which is assumed by
default to have 25 lines).
@return void
@param numLines The number of lines on the screen.
@pre None
@post <em>numLines</em> blank lines have been displayed on the standard
output stream (the screen).
*/


void DisplayOpeningScreen
(
    const string& programmerInfo = DEFAULT_PROGRAMMER_INFO, //in
    const string& programInfo = DEFAULT_PROGRAM_INFO,       //in
    int numBlankLinesBefore = 11, //in
    int numBlankLinesAfter = 12   //in
);
/**<
Displays an opening screen for any console program. The default display
shows a first line of programmer identification, the date and time of
the current program build on the second line, and a generic program
description on the third line of output. These three lines of output
are centered vertically, more or less, on an otherwise blank screen.
The idea is to keep the program description as short as possible
(preferably one or two lines), and to center vertically on the screen
all lines of output. To help accomplish these goals the user is permitted
to choose the number of blank lines to output both before and after the
lines containing information.
@return void
@param programmerInfo Text containing the programmer's ID info in the
appropriate form (specified elsewhere, but not in this documentation).
@param programInfo Text containing a brief (one-or-two-line)
description of the program.
@param numBlankLinesBefore The number of blank lines appearing on
the screen before the display of the contents of <em>programmerInfo</em>.
@param numBlankLinesAfter The number of blank lines appearing on the
screen after the display of the contents of <em>programInfo</em>.
@pre Note that default values are provided for all parameters and
the default values of <em>programmerInfo</em> and <em>programInfo</em>
are given by the named constants <em>DEFAULT_PROGRAMMER_INFO</em> and
<em>DEFAULT_PROGRAMMER_INFO</em> (respectively), which are described
elsewhere in this documentation. Here are the additional preconditions:
-# The standard input stream cin is empty.
-# Any newline character(s) required to begin a new line of output
have been included in the values of the string input parameter(s)
<em>programmerInfo</em> and/or <em>programInfo</em>.
@post
-# The contents of <em>programmerInfo</em> and <em>programInfo</em>
have been displayed, in that order, followed by a line similar to
the following:
<pre>
This executable was built on May 25 2007 at 23:47:51.
</pre>
There are no blank lines separating any of these lines of information,
but <em>numBlankLinesBefore</em> blank lines are output before the
contents of <em>programmerInfo</em> and <em>numBlankLinesAfter</em> blank lines
are output after the line containing the build date and time.
-# The program has paused after displaying a pause message, and the
user has pressed Enter.
*/


void DisplayTextfile
(
    const string& fileName,        //in
    int numberOfLinesPerPause = 23 //in
);
/**<
Displays a file of text numberOfLinesPerPause lines at a time.
This function allows the user to display any textfile on the
standard output and also lets the user decide how many lines
to display "between pauses", i.e., between the times when the
function pauses and waits for the user to press Enter to continue.
@return void
@param fileName The name of the file to be displayed.
@param numberOfLinesPerPause The number of lines displayed between
pauses.
@pre
<em>fileName</em> has been initialized.
@post
- Case 1 (typical): If <em>fileName</em> contains the name of an
existing and readable textfile in the current directory, or the full
pathname of an existing and readable textfile in some other accessible
directory, that file has been displayed on the screen numberOfLinesPerPause
lines at at time, preceded by the message
<pre>
==================================================
The file display will begin when you continue after this pause.
And note that one blank line not in the file will appear after each pause.
Press Enter to continue ...
</pre>
and followed by this message:
<pre>
End of file has been reached.
Press Enter to continue ...
</pre>
In addition, after each group of lines has been displayed, the program
pauses and waits for the user to press Enter, with a message like the
following:
<pre>
=====Line immediately above is line ## of file name-of-file.
Press Enter to continue ...
</pre>
- Case 2 (error): If the file designated by <em>fileName</em> cannot
be opened, the function pauses and waits for the user to press Enter to
continue, with the message
<pre>
Error: \<\<name-of-file\>\> could not be opened.
Press Enter to continue ...
</pre>
and then returns.
*/


int gcd
(
    int a, //in
    int b  //in
);
/**<
Finds the greatest common divisor of two nonnegative integers,
at least one of which is strictly positive.
@return The greatest common divisor of the two input integers.
@param a A nonnegative integer.
@param b A nonnegative integer.
@pre Both <em>a</em> and <em>b</em> have been initialized with
nonnegative integer values, and at least one of <em>a</em> or
<em>b</em> is strictly positive.
@post No side effects.
*/


bool isEven
(
    int n  //in
);
/**<
Determines if a positive integer is even.
@return <tt>true</tt> if n is an even integer, <tt>false</tt> if n is odd.
@param n The integer whose "evenness" is to be determined.
@pre <em>n</em> is a nonnegative integer.
@post No side effects.
*/


bool isOdd
(
    int n  //in
);
/**<
Determines if a positive integer is odd.
@return <tt>true</tt> if n is an odd integer, <tt>false</tt> if n is even.
@param n The integer whose "oddness" is to be determined.
@pre <em>n</em> is a nonnegative integer.
@post No side effects.
*/


int numberOfDigits
(
    int n  //in
);
/**<
Finds the number of digits in a positive integer.
@return The number of digits in the input integer.
@param n The integer whose digits are to be counted.
@pre <em>n</em> is a positive integer.
@post No side effects.
*/


void Pause
(
    int indentLevel = 0,  //in
    string message = "",  //in
    int pauseNumber = 0   //in
);
/**<
Causes the program to pause and wait for the user to press Enter
to continue, with default values for the indentation level, the
message supplying any additional information to the user, and the
pause number.
@return void
@param indentLevel The number of spaces to indent the first line
of each part of the output from the left margin.
@param message The message to be displayed, giving the reason for
this particular pause, if such a message is supplied.
@param pauseNumber The number of this particular pause, if pauses
are being numbered.
@pre
The input stream cin is empty.
@post
-# Each line of output produced by this function is automatically
indented <em>indentLevel</em> spaces, except for the second and any
subsequent lines of the text in <em>message</em>, which require a
newline character to start a new line.
-# If <em>pauseNumber</em> is 0 (the default value), there is no
corresponding output, while if <em>pauseNumber</em> is any positive
value (6 for example), a line like the following has been displayed
as the first line of output:
<pre>
This is pause #6.
</pre>
-# If <em>message</em> is non-empty, its content has been displayed
next, starting on the next line. An automatic newline is also inserted
following the text of <em>message</em>, so the text of <em>message</em>
itself need not (though it may) contain one or more newline characters.
-# As the last line of output, in all cases, the message
<pre>
Press Enter to continue ...
</pre>
has been displayed, with the cursor at the end of the line.
-# The user has pressed Enter.
*/


void ReadChar
(
    const string& userPrompt, //in
    char& charValue           //out
);
/**<
Gets a character (char) value from the user.
@param userPrompt Text of the prompt displayed to the user.
@param charValue Contains the character entered by the user.
@return void
@pre <em>userPrompt</em> has been initialized.
@post
-# The text in <em>userPrompt</em> has been displayed and the user
has entered a character (a value of type char), which is returned in
<em>charValue</em>. It is important to note that <strong>any</strong>
char value will be read, including any whitespace character.
-# The input stream cin is empty.
*/


void ReadDouble
(
    const string& userPrompt, //in
    double& doubleValue       //out
);
/**<
Gets a real (double) value from the user.
@return void
@param userPrompt Text of the prompt displayed to the user.
@param doubleValue Contains the real number entered by the user.
@pre
<em>userPrompt</em> has been initialized.
@post
-# The text in <em>userPrompt</em> has been displayed and the user
has entered a real number (a value of type <tt>double</tt>), which
is returned in <em>doubleValue</em>. If the user does not enter a
valid real number, the following message is displayed:
<pre>
Error: That was not a valid real number. Try again.
Press Enter to continue ...
</pre>
after which the prompt is displayed again and the user gets another
chance. This is essentially an infinite loop, so the user must eventually
enter a valid real number for the process to terminate normally.
-# The input stream cin is empty.
*/


void ReadInt
(
    const string& userPrompt, //in
    int& intValue             //out
);
/**<
Gets an integer (int) value from the user.
@return void
@param userPrompt Text of the prompt displayed to the user.
@param intValue Contains the integer value entered by the user.
@pre
<em>userPrompt</em> has been initialized.
@post
-# The text in <em>userPrompt</em> has been displayed and the user
has entered an integer (a value of type <tt>int</tt>), which is returned
in <em>intValue</em>. If the user does not enter a valid integer, the
following message is displayed:
<pre>
Error: That was not a valid integer. Try again.
Press Enter to continue ...
</pre>
after which the prompt is displayed again and the user gets another
chance. This is essentially an infinite loop, so the user must eventually
enter a valid integer value for the process to terminate normally.
-# The input stream cin is empty.
*/


void ReadThisLine
(
    const string& userPrompt, //in
    string& lineValue         //out
);
/**<
Reads the text entered by a user on the same line as the prompt.
@return void
@param userPrompt Text of the prompt displayed to the user.
@param lineValue Contains the text entered by the user.
@pre
<em>userPrompt</em> has been initialized.
@post
-# The text in <em>userPrompt</em> has been displayed and the user has
entered some text and then pressed Enter. All text entered on same line
as the prompt, after the prompt, (including all intermediate whitespace,
but not including the terminating newline character) is returned in
<em>lineValue</em>.
-# The input stream cin is empty.
*/


void ReadNextLine
(
    const string& userPrompt, //in
    string& lineValue         //out
);
/**<
Reads the text entered by a user on the line following the prompt.
@return void
@param userPrompt Text of the prompt displayed to the user.
@param lineValue Contains the line of text entered by the user.
@pre
<em>userPrompt</em> has been initialized.
@post
-# The text in <em>userPrompt</em> has been displayed and the
user has entered a line of input and then pressed Enter. The entire
line of input (including all intermediate whitespace, but not including
the terminating newline character) is returned in <em>lineValue</em>.
Note that in this case the input is entered on the line following
the prompt, while in each of the other Read* functions, the value is
entered by the user on the same line as the prompt for that value.
-# The input stream cin is empty.
*/


void ReadString
(
    const string& userPrompt, //in
    string& stringValue       //out
);
/**<
Gets a whitespace-delimited string value from the user.
@return void
@param userPrompt Text of the prompt displayed to the user.
@param stringValue Contains the string entered by the user.
@pre <em>userPrompt</em> has been initialized.
@post
-# The text in <em>userPrompt</em> has been displayed, and the user
has entered a string value and pressed Enter. The string value is
returned in <em>stringValue</em>. Note that the string read will be
terminated by any whitespace.
-# The input stream cin is empty.
*/


bool userSaysYes
(
    const string& question //in
);
/**<
Gets the user's yes-or-no answer to a single question.
@return <tt>true</tt> if the user answers "Yes" to the question asked,
and <tt>false</tt> otherwise.
@param question Text of the question the user is asked, including the
question mark.
@pre
-# <em>question</em> has been initialized.
-# The standard input stream is empty.
@post The text in <em>question</em> has been displayed, followed by
<tt>y/[n]</tt> and the user has responded by entering a character
and pressing Enter. The value <tt>true</tt> is returned if the user
responds positively to the question asked by entering a <tt>y</tt> or
a <tt>Y</tt>, or by entering any word beginning with either of these
letters. Entering any other letter or word, as well as simply
pressing the Enter key, will be interpreted as a negative response
and the return value will be <tt>false</tt>. The use of <tt>[n]</tt>
as part of the user prompt is meant to indicate to the user that simply
pressing Enter will generate a (default) response of "no". This is a
convention of reasonably widespread use in console applications.
*/


//
//
//************************************************************************
//Utility Class Section

class Menu
/**
For displaying menus and getting user menu choices in console applications.
The <tt>%Menu</tt> class provides a convenient way for simple text-based
console programs to display for the user a menu of choices. A menu has a
title and up to 20 numbered options which are  separated from the title by
a blank line when the menu is displayed. A menu knows what its range of
valid options is, and can get from the user a valid choice from that
range, or return an error value of -1 if the user fails to enter a valid
option number during three attempts (by default), or during some
client-chosen number of attempts.
*/
{
public:

    Menu();
    /**<
    Default constructor; creates a "blank" menu.
    @pre None
    @post A "blank" menu has been constructed which has
    the (default) title <tt>"Empty Menu"</tt> and no options.
    */


    Menu
    (
        const string& menuTitle //in
    );
    /**<
    Constructor for creating a menu with a user-supplied title
    but no options.
    @param menuTitle The text of the title for this menu.
    @pre <em>menuTitle</em> has been initialized and does not exceed
    70 characters in length.
    @post
    - Case 1 (typical): A menu has been constructed with a title
    given by the contents of <em>menuTitle</em>, and having 0 options.
    - Case 2 (error): If an attempt was made to use a title whose
    length exceeded the maximum length of 70 characters, the following
    message has been displayed and the user has pressed Enter:
<pre>
===== Error: %Menu title cannot exceed 70 characters in length.
The title
\<\<text_of_title_that_was_too_long_appears_here\>\>
was not added to the menu.
This menu has been given the following default title:
Empty %Menu
Press Enter to continue ...
</pre>
    */


   void setTitle
   (
       const string& menuTitle //in
   );
   /**<
   Sets (or resets) the menu title.
   @return void
   @param menuTitle Contains the text of the title for the menu.
   @pre <em>menuTitle</em> has been initialized and
   <em>menuTitle.length() <= 70</em>.
   @post
   - Case 1 (typical): The text in <em>menuTitle</em> has been
   assigned as the title of the menu.
   - Case 2 (error): If an attempt was made to set a title which
   exceeded the maximum length of 70 characters, the
   following message has been displayed, and the user has pressed
   Enter:
<pre>
===== Error: %Menu title cannot exceed 70 characters in length.
The title
\<\<text_of_title_that_was_too_long_appears_here\>\>
was not added to the menu. Previous title remains unchanged.
Press Enter to continue ...
</pre>
   In either case, the number of menu options is unchanged.
   */


    void addOption
    (
        const string& option //in
    );
    /**<
    Adds a new option to the menu and assigns it the next available
    option number.
    @return void
    @param option The text of the next option to be added to the menu.
    @pre
    The number of options on the menu is < 20.\n
    <em>option</em> has been initialized and has length <= 70 characters.
    @post
    - Case 1 (typical): The number of menu options has been
    incremented by 1 and the text in <em>option</em> has become the
    option with the new option number.
    - Case 2 (error): If the number of options was 20, then the
    following message has been displayed and the user has pressed
    Enter:
<pre>
===== Error: Number of menu options cannot exceed 20.
Option \<\<text_of_option_goes_here\>\> not added.
Press Enter to continue ...
</pre>
    - Case 3 (error): If an attempt was made to add an option which
    exceeded the maximum length of 70 characters, the following
    message has been displayed and the user has pressed Enter:
<pre>
===== Error: %Menu option cannot exceed 70 characters in length.
The option
\<\<text_of_option_that_was_too_long_appears_here\>\>
was not added to the menu.
Press Enter to continue ...
</pre>
    */


    void display() const;
    /**<
    Displays a "centered" menu on the screen.
    @return void
    @pre The menu has been initialized.
    @post The menu has been displayed on the screen, more or less
    centered left-to-right and top-to-bottom, but with a slight
    top-left bias. Note, however, that a blank menu, or a menu with
    just a title, is displayed with its title left-justified and with
    only the bias toward the top. Such a title is followed by a blank
    line and the following 1-line message, which also starts at the
    left margin:
<pre>
This menu currently has no options ...
</pre>
    The (typical) display format is achieved in the following way:
    - First, by displaying (1/2)(24-numMenuLines)+1 blank lines at
      the bottom of the screen.
    - Second, by arranging that column 38 (rather than column 40, of a
      typical 80 line display) be the column about which the menu title
      and the menu options are "centered" in the display.
    */


    int getChoice
    (
        int maxNumTries = 3, //in
        string userPrompt =
        "Enter the number of your menu choice here and press Enter: " //in
    ) const;
    /**<
    Gets a menu choice from the user, or a default value if the user
    fails to enter a valid menu choice before the permitted number
    of attempts runs out.
    @return The user's menu choice, or the default value of -1.
    @param maxNumTries The maximum number of tries permitted to the
    user to enter a valid menu choice.
    @param userPrompt The text of the prompt to be used to ask the
    user for a menu choice.
    @pre
    Typically, a menu has been initialized, and presumably
    displayed, though in fact this is not technically a necessary
    pre-condition for this function.
    @post
    - Case 1 (typical): A valid menu choice for the menu has been
    entered by the user and returned.
    - Case 2 (error): If a choice was sought from a blank menu, the
    message
<pre>
===== Error: The menu has no options from which to choose.
Press Enter to continue ...
</pre>
    has been displayed and the user has pressed Enter.
    - Case 3 (error): If an invalid menu choice has been entered, the
    displayed message is:
<pre>
===== Error: Sorry! Invalid response. Please try again:
</pre>
    If <em>maxNumTries</em> unsuccessful attempts have
    been made, the displayed message is:
<pre>
===== Error: Sorry, but you only get \<\<maxNumTries\>\> chances.
Press Enter to continue ...
</pre>
    and the user has pressed Enter, after which the value of -1
    is returned. Note that if no prompt is supplied by the client,
    the default prompt
<pre>
Enter the number of your menu choice here and press Enter:
</pre>
    is displayed slighty left-of-center on the screen below the
    menu.
    Note as well that anything other than a valid menu choice for
    the current menu will be read and rejected, including (for example)
    a valid menu choice followed by extraneous characters, as well
    as simply pressing Enter.
    */

private:
    static const int MAX_NUM_OPTIONS = 20;
    static const int MAX_OPTION_LENGTH = 70;
    static const int MAX_TITLE_LENGTH = 70;

    int numOptions;
    //Number of options currently on the menu.

    vector<string> menuText;
    //Contains the title and the options
    //Both constructors set the size of menuText to 1+MAX_NUM_OPTIONS,
    //which includes one row to hold the menu title, and MAX_NUM_OPTIONS
    //rows to hold the options.
};


class OperationCounter
/**
For counting operations performed by an algorithm.
An object of the <tt>%OperationCounter</tt> class may be used to keep
a count of the number of each of several different kinds operations
performed during the application of an algorithm to a data set. The
operations that can be counted are the usual comparisons, exchanges,
and assignments that one might be interested in tracking, as well as
one other kind of operation chosen by the client. The client may also
supply a name for that "other" operation, and use that name in summary
output.
*/
{
public:

    OperationCounter();
    /**<
    Default constructor.
    @pre None
    @post A counter object has been constructed, with all operation
    counters set to 0 and the name of the "other" operation set to
    "Other Op".
    */


    void reset();
    /**<
    Resets all operation counters to zero and the name of the "other"
    operation, if any, to an empty string.
    @return void
    @pre None
    @post All counting data members have been reset to 0, and the
    name of the "other" operation has been set to "Other Op".
    */


    void incrementAssignments
    (
        int numTimes = 1 //in
    );
    /**<
    Increments the counter for the number of assignment operations.
    @return void
    @param numTimes The number of times the assignment counter
    is to be incremented.
    @return void
    @pre None
    @post The number of assignment operations has been incremented
    by the value of <em>numTimes</em>.
    */


    void incrementComparisons
    (
        int numTimes = 1 //in
    );
    /**<
    Increments the counter for the number of comparison operations.
    @return void
    @param numTimes The number of times the comparison counter
    is to be incremented.
    @pre None
    @post The number of comparison operations has been incremented
    by the value of <em>numTimes</em>.
    */


    void incrementExchanges
    (
        int numTimes = 1 //in
    );
    /**<
    Increments the counter for the number of exchange operations.
    @return void
    @param numTimes The number of times the exchange counter
    is to be incremented.
    @pre None
    @post The number of exchange operations has been incremented
    by the value of <em>numTimes</em>.
    */


    void incrementOtherOp
    (
        int numTimes = 1 //in
    );
    /**<
    Increments the counter for the number of "other" operations.
    @return void
    @param numTimes The number of times the counter of the
    "other" operation is to be incremented.
    @pre None
    @post The number of "other" operations has been incremented
    by the value of <em>numTimes</em>.
    */


    int getNumberOfComparisons() const;
    /**<
    Gets the number of comparison operations counted.
    @return The number of comparison operations counted.
    @pre None
    @post No side effects.
    */


    int getNumberOfExchanges() const;
    /**<
    Gets the number of exchange operations counted.
    @return The number of exchange operations counted.
    @pre None
    @post No side effects.
    */


    int getNumberOfAssignments() const;
    /**<
    Gets the number of assignment operations counted.
    @return The number of assignment operations counted.
    @pre None
    @post No side effects.
    */


    int getNumberOfOtherOp() const;
    /**<
    Gets the number of "other" operations performed.
    @return The number of "other" operations counted.
    @pre None
    @post No side effects.
    */


    void setNameOfOtherOp
    (
        string nameOfOtherOp //in
    );
    /**<
    Sets (or resets) the name of the "other" operation.
    @return void
    @param nameOfOtherOp Text for the name of the "other" operation.
    @pre <em>nameOfOtherOp</em> has been initialized.
    @post The value of <em>nameOfOtherOp</em> has been assigned as
    the name of the other operation.
    */


    string getNameOfOtherOp() const;
    /**<
    Gets the name of the "other" operation.
    @return The name of the "other" operation.
    @pre None
    @post The name of the "other operation" has been returned (and
    will be "Other Op" unless it has been set to something
    else with setNameOfOtherOp().
    */


    void displayNonZeroCounts() const;
    /**<
    Displays a summary of the counts for all operations actually performed
    (and which therefore have non-zero counts). This method would normally
    be called if only one or two operations were being counted and the
    user did not want to take up space in the output with zero counts
    for the other operations.
    @return void
    @pre None
    @post
    - Case 1: Whatever counts of comparisons, number of exchanges, number
    of assignments and/or the number of operations of the "other" kind (if
    applicable) have been recorded by counter object and are non-zero have
    been displayed as shown below. That is, the title is displayed, along
    with those lines corresponding to non-zero counts.
<pre>
Summary of Non-Zero Operation Counts
Comparisons = #
Exchanges   = #
Assignments = #
Name of Other Operation = #
</pre>
    - Case 2: If all counts are zero, the following message is displayed.
<pre>
Summary of Non-Zero Operation Counts
No operations of any kind have been counted.
</pre>
    */


    void displayAllCounts() const;
    /**<
    Displays a summary of the number of operations counted. This method
    would normally be used when the user desires to see all counts, even
    if some are (and are known to be) zero.
    @return void
    @pre None
    @post
    - Case 1: All operation counts are displayed in the format shown below.
<pre>
Summary of All Operation Counts
Comparisons = #
Exchanges   = #
Assignments = #
Name of Other Operation = #
</pre>
    - Case 2: If all counts are zero, the following message is displayed:
<pre>
Summary of All Operation Counts
No operations of any kind have been counted.
</pre>
    */


private:
    int numComparisons;
    int numExchanges;
    int numAssignments;
    int numOtherOp;
    string nameOfOtherOp;
};



class RandomGenerator
/**
For generating pseudorandom integer, real, character and string values.
The <tt>%RandomGenerator</tt> class can be used to generate pseudorandom
values of the following types:
- int values in a user-chosen range
- double values in a user-chosen range
- char values in a user chosen range
- string values of a user chosen size, containing user-chosen characters
*/
{
public:

    RandomGenerator();
    /**<
    Default constructor, based on seed obtained from a call to the
    <tt>time()</tt> function. If a random generator constructed by
    this constructor is used, the sequence of random values will be
    different each time.
    @pre None
    @post The generator has been initialized with a random seed value
    obtained by a call to the <tt>time()</tt> function.
    */


    RandomGenerator
    (
        int userSeedValue //in
    );
    /**<
    Constructor based on a client-supplied seed. If a random generator
    constructed by this constructor is used, the <em>userSeedValue</em>
    used determines the sequence of random values obtained, and the same
    sequence of values can be obtained on a subsequent run by reusing
    the same <em>userSeedValue</em>. This same <em>userSeedValue</em> can
    be used to construct a new random generator object using this constructor,
    or to reset an already existing random generator object using the reset()
    method; either way, you get the same sequence of values as you did when
    that <em>userSeedValue</em> was employed previously.
    @param userSeedValue A seed value supplied by the client.
    @pre <em>userSeedValue</em> has been initialized.
    @post The generator has been initialized using a seed value
    (<em>userSeedValue</em>) supplied by the client.
    */


    void reset();
    /**<
    Resets the random generator using a seed obtained by a call to
    the <tt>time()</tt> function.
    @return void
    @pre None
    @post The generator has been re-initialized using a random seed
    value obtained by a call to the time function.
    */


    void reset
    (
        int userSeedValue //in
    );
    /**<
    Resets the random generator using a seed supplied by the client.
    @return void
    @pre userSeedValue has been initialized.
    @post The generator has been re-initialized using a seed value
    (userSeedValue) supplied by the client.
    */


    //
    //
    //********** Random int generators **********
    int getNext
    (
        int n //in
    );
    /**<
    Gets a pseudorandom integer in the range <em>[0,n)</em>.
    @return A pseudorandom int value in the range  <em>[0,n)</em>.
    @param n A positive integer value.
    @pre <em>n</em> has been initialized and <em>n > 0</em>.
    @post The object's internal random number generator has been
    called once.
    */


    int getNextInt
    (
        int n //in
    );
    /**<
    Same as getNext(int n) above, but with a more explicit name,
    for readability rather than for ease of use when programming
    "generically".
    */


    int getNext
    (
        int low, //in
        int high //in
    );
    /**<
    Gets a pseudorandom integer in the range [low,high].
    @return A pseudorandom integer value in the range <em>[low,high]</em>.
    @param low A positive integer value <= the value of <em>high</em>.
    @param high A positive integer value >= the value of <em>low</em>.
    @pre <em>low</em> and <em>high</em> have been initialized, and
    <em>low <= high</em>.
    @post The object's internal random number generator has been called
    once.
    */


    int getNextInt
    (
        int low, //in
        int high //in
    );
    /**<
    Same as getNext(int low, int high) above, but with a more
    explicit name, for readability rather than for ease of use
    when programming "generically".
    */


    //
    //
    //********** Random double generators **********
    double getNext
    (
        double x //in
    );
    /**<
    Gets a pseudorandom real (double) in the range [0,x).
    @return A pseudorandom double value in the range <em>[0,x)</em>.
    @param x A positive real (double) number.
    @pre <em>x</em> has been initialized and <em>x > 0</em>.
    @post The object's internal random number generator has been called
    once.
    */


    double getNextDouble
    (
        double x //in
    );
    /**<
    Same as getNext(double x) above, but with a more explicit name,
    for readability rather than for ease of use when programming
    "generically".
    */


    double getNext
    (
        double low, //in
        double high //in
    );
    /**<
    Gets a pseudorandom real (double) value in the range [low,high).
    @return A pseudorandom real (double) value in the range
    <em>[low,high)</em>.
    @param low A positive real (double) value < the value of <em>high</em>.
    @param high A positive real (double) value > the value of <em>low</em>.
    @pre <em>low</em> and <em>high</em> have been initialized, and
    <em>low < high</em>.
    @post The object's internal random number generator has been called
    once.
    */


    double getNextDouble
    (
        double low, //in
        double high //in
    );
    /**<
    Same as getNext(double low, double high) above, but with a more
    explicit name, for readability rather than for ease of use
    when programming "generically".
    */


    //
    //
    //********** Random string generators **********
    string getNext
    (
        const string& s //in
    );
    /**<
    Gets a pseudorandom string based on the length and content of
    <em>s</em>.
    @return A pseudorandom string object.
    @param s Any string of characters.
    @pre <em>s</em> has been initialized and <em>s.length() >= 2</em>.
    Let <em>a</em> and <em>b</em> represent the first two distinct
    characters in <em>s</em>. Suppose <em>a</em> occurs in the first
    <em>low</em> contiguous locations in <em>s</em>. Suppose <em>b</em>
    occurs in the next <em>high</em> contiguous locations in <em>s</em>.
    It is required that <em>a < b</em> and that <em>low <= high</em>.
    @post
    A pseudorandom string object has been returned, according to these rules:
    -# If <em>low == high</em>, then the length of any returned
    string is their common value.
    -# If <em>low < high</em>, then the length of any returned value
    is a random value in the range [low,high].
    -# If <em>s.length() == low+high</em>, the characters in the
    returned value are in the char range [a,b].
    -# If <em>s.length() > low+high</em>, the characters in any
    returned value come from the set of all characters in s, excluding
    the first two distinct characters.
    */


    string getNextString
    (
        const string& s //in
    );
    /**<
    Same as getNext(const string& s) above, but with a more explicit
    name, for readability rather than for ease of use when programming
    "generically".
    */


    string getNext
    (
        const string& first, //in
        const string& second //in
    );
    /**<
    Gets a random string in the "range" between the two strings
    <em>first</em> and <em>second</em>.
    @return A pseudorandom string object.
    @param first The "lower bound" of a "string range" from which
    the pseudorandom string object will be chosen.
    @param second The "upper bound" of a "string range" from which
    the pseudorandom string object will be chosen.
    @pre
    -# <em>first</em> and <em>second</em> have been initialized.
    -# <em>first <= second</em>.
    -# <em>first.length() <= second.length()</em>.
    @post A pseudorandom string value <tt>r</tt> satisfying the
    following three conditions is returned:
    -# <em>first <= r <= second</em>.
    -# <em>first.length() <= r.length() <= second.length()</em>.
    -# <em>r</em> contains only characters found in either
    <em>first</em> or <em>second</em>.
    */


    string getNextString
    (
        const string& first, //in
        const string& second //in
    );
    /**<
    Same as getNext(const string& first, const string& second)
    above, but with a more explicit name, for readability rather than
    for ease of use when programming "generically".
    */


    //
    //
    //********** Auxiliary random string generators **********
    //These are public since they may also be useful to class clients.
    string getNextStringFromCharRange
    (
        int size,       //in
        char firstChar, //in
        char lastChar   //in
    );
    /**<
    Gets a pseudorandom string containing <em>size</em> characters
    from the character range <em>[firstChar,secondChar]</em>.
    @return A pseudorandom string object.
    @param size The size of the string to be returned.
    @param firstChar The lower bound of the character range from which the
    characters for the returned string will be taken.
    @param lastChar The upper bound of the character range from which the
    characters for the returned string will be taken.
    @pre <em>size</em>, <em>first</em> and <em>last</em> have been
    initialized, with <em>size >=1</em>, <em>first <= last</em>.
    @post A pseudorandom string value containing <em>size</em> printable
    characters in the range <em>[first,last]</em> has been returned.
    */

    string getNextStringFromString
    (
        int size,            //in
        const string& source //in
    );
    /**<
    Gets a pseudorandom string containing <tt>size</tt> characters taken
    from the string <tt>s</tt>.
    @return A pseudorandom string object.
    @param size The size of the string to be returned.
    @param source The string from which the characters for the returned
    string will be taken.
    @pre <em>size</em> and <em>source</em> have been initialized, with
    <em>size >= 1</em> and <em>source</em> containing only printable
    characters.
    @post A random string value containing <em>size</em> printable
    characters, all of which appear in <em>source</em>, has been returned.
    */

private:
    int seed;
    void my_srand(int& seed);
    int my_rand();
};



class Stopwatch
/**
For measuring the time taken by an algorithm to perform its task.
An object of class <tt>%Stopwatch</tt> will behave like a stopwatch.
It can be started, stopped, and asked for the time elapsed.
This time can be computer time (clock ticks), or real time as measured
in seconds, minutes, or hours.
*/
{
public:

    Stopwatch();
    /**<
    Default constructor.
    @pre None
    @post The clock time at the time of declaration has been recorded.
    */

    Stopwatch
    (
        const string nameOfEventToBeTimed //in
    );
    /**<
    Constructor which allows the naming of the event to be timed.
    @pre None
    @post The clock time at the time of declaration has been recorded,
    as well as the name of the event to be timed.
    */

    void setEventName
    (
        const string nameOfEventToBeTimed //in
    );
    /**<
    Sets, or resets, the name of the event to be timed.
    @return void
    @pre None
    @post The name of the event to be timed has been set to be the text
    contained in nameOfEventToBeTimed, which may be the empty string
    if no name is desired.
    */

    string getEventName() const;
    /**<
    Gets the current name of the event to be timed.
    @return The current name of the event to be timed.
    @pre None
    @post No side effects.
    */


    void start();
    /**<
    Causes the stopwatch to start running.
    @return void
    @pre <em>stop()</em> has been called, or <em>start()</em> has
    never been called.
    @post The stopwatch timer has been "started" and the clock time
    at start time has been recorded, in computer clock ticks.
    */


    void stop();
    /**<
    Causes the stopwatch to stop running.
    @return void
    @pre <em>start()</em> has been called.
    @post The stopwatch timer has been "stopped" and the accumulated
    time since <em>start()</em> was called has been recorded.
    */


    void delay
    (
        int delayFactor = 1 //in
    ) const;
    /**<
    Adds some multiple of an artifical amount of time to the
    accumulated time on the stopwatch.
    @return void
    @pre <tt>start()</tt> has been called.
    @post An artificial amount of time has been added to the total
    computer process time as reported by the clock function. In other
    words, during this delay time the "stopwatch" continues to
    accumulate time but nothing else happens. Thus this is a way to
    make an operation appear to take longer than it actually does.
    It can be used to cause the stopwatch to accumulate "artificial"
    time when monitoring the performance of an algorithm on a relatively
    small data set. This helps us to overcome the problem of trying to
    measure the amount of time taken to perform a calulation and finding
    that it took "no time at all". Note that we still cannot measure the
    absoute time taken, but fortunately we are often only interested in
    measuring the relative time taken by the same algorithm on data sets
    of different sizes, or by different algorithms on data sets of the
    same size. The input parameter <em>delayFactor</em> is a linear
    multiplier for increasing the amount of delay time. For example,
    a <em>delayFactor</em> of 2 doubles the amount of delay time
    accumulated by a single call to the <em>delay()</em> member function.
    */


    clock_t getTicks() const;
    /**<
    Gets the number of clock ticks between the most recent calls of
    <em>start()</em> and <em>stop()</em>.
    @return The number of clock ticks between the last calls to
    <em>start()</em> and <em>stop()</em>.
    @pre <em>start()</em> and <em>stop()</em> have been called (in that
    order).
    @post The accumulated time, in computer clock ticks, between the times
    when the stopwatch was last started and stopped, has been returned.
    */


    double getSeconds() const;
    /**<
    Gets the number of seconds between the last calls of
    <em>start()</em> and <em>stop()</em>.
    @return The number of seconds between the last calls to
    <em>start()</em> and <em>stop()</em>.
    @pre <em>start()</em> and <em>stop()</em> have been called
    (in that order).
    @post The accumulated time, in seconds, between the times when the
    stopwatch was last started and stopped, has been returned.
    */


    double getMinutes() const;
    /**<
    Gets the number of minutes between the last calls of
    <em>start()</em> and <em>stop()</em>.
    @return The number of minutes between the last calls to
    <em>start()</em> and <em>stop()</em>.
    @pre <em>start()</em> and <em>stop()</em> have been called (in
    that order).
    @post The accumulated time, in minutes, between the times when the
    stopwatch was last started and stopped, has been returned.
    */


    double getHours() const;
    /**<
    Gets the number of hours between the last calls of
    <em>start()</em> and <em>stop()</em>.
    @return The number of hours between the last calls to
    <em>start()</em> and <em>stop()</em>.
    @pre <em>start()</em> and <em>stop()</em> have been called
    (in that order).
    @post The accumulated time, in hours, between the times when
    the stopwatch was last started and stopped, has been returned.
    */


    void display() const;
    /**<
    Displays the time, in hours (as an integer value), minutes (as an
    integer value), and seconds (as a double value), between the last
    time this <tt>%Stopwatch</tt> object was started and stopped.
    @pre <em>start()</em> and <em>stop()</em> must have been called,
    in that order.
    @post
    - Case 1: If no name has been given to the event that has just been
    timed, the ouput displayed is this:
<pre>
Total time elapsed = hh:mm:ss.sss
</pre>
    - Case 2: If a name (name-of-event) has been given to the event that
    has just been timed, the ouput displayed is this:
<pre>
Total time elapsed for event name-of-event = hh:mm:ss.sss
</pre>
    */

private:
    clock_t numClockTicksPassed;
    string eventName;
};


class TextItems
/**
For displaying on-line help and other text messages in
console applications.
The Textitems class provides a convenient mechanism for holding, in
memory, any number of "text items" and displaying any one of these text
items as required by the program. A "text item" consists of one or more
lines of text and all text items are loaded in from a textfile, which
must have the format specified below. One obvious use for this class
would be for handling on-line help, but any text item, consisting of
any number of lines, that needs to be displayed one or more times by
a program may be considered a candiate to become a "text item".

Any textfile containing text items must contain at least one text
item. Any such file and each text item in it must be formatted
according to the following rules:

-# All lines of text from the beginning of the file down to the first
line consisting of 40 equal signs will be ignored. Thus one or more
lines that serve to identify file content to a human reader of the
file may be placed before this line. Such a line of 40 equal signs
must be left-justified. A left-justified line of 40 equal signs looks
like this:
<pre>
========================================
</pre>
-# The first line of each text item must be its "title", i.e., the
exact string that will be used by the program to access that particular
text item for display. The title is not displayed when the text item is
displayed; it is used solely for identifying the item. There must be no
leading or trailing spaces in the title.
-# Each text item must be terminated by a line of exactly 40 dashes
(hyphens) which is not regarded as part of the item itself (and is
therefore not displayed when the text item is shown on the screen).
Each item-terminating line of 40 dashes must be left-justified.
A left-justified line of 40 dashes looks like this:
<pre>
----------------------------------------
</pre>
-# The body of a text item may contain one or more lines consisting
of exactly 40 exclamation marks (!) among the lines of "regular" text.
Such a line indicates a point where the display must pause and ask the
user to press Enter to continue, but the line itself is not displayed.
Such a line of 40 exclamation marks must be left-justified. A
left-justified line of 40 exclamation marks looks like this:
<pre>
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
</pre>
-# The last text item in the file must be followed immediately by an
additional line of 40 equal signs like that shown above. Any text
following this line in the file will also be ignored. It may thus
be inferred that a file of text items will normally contain exactly
two left-justified lines consisting of 40 equal signs, and there may
(or may not) be text before the first one, and after the second one,
with all such text being ingored by any program reading the file.
-#  Keep all lines in a text item strictly less than 80 characters in
length. In the first place, any line longer than this will likely wrap
to a second line, and may not break where you'd like it to.  Second,
some systems (DOS/Windows, for example) seem to put  an automatic line
feed at the end of each line of exactly 80 characters.
So, keeping lines under 80 characters in length will avoid extraneous
blank lines in the output that might be introduced in this way.
*/
{
public:

    TextItems();
    /**<
    Default constructor.
    @pre None
    @post The list of text items has been initialized and is empty.
    However, the program is then terminated after displaying the
    following 6-line message:
<pre>
Error: File name must be supplied when declaring
a %TextItems object, as in (for example):
%TextItems myTextItems("my_text_item_file.dat");
Program is now terminating.
Press Enter to continue ...
</pre>
    */


    TextItems
    (
        const string fileName //in
    );
    /**<
    Constructor which gets its list of text items from a textfile.
    @pre <em>fileName</em> has been initialized.
    @post
    - Case 1 (typical): If <em>fileName</em> contains the name (or
    the full pathname) of a properly-formatted file of text items, all
    text items in that file have been read into memory and the constructed
    object contains this list of text items.
    - Case 2 (error): If <em>fileName</em> contains the name of
    an empty file, the program displays this 3-line message:
<pre>
Error: Input file of text items is empty.
Program is now terminating.
Press Enter to continue ...
</pre>
    - Case 3: If <em>fileName</em> contains the name of a file that
    doesn't exist, the program will give the user one opportunity to
    rectify the situation by entering, from the standard input, the
    name of a valid file of text items (or the name and path to the
    file if it's not in the working directory). If the user then fails
    to do so, the program displays this 3-line message:
<pre>
Error: Input file of text items does not exist.
Program is now terminating.
Press Enter to continue ...
</pre>
    The program thus terminates if a validly-named file is empty, or
    if the name of a valid file is not supplied, either initially, or
    during the one additional permitted attempt.
    */


    void displayItem
    (
        const string title //in
    ) const;
    /**<
    Displays a text item on the standard output.
    @pre <em>title</em> has been initialized.
    @post
    - Case 1 (typical): The text item identified by <em>title</em>
    has been displayed.
    - Case 2 (error): If the text item designated by <em>title</em>
    cannot be found, the following 2-line message is displayed:
<pre>
Error: Text item \<\<title\>\> not found.
Press Enter to continue ...
</pre>
    */

private:
    vector< vector<string> > itemList;
};


//DisplayOpeningScreen free function
//********************************************************************
inline void DisplayOpeningScreen
(
    const string& programmerInfo, //in
    const string& programInfo,    //in
    int numBlankLinesBefore,      //in
    int numBlankLinesAfter        //in
)
{
    string blankLinesBefore(numBlankLinesBefore, '\n'),
        blankLinesAfter(numBlankLinesAfter, '\n');
    cout << blankLinesBefore
        << programmerInfo << "\n"
        << programInfo
        << "\nThe main driver of this executable was built on " << __DATE__
        << " at " << __TIME__ << ".\n"
        << blankLinesAfter;
    Pause();
}

} //End of this part of namespace Scobey

#endif
