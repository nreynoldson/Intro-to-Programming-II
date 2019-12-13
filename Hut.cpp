/******************************************************************************
 * Program Name: Final Project - Marooned - Hut Class Implementation File
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: No special actions or events for this space. Simply allows the
 * user a space to find another item. Provides a unique description of the
 * setting.
 * ****************************************************************************/
#include "Hut.hpp"
using std::cout;
using std::endl;

/*******************************************************************************
 * Description: Constructor initiliazes all strings required for describing
 * the space and the items with in it.
 * ****************************************************************************/
Hut::Hut(Player* survivor): Space(survivor)
{
	spaceType = "Old Hut";
	item = "Tarp";
	explorePrompt = "Nestled under some fallen planks and debris you find tarp."
						 " This could make a\ngood sail...";
}

/*******************************************************************************
 * Description: Outputs a description of the space as the player enters it.
 * ****************************************************************************/
void Hut::enterSpace()
{
	printStars();
	cout << "You enter an old worn down looking hut. Boards are hanging from the"
			  "ceiling and\nit looks like nature is reclaiming it.";
	printStars();

}
