// Author: Shawn Wilkinson
// Title: Distance Traveled
// Description: Ask the user for the speed of a vehicle, and how many hours it travled. 
// Return the distance that the vehicle traveled. 

//Includes
#include <iostream>
using namespace std;

int main() {
	//Vars
	float speed, time, distance; 

	//Get Input
	cout << "What is the speed of the vehicle in mph? ";
	cin >> speed;
	cout << "How many hours has it traveled? ";
	cin >> time;

	//Check Input
	if(speed > 0 && time >= 1) {
		//Calculate and Print
		cout << "Hour\t\tDistance Travled" << endl;
		cout << "--------------------------------------------------" << endl;
		for(int i=1; i <= time; i++) {
			cout << i << "\t\t" << i*speed << endl;
		}
	}
	else {
		cout << "Invalid input." << endl;
	}

	//Exit Program
	system("PAUSE");
	return 0;
}