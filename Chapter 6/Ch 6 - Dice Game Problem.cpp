/*
	Filename: Ch 6 - Dice Game Problem.cpp

	Author: Raul Conover
	Date: 11/8/2017

	Description: The program will generate 2d6 roll. On the first roll If the sum is 7 or 11 the 
		player wins and loses on a sum of 2, 3, or 12. If the sum is 4,5,6,8,9,10 on the first 
		throw that number becomes "the point". If you do not win or lose on the first throw 
		continue to roll until "the point" is rolled again (to win) or a 7 is rolled (to lose).
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Function Prototypes
void craps_rules();
int roll_dice();
void print_die(int);
char repeat_game();
int first_roll(int);
int point_roll(int, int);

int main()
{
	// Variables
	char again, ch;
	int roll, point;

	srand(unsigned(time(0)));	// Random number generator.
	craps_rules();				// Print out the title and rules for craps to the player.

	do
	{
		// Ask the player to roll the dice
		cout << "Press Enter to roll your first set of die." << endl;
		cin.get(ch);
		roll = roll_dice();
		point = first_roll(roll);
		
		
		// If the player 
		while(point > 0)
		{
			cout << "Press Enter to roll again." << endl;
			cin.get(ch);
			roll = roll_dice();
			point = point_roll(roll, point);
		}
		
		again = repeat_game();
		cin.ignore(40, '\n');
	} while (again == 'y');

	cout << "\nThank you for playing!" << endl << endl;
	return 0;
}

//***********************************************************************
// This function will print the rules for craps for the player to read.	*
//***********************************************************************
void craps_rules()
{

	cout << "              ################################" << endl
		 << "              #          Welcome to          #" << endl
		 << "              #      Raul's Craps game!      #" << endl
		 << "              ################################" << endl << endl;
	cout << "You will roll two dice. If the sum is 7 or 11 on the first throw,"<< endl 
		 << "you win. If the sum is 2, 3, or 12 on the first throw (called \"craps\")," << endl 
		 << "you lose. If the sum is 4, 5, 6, 8, 9, or 10 on the first throw," << endl 
		 << "then that sum becomes the your \"point\". If you don\'t win or lose on the" << endl 
		 << "first roll, you must continue rolling the dice until you win or lose. If you" << endl
		 << "\"make your point\" you win; if you roll a 7 you lose." << endl << endl;
}

//**************************************************************************
// This function will "roll" two dice and return the sum of die1 and die2. *
//**************************************************************************
int roll_dice()
{
	int die1, die2;
	die1 = rand() % 6 + 1;
	die2 = rand() % 6 + 1;
	print_die(die1);
	print_die(die2);
	return die1 + die2;
}

//*****************************************************************
// This function will print the face of each die that was rolled. *
//*****************************************************************
void print_die(int face)
{
	switch(face)
	{
		case 1: cout << "-------" << endl
			         << "|     |" << endl
			         << "|  o  |" << endl
			         << "|     |" << endl
			         << "-------" << endl;
		break;
		case 2: cout << "-------" << endl
					 << "|   o |" << endl
					 << "|     |" << endl
					 << "| o   |" << endl
					 << "-------" << endl;
		break;
		case 3: cout << "-------" << endl
					 << "|   o |" << endl
					 << "|  o  |" << endl
					 << "| o   |" << endl
					 << "-------" << endl;
		break;
		case 4: cout << "-------" << endl
					 << "| o o |" << endl
					 << "|     |" << endl
					 << "| o o |" << endl
					 << "-------" << endl;
		break;
		case 5: cout << "-------" << endl
					 << "| o o |" << endl
					 << "|  o  |" << endl
					 << "| o o |" << endl
					 << "-------" << endl;
		break;
		case 6: cout << "-------" << endl
					 << "| o o |" << endl
					 << "| o o |" << endl
					 << "| o o |" << endl
					 << "-------" << endl;
		break;
	}
}

//********************************************************************
// This funtion will take the sum of the two dice and determine if   *
// the player wins or loses. It returns dieTotal. If the player	     *
// wins or loses it returns -1 to skip the while loop for more rolls.*									   *
//********************************************************************
int first_roll(int dieTotal)
{
	if (dieTotal == 7 || dieTotal == 11)
	{
		cout << "Your roll was " << dieTotal << "." << endl;
		cout << "Congratulations! You win!" << endl;
		return -1;
	}
	else if (dieTotal == 2 || dieTotal == 3 || dieTotal == 12)
	{
		cout << "Your roll was " << dieTotal << "." << endl;
		cout << "You Lose!" << endl << endl;
			return -1;
	}
	else
	{
		cout << "Your roll was " << dieTotal << "." << endl
			<< "Your \"point\" is " << dieTotal << ", to win you must roll " << dieTotal 
			<< " again." << endl
			<< "If you roll a 7 you lose." << endl << endl;
		return dieTotal;
	}
		

}

//***************************************************************************
// This function reads in the sum of the die total. It will determine		*
// if the player wins loses, or has to roll again. It returns the point 	*
// If the player wins or loses it returns a -1 to end the while loop. 		*
//***************************************************************************
int point_roll(int dieTotal, int point)
{
	if (dieTotal == point)
	{
		cout << "You rolled a " << dieTotal << " and met your point!" << endl
			 << "Congratulations! You win!" << endl << endl;
		return -1;
	}
	else if (dieTotal == 7)
	{
		cout << "You rolled a 7. You lose!" << endl << endl;
		return -1;
	}
	else
	{
		cout << "Your point is  " << point << "." << endl
			<< "You rolled a " << dieTotal << "." << endl << endl;
		return point;
	}
}

//***************************************************************
// This function will ask the player if they would like to play *
// again and return a char.										*
//***************************************************************
char repeat_game()
{
	char repeat;
	cout << "Would you like to play again? y or n: ";
	cin >> repeat;
	repeat = tolower(repeat);
	return repeat;
}