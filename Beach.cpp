/******************************************************************************
 * Program Name: Final Project - Marooned - Beach Class Implementation File
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: Beach class allows strings to be passed in as parameters so 
 * that each beach space can be initialized with a different item and a new
 * prompt for exploring that item. Has unique space action that allows fishing.
 * An int is passed in as a parameter to initialize the probability of catching
 * a fish.
 * ****************************************************************************/
#include "Beach.hpp"
using std::cout;
using std::endl;
using std::string;

/*******************************************************************************
 * Description: Constructor allows for placement of items on the square and
 * varying levels of fishing probability. Initializes all space specific 
 * attributes.
 * ****************************************************************************/
Beach::Beach(Player* survivor, string item, string prompt, int fishProb): 
Space(survivor)
{
	this->item = item;
	this->fishProb = fishProb;
	actionItem = "Fishing pole";
	actionDesc = "Fish";
	spaceType = "Beach";
	explorePrompt = prompt;
}

/*******************************************************************************
 * Description: Outputs a description of the square whenever the player enters.
 * ****************************************************************************/
void Beach::enterSpace()
{
	printStars();
	cout << "You find yourself on a beautiful pristine sandy beach. Palm trees"
		     " shade you,\nsoft waves lap the shore and you see fish jumping in"
			  " the distance.";
	printStars();
}

/*******************************************************************************
 * Description: Attempts to allow the user to fish. If the action causes the 
 * user health to dip below 0, the user will be prompted.
 * ****************************************************************************/
void Beach::spaceAction()
{
	survivor->updateHealth(ACTION);
	
	if(!(survivor->isDead()))		
	{
		printStars();
		cout << "You cast your line out into the ocean and wait...";

		int N = randomNumber(1, 100);
	
		//Catch a fish and add to bag	
		if(N <= fishProb)
		{
			cout << "You caught a fish!\n";
			bag->addItem("Fish");
			printStars();
		}

		//No fish have been caught
		else
		{
			cout << "\nLooks like they aren't biting much.";
			printStars();
		}	
	}
	else
	{
		printStars();
		cout << "You tried to fish and you died from overexertion!";
	}
	
}


