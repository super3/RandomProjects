// DeckofCards.h
// Author: Shawn Wilkinson

#include <vector>
#include "Card.h"
using namespace std;

class DeckOfCards 
{
	private:
		vector<Card> deck;
		int currentCard;
	public: 
		DeckOfCards();
		void shuffle();
		Card dealCard();
		bool moreCards();
}