/* 
 * Linked Lists part 2
 * Alex Young
 * C++ Galbraith Period 6
 *
 * This is the second part of a student list program that uses linked lists.
 * Using code from Russell-Chai
 * 
 * Last updated: 1/25/2018
 */

#include <iostream>
#include <cstring>
#include <iomanip> // setPrecision
#include "Node.h"
#include "student.h"

using namespace std;

// function prototypes for the functions that the user will be prompted for
void add(Node* &head);
void addRecursive(Node* current, Node* newNode);
void print(Node* nextNode);
void erase(Node* current, int id);
void average(Node* current);

int main() {
	Node* head = NULL;
	bool cont = true; // program runs until this is false

	while (cont) {
		// user prompted to choose a command
		cout << "Student List, you can (ADD, PRINT, DELETE, AVERAGE, or QUIT)" << endl;
		char entry[10];
		cin.get(entry, sizeof(entry));
		cin.get();
		
		// read in user entry, call respective function

		if (strcmp(entry, "ADD") == 0 || strcmp(entry, "add") == 0) {
			add(head);
			cout << endl;
		}

		if (strcmp(entry, "PRINT") == 0 || strcmp(entry, "print") == 0) {
			cout << endl;
			print(head);
		}

		if (strcmp(entry, "DELETE") == 0 || strcmp(entry, "delete") == 0) {
			// if the user wants to delete something
			// need to read in an id to delete from user
			int id;
			cout << endl << "What Student do you want to delete? (ID)" << endl;
			cin >> id;
			cin.get();
			cout << endl;
			// check the head of the list to see if should delete
			if (head != NULL && head->getStudent()->getStudentID() == id) {
				Node* next = head->getNext();
				delete head;
				head = next;
			}

			else {
				erase(head, id);
			}
		}

		if (strcmp(entry, "AVERAGE") == 0 || strcmp(entry, "average") == 0) {
			average(head);
		}
		
		// quit if done
		if (strcmp(entry, "QUIT") == 0 || strcmp(entry, "quit") == 0) {
			cont = false;
		}

	}
	
	// wooo
	return 0;
}

// add function creates a student, a node, checks the head and calls a recursive adding
void add(Node* &head) {
	
	// create a new student by asking questions
	int id;
	float gpa;
	char* first = new char[20];
	char* last = new char[20];

	cout << endl << "First Name: ";
	cin.get(first, sizeof(first));
	cin.get();
	
	cout << "Last Name: ";
	cin.get(last, sizeof(last));
	cin.get();
	
	cout << "Student ID: ";
	cin >> id;
	cin.get();
	
	cout << "Student GPA: ";
	cin >> gpa;
	cin.get();
	
	Student* student = new Student(first, last, id, gpa);
	Node* node = new Node(student);

	// add if empty, at end, or if less than next
	if (head == NULL) {
		head = node;
		node->setNext(NULL);
	}

	else if (head->getStudent()->getStudentID() > id) {
		node->setNext(head);
		head = node;
	}

	else {
		addRecursive(head, node);
	}

}

// add recursive checks the next student in the list and if id is correct, adds the node
// my father, Jason Young, helped me understand and create the code for this addRecursive
// as well as the erase functions
void addRecursive(Node* current, Node* newNode) {
	// if nothing left, or next one is bigger, can set the new node
	if (current->getNext() == NULL || current->getNext()->getStudent()->getStudentID() >
	    newNode->getStudent()->getStudentID()) {
		
		newNode->setNext(current->getNext());
		current->setNext(newNode);
	}

	// if nothing to do, move onto the next student and check again
	else {
		current = current->getNext();
		addRecursive(current, newNode);
	}

}

// function to print out the nodes
void print(Node* nextNode) {
	// done if nothing left
	if (nextNode == NULL) {
		return;
	}
	
	// otherwise print out the student and their info
	cout << "Student: " << nextNode->getStudent()->getStudentFirst() <<
			" " << nextNode->getStudent()->getStudentLast() << endl;
	cout << "ID: " << nextNode->getStudent()->getStudentID() << endl;
	cout << "GPA: " << fixed << setprecision(2) <<
			nextNode->getStudent()->getStudentGPA() << endl << endl;
	// if their is anything left in the list print it
	if (nextNode->getNext() != NULL) {
		print(nextNode->getNext());
	}
}

// delete function deletes at a certain id
void erase(Node* current, int id) {

	if (current == NULL) {
		return;
	}

	if (current->getNext() == NULL) { // if nothing next we are at end of list
		return;
	}

	if (current->getNext()->getStudent()->getStudentID() > id) { // nothing left to do
	       return;
	}	       

	if (current->getNext()->getStudent()->getStudentID() == id) { // delete next in mid
		Node* next = current->getNext()->getNext();
		delete current->getNext();
		current->setNext(next);
		return;
	}	       

	current = current->getNext();
	erase(current, id);

}

// average function averages all the values
// I did not use recursive for this as it was not specified
void average(Node* current) {
	// create counters for gpa and number of students
	double gpa = 0;
	double count;
	cout << endl;

	// for loop runs through all the students, adding up gpa and counting them
	for (count = 0; current != NULL; count++) {
		gpa = gpa + current->getStudent()->getStudentGPA();
		current = current->getNext();
	}

	// average gpa is total divided by number of students
	if (count != 0) {
		double avg = gpa / count;
		cout << "The average gpa is: " << fixed << setprecision(2) << avg << endl;
	}

	// if their no students say so
	else {
		cout << "There are no students to average." << endl;
	}

	cout << endl;
}

