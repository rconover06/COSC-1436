/*	
*	Raul Conover
*	October 10/16/2017
*	finding an average with an event controlled loop by
*	testing the state of the input string.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i, grade, total, low = 100;
	double avg;

	cout << "Enter grades, Q to quit." << endl;
	i = 0;				// i holds the number of valid grades.
	total = 0;
	cout << "Enter grade " << setw(2) << i+1 << ": ";
	//cin >> grade; // When shortcut conditionis used , this is not needed.

	while (cin >> grade) {		// The stream name can be tested by a bool variable.
		total = total + grade;
		i++;
		if (grade < low)
			low = grade;
		cout << "Enter grade " << setw(2) << i+1 << ": ";
		//cin >> grade; // When shortcut condition is used, this is not needed.
	}
	if (i > 1) {
		avg = double(total - low) / (i - 1);
		cout << "Your average after dropping low grade of " << low <<
			" is: " <<
			fixed << showpoint << setprecision(1) << avg << endl;
	}
	else if (i == 1) {
		cout << "Your Average is: " << total << endl;
		avg = total;
	}
	else {
		cout << "No valid grades to average." << endl;
		avg = -1;
	}

	if (avg >= 89.5)
		cout << "Your letter grade is A." << endl;
	else if (avg >= 79.5 && avg <= 89.5)
		cout << "Your letter grade is B." << endl;
	else if (avg >= 69.5 && avg <= 79.5)
		cout << "Your letter grade is C." << endl;
	else if (avg >= 59.5 && avg <= 69.5)
		cout << "Your letter grade is D." << endl;
	else if (avg >= 0 && avg <= 59.5)
		cout << "Your letter grade is F." << endl;
	else
	

	return 0;
}