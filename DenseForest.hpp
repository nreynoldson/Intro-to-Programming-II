/******************************************************************************
 * Program Name: Final Project - Marooned - DenseForest Class Header
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: Derived from Space class. Unique spaceAction function allows
 * the player to chop wood if they have an axe. RandomEvent() will give the
 * player a chance to be bit by a snake.
 * ****************************************************************************/
#ifndef DENSEFOREST_HPP
#define DENSEFOREST_HPP
#include "Space.hpp"

class DenseForest: public Space
{
	public:
		DenseForest(Player*);
		void spaceAction();
		void enterSpace();
		void randomEvent();
		~DenseForest(){}
};

#endif
