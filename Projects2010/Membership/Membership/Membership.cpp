// Author: Shawn Wilkinson
// Title: Membership Fees Increase
// Description: Print the yearly fee of a country club with a membership of $2,500 
// for 6 years with an increase if 4% a year.  

//Includes
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	//Vars
	float cost = 2500, fee = 1.04;

	//Print Membership Rates
	for(int i = 1; i <= 6; i++) {
		cost = cost * fee;
		cout << "Membership cost for year " << i << ": $" << setprecision(2) << fixed << cost << endl;
	}

	//Exit Program
	system("PAUSE");
	return 0;
}