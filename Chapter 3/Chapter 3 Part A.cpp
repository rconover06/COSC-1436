/* 
Raul Conover
9/19/2017
Chapter 3 Problems Part A
Create a program that will calculate the wind chill given temperature and
wind velocity. 
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double  windChill,
            velMPH,
            fTemp;
    char    degree = char(248);
    
    // Ask the user for the temperature and wind velocity.
    cout << "Enter the temperature in degrees Fahrenheit: ";
    cin >> fTemp;
    cout << "Enter the velocity of the wind in miles per hour: ";
    cin >> velMPH;
    
    // Calculate the wind chill and assign it to windChill.
    windChill = 35.74 + 0.6215 * fTemp - 35.75 * pow(velMPH, 0.16)
            + 0.4275 * fTemp * pow(velMPH, 0.16);
    
    // Print out the windchill
    cout << fixed << showpoint << setprecision(2);
    cout << "The wind chill is " << windChill << degree << "F" << endl;
    
    return 0;
}
