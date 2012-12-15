//Include Statements
#include "stdafx.h"
#include "Tile.h"

//Contructor
Tile::Tile() {
	name = "DefaultTile";
	img = "images/blank.png";
	mCost = 1;
	def = 0; 
}

//Getters
string Tile::getName() {
	return name;
}
string Tile::getImg() {
	return img;
}
short int Tile::getMovementCost() {
	return mCost;
}
short int Tile::getDefenseRating() {
	return def;
}