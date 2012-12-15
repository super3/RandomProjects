// Author: Shawn Wilkinson
// Includes and Namespaces
#include <iostream>
using namespace std;

// Function Prototypes
void printArr( int [] );
void sortArr( int [], int, int );

// Declare Constants
int const SORTSIZE = 10;

// Main Function
int main() {
	// Declare Vars
	int sortMe[SORTSIZE] = { 37, 2, 6, 4, 89, 8, 10, 12, 68, 45 };

	// Print Before and After
	printArr(sortMe);
	sortArr(sortMe, 0, 9);
	cout << endl; // Newline
	printArr(sortMe);
	cout << endl; // Newline

	// Exit Program
	system("PAUSE");
	return 0;
}

// Functions
void printArr(int arr[]) {
	for( int i = 0; i < SORTSIZE; i++) {
		cout << arr[i] << " ";
	}
}

void sortArr(int arr[], int start, int end) {
	// Declare Vars
	int swap;
	int pivot = arr[(start + end) / 2];
	int posLeft = start, posRight = end;

	// Partition Step
	while ( posLeft <= posRight )
	{
		// Go through values
		while ( arr[posLeft] < pivot ) {
			++posLeft;
		}
		while ( arr[posRight] > pivot ) {
			--posRight;
		}

		if ( posLeft <= posRight ) {
			// Swap Value
			swap = arr[posLeft];
			arr[posLeft] = arr[posRight];
			arr[posRight] = swap;

			// Go forward a step
			++posLeft;
			--posRight;
		}
	}

	// Recursion Step
	if ( start < posRight )
		sortArr(arr, start, posRight); // Sub-array
	if ( posRight < end )
		sortArr(arr, posLeft, end); // Sub-array
}