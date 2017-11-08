/* 
 * File:   Ch 5-3 Looping Binary Conversion.cpp
 * Author: Raul Conover
 *
 * Created on October 17, 2017
 * 
 * Description: This program will ask a user for an int between 0 and 255 and 
 * convert the decimal number into an unsigned binary number.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    int i, decimal, bit;
	char repeat;
    
	do
	{
			// Ask the user for an integer value.
			cout << "Input a value between 0 and 65,535: ";
			cin >> decimal;
			bit = 32768;

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
			}
			else
			{
				cout << "ERROR! Input value " << decimal
					 << " is out of range for this program.";
			}
			cout << endl << endl;
			cout << "Would you like to convert another number? y or n: ";
			cin >> repeat;
			repeat = tolower(repeat);
			cout << endl;
	} while (repeat == 'y');
	cout << "Thank you!\n\n";
    return 0;
}