#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	Node* position = head; 
	// create copy of head to track current position and traverse list
	
	if (position == nullptr ){ // list is empty
    smaller = nullptr;
    larger = nullptr;
    return; 
  }
	
	else if ((position -> val) <= pivot){ // if SMALLER
    smaller = position; // assign pos in smaller 
    position = position -> next; // move down in position
    llpivot(position, smaller -> next, larger, pivot); 
    //recursively call again 
  }
	
	else { // if LARGER
    larger = position;  
    position = position -> next;
    llpivot(position, smaller, larger -> next, pivot); 
  }
  head = nullptr;

}
