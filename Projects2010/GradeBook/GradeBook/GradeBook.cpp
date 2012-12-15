// Author: Shawn Wilkinson

// Fig. 3.12: GradeBook.cpp
// GradeBook member-functions definitions. The file contains
// implementations of the member functions prototyped in GradeBook.h
#include <iostream>
#include "GradeBook.h" // include definitions of class GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument
GradeBook::GradeBook( string name, string instructor )
{
	setCourseName( name ); // call set function to initialize courseName
	setInstructorName( instructor ); // call set function to initialize instructorName
	// end GradeBook constructors 
}

// function to set the course name
void GradeBook::setCourseName( string name )
{
	courseName = name; //store the course name in the object
} //end function setCouseName

// function to get the course name
string GradeBook::getCourseName()
{
	return courseName; // return object's courseName
} // end function getCourseName

// function to set the instructor's name
void GradeBook::setInstructorName( string name )
{
	instructorName = name; 
}

// function to get the instructor's name
string GradeBook::getInstructorName()
{
	return instructorName;
}

// display a welcome message to the GradeBook user
void GradeBook::displayMessage()
{
	// call getCouseName to get the courseName
	cout << "Welcome to the gradebook for \n" << getCourseName() 
		<< "!" << endl;
} // end function displayMessage