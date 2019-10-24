#include <string>
#include "studentRoll.h"
using namespace std;
#include <iostream>
#include <cstring>
#include <sstream>

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node *n = new Node;
  if(!tail||!head){
    tail = head = n;
  }
  else{tail->next = n;}
  
  n->s = new Student(s.getName(), s.getPerm());

  n->next = NULL;
  tail = n;

}


std::string StudentRoll::toString() const {
  if(head == NULL || tail == NULL){
    return "[]";
  }
  Node* i = head;
  ostringstream oss;

  oss<<"[";
  while (i!=NULL){
      oss<<"["<<i->s->getName()<<","<<i->s->getPerm()<<"]";
    if(i->next != NULL){
      oss<<",";
    }
    i = i->next;
  }
  oss<<"]";
  return oss.str();
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  if(this->head){
      //delete this;
  }
  if(!orig.head){
    return;
  }
  Node* iter = head;
    for (Node*i = orig.head; i != NULL; i = i->next){
    iter = new Node;
    iter->s = new Student(i->s->getName(), i->s->getPerm());
    tail = iter;
    iter = iter->next;
  }
}

StudentRoll::~StudentRoll() {
  Node* cur = head;
  while(cur!=NULL){
    Node*nexte = cur->next;
    delete cur;
    cur = nexte;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this)
    return (*this);

  // TODO... Here is where there is code missing that you need to
  // fill in...
  if(this->head){
    delete this;
  }
  
  Node* iter = this->head;
  Node*i = right.head;
  while(i != NULL){
    iter = new Node;
    iter->s = new Student(i->s->getName(), i->s->getPerm());
    tail = iter;
    iter = iter->next;
    i = i->next;
  }
  iter = NULL;

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this);

}





