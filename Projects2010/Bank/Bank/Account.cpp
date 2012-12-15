// Author: Shawn Wilkinson
// File: Bank.cpp

#include <iostream>
#include "Account.h"
using namespace std;

// Bank Construtor
Account::Account(int initialBalance)
{
	// Check if initial balance is greater than or
	// equal to zero, if not set balance to 0, and
	// display an error.
	if (initialBalance >= 0) 
		setBalance( initialBalance );
	else {
		setBalance(0);
		cout << "Initial Balance Invalid." << endl;
	}
}

// function to add funds to the account
void Account::credit(int amount)
{
	balance += amount; 
}

// function to remove funds from the account
void Account::debit(int amount)
{
	if(amount <= balance)
		balance -= amount;
	else {
		cout << "Debit amount exceeded acount "
			<< "balance" << endl;
	}
}

// function to return account balance
int Account::getBalance() 
{
	return balance;
}

// function to set account balance
void Account::setBalance(int amount)
{
	balance = amount;
}