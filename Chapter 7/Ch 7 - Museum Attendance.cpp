/*
	Filename: Ch 7 - Museum Attendance.cpp

	Author: Raul Conover
	Date: 11/28/2017

	Description: Import in an museum attendance file and generate a report
		using the information provided in the file.
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

// 	Global Variables
const int NDAYS = 14,
		  FIRST = 3,
		  LAST = 11;

//	Function Prototypes
void print_header(ofstream &);
void load_attendance(int [], ifstream &);
void total_attendance(int [], ofstream &);
double avg_attendance(int[], int, int, ofstream &);
void min_max(int[], ofstream &);
void print_attendance(int[], ofstream &);

int main()
{

	int attendance[NDAYS];
	double average;

	ifstream infile;
	infile.open("museumattend.txt");
	ofstream outfile;

	if(!infile)
	{
		cout << "ERROR: Problem opening input file.\nPROGRAM ABORTED";
		return 1;
	}
	outfile.open("Museum Attendance Report.txt");

	load_attendance(attendance, infile);

	outfile << setprecision(1) << fixed;

	//Print out the header for the report.
	print_header(outfile);

	//	Print the total attendance.
	total_attendance(attendance, outfile);

	// Print the max/min daily attendance and day it occurred.
	min_max(attendance, outfile);

	// This will generate the average for the entire 14 day period.
	average = avg_attendance(attendance, 0, NDAYS, outfile);
	outfile << "Average Attendance for past 14 days:\t" << average << endl;

	// This will generate the average for the first 3 days of the period.
	average = avg_attendance(attendance, 0, FIRST, outfile);
	outfile << "Average Attendance for first 3 days:\t" << average << endl;

	// This will generate the average for the last 3 days in the cycle.
	average = avg_attendance(attendance, LAST, NDAYS, outfile);
	outfile << "Average Attendance for last 3 days:\t\t" << average << endl;

	// Print the daily attendance totals.
	print_attendance(attendance, outfile);

	return 0;
}

//	Print Header Function
//	Pre: Input file was successcully imported
//	Post: output the header for the report.
void print_header(ofstream &outfile)
{
	char dateStr [9];
	_strdate_s( dateStr);
	outfile << "\t\t\t\tRaul Conover" << endl
		 << "\t\t\t\tDate: "<< dateStr << endl << endl
		 << "\tPrevious 14 Day Museum Attendance Report" << endl << endl;	
}

//	Load Attendance Function
//	Pre: input file was successfully opened.
//	Post: array filled up to NDAYS of values.
void load_attendance(int a[], ifstream &infile)
{
	int count = 0;

	while (count < NDAYS && infile >> a[count])
	{
		count++;
	}
}

//	Total Attendance Function
//	Pre: Header output on the screen.
//	Post: Output the total attendance for the period.
void total_attendance(int a[], ofstream &outfile)
{
	int total = 0;
	for (int i = 0; i < NDAYS; i++)
	{
		total += a[i];
	}
	outfile << "Total Attendace for period:\t\t\t" << setw(8) << total << endl << endl;
}

//	Average Attendance Function. 
//	Pre: use the attenance array, a start for the index and range.
//	Post: Returns the average using the parameters.
double avg_attendance(int a[], int start, int range, ofstream &outfile)
{
	double avg = 0;
	int i;

	for (i = start; i < range; i++)
	{
		avg += a[i];
	}
	avg /= range - start;
	return avg;
}
//	Min Max Function. Prints daily max and min attendance and the day it occurred.
//	Pre: use attendance array and outfile.
//	Post: print out the max and min attendance and days they occurred.
void min_max(int a[], ofstream &outfile)
{
	int min, max, minDay, maxDay;
	min = a[0];
	max = a[0];

	for (int i = 0; i < NDAYS; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			maxDay = i + 1;
		}
			
	}
	for (int i = 0; i < NDAYS; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			minDay = i + 1;
		}
	}
	outfile << "Maximum Attendance was on day " << maxDay << ":\t\t" << max << endl
			<< "Minimum Attendance was on day " << minDay << ":\t\t" << min << endl << endl;
}

//	Print Attendance Function.
//	Pre: use attendance array and outfile
//	Post: Print out the daily attendance records.
void print_attendance(int a[], ofstream &outfile)
{
	outfile << "\n\t\tDaily Attendance Records" << endl
			<< "\t\t\tDay		Attendees" << endl;
	for (int i = 0; i < NDAYS; i++)
	{
		outfile << "\t\t\t" << setw(3) << i + 1 << "\t\t" << setw(5) << a[i] << endl;
	}
}