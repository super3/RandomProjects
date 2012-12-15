// Author: Shawn Wilkinson

#include <iostream>
using namespace std;

int main() {
	//Vars and Get Input
	float floors = 1, totalRoom = 0, totalOcc = 0, totalUn = 0, percent = 0;
	float numRoom[50], numOcc[50];
	cout << "How many floors does your hotel have? ";
	cin >> floors;

	for(int b=0; b < 50; b++) {
		numRoom[b] = 0;
		numOcc[b] = 0;
	}

	//Get rooms
	for(int i=1; i <= floors; i++) {
		cout << "Please enter number of rooms on floor " <<  i << ": ";
		cin >> numRoom[i];
		cout << "Please enter number of rooms occupied on floor " <<  i << ": ";
		cin >> numOcc[i];
	}

	//Add up
	for(int j=0; j < 50; j++) {
		totalRoom += numRoom[j];
		totalOcc += numOcc[j];
	}

	//Get stuff
	percent = (totalOcc / totalRoom) *100;
	totalUn = totalRoom - totalOcc;

	//Output
	cout << "The hotel has " << totalRoom << " rooms." << endl;
	cout << "The hotel has " << totalOcc << " occupied rooms." << endl;
	cout << "The hotel has " << totalUn << " unoccupied rooms." << endl;
	cout << "The hotel is " << percent << "% full." << endl;

	//Exit Program
	system("PAUSE");
	return 0;
}