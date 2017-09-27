// Raul Conover
// 09/18/2017
// Chapter 3 Problems
/* Ask for a radius and height, then calculate area, and circumference of a circle,
volume and surface area of a sphere and volume and surface area of a cone. 
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = 3.1416;

int main()
{
	double radius, radiusSq, radiusCu, area, circumference, volume, surfaceArea, height, coneVolume, coneSurfaceArea, slantHeight, slantRt;

	// Ask the user for the radius in Centemeters.
	cout << "Enter the radius in centimeters (cm): ";
	cin >> radius;

	// Ask the user for the height (used for cone calculations).
	cout << "Enter the height in centimeters (cm): ";
	cin >> height;

	// Calculate Radius squared and Radius cubed
	radiusSq = radius * radius;
	radiusCu = pow(radius, 3);

	// CIRCLE - Calculate circumference and area of a circle with that radius.
	area = PI * radiusSq;
	circumference = 2 * PI * radius;

	// SPHERE - Calculate volume and surface area for a sphere with that radius.
	volume = (4.0 / 3.0) * PI * radiusCu;
	surfaceArea = 4 * PI * radiusSq;

	// CONE - Calculate coneVolume, slantHeight, and coneSurfaceArea.
	coneVolume = (1.0 / 3.0) * PI * radiusSq * height;
	slantRt = radiusSq + height * height;
	slantHeight = sqrt(slantRt);
	coneSurfaceArea = PI * radiusSq + PI * radius * slantHeight;

	// Print out the calculations (2 decimal places, right justified in a column).
	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "Circle Area          " << setw(8) << area << "cm^2"<< endl
		 << "Circle Circumference " << setw(8) << circumference << "cm" << endl
		 << "Sphere Volume        " << setw(8) << volume << "cm^3"  << endl
		 << "Sphere Surface Area  " << setw(8) << surfaceArea << "cm^2" << endl
		 << "Cone Volume          " << setw(8) << coneVolume << "cm^3" << endl
		 << "Cone Surface Area    " << setw(8) << coneSurfaceArea << "cm^2" << endl << endl;
	//cout << "slantHeight          " << setw(8) << slantHeight << endl; // for debugging purposes

	return 0;
}
