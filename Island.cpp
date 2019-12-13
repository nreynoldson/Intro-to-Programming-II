/******************************************************************************
 * Program Name: Final Project - Marooned - Island Class Implementation
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: Island class instantiates all of the spaces for the board and
 * links them together. Responsible dynamically creating a menu of options 
 * based on which items are avilable and the current space. Completes a full
 * turn and allows the user to change locations
 * ****************************************************************************/
#include "Island.hpp"
using std::cout;
using std::endl;

/*******************************************************************************
 * Description: Island constructor will allocate space for a player object,
 * instantiate the board and link each space in the correct position. Sets the
 * game state and the starting position of the player on the board.
 ******************************************************************************/
Island::Island()
{
	survivor = new Player(12);
	createBoard();
	gameState = INPROGRESS;
	bag = survivor->getInventory();	
}

/*******************************************************************************
 * Description: Instantiates an instance of each type of space. Initializes
 * objects on to the four different beaches and sets the probability for 
 * catching fish on each. Links all of the squares together and initializes
 * the starting position to the North beach.
 ******************************************************************************/
void Island::createBoard()
{
	//Prompts that describe the player exploring the space
	string b1 = "You find a fishing pole leaning against a palm tree.\n";
	string b2 = "You find an axe partially buried in the sand.\n";
	string b3 = "You find a weird volleyball with a face on it. This probably"
				   " won't be useful.\n";

	beach1 = new Beach(survivor, "Fishing pole", b1, FISHPROB1);
	beach2 = new Beach(survivor, "Axe", b2, FISHPROB2);
	beach3 = new Beach(survivor, "Wilson", b3, FISHPROB3);
	beach4 = new Beach(survivor, "void", "", FISHPROB4);
	sparse1 = new SparseForest(survivor);
	sparse2 = new SparseForest(survivor);
	dense = new DenseForest(survivor);
	abanHut = new Hut(survivor);
	aCave = new Cave(survivor);
	
	beach1->setLinks(nullptr, sparse2, abanHut, beach2);
	beach2->setLinks(nullptr, beach3, beach1, nullptr);
	beach3->setLinks(beach2, aCave, sparse2, nullptr);
	beach4->setLinks(sparse2, nullptr, dense, aCave);
	sparse1->setLinks(abanHut, dense, nullptr, sparse2);
	sparse2->setLinks(beach1, beach4, sparse1, beach3);
	dense->setLinks(sparse1, nullptr, nullptr, beach4);
	abanHut->setLinks(nullptr, sparse1, nullptr, beach1);
	aCave->setLinks(beach3, nullptr, beach4, nullptr);

	currSpace = beach1;
}

/******************************************************************************
 * Description: Assesses whether a move is possible. If so, it is added to a
 * menu of options that the user may choose from.
 ******************************************************************************/
void Island::catalogMoves()
{
	moveMenu.clear();
	if(currSpace->getTop() != nullptr)
	{
		moveMenu.push_back(Option("North", 1));
	}
	
	if(currSpace->getRight() != nullptr)
	{
		moveMenu.push_back(Option("East", 2));
	}

	if(currSpace->getBottom() != nullptr)
	{
		moveMenu.push_back(Option("South", 3));
	}

	if(currSpace->getLeft() != nullptr)
	{
		moveMenu.push_back(Option("West", 4));
	}
	moveMenu.push_back(Option("Back", 5));
}

/*******************************************************************************
 * Description: Allows the user to choose where they would like to move by 
 * printing the dynamic menu that only includes legal moves. Sets the current
 * space to that chosen by the user. 
 ******************************************************************************/
void Island::changeLocation()
{
	catalogMoves();
	cout << "\nWhere would you like to go?" << endl;
	int choice = displayMenu(moveMenu);

	switch(choice)
	{
		case 1: 
			currSpace = currSpace->getTop();
			break;
		case 2:
			currSpace = currSpace->getRight();
			break;
		case 3:
			currSpace = currSpace->getBottom();
			break;
		case 4:
			currSpace = currSpace->getLeft();
			break;
		case 5:
			return;
	}
	
	//Moving costs HP, if the player dies let them know how else call the
	//enterSpace() function to give a description of the new space
	survivor->updateHealth(MOVE);
	if(survivor->isDead())
	{
		cout << "You died while trying to hike somewhere else on the island."
				  " Bummer.";
		printStars();
	}
	else
	{
		currSpace->enterSpace();
	}
}

/*******************************************************************************
 * Description: Generates a vector of menu options depending on what items the
 * user has and what space they currently occupy.
 ******************************************************************************/
void Island::generateMenu()
{
	mainMenu.push_back(Option("View map", 1));
	mainMenu.push_back(Option("View inventory/eat food", 2));
	mainMenu.push_back(Option("Explore current location", 3));
	mainMenu.push_back(Option("Change location", 4));

	if(currSpace->doAction() == true)
	{
		mainMenu.push_back(Option(currSpace->getActionDesc(), 5));
	}
	if(bag->hasItem("Wilson"))
	{
		mainMenu.push_back(Option("Talk to Wilson", 6));
	}
	if(survivor->canBuild() && currSpace->getSpaceType() == "Beach")
	{
		mainMenu.push_back(Option("Build raft", 7));
	}
	mainMenu.push_back(Option("Quit", 8));
}

/*******************************************************************************
 * Description: Display the dynamic menu and get the user choice. Completes the
 * appropriate action and checks at the end of the turn if the user has died to
 * update the gameState variable.
 ******************************************************************************/
void Island::turn()
{
	generateMenu();
	
	cout << endl << string(80, '-') << endl;
	cout << endl << "MAIN MENU" << std::right 
		  << std::setw(68) << "HP: " << survivor->getHealth();
	cout << endl << string(80, '-') << endl;

	int choice = displayMenu(mainMenu);
	
	switch(choice)
	{
		case 1:
		{
			displayMap();
			break;
		}
		case 2:
		{
			bag->printInventory();
			survivor->eatFood();
			break;
		}
		case 3:
		{
			currSpace->explore();
			break;
		}
		case 4:
		{
			changeLocation();
			break;
		}
		case 5:{
			currSpace->spaceAction();
			break;
		}
		case 6: {
			survivor->wilson();
			break;
		}
		case 7: {
			gameState = WON;
			break;
		}
		case 8:
		{
			gameState = EXIT;
		}
	}
	mainMenu.clear();
	
	if(survivor->isDead())
	{
		gameState = LOST;
	}
}

	
/*******************************************************************************
 * Description: Displays a map of the island and updates the players location 
 * to the correct square when called.
 ******************************************************************************/
void Island::displayMap()
{
	Space* spaces[3][3] = { {abanHut, beach1, beach2},
									{sparse1, sparse2, beach3},
									{dense, beach4, aCave} };  
	

	cout << endl << center("TATTERED MAP OF DESERTED ISLAND", 46) << endl;
	//Rows
	for(int i = 0; i < 3; i++)
	{
		cout << string(46, '-') << endl;
		//Make the top half of each square of the board
		for(int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cout << "|" << center(" ", 14);
			}
			cout << "|" << endl;
		}
	
		// print the current square type
		for(int j = 0; j < 3; j++)
		{
			cout << "|" << center(spaces[i][j]->getSpaceType(), 14);
		}
		cout <<"|" << endl;

		//If on the specific space, print a character	
		for(int j = 0; j < 3; j++)
		{
			if(spaces[i][j] == currSpace)
			{
				cout <<"|" <<  center("\\(^-^)/", 14);
			}
			else
			{
				cout << "|" << center(" ", 14);
			}
		}
		cout << "|" << endl;
		
		// Complete the bottom of each box
		for(int k = 0; k < 2; k++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << "|" << center(" ", 14);
			}
			cout << "|" << endl;
		}
	}
	cout << string(46, '-') << endl << endl;
}

/*******************************************************************************
 * Getters and Setters 
 ******************************************************************************/
State Island::getGameState()
{
	return gameState;
}

/*******************************************************************************
 * Desctructor frees all of the memory allocated in the constructor 
 ******************************************************************************/
Island::~Island()
{
	delete survivor;
	delete beach1;
	delete beach2;
	delete beach3;
	delete beach4;
	delete sparse1;
	delete sparse2;
	delete dense;
	delete abanHut;
	delete aCave;
}
