//Example program for value-returning function with value parameter
// 11/2/2017 C young

#include <iostream>
#include <string>
using namespace std;

string binconvert(int);  //function prototype for VR function. return type is string

int main(){
	int num;          //local variables for main
	char reply;
	string binstring;
	do{
		//ask user for number. Force correct output
		do{
			cout << "Enter an integer between 0 and 65,535: ";
			cin >> num;
			if (!cin){  //check state of input stream
				cin.clear();
				cin.ignore(40, '\n');
				num = -1;
			}
		} while (num < 0 || num > 65535);

		//call function to convert to binary. function call is INSIDE another statement
		binstring = binconvert(num);  //function call with ARGUMENT
		cout << "The binary representation of " << num << " is: "
			<< binstring << endl;
		
		cout << "Convert another integer? y/n ";
		cin >> reply;
		cin.ignore(40, '\n');  //flushes any extra characters out of input stream
		reply = tolower(reply);
	} while (reply == 'y');
	cout << "Thanks for using the binary converter." << endl;
	return 0;
}

//function definition for binconvert
//Preconditions: number is in proper range between 0 and 65,535
//Postconditions: a 16-bit string with proper spacing is returned
string binconvert(int number){  //function header with FORMAL parameter
	int base, count;      //local variables
	string answer = "";  //initialize answer string to no characters

	base = 32768;
	count = 0;

	while (base > 0){
		if (number >= base){
			answer = answer + "1";  //string concatenation
			number = number - base;
		}
		else
			answer = answer + "0";
		//check if space is needed
		count++;
		if (count == 4){
			answer += " ";
			count = 0;
		}
		
		base = base / 2;
	}
	return answer;  //required return statement!
}
