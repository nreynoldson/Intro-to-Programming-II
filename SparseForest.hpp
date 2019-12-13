/******************************************************************************
 * Program Name: Final Project - Marooned - SparseForest Class Header
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: Derived from Space class. Special random event allows user to
 * find and heal from aloe. Unique space action allows the user to forage for
 * berries.
 * ****************************************************************************/
#ifndef SPARSEFOREST_HPP
#define SPARSEFOREST_HPP
#include "Space.hpp"

class SparseForest: public Space
{
	public:
		SparseForest(Player*);
		void enterSpace();
		void spaceAction();
		void randomEvent();
		bool doAction();
		~SparseForest(){}
};

#endif
