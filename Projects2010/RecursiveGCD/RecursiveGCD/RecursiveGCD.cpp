// 6.41, P.262
// Problem: Recursive Greatest Common Divisor
// Author: Shawn Wilkinson 

#include <iostream>
using namespace std; 

/* Function prototype for GCD */
int gcd(int, int);

int main()
{
   int a; // first number
   int b; // second number

   // loop for 5 pairs of inputs
   for ( int j = 1; j <= 5; j++ ) 
   {
      cout << "Enter two integers: ";
      cin >> a >> b;

      cout << "The greatest common divisor of " 
         << a << " and " << b << " is ";

      // find greatest common divisor of a and b
      cout <<  gcd(a, b) << endl;
   } // end for

   //end program
   return 0;
} // end main

// Recursive Greatest Common Divisor. For this algorithm 
// to work x must be larger than y.
int gcd(int x, int y) {
	if (y == 0) 
		return x;
	else
		gcd(y, x% y);
}