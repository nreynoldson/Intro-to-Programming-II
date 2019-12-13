/******************************************************************************
 * Program Name: Miscellaneous Utility Functions
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: A collection of random functions include print functions and 
 * random number generators 
 *****************************************************************************/
#include "utilityFunctions.hpp"
using std::string;
using std::endl;
using std::cout;

/*******************************************************************************
 * Description: Take integers as arguments for minimum and maxiumum value. 
 * Calculates a random number between the max and min and returns the value.
 ******************************************************************************/
int randomNumber(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

/*******************************************************************************
 * Description: Uses the random number function to simulate a dice roll. Sides
 * and dies are taken as arguments. The total roll is calculated and returned.
 ******************************************************************************/
int rollDie(int sides, int dies)
{
	int roll = 0;
	for(int i = 0; i < dies; i++)
	{
		roll += randomNumber(1, sides);
	}

	return roll;
}

/*******************************************************************************
 * Description: Takes a string and an int representing the width of the field
 * as parameters and returns a padded cenetered string.
 ******************************************************************************/
string center(const string str, const int width)
{
//Adapted from https://stackoverflow.com/questions/14861018/center-text-in-fixed
//-width-field-with-stream-manipulators-in-c 
	int length = str.length();
	if (width < length)
	{
		return str;
	}
	
	int diff = width - length;
	int padLeft = diff/2;
	int padRight = diff - padLeft;
	
	return string(padLeft, ' ') + str + string(padRight, ' ');
}


/*******************************************************************************
 * Description: Prints a row of asterisks.
 ******************************************************************************/
void printStars()
{
	cout << endl << string(80, '*') << endl;
}
