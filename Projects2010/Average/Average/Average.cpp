// Average.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	//Declare Varibles and Process
	int num1 = 28, num2 = 32, num3 = 37, num4 = 24, num5 = 33;
	int sum = num1 + num2 + num3 + num4 + num5;
	double average = sum / 5;

	//Print Result
	cout << "Sum: " << sum << endl;
	cout << "Average: " << average << endl;

	//End Program
	system("PAUSE");
	return 0;
}

