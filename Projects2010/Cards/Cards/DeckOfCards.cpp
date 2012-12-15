// DeckofCards.cpp
// Author: Shawn Wilkinson

#include <string>
#include <vector>
#include <random>
#include <time.h>
#include "Card.h"
#include "DeckOfCards.h"
using namespace std;

DeckOfCards::DeckOfCards() 
{
	// Initialize Value
	currentCard = -1;

	// Nested Loops
	for(int i=1; i<=52; i++) {
		for( int j=1; j <= 4; j++) {
			for( int k=1; k <= 13; k++) {
				Card tmpCard = Card(j, k);
				deck.push_back(tmpCard);
			}
		}
	}
}

void DeckOfCards::shuffle() {
	// Seed Random
	srand ( time(NULL) );
	
	// Swap Cards
	for(int i=0; i<=52; i++) {
		int myRand = rand() % 53;
		Card tmpCard = deck[myRand];
		deck[myRand] = deck[i];
		deck[i] = tmpCard;
	}
}

Card DeckOfCards::dealCard() {
	return deck[++currentCard];
}

bool DeckOfCards::moreCards() {
	return (currentCard < 52);
}