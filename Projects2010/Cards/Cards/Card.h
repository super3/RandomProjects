// Card.h
// Author: Shawn Wilkinson
#include <string>
using namespace std;

class Card
{
	public:
		Card( int, int ); // constructor
		string toString(); // face of suit
	private:
		int _suit; // suit of the card
		int _face; // face of the card

		// Two static arrays of string representing
		// the faces and suites
		static string arrSuit[4];
		static string arrFace[13];
}