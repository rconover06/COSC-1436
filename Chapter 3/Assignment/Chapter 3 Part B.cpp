/* 
Raul Conover
9/19/2017
Chapter 3 Problems Part B
Create a program that will calculate the wind chill given temperature and
wind velocity. 
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double  windChillF,
            windChillC,
            velMPH,
            velKPH,
            fTemp,
            cTemp;
    char    degree = char(248);
    
    // Ask the user for the temperature and wind velocity.
    cout << "Enter the temperature in degrees Celsius: ";
    cin >> cTemp;
    cout << "Enter the velocity of the wind in kilometers per hour: ";
    cin >> velKPH;
    
    // Convert metric to imperial system
    fTemp = (9.0 / 5.0) * cTemp + 32.0;
    velMPH = velKPH * 0.621;
    
    // Calculate the wind chill and assign it to windChill.
    windChillF = 35.74 + 0.6215 * fTemp - 35.75 * pow(velMPH, 0.16)
            + 0.4275 * fTemp * pow(velMPH, 0.16);
    
    // Convert wind chill from degrees Fahrenheit to Celsius
    windChillC = (5.0 / 9.0) * (windChillF - 32.0);
    
    // Print out the windchill
    cout << fixed << showpoint << setprecision(2);
    cout << "The wind chill is " << windChillC << degree << "C " << "or " 
            << windChillF << degree << "F." << endl;
    //cout << "velMPH: " << velMPH << endl;     // For Debugging
    //cout << "fTemp: " << fTemp << endl;       // For Debugging
    return 0;
}
