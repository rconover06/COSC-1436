/*
* Filename: Ch 6 - Calendar Problem.cpp
	
	Author: Raul Conover
	Date: 11/09/20178

	Description: Program that will print a calendar for a given year.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

// function Prototyes
bool is_leap(int);
int begin_year(int);
int calendar_header(int, int, ofstream&outfile);
void print_days(int, int &, ofstream&outfile);
bool again();

int main()
{
	ofstream outfile;

	int year, days, dayOfWeek;

	// Open an ouput file for the calendar to print to.
	outfile.open("Ch 6 Calendar Output.txt");

	do {
		cout << "Enter the calendar Year: ";
		cin >> year;

		dayOfWeek = begin_year(year);

		// outfile << "First day of the year code: " << dayOfWeek << endl;	 // Used for debugging

		for (int i = 1; i <= 12; i++)
		{
			days = calendar_header(year, i, outfile);
			//outfile << "Days in month = " << dayOfWeek << endl;			//Used for debugging
			print_days(days, dayOfWeek, outfile);
			outfile << endl;
		}
	} while (again());


	return 0;
}
//***************************************************************
// Function will read in the year the user input. Will return a	*
// bool value true if it is a leap year and false if it is not.	*
//***************************************************************
bool is_leap(int year)
{
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		return true;
	else
		return false;
}
//***************************************************************
// Function reads in the year and returns the day of the week.	*
// Sunday = 0, Monday = 1, Tueday = 2, Wednesday = 3			*
// Thursday = 4, Friday = 5, Saturday = 6;						*
//***************************************************************
int begin_year(int year)
{
	int janFirst;
	year = year - 1;
	janFirst = (1 + year + (year / 4) - (year / 100) + (year / 400)) % 7;
	return janFirst;
}
//***********************************************************************
// Function reads in the ear and month number. It will print the header	*
// for the calendar and returns the number of days in the month.		*
//***********************************************************************
int calendar_header(int year, int month, ofstream&outfile)
{
	int daysInMonth;

	outfile << "=======================" << endl;
	switch(month)
	{
		case 1: outfile << "#    January  " << year <<"    #" << endl;
			daysInMonth = 31;
		break;
		case 2: outfile << "#   February  " << year <<"    #" << endl;
			if (is_leap(year))
				daysInMonth = 29;
			else
				daysInMonth = 28;
		break;
		case 3: outfile << "#     March  " << year <<"     #" << endl;
			daysInMonth = 31;
		break;
		case 4: outfile << "#     April  " << year <<"     #" << endl;
			daysInMonth = 30;
		break;
		case 5: outfile << "#      May  " << year <<"      #" << endl;
			daysInMonth = 31;
		break;
		case 6: outfile << "#      June  " << year <<"     #" << endl;
			daysInMonth = 30;
		break;
		case 7: outfile << "#      July  " << year <<"     #" << endl;
			daysInMonth = 31;
		break;
		case 8: outfile << "#     August  " << year <<"    #" << endl;
			daysInMonth = 31;
		break;
		case 9: outfile << "#   September  " << year <<"   #" << endl;
			daysInMonth = 30;
		break;
		case 10: outfile << "#    October  " << year <<"    #" << endl;
			daysInMonth = 31;
		break;
		case 11: outfile << "#   November  " << year <<"    #" << endl;
			daysInMonth = 30;
		break;
		case 12: outfile << "#   December  " << year <<"    #" << endl;
			daysInMonth = 31;
		break;
	}

	outfile << "# S  M  T  W  T  F  S # " << endl
		 << "=======================" << endl;
	return daysInMonth;
}
//***********************************************************
// Function accepts days for the number of days in a month	*
// and firstDay as the first day of the year. Returns a new	*
// int for first day to be used for the next month.			*
//***********************************************************
void print_days(int days, int &dayOfWeek, ofstream&outfile)
{
	int i,j = 1;

	for (i = 1; i <= dayOfWeek; i++)
	{
		outfile << "   ";
	}
	for (int date = 1; date <= days; date++)
	{
		outfile << setw(3) << date;
		dayOfWeek++;
		if (dayOfWeek > 6)
		{
			outfile << endl;
			dayOfWeek = 0;
		}
	}
}
//*******************************************************
// Funciton will ask the user if they want to repeat	*
// the program and return a bool.						*
//*******************************************************
bool again()
{
	char repeat;
	cout << endl << "Would you like to enter another year? y or n: ";
	cin >> repeat;
	repeat = tolower(repeat);
	if (repeat == 'y')
		return true;
	else
	{
		cout << "Thank you!" << endl << endl;
		return false;
	}
}