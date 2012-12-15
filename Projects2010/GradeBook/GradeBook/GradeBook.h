// Fig. 3.11: GradeBook.h
// GradeBook class definition. This file presents GradeBook's public
// interface without revealing the impementation of GradeBook's member
// functions, which are defined in GradeBook.cpp
#include <string> //class Gradebook uses C++ standard string class
using namespace std;
// Author: Shawn Wilkinson

// GradeBook class definition
class GradeBook
{
	public:
		GradeBook(string, string); //constructor that initialized courseName
		void setCourseName(string); // function that sets the course name
		string getCourseName(); // function that gets the course name
		void setInstructorName(string); // function that sets the course instructor's name
		string getInstructorName(); // function that gets the instructor's name
		void displayMessage(); // function that displays a welcome message
	private:
		string courseName; // course name for this GradeBook
		string instructorName; // course instructor's name
}; // end class GradeBook