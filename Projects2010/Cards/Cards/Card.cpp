// Card.cpp
// Author: Shawn Wilkinson
#include <string>
#include "Card.h"
using namespace std;

// Initialize Static Vars
string Card::arrSuit[4] = { "Clubs", "Diamonds", "Hearts", "Spades" };
string Card::arrFace[13] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };

// Constructor 
Card::Card(int suit, int face) {
	_suit = suit;
	_face = face;
}

// toString Method
string Card::toString() {
	return arrFace[_face] + " of " + arrSuit[_suit];
}

	