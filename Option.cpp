/******************************************************************************
 * Program Name: Option Class
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: Intended to link a string object with a unique numerical 
 * identifier. Contains getters for both member variables.
 *****************************************************************************/
#include "Option.hpp"

/*******************************************************************************
 * Description: Constructor allows you to pass in a string as the option that
 * appears in the menu and a key to be used as a unique identifier for that 
 * option.
 ******************************************************************************/
Option::Option(string option, int key)
{
	this->option = option;
	this->key = key;
}

/*******************************************************************************
 * Getters and Setters
 ******************************************************************************/
string Option::getOption()
{
	return option;
}

int Option::getKey()
{
	return key;
}

