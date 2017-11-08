/* 
 * File:   Chapter 4-2 Problem.cpp
 * Author: Raul Conover
 * Created on October 5, 2017
 * 
 * Description: Program will ask a user what medium sound waves are traveling
 * through and a distance and the program will calculate how long it will take
 * travel that distance.
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// Constants for foot per second speed in air, water, and steel.
	const int AIR_CHOICE = 1,
		H2O_CHOICE = 2,
		STL_CHOICE = 3,
		QUIT_CHOICE = 4,
		AIR_FPS = 1100,
		H2O_FPS = 4900,
		STL_FPS = 1640;

	// Variables
	int choice;
	double distance, time;

	do
	{
		// Display the menu for the program.
		cout << "Select a medium the sound wave is traveling through or option 4 to quit.\n"
			<< "\t1. Air\n"
			<< "\t2. Water\n"
			<< "\t3. Steel\n"
			<< "\t4. To exit the program.\n"
			<< "Selection: ";
		cin >> choice;

		// Validate the menu choice.
		while (choice < AIR_CHOICE || choice > QUIT_CHOICE)
		{
			cout << "Enter a valid menu option: ";
			cin >> choice;
		}
		// Process the user choice
		if (choice != QUIT_CHOICE)
		{
			cout << "Enter a distance in feet: ";
			cin >> distance;

			// Validate the distance is not negative.
			if (distance <= 0)
			{
				cout << "ERROR! Enter a non negative distance.\n\n";
			}
			else
			{
				cout << fixed << showpoint << setprecision(1);
				// Air
				if (choice == AIR_CHOICE)
				{
					time = distance / AIR_FPS;
					cout << "Through air, sound waves travel " << distance
						<< " feet in " << setprecision(4) << time << " seconds.\n\n";
				}
				// Water 
				else if (choice == H2O_CHOICE)
				{
					time = distance / H2O_FPS;
					cout << "Through Water, sound waves travel " << distance
						<< " feet in " << setprecision(4) << time << " seconds.\n\n";
				}
				else
				{
					time = distance / STL_FPS;
					cout << "Through steel, sound waves travel " << distance
						<< " feet in " << setprecision(4) << time << " seconds.\n\n";
				}
			}
		}
	}
    while (choice != QUIT_CHOICE);
    cout << "Thank you!" << endl << endl;
    return 0;
}