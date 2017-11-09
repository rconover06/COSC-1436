/*	Raul Conover and Kip Fletcher
	09/207/2017
	Group Problem
	Quadratic Formula Program
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double a, b, c, x1, x2, solutions;

	cout << "Enter the vaules for 3 coefficients:" << endl;
	cin >> a >> b >> c;


	// Output the equation in General Form.
	cout << endl <<"General Form  of the quadratic equation: " << endl
		<< a << "x^2 + " << b << "x + " << c << " = 0" << endl << endl;

	cout << fixed << showpoint << setprecision(2);

	// Determine how many possible solutions exist if any.
	solutions = b * b - 4 * a * c;

	if (solutions > 0) // 2 possible solutions
	{
		x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		cout << "The polynomial has 2 real solutions. They are x =" << x1 << " and x = " << x2 << endl << endl;
	}

	else if (solutions == 0) // One possible Solution
	{
		x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		cout << "There is one unique solution. The solution is x = " << x1 << endl << endl;
	}
	else
		cout << "There are no solutions.";

	return 0;
}