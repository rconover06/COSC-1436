/*
*	Raul Conover
*	10/16/2017
*	Chapter 5 Part 2
*
*	Description: Print the following table. Each row has an integar, its square, its cube,
*	and then its square root to two decimal places. Print column headings. Start with
*	integars 50 and end with 75 (inclusive). After all rows have printed , print a new line 
*	and the totals for each column. Save output to a file.
*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

int main() 
{
	// Create the output file.
	ofstream outputFile;
	outputFile.open("Ch 5-2 Output.txt");

	// Variables
	int i;

	double	i_row,
			i_sq,
			i_cu,
			i_sqrt,
			int_total = 0,
			sq_total = 0,
			cu_total = 0,
			sqrt_total = 0;
	// Create the header for the file.
	outputFile << "Integar " << "Squared " << "Cubed  " << "Square Root" << endl;
	for (i = 50; i <= 75; i++)
	{
		// Calculate the values to be printed in each row.
		outputFile << setprecision(0);
		i_row = i;
		i_sq = i * i;
		i_cu = i * i * i;
		i_sqrt = sqrt(i);
		outputFile << setw(7) << i_row << " " << setw(7) << i_sq << " " << setw(6) << i_cu << " " << setw(11) << setprecision(2) << fixed << i_sqrt << endl;

		// Start calculating totals for the final line.
		int_total = i_row + int_total;
		sq_total = i_sq + sq_total;
		cu_total = i_cu + sq_total;
		sqrt_total = i_sqrt + sqrt_total;
	}
	// Output a line with the totals for each column.
	outputFile << setprecision(0);
	outputFile << setw(7) <<int_total << " " << setw(7) << sq_total << " " << setw(6) << cu_total << " " << setw(11) << fixed << setprecision(2) << sqrt_total << endl;

	return 0;
}