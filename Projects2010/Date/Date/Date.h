// Date.h
// Author: Shawn Wilkinson (super3.org)

class Date {
	public: 
		// Constructor 
		Date(int, int, int);
		// Display the Date
		void displayDate();	
		// Get and Set Functions for Month, Day, and Year
		int getMonth();
		void setMonth(int);
		int getDay();
		void setDay(int);
		int getYear();
		void setYear(int);
	private:
		// Month, Day, and Year Varibles
		int month;
		int day;
		int year;
};