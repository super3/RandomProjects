// TicTacToeForm.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include <string>
#include <iostream>

using namespace TicTacToeForm;
using namespace std;



// Global Varibles
char board[3][3] =
{
	{'_','_','_',},
	{'_','_','_',},
	{'_','_','_',}
};
string tmpBoard;
string winsX[9] = { "XXX??????", "???XXX???", "??????XXX", "X??X??X??", "?X??X??X?", "??X??X??X", "X???X???X", "??X?X?X??" };
string winsO[9] = { "OOO??????", "???OOO???", "??????OOO", "O??O??O??", "?O??O??O?", "??O??O??O", "O???O???O", "??O?O?O??" };
short int x, y; // "Disposable" varibles for positions on the game board 
bool trade = true; // Switches between true, and false for each players turn

// http://www.codeproject.com/KB/string/wildcmp.aspx
// Stolen wildcard functions
int wildcmp(const char *wild, const char *string) {
  // Written by Jack Handy - jakkhandy@hotmail.com

  const char *cp = NULL, *mp = NULL;

  while ((*string) && (*wild != '*')) {
    if ((*wild != *string) && (*wild != '?')) {
      return 0;
    }
    wild++;
    string++;
  }

  while (*string) {
    if (*wild == '*') {
      if (!*++wild) {
        return 1;
      }
      mp = wild;
      cp = string+1;
    } else if ((*wild == *string) || (*wild == '?')) {
      wild++;
      string++;
    } else {
      wild = mp;
      string = cp++;
    }
  }

  while (*wild == '*') {
    wild++;
  }
  return !*wild;
}

// Prints out the game board
bool isNotFull() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			if(board[i][j] == '_') { return true; } 
	}
	return false; 
}


// Replaces an empty spot on the grid board
bool move(short int x, short int y, char spot) {
	// This is a way to use an if statment without specifying an else statement. The if statment contains a 
	// return so the function will exit. All other values, i.e. else, will return false. 
	if(board[(y-1)][(x-1)] == '_') {
		board[(y-1)][(x-1)] = spot;
		return true;
	}
	return false; 
}

// Reduces the board to a 9 letter string so it can be tested for a win
string boardString() {
	tmpBoard = ""; 
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			tmpBoard += board[i][j];
	}
	return tmpBoard;
}

// Checks the board's state using all known win states. 
bool isWin() {
	for(int i = 0; i < 9; i++) {
		if( wildcmp(winsX[i].c_str(), boardString().c_str()) )
			{
				MessageBox::Show("\nPlayer 1 Wins!");
				return true; 
			}
		else if ( wildcmp(winsO[i].c_str(), boardString().c_str()) ) 
			{
				MessageBox::Show("\nPlayer 2 Wins!");
				return true;
			}	
		else if  ( !isNotFull() ) 
			{
				MessageBox::Show("\nThe game is a tie.");
				return true; 
			}
		}
	return false;
}

void press() {
	MessageBox::Show("Hello there!");
} 

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
