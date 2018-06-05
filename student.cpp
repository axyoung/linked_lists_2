#include "student.h"

// constructor
// the student has an ID that is unique to itself
// this can be extended to be a name, gpa, etc.
Student::Student(char* first, char* last, int id, float gpa) {
	studentID = id;
	studentFirst = first;
	studentLast = last;
	studentGPA = gpa;
}

Student::~Student() {
	delete studentFirst;
	delete studentLast;
}

// get the student's ID with this command
int Student::getStudentID() {
	return studentID;
}

char* Student::getStudentFirst() {
	return studentFirst;
}

char* Student::getStudentLast() {
	return studentLast;
}

float Student::getStudentGPA() {
	return studentGPA;
}



