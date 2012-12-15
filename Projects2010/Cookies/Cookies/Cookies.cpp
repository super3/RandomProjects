//Author: Shawn Wilkinson

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	//Set Varibles
	double cookies = 40, calories = 300, servings = 10;
	double calPerCookie = (calories * servings) / cookies;
	double cookiesEaten;

	//Get Cookies
	cout << "How many cookies did you eat? ";
	cin >> cookiesEaten;

	//Print Result
	cout << "You consumed " << (calPerCookie * cookiesEaten) << " calories." << endl;

	//Exit Program
	system("PAUSE");
	return 0;
}

