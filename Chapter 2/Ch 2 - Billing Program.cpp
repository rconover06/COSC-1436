// Raul Conover
// 9/13/2017
// Program that calculates tax, tip and prints the totals as a reciept.

#include <iostream>
#include <iomanip>
#include<string>
using namespace std;

int main()
{
	//declare constants and variables
	const double TAX = 0.0825, TIP = 0.15;
	double mealCharge, taxAmount, tipAmount, totalBill;

	//Ask the user for the mealCharge
	cout << "Please enter in the cost of the meal(before tax and tip): ";
	cin >> mealCharge;
	
	//Calculate the taxAmount, tipAmount, and totalBill
	taxAmount = mealCharge * TAX;
	tipAmount = (mealCharge + taxAmount) * TIP;
	totalBill = mealCharge + tipAmount + taxAmount;

	//Print out
	cout << fixed << showpoint << setprecision(2);
	cout << "Raul's Tacos" << endl;
	cout << "Raul Conover" << endl;
	cout << "Meal Charge: $" << setw(6) << mealCharge << endl;
	cout << "Tax:         $" << setw(6) << taxAmount << endl;
	cout << "Tip:         $" << setw(6) << tipAmount << endl;
	cout << "Total:       $" << setw(6) << totalBill << endl;

	return 0;
}
