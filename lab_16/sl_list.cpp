/*
 * Name        : lab_16.cpp
 * Author      : Jason Lamphere
 * Description : practice creating nodes for use with linked lists later on.
 *               
 */

#include "sl_list.h"
void SLList::InsertHead(int contents) {
  SLNode* new_node = new SLNode(contents);
  new_node->set_next_node(head_);
  head_ = new_node;
  size_++;
}

void SLList::RemoveHead() {
  if (size_ != 0) {
    SLNode *temp = head_;
    head_ = temp->next_node();
    delete temp;
    size_--;
  }
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






