/******************************************************************************
 * Program Name: Final Project - Marooned - Hut Class Header
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: No special actions or events for this space. Simply allows the
 * user a space to find another item. Provides a unique description of the
 * setting.
 * ****************************************************************************/
#ifndef HUT_HPP
#define HUT_HPP
#include "Space.hpp"

class Hut: public Space
{
	public:
		Hut(Player*);
		void enterSpace();
		~Hut(){}
};

#endif
