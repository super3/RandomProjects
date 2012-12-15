// Author: Shawn Wilkinson
// File: main.cpp

#include <iostream>
#include "Account.h"
using namespace std;

int main() {
	//Create two account objects
	Account account1(500);
	Account account2(-50);

	//New Line
	cout << endl;

	//Credit and Debit Account 1
	cout << "Account1: " << account1.getBalance() << endl;
	account1.credit(50); // Add $50
	cout << "Account1: " << account1.getBalance() << endl;
	account1.debit(100); // Remove $100
	cout << "Account1: " << account1.getBalance() << endl;

	//New Line
	cout << endl;

	//Credit and Debit Account 1
	cout << "Account1: " << account2.getBalance() << endl;
	account2.debit(50); // Remove $50
	cout << "Account1: " << account2.getBalance() << endl;
	account2.credit(100); // Add $100
	cout << "Account1: " << account2.getBalance() << endl;

	// Pause for Debug
	system("PAUSE");
}