// Project Name: Knight Tour
// File Name: KnightTour.cpp
// Author: Shawn Wilkinson

// Include and Using Stateements
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Board Size Constants
int const SIZEX = 8;
int const SIZEY = 8;

// Initialize and Populate Move Arrays Constants
int const HORI[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; // An array with 8 values
int const VERT[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

// Initialize and Populate Heuristic
int accessibility[SIZEX][SIZEY] =
{
	{2, 3, 4, 4, 4, 4, 3, 2},
	{3, 4, 6, 6, 6, 6, 4, 3},
	{4, 6, 8, 8, 8, 8, 6, 4},
	{4, 6, 8, 8, 8, 8, 6, 4},
	{4, 6, 8, 8, 8, 8, 6, 4},
	{4, 6, 8, 8, 8, 8, 6, 4},
	{3, 4, 6, 6, 6, 6, 4, 3},
	{2, 3, 4, 4, 4, 4, 3, 2}
};

// Function Prototypes
bool validMove( int, int, int, int [][SIZEY] );
int bestMove( int, int, int [][SIZEY] );
void displayBoard( int [][SIZEY] );

// Main Program and Loop
int main() {
	// Initialize Variables
	int currentRow = 0;
	int currentColum = 0;
	int moveCounter = 1;
	bool noMoves = false;

	// Initalize and Populate Board Array
	int board[SIZEX][SIZEY];
	for(int x=0; x < SIZEX; x++) {
		for(int y=0; y < SIZEY; y++){
			board[x][y] = 0;
		}
	}
	board[currentRow][currentColum] = moveCounter; // Set Start Point to Used

	// Make a Move
	while(moveCounter <= 64 && noMoves == false) {
		// Check for Valid Move. If the move is not
		// valid try another move. If no valid moves
		// are found the sentinel will end the loop.

		int move = bestMove( currentRow, currentColum, board );
		if( move == -1) {
			break;
		}
		currentRow += VERT[move];
		currentColum += HORI[move]; 
		moveCounter++;
		board[currentRow][currentColum] = moveCounter;
	}

	// Print Total Moves
	cout << "\n" << "Total Moves: " << moveCounter << "\n" << endl;

	// Display Board
	cout << "Board:\n" << endl;
	displayBoard(board);

	// Exit Program
	system("PAUSE");
	return 0;
}

// Function Definitions
bool validMove(int moveNumber, int cRow, int cColum, int board[][SIZEY]) {
	cRow += VERT[moveNumber];
	cColum += HORI[moveNumber]; 
	if(cRow < 0 || cRow > SIZEX || cColum < 0 || cColum > SIZEY) {
		return false; 
	}
	else if(board[cRow][cColum] == 0) {
		return true;
	}
	return false;
}
int bestMove( int cRow, int cColum, int board[][SIZEY]) {
	int bestMove = -1;
	int heuristic = 9;

	int tmpRow = cRow;
	int tmpColum = cColum;

	for(int i=0; i <= 7; i++) { 
		tmpRow += VERT[i];
		tmpColum += HORI[i];
		if( validMove(i, cRow, cColum, board) && accessibility[tmpRow][tmpColum] <= heuristic)
		{
			 heuristic = accessibility[tmpRow][tmpColum];
			 bestMove = i;
		}
		tmpRow = cRow;
		tmpColum = cColum;
	}

	return bestMove;
}
void displayBoard(int board[][SIZEY]) {
	for(int x=0; x < SIZEX; x++) {
		for(int y=0; y < SIZEY; y++){
			cout << setw(4) << board[x][y] << "|";
		}
		cout << endl;
	}
}