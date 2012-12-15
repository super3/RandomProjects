// Author: Shawn Wilkinson

//Include Statements
#include "stdafx.h"
#include "Tile.h"
#include "Grid.cpp"
#include <iostream>

using namespace std;

//Main Function
int main()
{
	//Output Test
	cout << "Hello World" << endl;

	//Tile Test
	Tile tile1;
	cout << tile1.getDefenseRating() << endl;
	cout << tile1.getMovementCost() << endl;

	//Grid Test
	//Grid grid1 (10, 10);
	//grid1.getTile(0, 0)

	//End Programing
	cin.get();
	return 0;
}

