/* 
 * Author: Raul Conover
 *
 * Created on November 1, 2017
 * 
 * Description: This program will ask a user for an int between 0 and 255 and 
 * convert the decimal number into an unsigned binary number. This time with Functions!
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Function Protopyes.
void binaryConverter(int);
void printLines(int, int, char);
                                        
int main()
{
    // Variables
    int decimal;
	char repeat;
    
	do
	{
		printLines(2, 60, '-');			// Function call with aruments.
		// Ask the user for an integer value.
		cout << "Input a value between 0 and 65,535: ";
		cin >> decimal;

		printLines(1, 60, '=');			// Function call with aruments.
		binaryConverter(decimal);		// Function call with aruments.
		printLines(1, 60, '=');			// Function call with aruments.

		cout << "Would you like to convert another number? y or n: ";
		cin >> repeat;
		repeat = tolower(repeat);	

	} while (repeat == 'y');

	cout << "Thank you!" << endl;
	printLines(2, 60, '-');				// Function call with aruments.
    return 0;
}

// Function Definition with formal parameters.
void printLines(int lines, int length, char symbol)
{
	int i, j;			// Local variables.

	for (i = 1; i <= lines; i++)
	{

		for (j = 1; j <= length; j++)
			cout << symbol;
		cout << endl;
	}
}

// Function Definition with formal parameters.
void binaryConverter(int decimal)
{
	int bit = 32768, i;			// Local Variables

	if (decimal >= 0 && decimal <= 65535)
	{
		cout << decimal << " converted to unsigned binary:";
		for (i = 0; i < 16; i++)
		{
			// This will inset a space every 4 iterations.
			if (i % 4 == 0)
				cout << " ";

			if (decimal - bit < 0)
			{
				cout << "0";
			}
			else
			{
				cout << "1";
				decimal = decimal - bit;
			}
			bit /= 2;
		}
		cout << endl;
	}
	else
	{
		cout << "ERROR! Input value " << decimal
			<< " is out of range for this program." << endl;
	}
}