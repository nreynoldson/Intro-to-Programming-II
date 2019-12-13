/******************************************************************************
 * Program Name: Final Project - Marooned - Inventory Class Implementation
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: Inventory class made up of a container that can hold string 
 * objects representing items in the world. Contains functions for adding, 
 * removing, searching and printing the inventory.
 * ****************************************************************************/
#include "Inventory.hpp"
using std::vector;
using std::cout;
using std::endl;
using std::setw;

/*******************************************************************************
 * Description: Inventory constructor initializes the max allowable capacity of
 * the inventory.
 ******************************************************************************/
Inventory::Inventory(int cap)
{
	capacity = cap;
}

/*******************************************************************************
 * Description: addItem() takes a string as the item to add to the inventory.
 * If the inventory is full it will prompt the user to make some space.
 ******************************************************************************/
void Inventory::addItem(string item)
{
	if(static_cast<int>(bag.size()) == capacity)
	{
		cout << "Your bag is full. You should make some space.";
	}
	else
	{
		bag.push_back(item);
		cout << item << " added to your bag.";
	}
}

/*******************************************************************************
 * Description: Searches the inventory for a specific item (a string argument)
 * and returns true if the item is present.
 ******************************************************************************/
bool Inventory::hasItem(string item)
{
	for(unsigned int i = 0; i < bag.size(); i++)
	{
		if(bag.at(i) == item)
		{
			return true;
		}
	}
	return false;
}

/*******************************************************************************
 * Description: Searches the inventory for a specific item (a string argument)
 * and removes the first match it finds. If it is available to be removed the
 * function returns true.
 * ****************************************************************************/
bool Inventory::remItem(string item)
{
	for(vector<string>::iterator temp = bag.begin(); temp != bag.end(); temp++)
	{
		if(*temp == item)
		{
			bag.erase(temp);
			return true;
		}
	}
	
	return false;
}

/*******************************************************************************
 * Description: Checks whether the bag is at capacity. Returns true if no more
 * items can be added or false if there is still room.
 * ****************************************************************************/
bool Inventory::isFull()
{
	if(static_cast<int>(bag.size()) == capacity)
	{
		return true;
	}
	
	return false;
}

/*******************************************************************************
 * Description: Takes no parameters and returns no values. Prints the current
 * items in the inventory.
 * ****************************************************************************/
void Inventory::printInventory()
{
	if(bag.empty())
	{
		printStars();
		cout << "No items in inventory. Go do some exploring!";
		printStars();
	}
	else
	{
		cout << endl << string(20, '-') << endl;
		cout << "|" << center("INVENTORY", 18) << "|" << endl;
		cout << string(20, '-') << endl;

		for(unsigned int i = 0; i < bag.size(); i++)
		{
			cout << "|" << center(bag[i], 18) << "|" << endl;
		}
		cout << string(20, '-') << endl;
	}
}

/*******************************************************************************
 * Description: Takes a string as parameter and returns the number of items in
 * the inventory that match that description.
 * ****************************************************************************/
int Inventory::getItemQty(string item)
{
	int itemQty = 0;
	for(unsigned int i = 0; i < bag.size(); i++)
	{
		if(bag.at(i) == item)
		{
			itemQty++;
		}
	}
	
	return itemQty;
}
