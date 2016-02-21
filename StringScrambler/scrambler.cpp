#include "scrambler.h"

/*
Main Function Section
*/
int main ()
{
    string userInput;

    int choice = mainMenu();

    while (choice >=1 || choice <=3)
    {
        switch (choice)
        {
        case 1:
            cout << "Goodbye!" << endl << endl;
            Pause();
            exit(1);
            break;

        case 2:
            cout<< "Enter text to be scrambled below: \n";
            getline(cin, userInput);

            cout << endl << endl;

            while (!userInput.empty())
            {
                cout << "Scrambled:     " << "\""
                    << scrambleText(userInput)<< "\""<<endl;
                Pause();

                cout << endl <<"Enter more text to be scrambled,"
                    <<" or press enter to return to the menu: \n";
                getline(cin, userInput);
                cout << endl << endl;
            }

            choice = mainMenu();
            break;

        case 3:
            cout<< "Enter text to be unscrambled below: \n";
            getline(cin, userInput);

            cout << endl << endl;

            while (!userInput.empty())
            {
                cout << "Unscrambled:     " << "\""
                    << unscrambleText(userInput)<< "\""<<endl;
                Pause();

                cout << endl <<"Enter more text to be unscrambled,"
                    <<" or press enter to return to the menu: \n";
                getline(cin, userInput);
                cout << endl << endl;
            }

            choice = mainMenu();
            break;

        default:
            break;
        }
    }

    Pause();
    return 0;
}

/*
Definition Section for prototypes
*/

//defination for mainMenu fuction
int mainMenu()
{
    Menu m;

    m.setTitle("Choose Action:");
    m.addOption("Quit");
    m.addOption("Scramble Text");
    m.addOption("Unscramble Text");
    m.display();

    return m.getChoice();
}

//definition for scrambleText fucntion
string scrambleText(string userInput)
{
    if (0 < userInput.length())
    {
        string value, lowerValue, upperValue;

        int mid = (0 + userInput.length()) / 2;   //find the middle value

        value = userInput.substr(mid, 1);

        //separate the string into lowerPart
        lowerValue = userInput.substr(0, mid);

        //scramble lowerPart recurssivley
        if (lowerValue.length() > 0)
        {
            lowerValue = scrambleText(lowerValue);
        }

        //separate the string into upperPart
        upperValue = userInput.substr((mid +1) , mid);

        //scramble upperPart recurssivley
        if (upperValue.length() > 0)
        {
            upperValue = scrambleText(upperValue);
        }

        value = value + lowerValue + upperValue;

        return value;
    }

    return 0;
}

//defination for unscrambleText fucntion
string unscrambleText(string userInput)
{
    if (0 < userInput.length())
    {
        string value, lowerValue, upperValue;

        int mid = (0 + userInput.length()) / 2;   //find the middle value

        //get the first value of the string
        value = userInput.substr(0, 1);

        //separate the string into lowerPart
        lowerValue = userInput.substr(1, mid);

        //scramble lowerPart recurssivley
        if (lowerValue.length() > 0)
        {
            lowerValue = unscrambleText(lowerValue);
        }

        //separate the string into upperPart
        upperValue = userInput.substr((mid + 1), mid);

        //unscramble upperPart recurssivley
        if (upperValue.length() > 0)
        {
            upperValue = unscrambleText(upperValue);
        }

        value = lowerValue + value + upperValue;

        return value;
    }

    return 0;
}