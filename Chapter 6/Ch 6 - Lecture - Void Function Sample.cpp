// Raul Conover
// 11/1/2017
// Description: Programs We will be writing in class to learn about functions.
//				Example progam using a VOID FUNCTION.

#include <iostream>
#include <string>

using namespace std;


void printLines(int, int, char);		// Function prototype in the global definiation space.

int main()
{
	string name;
	int age;

	printLines(2, 60, '=');		// Function call for a VOID FUNCTION with argument.
	cout << "Enter your first name: ";
	cin >> name;
	cout << "Enter your age in years: ";
	cin >> age;
	printLines(1, 50, '-');		// Function call for a VOID FUNCTION.
	if (name < "M")
		cout << "A tall stranger will give you a package." << endl;
	else
		cout << "A secret message will be delivered by a tall stranger." << endl;
	printLines(2, 60, '=');		// Function call for a VOID FUNCTION.

	return 0;
}

void printLines(int lines, int length, char symbol)		// Function Definition for printLines. Lines is a formal parameter.
{
	int i, j;			// Local variables.
	
	for (i = 1; i <= lines; i++)
	{
		
		for (j = 1; j <= length; j++)
			cout << symbol;
		cout << endl;
	}
}