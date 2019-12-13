/******************************************************************************
 * Program Name: Option Class
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: Intended to link a string object with a unique numerical 
 * identifier. Contains getters for both member variables.
 *****************************************************************************/
#ifndef OPTION_HPP
#define OPTION_HPP
#include <string>
using std::string;

class Option
{
	private:
		string option;
		int key;
	
	public:
		Option(string, int);
		string getOption();
		int getKey();
};

#endif
