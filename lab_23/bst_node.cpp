/*
 * Name        : Lab_23
 * Author      : Jason Lamphere
 * Description :Creating a node class for use in a binary  search tree. The nodes for a tree are a little different than those of a linked list. * 
 * Sources     : ide.c9.io/nofunever/csci21   github.com/nofunever/csci21
 */

#include "bst_node.h"




void BSTNode::set_contents(int contents) { // sets node contents
  contents_ = contents;
}

int BSTNode::contents() const {      //gets node contents not allowing it to be changed
  return contents_;
}

int& BSTNode::contents() {        //gets address of contets
  return contents_;
}

void BSTNode::set_left_child(BSTNode* SetLeft) { //sets child contents
  left_child_ = SetLeft;
}

void BSTNode::set_right_child(BSTNode* SetRight) {
  right_child_ = SetRight;
}

BSTNode* BSTNode::left_child() const {  //get left child
  return left_child_;
}

BSTNode*& BSTNode::left_child() {  //get left child 
  return left_child_;
}

BSTNode* BSTNode::right_child() const { //get right child
  return right_child_;
}

BSTNode*& BSTNode::right_child() { //get right child
  return right_child_;
}



 











