/******************************************************************************
 * Program Name: Final Project - Marooned - Space Class Implementation File
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: Pure virtual abstract base class Space. Contains functions to
 * link spaces together, trigger random events, give space descriptions, and
 * complete special space functions.
 *****************************************************************************/
#include "Space.hpp"
using std::cout;
using std::endl;

/*******************************************************************************
 * Description: Constructor sets all pointers to null, initializes all string
 * variables to "void" and uses the Player pointer passed in to initialize 
 * member variables to allow the space access to interact with player.
 * ****************************************************************************/
Space::Space(Player* survivor)
{
	top = nullptr;
	bottom = nullptr;
	left = nullptr;
	right = nullptr;
	item = actionItem = "void";
	actionDesc = "void";
	this->survivor = survivor;
	bag = survivor->getInventory();
}

/*******************************************************************************
 * Description: Allows the player to investigate an area. Compares the player
 * bag to the item member variable (indicates an item can be found on that 
 * space). If there is no item, it will notify the user, else it will add the
 * item to the bag.
 * ****************************************************************************/
void Space::explore()
{
	if(item == "void")
	{
		printStars();
		cout << "You look around for a while, but don't find anything.";
		printStars();
	}
	else
	{
		printStars();
		cout << explorePrompt;
		bag->addItem(item);
		item = "void";
		printStars();
	}	
}

	
/*******************************************************************************
 * Description: Compares the player bag to the specific item required to
 * complete the specific space action (ie. axe to chop)
 * ****************************************************************************/
bool Space::doAction()
{
	if(bag->hasItem(actionItem))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*******************************************************************************
 * Setters and Getters
 * ****************************************************************************/
void Space::setLinks(Space* top, Space* bottom, Space* left, Space* right)
{
	this->top = top;
	this->bottom = bottom;
	this->left = left;
	this->right = right;
}

Space* Space::getTop()
{
	return top;
}

Space* Space::getBottom()
{
	return bottom;
}

Space* Space::getLeft()
{
	return left;
}

Space* Space::getRight()
{
	return right;
}

string Space::getItem()
{
	return item;
}

string Space::getSpaceType()
{
	return spaceType;
}

string Space::getActionDesc()
{
	return actionDesc;
}
