// Author: Shawn Wilkinson
// Includes and Namespaces
#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>
#include <Windows.h>
using namespace std;

// Function Prototypes
void moveTortoise(int * const, int const);
void moveHare(int * const , int const);

// Main Function
int main() {
	// Declare Vars and Constants
	int tortoiseLoc = 1, hareLoc = 1, torRun, harRun;
	int const FINISH_LINE = 70;

	int const FAST_PLOD = 3, SLIP = -6, SLOW_PLOD = 1 ;
	int const SLEEP = 0, BIG_HOP = 9, BIG_SLIP = -12, SMALL_HOP = 1, SMALL_SLIP = 2;

	// Begin the Race
	cout << "BANG !!!!!" << endl;
	cout << "AND THEY'RE OFF !!!!!" << endl;
		// Why did the author have to use so many exclamation points....

	// Seed Random
    srand ( time(NULL) );

	// Game Loop

	while(1) {
		// Pause One Second
		Sleep(1000);

		// Generate Random Values
		torRun = rand() % 10 + 1;
		harRun = rand() % 10 + 1;

		// Debug
		cout << torRun << " " << harRun << endl;

		// Move Tortoise
		if(torRun >= 1 && torRun <= 5)
			moveTortoise(&tortoiseLoc, FAST_PLOD);
		else if (torRun >= 6 && torRun <= 7)
			moveTortoise(&tortoiseLoc, SLIP);
		else 
			moveTortoise(&tortoiseLoc, SLOW_PLOD);

		// Move Hare 
		if(harRun >= 1 && harRun <= 2)
			moveHare(&hareLoc, SLEEP);
		else if (harRun >= 3 && harRun <= 4)
			moveHare(&hareLoc, BIG_HOP);
		else if (harRun == 5)
			moveHare(&hareLoc, BIG_SLIP);
		else if (harRun >= 6 && harRun <= 8)
			moveHare(&hareLoc, SMALL_HOP);
		else 
			moveHare(&hareLoc, SMALL_SLIP);

		// Reset if Outside Bounds
		if ( tortoiseLoc < 1 )
			tortoiseLoc = 1;
		if ( hareLoc < 1 ) 
			hareLoc = 1;

		if ( tortoiseLoc ==  hareLoc) 
			cout << "OUCH!!!" << endl;

		// Print Positions
		for( int i = 1; i <= 70; i++) {
			if (i == tortoiseLoc) 
				cout << "T";
			else if (i == hareLoc)
				cout << "H";
			else
				cout << "-";
		}

		// Check Win
		if( tortoiseLoc == hareLoc && tortoiseLoc == FINISH_LINE) {
			cout << "\nIt's a tie." << endl;
			break;
		}
		else if (  tortoiseLoc >= FINISH_LINE ) {
			cout << "\nTORTOISE WINS!!! YAY!!!" << endl;
			break;
		}
		else if (  hareLoc >= FINISH_LINE ) {
			cout << "\nHare wins. Yuch." << endl;
			break;
		}
		//else: continue running
	}
	
	// Exit Program
	system("PAUSE");
	return 0;
}

void moveTortoise(int * const loc, int const move) {
	*loc += move;
}

void moveHare(int * const loc, int const move) {
	*loc += move;
}