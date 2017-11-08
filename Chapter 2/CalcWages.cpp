// Raul Conover
// 9/11/2017
// Calculate Wages Program

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double hours, rate, pay;

	// get number of hours worked
	cout << "How many hours did you work? ";
	cin >> hours;

	// get the hourly pay rate
	cout << "How much did you get paid per hour? ";
	cin >> rate;

	if(hours <= 40)
		//calculate the pay
		pay = hours * rate;
	else
	{
		//calculate overtime
		pay = 40 * rate + (hours - 40) * 1.5 * rate;
		cout << "Overtime Calculated!\n";
	}

	// display the pay.
	cout << fixed << showpoint << setprecision(2);
	cout << "You have earned $" << pay << endl;
	return 0;
}