// Author: Shawn Wilkinson

// Fig. 3.13: fig03_13.cpp
// GradeBook class demonstration after seperating
// its interface from its implematation. 
#include <iostream>
#include "GradeBook.h" //include definition of class GradeBook
using namespace std;

// function main begins program execution
int main()
{
	// create two GradeBook objects
	GradeBook gradeBook1("CS101 Introduction to C++ Programming", "Professor Cook");
	GradeBook gradeBook2("CS102 Data Structures in C++", "Professor Cook");

	// display initial value of the courseName for each GradeBook 
	cout << "gradeBook created for course: " << gradeBook1.getCourseName()
		<< "\nThis course is presented by: " << gradeBook1.getInstructorName() 
		<< "\n\ngradeBook created for course: " << gradeBook1.getCourseName()
		<< "\nThis course is presented by: " << gradeBook2.getInstructorName() 
		<< endl;

	system("PAUSE");
} // end main