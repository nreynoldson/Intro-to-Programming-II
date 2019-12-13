/******************************************************************************
 * Program Name: Final Project - Marooned - Cave Class Implementation
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: No randomEvents on this space, but exploration triggers a 
 * combat sequence between the player and a bat. If the player runs, the bat
 * will regenerate health but the player will not.
 * ****************************************************************************/
#include "Cave.hpp"
using std::vector;
using std::string;
using std::cout;
using std::endl;

/*******************************************************************************
 * Description: Cave constructor initializes the Space base class constructor.
 * Sets up a menu of options for the player in the cave.
 ******************************************************************************/
Cave::Cave(Player* survivor): Space(survivor)
{
	spaceType = "Cave";
	item = "Rope";
	
	//Set the fight menu
	fightMenu.push_back("Fight the bat");
	fightMenu.push_back("Turn and run");
}

/*******************************************************************************
 * Description: Outputs a description of the area as the player enters it. 
 ******************************************************************************/
void Cave::enterSpace()
{
	printStars();
	cout << "You enter a dark damp cave. After a few steps in, it becomes pitch"
			  " dark. You\nhear the faint drip of water.";
	printStars();
}


/*******************************************************************************
 * Description: Will trigger the bat fight so long as the player does not
 * already have the rope in their inventory.
 ******************************************************************************/
void Cave::explore()
{
	//Player has already defeated the bat
	if(bag->hasItem("Rope"))
	{
		printStars();
		cout << "The cave is eerily quiet and peaceful now. Looks like there"
				  " isn't much else in here.";
		printStars();
	}
	
	// Start bat fight sequence
	else
	{
		printStars();
		cout << "A giant bat swoops down from the shadows! A long piece of rope"
				  " dangles in it's\ntalons....";
		printStars();

		batFight();
	}
}

/*******************************************************************************
 * Description: If the player has the axe in their inventory they will do more
 * damage than just using their fists. If the player runs, the bats health will
 * regenerate to full health.
 ******************************************************************************/
void Cave::batFight()
{
	batHealth = BATHEALTH;
	
	//Determine what the players attack will be
	if(bag->hasItem("Axe"))
	{
		survivorSides = 10;
		survivorDies = 3;
	}
	else
	{
		survivorSides = 10;
		survivorDies = 2;
	}

	//Loop through the menu options and process while the player is not 
	//dead, the bat is not dead and the user has not chosen to run
	int choice;
	do
	{
		cout << endl;
		choice = displayMenu(fightMenu);
		switch(choice)
		{
			case 1:
			{
				combat();
				break;
			}
			case 2:
			{
				printStars();
				cout << "You turn and run!";
				printStars();
			}
		}
	}while(choice == 1 && batHealth > 0 && !survivor->isDead());
}

/*******************************************************************************
 * Description: Controls the actual fight sequence for the player and bat.
 * Player attacks first, followed by the bat. When the bat dies, the player
 * inventory is updated with the rope (needed to complete the raft).
 ******************************************************************************/
void Cave::combat()
{	
	//Player attack
	printStars();
	cout << "You swing back and strike the bat." << endl;
	
	int attack = rollDie(survivorSides, survivorDies);
	batHealth -= attack;

	cout << "The bat takes " << attack << " points of damage.\n" << endl;

	if(batHealth <= 0)
	{
		printStars();
		cout << "You killed it! Nice job! You are able grab the rope that it "
				  "was guarding.\n";

		bag->addItem("Rope");
		printStars();
	}
	else
	{
		cout << "****Bat Health: " << batHealth << "****" << endl;
		cout << string(80, '`') << endl;
		
		//Bat attack
		cout << "\nThe bat comes at you with its talons poised to scratch!\n";

		attack = rollDie(BATSIDES, BATDIES);
		
		survivor->updateHealth(-attack);
		
		if(!survivor->isDead())
		{
			cout << "You take " << attack << " points of damage." << endl;
			cout << "****HP: " << survivor->getHealth() << "****";
			printStars();
		}
		else
		{
			cout << "It managed to kill you. Tough luck.";
			printStars();
		}
	}
}

