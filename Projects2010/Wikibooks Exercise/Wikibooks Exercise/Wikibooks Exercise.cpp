//Author: Shawn Wilknsion 
//http://en.wikibooks.org/wiki/C++_Programming/Exercises/Iterations

//Include Statements 
#include "stdafx.h"
#include <iostream>

//Using Statements
using namespace std;

// Exercise 2
// Instructions: Write a program that asks the user to type all the 
// integers between 8 and 23 (both included) using a for loop.
void ex2()
{
	//Declare Varibles
	int input = 0;

	//Print Start Message
	cout << "We are going to have you enter in some numbers." << endl;

	for(int i=8; i<=23; i++) {
		cout << "Please enter the number " << i << ": ";
		cin >> input; 
	}
}

//Main Function
int main()
{
	//Current Function
	ex2();
	
	//End Program
	system("PAUSE");
	return 0;
}

