// Author: Shawn Wilkinson
// File: Bank.h

#include <string>
using namespace std;

class Account
{
	public:
		Account(int);
		void credit(int);
		void debit(int);
		void setBalance(int);
		int getBalance();
	private:
		int balance;
};