//Author: Shawn Wilkinson

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	//Vars
	double far, cel;

	//Print
	cout << "Please enter a tempeture in celsius: ";
	cin >> cel; 

	//Calculate
	far = (1.8 * cel) + 32;

	//Result
	cout << cel << "*C is " << far << "*F" << endl;

	//Exit Program
	system("PAUSE");
	return 0;
}

