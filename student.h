#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

// this is a header file for the student class

using namespace std;

class Student {
	// the student class has includes the Student and the function to get the ID
	public:
		Student(char*, char*, int, float);
		int getStudentID();
		char* getStudentFirst();
		char* getStudentLast();
		float getStudentGPA();
		~Student();


	private:
		int studentID;
		float studentGPA;
		char* studentFirst;
		char* studentLast;
};
#endif
