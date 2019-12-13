/******************************************************************************
 * Program Name: Final Project - Marooned - SparseForest Class Implementation
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: Derived from Space class. Special random event allows user to
 * find and heal from aloe. Unique space action allows the user to forage for
 * berries.
 * ****************************************************************************/
#include "SparseForest.hpp"
using std::cout;
using std::endl;

/*******************************************************************************
 * Description: Has no item to be foundon this square. Initializes the base 
 * class constructor.
 ******************************************************************************/
SparseForest::SparseForest(Player* survivor) : Space(survivor)
{
	spaceType = "Forest Edge";
	actionDesc = "Forage";
}

/*******************************************************************************
 * Description: Outputs a description of the space as the player enters it.
 * ****************************************************************************/
void SparseForest::enterSpace()
{
	printStars();
	cout << "You enter a sparsely vegetated clearing. There aren't many trees,"
			  " but there's\nan abundance of berry bushes. Who knows if they are"
			  " even edible...";
	printStars();
	randomEvent();
}

/*******************************************************************************
 * Description: The player will always find berries when the function is called.
 * When the berries are eaten, there will be a chance for the player to be
 * poisoned.
 ******************************************************************************/
void SparseForest::spaceAction()
{
	printStars();
	survivor->updateHealth(FORAGE);
	
	if(survivor -> isDead())
	{
		cout << "You overexerted and died while foraging berries...what a lame"
				  " way to go!";
		printStars();
	}
	else
	{
		cout << "You found some berries!" << endl;
		bag->addItem("Berries");
		printStars();
	}
}

/*******************************************************************************
 * Description: Overridden from Space base class. Generates a random number
 * and compares to the probability of aloe being found in the forest. 
 ******************************************************************************/
void SparseForest::randomEvent()
{
	int N = randomNumber(1, 100);
	if(N <= ALOEPROB)
	{
		cout << endl;
		printStars();
		cout << "You stumble upon an aloe vera plant and gain some health.\n";
		survivor->updateHealth(ALOE);
		printStars();
	}
}

/*******************************************************************************
 * Description: Overridden from base Space class. Returns true, since the 
 * player is always able to forage on this square regardless of items.
 * ***************************************************************************/
bool SparseForest::doAction()
{
	return true;
}
