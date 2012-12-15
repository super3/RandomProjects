// Author: Shawn Wilkinson

#include <iostream>
using namespace std;

//Function Prototypes
void hanoi(int, int, int, int);
bool limit(int);

// Testing Tower of Hanoi Recursive Function
int main() 
{
	// Starter Varibles
	int numDisk; // The number of disks to be moved.
	int startPeg; // The peg on which the disks are initially threaded.
	int holdPeg; // The peg to which this stack of disks is to be moved.
	int endPeg; //The peg to be used as a temporary holding area.

	// Welcome Message
	cout << "Welcome to Tower of Hanoi Tester.\n" << endl;

	// User Input
	// Loop until correct input is given
	do {
		cout << "Number of disks: ";
		cin >> numDisk;
		cout << "Start Peg: ";
		cin >> startPeg; 
		cout << "Holding Peg: ";
		cin >> holdPeg;
		cout << "End Peg: ";
		cin >> endPeg;
	} while( !(numDisk < 64) || !(limit(startPeg)) || !(limit(holdPeg)) ||  !(limit(endPeg)) );
		// Keep user from ending the world
		// Check to make sure values are in between 1 and 3

	//Extra Line
	cout << "\nSteps:" << endl;

	// Run Function
	hanoi(numDisk, startPeg, holdPeg, endPeg);

	// Pause
	system("PAUSE");
}

// Tower of Hanoi Recursive Function
void hanoi(int numDisk, int startPeg, int holdPeg, int endPeg) {
	// Base Case
	if(numDisk == 1) {
		cout << startPeg << "->" << endPeg << endl;
	}
	// Recursive Part
	else {
		hanoi(numDisk-1, startPeg, endPeg, holdPeg);
		hanoi(1, startPeg, holdPeg, endPeg);
		hanoi(numDisk-1, holdPeg, startPeg, endPeg);
	}
}

// Check to make sure values are in between 1 and 3
bool limit(int peg) {
	if(peg <= 3 && peg >= 1)
		return true;
	else {
		cout << "Invalid Value(s). Try again." << endl;
		return false;
	}
}