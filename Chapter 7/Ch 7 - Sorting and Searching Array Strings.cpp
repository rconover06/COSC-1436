/*
	Filename: Ch 7 - Sorting and Searching Array Strings.cpp

	Author: Raul Conover
	Date: 11/29/2017

	Description: Program reads in two lists of words into an arrays.
		The program sorts the arrays alphabetically, and then uses a 
		search value input file to search each array for a list of words.
		It will print the if the word is found, and its position.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

// Global Constants
const int MAXSIZE = 50;

// Function Prototypes
int load_array(string [], ifstream &);
void print_word_list(string [], int, ofstream &);
void sort_list(string [], int);
int word_search(string[], int, string);
void print_results(int, int, string, ofstream &);


int main()
{
	string words1[MAXSIZE], words2[MAXSIZE];
	int count1, count2, count3;
	
	// Initialize outfile and open all infiles.
	ifstream infile1, infile2, infile3;
	ofstream outfile;
	infile1.open("words1.txt");
	infile2.open("words2.txt");
	infile3.open("searchvalues.txt");
	if(!infile1 || !infile2 || !infile3)
	{
		cout << "ERROR: Problem reading one or more files.\nPROGRAM ABORTED!";
		return 1;
	}
	outfile.open("Ch 7 - Sorting and Searching Output.txt");

	// Determine the number of words in each list.
	count1 = load_array(words1, infile1);
	count2 = load_array(words2, infile2);

	//Print the word lists as they were imported in.
	outfile << "Word list 1 (unsorted)" << endl << endl;
	print_word_list(words1, count1, outfile);
	outfile << "Word list 2 (unsorted)" << endl << endl;
	print_word_list(words2, count2, outfile);

	// Sort the Arrays
	sort_list(words1, count1);
	sort_list(words2, count2);

	// Print the sorted word lists.
	outfile << "Word list 1 (sorted)" << endl << endl;
	print_word_list(words1, count1, outfile);
	outfile << "Word list 2 (sorted)" << endl << endl;
	print_word_list(words2,count2, outfile);

	// Search the arrays for the searchvalues in the file. Rhen prints the results.
	string searchValue;
	int position1, position2;
	while (infile3 >> searchValue)
	{
		position1 = word_search(words1,count1, searchValue);
		position2 = word_search(words2, count2, searchValue);

		print_results(position1, position2, searchValue, outfile);

	}
	return 0;
}
// 	Load Array Function: load the array with values on the txt file.
// 	Pre: Array a is filled with count values.
//	Post: Array is filled up to MAXSIZE value. Returns # of valid entries.
int load_array(string a[], ifstream &infile)
{
	int count = 0;
	while(count < MAXSIZE && infile >> a[count])
	{
		count++;
	}
	return count; // Count repreents # of values, NOT the last index number.
}
//	Print Word List Funciton: Prints out the array word list.
//	Pre: Uses count, array of strings, and outfile
//	Post: Print out the list of words in array.
void print_word_list(string arr[], int count, ofstream &outfile)
{
	for(int i = 0; i < count; i++)
	{
		outfile << setw(3) << i + 1 << "\t" << arr[i] << endl;
	}
	outfile << endl << "=========================" << endl;
}
//	Sort Array Function: arrange array elements in ascending order.
//	Selection Sort Algorithm is implemented.
//	Pre: Array a is filled with count values.
//	Post: Array values are rearranged into ascending alphabetical order.
void sort_list(string arr[], int count)
{
	int i, j, min;	// These hold index numbers. ALWAYS of type int.
	string temp;		// MUST be of same data type as array.

	for (i = 0; i < count - 1; i++)
	{
		min = i;

		for (j = i + 1; j < count; j++)	// Find index of lowest value.
			if (arr[j] < arr[min])
				min = j;

		// Swap smallest value in current list with "top" of current list.
		if (min != i)
		{
			temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}
//	Binary Search Function will search the list and find the value.
//	Pre: Array a is filled with count values, search has been set. ARRAY a IS SORTED.
//	Post: Returns the index if found, returns -1 if not found.
int word_search(string arr[], int count, string searchValue)
{
	int top, bottom, mid;
	top = 0;
	bottom = count - 1;
	while (top <= bottom)
	{
		mid = (top + bottom) / 2; // int division.
		if (searchValue == arr[mid])
			return mid;
		else if (searchValue < arr[mid])
			bottom = mid - 1; // look in "top" half
		else
			top = mid + 1; // Look in "bottom" half
	}
	return -1; // SearchValue not found.
}
//	print Results function will print out on the report the words that were found or not found
//		and thier position on the sorted word lists.
//	Pre: Reads in position1 and position2
//	Post: Will print out the results using based upon what was returned from word_search
void print_results(int position1, int position2, string searchValue, ofstream &outfile)
{
		if (position1 >= 0 && position2 >=0)
		{
			outfile << "The word \"" << searchValue 
					<< "\" was found was found in word list one at position " << position1 + 1 
					<< " and was found in word list two at position " << position2 + 1 << "." << endl;
		}
		else if (position1 >= 0 && position2 < 0)
		{
			outfile << "The word \"" << searchValue
					<< "\" was found was found in word list one at position " << position1 + 1
					<< " and was not found on word list two." << endl;
		}
		else if (position1 < 0 && position2 >= 0)
		{
			outfile << "The word \"" << searchValue
					<< "\" was found was found in word list two at position " << position2 + 1
					<< " and was not found on word list one." << endl;
		}
		else
			outfile << "The word \"" << searchValue << "\" was not found on either list." << endl;
}