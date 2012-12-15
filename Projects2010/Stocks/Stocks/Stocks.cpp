//Author: Shawn Wilkinson

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Set Varibles
    double stocks = 600, price = 21.77, percent = 0.02;
	//Calculate Varibles
	double paid = stocks * price;
	double commission = paid * percent;
    double total = paid + commission;
    
    //Print
    cout << "Amount paid for stocks(no commission): $" << paid << endl;
    cout << "Amount of the commission: $" << commission << endl;
    cout << "Total Amount Paid: $" << total << endl;

    //Exit Program
    system("PAUSE");
    return 0;
}