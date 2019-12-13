/******************************************************************************
 * Program Name: Final Project - Marooned - Player Class Implementation
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: Inventory class made up of a container that can hold string 
 * objects representing items in the world. Contains functions for adding, 
 * removing, searching and printing the inventory.
 * ****************************************************************************/
#include "Player.hpp"
using std::cout;
using std::endl;

/*******************************************************************************
 * Description: Player constructor initializes the user health, dead or alive
 * status and allocates a new inventory.
 ******************************************************************************/
Player::Player(int cap)
{
	health = 100;
	bag = new Inventory(cap);
	dead = false;
}

/*******************************************************************************
 * Description: Takes an integer as a parameter as a value by which the health
 * should change. If the health is less than 0 following the change, it will be
 * set to 0. If the health exceeds 100, it should be set to 100. 
 ******************************************************************************/
void Player::updateHealth(int val)
{
	health += val;

	if(health <= 0)
	{
		dead = true;
		health = 0;
	}
	if(health > 100)
	{
		health = 100;
	}
}

/*******************************************************************************
 * Description: If the user has any of the food options in their inventory, the
 * option is added to the end of the menu vector. Returns true if the player has
 * food and false if the player does not.
 ******************************************************************************/
bool Player::catalogFood()
{
	foodMenu.clear();
	bool food = false;
	if(bag->hasItem("Berries")) 
	{
		foodMenu.push_back(Option("Berries", 1));
		food = true;
	}
	if(bag->hasItem("Fish"))
	{
		foodMenu.push_back(Option("Fish", 2));
		food = true;
	}
	foodMenu.push_back(Option("Back", 3));

	//If there is food in the player inventory ask if they would like to eat
	if(food)
	{
		cout << "\nYou have food in your bag. Would you like to eat? (y/n)\n";
		char ch = getChar('y', 'n');
		
		if(ch == 'y')
		{
			return true;
		}
	}
	
	return false;
}

/*******************************************************************************
 * Description: Takes no parameters and returns no values. If there is food that
 * could be eaten, the function displays a menu for the user to choose which 
 * item to eat.  
 ******************************************************************************/
void Player::eatFood()
{
	if(catalogFood())
	{
		cout << "\nWhat would you like to eat?" << endl;
		int choice = displayMenu(foodMenu);
		
		switch(choice)
		{
			//Eat berries
			case 1:
			{
				//Gives a random chance of being poisoned.
				bag->remItem("Berries");
				
				int val = randomNumber(1, 100);
				if(val <= POISONPROB)
				{	
					printStars();
					updateHealth(-BERRIES);

					if(isDead())
					{
						cout << "Wow, you died from eating a poison berry...what a"
								  " way to go.";
						printStars();
					}
					else
					{
						cout << "Oh no! They were poisonous. You lose some health!\n";
						printStars();
					}
				}
				else
				{
					printStars();
					cout << "You eat some berries and gain a little health!";
					printStars();
					updateHealth(BERRIES);
				}
				break;
			}
			//Eat fish
			case 2:
			{
				bag->remItem("Fish");
				printStars();
				cout << "You eat a fish - raw and wriggling. You gain some health!";
				printStars();
				updateHealth(FISH);
				break;
			}
			case 3:
			{}
		}
	}
}

/******************************************************************************
 * Description: Checks whether the user has all of the necessary items for
 * completing the raft. Returns true if they are all present.
 * ****************************************************************************/
bool Player::canBuild()
{
	int logs = bag->getItemQty("Log");
		
	if(bag->hasItem("Tarp") && bag->hasItem("Rope") && logs >= 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/******************************************************************************
 * Description: Checks what items the user has in their inventory and provides
 * hints based on what is yet to be found/done.
 * ****************************************************************************/
void Player::setWilson()
{	
	wilsonTip.clear();
	if(!bag->hasItem("Axe"))
	{
		wilsonTip.push_back("\"My spirit tells me there's an axe on one of the"
								 " beaches...Trust in Wilson.\"");
	}
	if(!bag->hasItem("Log") && bag->hasItem("Axe"))
	{
		wilsonTip.push_back("\"That axe is probably for chopping stuff. I'm just"
								  " a ball though, so I dunno. But you probably need "
								  "3 logs...just saying\"");
	}
	if(!bag->hasItem("Fishing pole"))
	{
		wilsonTip.push_back("\"I could've sworn I saw a fishing pole on one of "
								  "these beaches a few years ago.\nCourse it's been a"
								  " while since I explored...I got no legs!\"");
	}
	if(!bag->hasItem("Tarp"))
	{
		wilsonTip.push_back("\"My senses tell me there is an important item in"
								  " the hut. Don't miss out!\"");
	}
	if(!bag->hasItem("Rope"))
	{
		wilsonTip.push_back("\"Weird sounds come from that cave at night. I "
								  "wouldn't go in there, but you\nprobably should! I"
								  " bet bringing a weapon would be helpful...\"");
	}
	if(canBuild())
	{
		wilsonTip.push_back("\"Looks like you have everything you need! What are "
								  "you waiting for? Get to a\nbeach and build that "
								  "raft!\"");
	}
}

/******************************************************************************
 * Description: Prints a random hint based on what tips Wilson can possibly
 * give with the current items.
 * ****************************************************************************/
void Player::wilson()
{	
	setWilson();
	printStars();
	cout << "You hear a faint whisper so soft, you almost doubt you heard it:";
	cout << endl << endl;

	int size = wilsonTip.size();
	int N = randomNumber(0, size - 1);
	cout << wilsonTip.at(N);
	printStars();
}

/*******************************************************************************
 * Getters and Setters
 * ****************************************************************************/
bool Player::isDead()
{
	return dead;
}

int Player::getHealth()
{
	return health;
}

Inventory* Player::getInventory()
{
	return bag;
}

/******************************************************************************
 * Description: Destructor frees memory allocated for the user inventory.
 * ****************************************************************************/
Player::~Player()
{
	delete bag;
}
