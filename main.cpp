/******************************************************************************
 * Program Name: Final Project - Marooned
 * Date: 8/13/19
 * Name: Nicole Reynoldson
 * Description: A text based adventure game follows the player stuck on a 
 * deserted island. They must craft a raft on a beach to be able to get off
 * safely. Requires a tarp, rope and 3 logs and that the user be on a beach
 * for them to escape. The game allows the user to collect food to regenerate
 * health while also triggering random events that could bring down HP. 
 *****************************************************************************/
#include "Island.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	srand(time(0));
	cout << endl << string(80, '-') << endl;
	cout << endl << center("MAROONED", 80) << endl;
	cout << endl << string(80, '-') << endl;

	cout << "Groggy, you wake up on a beach you've never seen before. You can't"
			  " remember what\nhappened, or how you got here. All you have on you "
			  "is a frayed, dirty backpack\nand a tattered old map. You should try"
			  " to build a raft to get home. You will\nneed a tarp, rope and 3 "
			  "logs. You can probably find items around the island to\nhelp you"
			  " out. Explore, but be careful not to wear yourself out...\n"<< endl; 

	Island desIsland;
	
	while(desIsland.getGameState() == INPROGRESS )
	{
		desIsland.turn();
	}

	if(desIsland.getGameState() == EXIT)
	{
		cout << "\nI guess you'll just starve to death then..." << endl;
	}
	else if(desIsland.getGameState() == LOST)
	{
		cout << "\nGAMEOVER!\n"; 
		printStars();
	}
	else
	{
		cout << "\nWow! You escaped the island! Wait, do you even know how to"
				  " sail?\n";
		printStars();
	}
}
