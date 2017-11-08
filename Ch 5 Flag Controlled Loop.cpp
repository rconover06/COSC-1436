/*	
*	Raul Conover
*	October 10/16/2017
*	finding an average with an event controlled loop by
*	testing the state of the input string.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	ifstream infile;
	ofstream outfile;

	int i, grade, total, low = 100;
	double avg;

	// Connect to the file.
	infile.open("gradedata.txt");

	// Test for open failure.
	if (!infile)
	{
		cout << "INPUT FILE NOT FOUND. PROGRAM ABORTED." << endl;
		return 1;
	}
	outfile.open("graderesults.txt");

	cout << "Enter grades, Enter -1 to quit." << endl;
	i = 0;		// i holds the number of valid grades.
	total = 0;
	cout << "Enter grade " << setw(2) << i+1 << ": ";
	cin >> grade;

	while (grade >= 0) {
		total = total + grade;
		i++;
		if (grade < low)
			low = grade;
		cout << "Enter grade " << setw(2) << i+1 << ": ";
		cin >> grade;
	}
	if (i > 1) {
		avg = double(total - low) / (i - 1);
		cout << "Your average after dropping low grade of " << low <<
			" is: " <<
			fixed << showpoint << setprecision(1) << avg << endl;
	}
	else if (i == 1)
		cout << "Your Average is " << total << endl;
	else
		cout << "No valid grades to average." << endl;

	return 0;
}