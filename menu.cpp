/*****************************************************************************
 * Program name: Menu Functions
 * Date: 8/4/19
 * Name: Nicole Reynoldson
 * Description: A collection of functions used for implementing a menu.
 * ***************************************************************************/
#include "menu.hpp"
using std::cout;
using std::endl;
using std::string;
using std::vector;

/*****************************************************************************
 * Description: Takes a vector of strings as a parameter. Iterates through
 * the list and returns the user choice/
 * ***************************************************************************/
int displayMenu(vector<string> menuOpts)
{
	for(unsigned int i = 0; i < menuOpts.size(); i++)
	{
		cout << i + 1 << ". " << menuOpts[i] << endl;
	}
	
	return getInt(1, menuOpts.size());
}

/*****************************************************************************
 * Description: Overloaded displayMenu function takes a vector of Option objects
 * as a parameter and iterates through the options. The users choice is returned
 * in the form of the key for that specific option.
 * ***************************************************************************/
int displayMenu(vector<Option> menuOpts)
{
	for(unsigned int i = 0; i < menuOpts.size(); i++)
	{
		cout << i + 1 << ". " << menuOpts[i].getOption() << endl;
	}
	
	//Get the choice corresponding to the list placement
	int choice = getInt(1, menuOpts.size());
	
	//Return a number identifier for comparing in a switch
	return menuOpts[choice-1].getKey();
}
