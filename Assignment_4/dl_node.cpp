/*
 * Name        : Assignment_4
 * Author      : Jason
 * Description : this file is the main file for the nodes in our
 * fourth assignment. This file will create the nodes for our linked
 * list.
 * Sources     :
 */
 
#include "dl_node.h"

void DLNode::SetContents(string newContents) { // sets contents of node
  contents_ = newContents;
}

void DLNode::SetNext(DLNode* newNext) {//sets the next node
  next_node_ = newNext;
}

void DLNode::SetPrevious(DLNode* newPrevious) {//sets the previous
  previous_node_ = newPrevious;
}

string DLNode::GetContents() const { //returns the contents
  return contents_;
}

DLNode* DLNode::GetNext() const { //gets the next
  return next_node_;
}

DLNode* DLNode::GetPrevious() const {// gets value of the previous
  return previous_node_;
}





