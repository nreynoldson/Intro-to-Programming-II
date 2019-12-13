/******************************************************************************
 * Program Name: Final Project - Marooned - Space Class Header
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: Pure virtual abstract base class Space. Contains functions to
 * link spaces together, trigger random events, give space descriptions, and
 * complete special space functions.
 *****************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include "Player.hpp"
#include "menu.hpp"
#include <string>
#include "constants.hpp"
#include <iostream>
#include "utilityFunctions.hpp"

class Space
{
	protected:
		Space *top, *bottom, *left, *right;

		string item, actionItem, actionDesc;
		string spaceType, explorePrompt;

		Player* survivor;
		Inventory* bag;

	public:
		Space(Player*);
		
		//Setters and Getters
		void setLinks(Space*, Space*, Space*, Space*);
		Space* getTop();
		Space* getBottom();
		Space* getLeft();
		Space* getRight();
		string getItem();
		string getSpaceType();
		string getActionDesc();
	
		virtual bool doAction();
	
		//Various action/event functions
		virtual void enterSpace()=0;
		virtual void randomEvent(){}
		virtual void spaceAction(){}
		virtual void explore();
		virtual ~Space(){}
};

#endif		
