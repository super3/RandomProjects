// Author: Shawn Wilkinson
// Title: Sum of Numbers
// Description: Ask the user for a positive interger value, and return the 
// sum of all the integer from 1 up to the number entered.

// Includes
#include <iostream>
using namespace std;

int main() {
	//Vars
	int value, sum = 0;

	//Get Input
	cout << "Please enter a positive integer value: ";
	cin >> value; 

	//Check input and Calculate Sum
	if(value > 0) {
		for(int i = value; i > 0; i--) {
			sum += i;
		}
	}
	else {
		cout << "You did not enter a postive integer value. Please run again." << endl;
	}

	//Output Value
	cout << "\nThe sum of all intergers from 1 up to " << value << " is " << sum << endl;

	//Exit Program
	system("PAUSE");
	return 0;
}
