/******************************************************************************
 * Program Name: Final Project - Marooned - DenseForest Class Implementation
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: Derived from Space class. Unique spaceAction function allows
 * the player to chop wood if they have an axe. RandomEvent() will give the
 * player a chance to be bit by a snake.
 * ****************************************************************************/
#include "DenseForest.hpp"
using std::cout;
using std::endl;

/*******************************************************************************
 * Description: No items to be found on this square. Initializes the Space base
 * class constructor.
 ******************************************************************************/
DenseForest::DenseForest(Player* survivor): Space(survivor)
{
	spaceType = "Dense Forest";
	actionItem = "Axe";
	actionDesc = "Chop Wood";
}


/*******************************************************************************
 * Description: Function describes the setting and triggers the random event.
 ******************************************************************************/
void DenseForest::enterSpace()
{
	printStars();
	cout << "You find yourself entering a dense forest full of trees. The"
			  " canopy blots out\nthe sun from above.";
	printStars();

	randomEvent();
}

/*******************************************************************************
 * Description: Allows the user to chop trees and add logs to their inventory.
 ******************************************************************************/
void DenseForest::spaceAction()
{
	survivor->updateHealth(ACTION);
	
	if(!survivor->isDead())
	{
		printStars();
		cout << "You use your axe to chop down some trees." << endl;
		bag->addItem("Log");
		printStars();
	}
	else
	{
		printStars();
		cout << "You try to chop wood and die from exhaustion. " << endl;
		printStars();
	}
}

/*******************************************************************************
 * Description: Will randomly determine whether the user is bitten by a snake
 * or not.
 ******************************************************************************/
void DenseForest::randomEvent()
{
	int N = randomNumber(1, 100);
	if(N <= SNAKEPROB)
	{
		survivor->updateHealth(SNAKEBITE);
		if(!survivor->isDead())
		{
			cout << endl;
			printStars();
			cout << "These woods can be dangerous."
					  " You've been bitten by a snake!\n";
			printStars();
		}
		else
		{
			printStars();
			cout << "A snake bit you and you died!";
			printStars();
		}
	}
}

