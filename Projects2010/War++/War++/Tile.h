//Include Statements
#include "stdafx.h"

// Char: -128 to 127
// Short Int: -32768 to 32767

class Tile {
	private: 		
		string name;
			// Short Name - A short unique name to describe the tile, should be
			// between 5-20 charaters in length. 
		string img;
			// Image Location - The image path of the tile relative to the 
			// install directory. 
		short int mCost;
			// Unit Movement Cost - Number of movement points, value 1-3, this
			// tile takes to cross. 
		short int def;
			// Defense Rating - A percentage, 0% - 50%, which determines how many
			// hit points that the tile absorbs.
		//enum type { GROUND, WATER }; Later...
	public:
		//Contructor
		Tile();

		//Getters
		string getName();
		string getImg();
		short int getMovementCost();
		short int getDefenseRating();		
};