/*
 * Name        : Assignment_4
 * Author      : Jason
 * Description : the main file for our linked list which will include
 * our dl_list header file.
 * Sources     :
 */

 
#include "dl_list.h"

using namespace std;

int DLList::GetSize() const {
 return size_;
}

void DLList::PushFront(string add_to) {
  DLNode* new_node = new DLNode(add_to);
  if (head_ == NULL) {
    tail_ = new_node;  
  }
  new_node->SetNext(head_);
  if (head_ != NULL)
  head_->SetPrevious(new_node);
  head_ = new_node;
  size_++;
}

void DLList::PushBack(string add_to) {
  if (head_ == NULL) {
    PushFront(add_to);  
  } else {
    DLNode* new_node = new DLNode(add_to);
    tail_->SetNext(new_node);
    new_node->SetPrevious(tail_);
    tail_ = new_node;
    size_++;
  }
}

void DLList::insert(string newContents)
{
            //: create new DLNode with newContents and insert in ascending (based on newContents) order
  DLNode* insert = new DLNode(newContents); //assigns data to new node 
  DLNode* current = head_; //assigns head to current
  DLNode* prev = current;
  if(!head_ || newContents <= current->GetContents()) //if there is a list or data is less than or equal to head_                                                          
  {
    PushFront(newContents); 
  }
  else if(newContents > tail_->GetContents()) //if data is greater than tail
  {
    PushBack(newContents);
  }
  else
  {
  while(current->GetContents()  < newContents) //while current is less than data
  {
    prev = current; //we assign prev to currents position
    current = current->GetNext(); //then assign current to next position
  }
  insert->SetNext(current); //set node at currents position
  prev->SetNext(insert); //set data at proper position
  size_++;
  }
}





string DLList::GetFront() const { 
if (head_ == NULL) {
  cerr << "List Empty";
  return "";
  } else {
  return head_->GetContents();
  }
}

string DLList::GetBack() const { 
if (tail_ == NULL) {
  cerr << "List Empty";
  return "";
  } else {
  return tail_->GetContents();
  }
}

void DLList::PopFront() {
  if (size_ == 0) {
    cerr << "List Empty";
  } else {
    DLNode *temp = head_;
  head_ = temp->GetNext();
  delete temp;
  size_--;
    if (head_ == NULL) {
    tail_ = NULL;  
    }
  }
}

void DLList::PopBack() { 
  if (size_ == 0) {
    cerr << "List Empty";
  } else if (size_ == 1) {
  PopFront();  
  } else {
    DLNode* temp = head_;
  while (temp->GetNext() != tail_) {
      temp = temp->GetNext();
  }
  temp->SetNext(NULL);
  delete tail_;
  tail_ = temp;
  size_--;
  }
}

void DLList::RemoveFirst(string find) {
  if (size_ == 0) {
  cerr << "Not Found";
  } else {
    DLNode* it = head_, *trailer = head_;
  while (it != NULL && it->GetContents() != find) {
      trailer = it;
    it = it->GetNext();
  }
  if (it == NULL) {
      cerr << "Not Found";
  } else if (it == head_) {
      PopFront();
  } else if (it == tail_) {
      PopBack();
  } else {
      trailer->SetNext(it->GetNext());
    it->GetNext()->SetPrevious(trailer);
    size_--;
    delete it;
  }
  }
}

void DLList::RemoveAll(string find) {
  if (size_ == 0) {
  cerr << "Not Found";
  } else {
  for (unsigned int i = 0; i < size_; i++) {
    DLNode* it = head_, *trailer = head_;
  while (it != NULL && it->GetContents() != find) {
      trailer = it;
    it = it->GetNext();
  }
  if (it == NULL) {
      cerr << "Not Found";
  } else if (it == head_) {
      PopFront();
  } else if (it == tail_) {
      PopBack();
  } else {
      if (it->GetContents() != find) {
	  cerr << "Not Found";
      break;	  
	}
    trailer->SetNext(it->GetNext());
    it->GetNext()->SetPrevious(trailer);
    size_--;
    delete it;
  }
  }
  }
}




bool DLList::get(string target) {
  if (size_ == 0) {
    return false;
  }
    DLNode* it = head_;
  while (it != NULL && it->GetContents() != target) {
    it = it->GetNext();
  }
  if (it == NULL || it->GetContents() != target) {
    return false;
  }
  return true;
}

void DLList::Clear() {
  while (head_ != NULL) {
    DLNode *temp = head_;
    head_ = head_->GetNext();
    delete temp;
  }
  size_ = 0;
}



string DLList::Traverse(int x){
  DLNode* it = head_;
  int count = 0;
  while(x>count){
      
            it = it->GetNext();
            count++;
            
  }     
    return it->GetContents();          
      
          
  
}





ostream& operator<<(ostream& out, const DLList& src)
	{
	DLNode* it = src.head_;
	
	if (it == NULL)
		return out << "EMPTY";
	else
		{
		while (it != NULL)
			{
			  
			out << it->GetContents() << endl;
			it = it->GetNext();
		
			
	
			}
		return out;
		}
	}





