// Author: Shawn Wilkinson
// Includes and Namespaces
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Function Prototypes
void printVector(const vector<int> &array);

//Main Function
int main() {
	// Vector and Vars
	vector< int > totalsales( 9 );
	int sale, total;

	// Loop
	while(1) {
		//Reset Total
		total = 0;

		// Get Input 
		cout << "Please enter sales (Enter -1 to exit): ";
		cin >> sale;

		// Sentinel 
		if (sale == -1) 
			break;

		// Add Baseline $200
		total += 200;
		// Add Sales Percentage
		total += (int)(sale * (double)0.09);

		// Add Tally 
		if( total <= 299 )
			totalsales[0] += 1;
		else if( total <= 399 )
			totalsales[1] += 1;
		else if( total <= 499 )
			totalsales[2] += 1;
		else if( total <= 599 )
			totalsales[3] += 1;
		else if( total <= 699 )
			totalsales[4] += 1;
		else if( total <= 799 )
			totalsales[5] += 1;
		else if( total <= 899 )
			totalsales[6] += 1;
		else if( total <= 999 )
			totalsales[7] += 1;
		else if( total >= 1000 )
			totalsales[8] += 1;
	}

	// Print Array
	printVector(totalsales);

	// Exit Program
	system("PAUSE");
	return 0; 
}

void printVector(const vector<int> &array) {
	cout << setw(20) << "Salary Range" << "|" << setw(20) << "Salespeople" << endl;
	cout << "------------------------------------------------------" << endl;
	for( int i = 0; i < array.size(); i++) {
		cout << "$" << (100*i+200) << "-" << ((100*i+300)-1) << " | " << setw(15) << array[i] << endl;
	}
}