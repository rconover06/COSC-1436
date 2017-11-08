/* 
 * File:   Ch 5-4 input output file binary.cpp
 * Author: Raul Conover
 *
 * Created on October 18, 2017
 * 
 * Description: This program will ask a user for an int between 0 and 255 and 
 * convert the decimal number into an unsigned binary number.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	ifstream infile;
	ofstream outfile;

    // Variables
    int i, decimal, bit;

	infile.open("Ch 5-4 inputfile.txt");
	
	if (!infile)
	{
		cout << "INPUT FILE NOT FOUND. PROGRAM ABORTED." << endl;
		return 1;
	}
	outfile.open("Ch 5-4 Output.txt");
    
	do
	{
			// import an integar value for decimal.
			infile >> decimal;
			bit = 32768;

			if (decimal >= 0 && decimal <= 65535)
			{
				outfile << decimal << " converted to unsigned binary:";
				for (i = 0; i < 16; i++)
				{
					// This will inset a space every 4 iterations.
					if (i % 4 == 0)
						outfile << " ";

					if (decimal - bit < 0)
					{
						outfile << "0";
					}
					else
					{
						outfile << "1";
						decimal = decimal - bit;
					}
					bit /= 2;
				}
			}
			else
			{
				outfile << "ERROR! Input value " << decimal
					 << " is out of range for this program.";
			}
			outfile << endl;
	} while (infile);
    return 0;
}