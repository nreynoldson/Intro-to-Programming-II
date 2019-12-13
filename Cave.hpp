/******************************************************************************
 * Program Name: Final Project - Marooned - Cave Class Header
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: No randomEvents on this space, but exploration triggers a 
 * combat sequence between the player and a bat. If the player runs, the bat
 * will regenerate health but the player will not.
 * ****************************************************************************/
#ifndef CAVE_HPP
#define CAVE_HPP
#include "Space.hpp"
#include <vector>
#include <string>

class Cave: public Space
{
	private:
		std::vector<std::string> fightMenu;
		int survivorSides, survivorDies;
		int batHealth;
	
	public:
		Cave(Player*);
		void batFight();
		void combat();
		void explore();
		void enterSpace();
		~Cave(){}
};

#endif
