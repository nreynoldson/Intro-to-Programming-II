/******************************************************************************
 * Program Name: Final Project - Marooned - Player Class Header
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: Player class contains the players health, and functions for
 * allowing the user to eat food. If the player has the volleyball Wilson,
 * he will provide tips when prompted based on the items in the users bag.  
 * ****************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <vector>
#include <string>
#include "Inventory.hpp"
#include "utilityFunctions.hpp"
#include "menu.hpp"
#include "Option.hpp"
#include "constants.hpp"

class Player
{
	private:
		int health;
		std::vector<Option> foodMenu;
		std::vector<string> wilsonTip;
		Inventory* bag;
		bool dead;

	public:
		Player(int);
		void updateHealth(int);
		bool catalogFood();
		void eatFood();
		bool isDead();
		int getHealth();
		Inventory* getInventory();
		bool canBuild();
		void wilson();
		void setWilson();
		~Player();	
};

#endif		
