// DateTest.cpp
// Author: Shawn Wilkinson (super3.org)

#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

int main()
{
	Date date1(8, 31, 2011);
	date1.displayDate();
	Date date2(23, 4, 1975);
	date2.displayDate();

	system("PAUSE");
}