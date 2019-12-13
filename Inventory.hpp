/******************************************************************************
 * Program Name: Final Project - Marooned - Inventory Class Header
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: Inventory class made up of a container that can hold string 
 * objects representing items in the world. Contains functions for adding, 
 * removing, searching and printing the inventory.
 * ****************************************************************************/
#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "utilityFunctions.hpp"
using std::string;

class Inventory
{
	private:
		std::vector<string> bag;
		int capacity;
	
	public:
		Inventory(int);
		void addItem(string);
		bool hasItem(string);
		bool remItem(string);
		bool isFull();
		void printInventory();
		int getItemQty(string);
};

#endif
