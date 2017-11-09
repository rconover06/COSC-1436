/* 
 * File:   Chapter 4-1 Problem.cpp
 * Author: Raul Conover
 *
 * Created on October 4, 2017
 * 
 * Description: This program will ask a user for an int between 0 and 255 and 
 * convert the decimal number into an unsigned binary number.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
    // Variables
    int decimal, remainder,
        b1, b2, b3, b4, b5, b6, b7, b8;
    
    // Ask the user for an integer value.
    cout << "Input a value between 0 and 255: ";
    cin >> decimal;
    
    // Validate the entry and process.
    if(decimal >= 0 && decimal <= 255)
    {
        //Calculate the 1st order bit
        b1 = decimal % 2;
        decimal = decimal / 2;
        // 2nd order bit
        b2 = decimal % 2;
        decimal =  decimal / 2;
        // 3rd order bit.
        b3 = decimal % 2;
        decimal =  decimal / 2;
        // 4th order bit.
        b4 = decimal % 2;
        decimal =  decimal / 2;
        // 5th order bit.
        b5 = decimal % 2;
        decimal =  decimal / 2;
        // 6th order bit
        b6 = decimal % 2;
        decimal =  decimal / 2;
        // 7th order it
        b7 = decimal % 2;
        decimal =  decimal / 2;
        // 8th order bit
        b8 = decimal % 2;
        decimal =  decimal / 2;
        
        // Print out the binary equivelent, (reverse order from calculation)
        cout << "The unsigned binary equivalent is: "
             << b8 << b7 << b6 << b5 << " " << b4 << b3 << b2 << b1 << endl;
    }
    else
    {
        cout << "ERROR! Input value " << decimal 
             << " is out of range for this program." << endl;
    }
    /*// These outputs are for debugging purposes.
    cout << "\nDebugging Values"
         << "Decimal:   " << decimal << endl
         << "remainder: " << remainder << endl
         << "binary:    " << b8 << b7 << b6 << b5 << " " <<
                             b4 << b3 << b2 << b1 << endl;
    */
    return 0;
}