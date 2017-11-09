/* 
 * File:   Switch Statements.cpp
 * Author: Raul Conover
 *
 * Created on October 3, 2017
 * 
 *  Write a program that uses switch statements to print out the number of days
 *  in a given month.
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Constants for menu choice in Do..While Loop.
    const int CONTINUE_CHOICE = 1,
              QUIT_CHOICE = 2;
    
    // Declare variables
    int month, 
        year, 
        days,
        choice;
    
    cout << "This program will tell you how many days are in a month\n\n";
    do
    {
        // Display the menu to continue or quit the program.
        cout << "Select an option:" << endl
             << "\t1. To Continue." << endl
             << "\t2. To Quit the program." << endl
             << "Selection: ";
        cin >> choice;
        
        // Validate the menu choice.
        while (choice < CONTINUE_CHOICE || choice > QUIT_CHOICE)
        {
            cout << "Please enter a valid option: ";
            cin >> choice;
        }
        
        // Process the users choice. This part will print the number of days in
        // the selected month.
        if (choice != QUIT_CHOICE)
        {
            cout << "Enter the the month number (1-12): ";
            cin >> month;

			switch(month)
            {
                case 1: cout << "January has 31 days.\n\n";
                    break;
                case 3: cout << "March has 31 days.\n\n";
                    break;
				case 2:                 
					cout << "Enter a year: ";
					cin >> year;
					if (year % 100 == 0 && year % 400 == 0)
						cout << "February has 29 days.\n\n";
					else if (year % 4 == 0 && year % 100 != 0)
						cout << "Februrary has 29 days.\n\n";
					else
						cout << "February has 28 days.\n\n";
					break;
                case 4: cout << "April has 30 days.\n\n";
					break;
                case 5: cout << "May has 31 days.\n\n";
                    break;
                case 6: cout << "June has 30 days.\n\n";
                    break;
                case 7: cout << "July has 31 days.\n\n";
                    break;
                case 8: cout << "August has 31 days.\n\n";
                    break;
                case 9: cout << "September has 30 days.\n\n";
                    break;
                case 10: cout << "October has 31 days.\n\n";
                    break;
                case 11: cout << "November has 30 days.\n\n";
                    break;
                case 12: cout << "December has 31 days.\n\n";
                    break;
                default: cout << "INVALID ENTRY\n\n";
            }
            }
        }
    }
    while (choice != QUIT_CHOICE);    
    cout << "Thank you!\n\n";
    return 0;
}

