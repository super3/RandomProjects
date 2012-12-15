// Mileage.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int tank, driven;
	double mpg; 
	//Get Input
	cout << "Please enter the number of gallons that the tank can hold";
	cin >> tank;
	cout << "\nPlease enter the number of miles it can be driven on a full tank:";
	cin >> driven;

	mpg = tank / driven; 

	cout << "\n Car's MPG: " << mpg << endl;

	//Exit Program
	std::cin.get();
	return 0;
}

