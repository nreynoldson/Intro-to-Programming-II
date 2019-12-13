/******************************************************************************
 * Program Name: Final Project - Marooned - Beach Class Header
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: Beach class allows strings to be passed in as parameters so 
 * that each beach space can be initialized with a different item and a new
 * prompt for exploring that item. Has unique space action that allows fishing.
 * An int is passed in as a parameter to initialize the probability of catching
 * a fish.
 *****************************************************************************/
#ifndef BEACH_HPP
#define BEACH_HPP
#include "Player.hpp"
#include "Space.hpp"
#include <string>

class Beach: public Space
{
	private:
		int fishProb;
		
	public:
		Beach(Player*, string, string,  int);
		void enterSpace();
		void spaceAction();
		~Beach(){}
};

#endif
		
