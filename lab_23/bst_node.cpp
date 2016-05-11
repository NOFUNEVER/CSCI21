/*
 * Name        : Lab_23
 * Author      : Jason
 * 
 * Sources     :
 */

#include "bst_node.h"

void BSTNode::set_contents(int contents) {
  contents_ = contents;
}

int BSTNode::contents() const {
  return contents_;
}

int& BSTNode::contents() {
  return contents_;
}

void BSTNode::set_left_child(BSTNode* SetLeft) {
  left_child_ = SetLeft;
}

void BSTNode::set_right_child(BSTNode* SetRight) {
  right_child_ = SetRight;
}

BSTNode* BSTNode::left_child() const {
  return left_child_;
}

BSTNode*& BSTNode::left_child() {
  return left_child_;
}

BSTNode* BSTNode::right_child() const {
  return right_child_;
}

BSTNode*& BSTNode::right_child() {
  return right_child_;
}





















