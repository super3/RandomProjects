//Author: Shawn Wilkinson

//Includes
#include "stdafx.h"
#include <iostream>
using namespace std;

//Varibles
char ttt[3][3] =
{
	{'_','_','_',},
	{'_','_','_',},
	{'_','_','_',}
};
short int x, y; 
bool trade = true;

void showGrid() {
	for(int i = 0; i < 3; i++) {
		cout << "\n";
		for(int j = 0; j < 3; j++)
			cout << ttt[i][j];
	}
}

void move(short int x, short int y, char spot) {
	ttt[(y-1)][(x-1)] = spot;
}

void checkWin() {
	if(ttt[0][0] == 'X' && ttt[0][1] == 'X' && ttt[0][2] == 'X') {
		cout << "X Wins!" << endl;
	}
}

int main()
{
	//Welcome Message
	cout << "Welcome to Tic Tac Toe." << endl;
	cout << "Please pick your spots in grid format." << endl;

	//Choose Spot
	while (1) {
		if(trade) {
			cout << "\nPlayer 1, please choose a spot: ";
			cin >> x >> y;
			move(x, y, 'X');
			trade = false;
		}
		else {
			cout << "\nPlayer 2, please choose a spot: ";
			cin >> x >> y;
			move(x, y, 'O');
			trade = true;
		}
		//Print Array
		showGrid();
		//Check Win
		checkWin();
	}

	//Exit Program
	cout << endl;
	system("PAUSE");
	return 0;
}