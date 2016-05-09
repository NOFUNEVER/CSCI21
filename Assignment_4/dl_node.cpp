/*
 * Name        : Assignment_4
 * Author      : Jason
 * Description : this file is the main file for the nodes in our
 * fourth assignment. This file will create the nodes for our linked
 * list.
 * Sources     :
 */
 
#include "dl_node.h"

void DLNode::SetContents(string newContents) {
  contents_ = newContents;
}

void DLNode::SetNext(DLNode* newNext) {
  next_node_ = newNext;
}

void DLNode::SetPrevious(DLNode* newPrevious) {
  previous_node_ = newPrevious;
}

string DLNode::GetContents() const {
  return contents_;
}

DLNode* DLNode::GetNext() const {
  return next_node_;
}

DLNode* DLNode::GetPrevious() const {
  return previous_node_;
}





