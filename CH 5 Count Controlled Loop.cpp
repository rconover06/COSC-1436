/*	
*	Raul Conover
*	October 10/16/2017
*	finding an average with count controlled loop
*
*
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int num, i, grade, total, low = 100;
	double avg;

	cout << "Enter number of grades to average: ";
	cin >> num;
	i = 1;
	total = 0;
	while (i <= num){
		cout << "Enter grade " << setw(2) << i << ": ";
		cin >> grade;
		total = total + grade;
		if (grade < low)
			low = grade;
		i++;
	}
	if (total > 1) {
		avg = double(total-low) / (num-1);
		cout << "Your average after dropping low grade of " << low <<
			" is: " <<
			fixed << showpoint << setprecision(1) << avg << endl;
	}
	else
		cout << "No valid grades to average." << endl;

	return 0;
}