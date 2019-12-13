/******************************************************************************
 * Program Name: Final Project - Marooned - Island Class Header
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: Island class instantiates all of the spaces for the board and
 * links them together. Responsible dynamically creating a menu of options 
 * based on which items are avilable and the current space. Completes a full
 * turn and allows the user to change locations
 * ****************************************************************************/
#ifndef ISLAND_HPP
#define ISLAND_HPP
#include "Player.hpp"
#include "Space.hpp"
#include "Beach.hpp"
#include "DenseForest.hpp"
#include "SparseForest.hpp"
#include "Hut.hpp"
#include "Cave.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>

enum State {INPROGRESS, WON, LOST, EXIT};

class Island
{
	public:
		//Pointers to player info
		Player* survivor;
		Inventory* bag;
		
		//Pointers for instantiating spaces
		Space* currSpace;
		Beach* beach1;
		Beach* beach2;
		Beach* beach3;
		Beach* beach4;
		SparseForest *sparse1;
		SparseForest *sparse2;
		DenseForest *dense;
		Hut* abanHut;
		Cave* aCave;
		
		State gameState;
		
		//Vectors for creating menu options
		std::vector<Option> moveMenu;
		std::vector<Option> mainMenu;

		//Functions for menu and board generation
		void createBoard();
		void catalogMoves();
		void generateMenu();
		void changeLocation();
		void displayMap();

	public:
		Island();
		~Island();
		void turn();
		State getGameState();
};

#endif

