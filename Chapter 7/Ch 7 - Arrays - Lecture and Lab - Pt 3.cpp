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
void sort_array(int[], int);
int binary_search(int[], int, int);

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
	cout << "Unsorted Values: " << endl;
	cout << "Grades from Section 001:" << endl;
	print_array(section1, size1);
	cout << "***********************************" << endl << endl;
	cout << "Grades from Section 002:" << endl;
	print_array(section2, size2);
	cout << "***********************************" << endl << endl;

	//	Sort the arrays
	sort_array(section1, size1);
	sort_array(section2, size2);

	//	Display values in the array.
	cout << "Sorted Values: " << endl;
	cout << "Grades from Section 001:" << endl;
	print_array(section1, size1);
	cout << "***********************************" << endl << endl;
	cout << "Grades from Section 002:" << endl;
	print_array(section2, size2);
	cout << "***********************************" << endl << endl;

	//Ask user for values to search for in section 1
	int search, position;
	char reply;
	do
	{
		cout << "Give a value to look for in section 001: ";
		cin >> search;
		position = binary_search(section1, size1, search);
		if (position >= 0)
		{
			cout << "Found value " << search << " at number " << position + 1 << endl;
		}
		else
			cout << "Search NOT in section 1 array" << endl;
		cout << "Give another search value? y/n: ";
		cin >> reply;
	} while (reply != 'n');

	return 0;
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
//	Sort Array Function: arrange array elements in ascending order.
//	Selection Sort Algorithm is implemented.
//	Pre: Array a is filled with count values.
//	Post: Array values are rearranged into ascending order.
void sort_array(int a[], int count)
{
	int i, j, min;	// These hold index numbers. ALWAYS of type int.
	int temp;		// MUST be of same data type as array.

	for (i = 0; i < count - 1; i++)
	{
		min = i;

		for (j = i + 1; j < count; j++)	// Find index of lowest value.
			if (a[j] < a[min])
				min = j;

		// Swap smallest value in current list with "top" of current list.
		if (min != i)
		{
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
}
//	Binary Search Function will search the list and find the value.
//	Pre: Array a is filled with count values, search has been set. ARRAY a IS SORTED.
//	Post: Returns the index if found, returns -1 if not found.
int binary_search(int a[], int count, int searchValue)
{
	//	Note: Array datatype and search datatype must be the same.
	int top, bottom, mid;	// These hold indexes, Will always be type int.
	top = 0;
	bottom = count - 1;
	while (top <= bottom)
	{
		mid = (top + bottom) / 2; // int division.
		if (searchValue == a[mid])
			return mid;
		else if (searchValue < a[mid])
			bottom = mid - 1; // look in "top" half
		else
			top = mid + 1; // Look in "bottom" half
	}
	return -1; // Search not found.
}