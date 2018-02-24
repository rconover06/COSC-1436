/*
	Filename: Ch 7 - Arrays - Lecture and Lab.cpp

	Author: Raul Conover
	Date: 11/27/2017

	Desciption: Program demonstrating the use of arrays and functions.
*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//	Global Constants
const int MAXSIZE = 50;

//	Function Prototypes
int load_array(int[], ifstream &);
void print_array(int[], int);

int main()
{
	int section1[MAXSIZE], section2[MAXSIZE];		//Define 2 arrays
	int size1, size2;		//Variables that hold valid # of values in each array.

	ifstream infile1, infile2;

	infile1.open("section001.txt");
	infile2.open("section002.txt");

	if (!infile1 || !infile2)
	{
		cout << "ERROR: Problem opening one or more input files.\nPROGRAM ABORTED" << endl;
		return 1;
	}

	//	Put values in arrays from input files.
	size1 = load_array(section1, infile1);
	size2 = load_array(section2, infile2);

	//	Display values in the array.
	cout << "Grades from Section 001:" << endl;
	print_array(section1, size1);
	cout << "***********************************" << endl << endl;
	cout << "Grades from Section 002:" << endl;
	print_array(section2, size2);
	cout << "***********************************" << endl << endl;
}

//	Load Array Funciton: Reads values form input file and loads an array
//	Pre: Input file successfully opened.
//	Post: Array is filled up to MAXSIZE values. Function returns # of valid values.
int load_array(int a[], ifstream &infile)
{
	int count = 0;

	while (count < MAXSIZE && infile >> a[count])
	{
		count++;
	}
	return count;	//	Count represents # of values NOT last index.
}

//	Print Array Function: Displays the values in an array.
//	Pre: Array a is filled with count values.
//	Post: All valid values have been displayed.
void print_array(int a[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << setw(3) << i + 1 << setw(5) << a[i] << endl;
	}
}