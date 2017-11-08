/* Raul Conover
   09/27/2017
   COSC 1436 LAB - Program together,
		Accept 4 grades
		Drop lowest grade
		Find average and print with one place afer the decimal.
		print corresponding letter grade. */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	int ex1, ex2, ex3, ex4, low;
	double average;
	char letterGrade;

	cout << "Enter 4 exam scores: " << endl;
	cin >> ex1 >> ex2 >> ex3 >> ex4;

	low = ex1;

	// Find the lowest value.
	if (ex2 < low)
		low = ex2;
	if (ex3 < low)
		low = ex3;
	if (ex4 < low)
		low = ex4;

	//Find the average. Add all exams and subtract the lowest.
	average = (ex1 + ex2 + ex3 + ex4 - low) / 3.0;

	//Determine the letterGrade
	if (average >= 89.5)
		letterGrade = 'A';
	else if (average >= 79.5)
		letterGrade = 'B';
	else if (average >= 69.5)
		letterGrade = 'C';
	else if (average >= 59.5)
		letterGrade = 'D';
	else
		letterGrade = 'F';

	cout << fixed << showpoint << setprecision(1);
	cout << "Lowest Exam was dropped." << endl
		 << "You earned an average of " << average << " "
		 << letterGrade << endl;

	//cout << "Lowest Grade Dropped: " << low << endl;		// For debugging purposes

	return 0;
}
