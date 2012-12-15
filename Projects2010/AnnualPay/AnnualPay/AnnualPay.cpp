// AnnualPay.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	//Create Vars
	double payAmount = 1700, payPeriods = 26;
	double annualPay = payAmount * payPeriods;

	//Print
	cout << "Pay Amount: $" << payAmount << endl;
	cout << "Pay Periods: " << payPeriods << endl;
	cout << "Annual Pay: $" << annualPay << endl;

	//Testing
	#pragma message("You win!");

	//Exit Program
	system("PAUSE");
	return 0;
}

