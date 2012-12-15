// Author: Shawn Wilkinson
// Program One: Book Club Points
// Description: Gives the customer a number of points based on how many books they have purchased. 

//Includes
#include <iostream>
using namespace std;

int main() {
	//Vars
	int books, points = 0;

	 //Get Input
	cout << "How many books did you buy this month? ";
	cin >> books;

	//Set Points
	switch(books) {
		case 0:
			points = 0;
			break;
		case 1:
			points = 5;
			break;
		case 2:
			points = 15;
			break;
		case 3:
			points = 30;
			break;
		case 4:
			points = 60;
			break;
		default:
			if(books > 4) {
				points = 60;
			}
			else {
				cout << "Invalid input." << endl;
			}
	}

	cout << "You have earned " << points << " points." << endl;

	//Exit Program
	system("PAUSE");
	return 0;
}