// ForTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	//Intro Text
	cout << "Please enter the follow values: " << endl;

	//For Loop
	for(short int i=1, input; i<=10; i+=(input==i)) {
		cout << "\nPlease enter the number: "<< i;
		cin >> input; 
	}

	//Exit Program
	system("PAUSE");
	return 0;
}

