#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  tail->s = s;
  tail->next = NULL;
  tail = tail->nest;
}

std::string StudentRoll::toString() const {
  for(Node* i = head; i != NULL; i = i->next){
    i->s.toString();
    if(i->next != NULL){
      sdt::cout<<",";
    }
  }
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  Node* iter = this->head;
  iter->head = orig->head;
  for (Node*i = orig.head; i != NULL; i = i->next){
    iter->next = i->next;
    iter = iter->next;
  }
  tail = NULL;
}

StudentRoll::~StudentRoll() {
  Node* cur = head;
  while(cur!=NULL)(
    Node*next = cur->next;
    delete cur;
    cur = next;
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
  delete this;
  Node* iter = this->head;
  Node*i = right->head;
  while(i != NULL){
    iter->s = i->s;
    iter = iter->next;
    i = i->next;
  }
  iter->next = NULL;

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





