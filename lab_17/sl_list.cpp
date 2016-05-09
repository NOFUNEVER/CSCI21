/*
 * Name        : lab_18.cpp
 * Author      : Jason Lamphere
 * Description : practice creating linked lists.
 *               
 */

#include "sl_list.h"
void SLList::InsertHead(int contents) {
  SLNode* new_node = new SLNode(contents);
  if (head_ == NULL) {
    tail_ = new_node;
  }
  new_node->set_next_node(head_);
  head_ = new_node;
  size_++;
}

void SLList::InsertTail(int contents) {
  if (head_ == NULL) {
    InsertHead(contents);
  } else {
    SLNode* new_node = new SLNode(contents);
    tail_->set_next_node(new_node);
    tail_ = new_node;
    size_++;
  }
}

void SLList::RemoveHead() {
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

void SLList::RemoveTail() {
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

int SLList::GetHead() const {
if (head_ == NULL) {
  return 0;
}
  return head_->contents();
}

int SLList::GetTail() const {
if (tail_ == NULL) {
  return 0;
}
  return tail_->contents();
}

void SLList::Clear() {
  while (head_ != NULL) {
    SLNode *temp = head_;
    head_ = head_->next_node();
    delete temp;
  }
  size_ = 0;
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






