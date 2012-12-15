// Date.cpp
// Author: Shawn Wilkinson

#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

// Constructor 
Date::Date(int gMonth, int gDay, int gYear) {
	setMonth(gMonth);
	setDay(gDay);
	setYear(gYear);
}

// Get and Set for Month
int Date::getMonth() {
	return month;
}
void Date::setMonth(int gMonth) {
	if(1 <= gMonth && gMonth <= 12)
		month = gMonth;
	else 
		month = 1;
}

// Get and Set for Day
int Date::getDay() {
	return day;
}
void Date::setDay(int gDay) {
	day = gDay;
}

// Get and Set for Year
int Date::getYear() {
	return year;
}
void Date::setYear(int gYear) {
	year = gYear;
}

// Display the Date
void Date::displayDate() {
	cout << month << "/" << day <<  "/" << year << endl;
}