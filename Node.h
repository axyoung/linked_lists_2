#include "student.h"

class Node {
 public:
  Node(Student newStudent);
  ~Node();
  Node* getNext();
  Student* getStudent();
  void setNext(Node*);
  Node(Student*);
  
 private:
  Student* student;
  Node* nextNode;
};
