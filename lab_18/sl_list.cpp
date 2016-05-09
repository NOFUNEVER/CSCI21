/*
 * Name        : lab_18.cpp
 * Author      : Jason
 * Description : practice creating linked lists.
 *               
 */

#include "sl_list.h"
void SLList::InsertHead(int contents) {  // creates head
  SLNode* new_node = new SLNode(contents);
  if (head_ == NULL) {
    tail_ = new_node;
  }
  new_node->set_next_node(head_);
  head_ = new_node;
  size_++;
}

void SLList::InsertTail(int contents) { //creates tail
  if (head_ == NULL) {
    InsertHead(contents);
  } else {
    SLNode* new_node = new SLNode(contents);
    tail_->set_next_node(new_node);
    tail_ = new_node;
    size_++;
  }
}
  
void SLList::RemoveHead() { //removes head makes next node head
  if (size_ != 0) {
    SLNode *temp = head_;
    head_ = temp->next_node();
    delete temp;
    size_--;
  }
  if (head_ == NULL) {
    tail_ = NULL;
  }
}

void SLList::RemoveTail() { //removes tail
  if (size_ > 1) {
    SLNode *temp = head_;
  while (temp->next_node() != tail_) {
    temp = temp->next_node();
  }
  temp->set_next_node(NULL);
  delete tail_;
  tail_ = temp;
  size_--;
  } else if (size_ == 1) {
    RemoveHead();
  } else {
    tail_ = NULL;
  }
}

int SLList::GetHead() const {//returns head value
if (head_ == NULL) {
  return 0;
}
  return head_->contents();
}

int SLList::GetTail() const { //returns tail value
if (tail_ == NULL) {
  return 0;
}
  return tail_->contents();
}

void SLList::Clear() {
 while(head_) //calls the remove head function and cycles until there is now more contents
  {
    RemoveHead();
	 }
	 !tail_; //sets tail to NULL
}

unsigned int SLList::size() const {
  return size_;
}

string SLList::ToString() const {
stringstream ss;
  if (size_ != 0) {
    SLNode *it = head_;
  while (it != NULL) {
    ss << it->contents();
  if (it->next_node() != NULL)
    ss << ", ";
    it = it->next_node();
  }
  return ss.str();
  }
  return "";
}

void SLList::Insert(int value) {
  SLNode* new_node = new SLNode(value);
  if (head_ == NULL || head_->contents() >= value) {
    InsertHead(value);
  } else if (tail_->contents() < value) {
    InsertTail(value);
  } else {
    SLNode *it = head_, *trailer = head_;
  while (it->contents() < value) {
    trailer = it;
    it = it->next_node();
  }
      trailer->set_next_node(new_node);
    new_node->set_next_node(it);
    size_++;
  }
}

bool SLList::RemoveFirstOccurence(int value) {
  if (head_ == NULL) {
    return false;
  }
  SLNode *it = head_, *trailer = head_;
  while (it != NULL && it->contents() != value) {
    trailer = it;
  it = it->next_node();
  }
    if (it == NULL) {
    return false;
  } else if (it == head_) {
    RemoveHead();
    return true;
  } else if (it == tail_) {
    RemoveTail();
    return true;
  } else {
    trailer->set_next_node(it->next_node());
    size_--;
    delete it;
    return true;
  }
}












