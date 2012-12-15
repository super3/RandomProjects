// Main.cpp
// Author: Shawn Wilkinson

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include "Card.h"
#include "DeckOfCards.h"
using namespace std;

int main() {
	// Create DeckOfCards Object
	DeckOfCards myDeck;

	// Shuffle DeckOfCards 
	myDeck.shuffle();

	// Loop and Deal Cards
	while( myDeck.moreCards() ) {
		Card tmpCard = myDeck.dealCard();
		cout << tmpCard.toString() << endl;
	}

	// Exit Program
	system("PAUSE");
	return 0;
}