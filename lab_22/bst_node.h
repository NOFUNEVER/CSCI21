/*
 * Name        : BST_NODE header
 * Author      : Jason Lamphere
 * Description : creating a BST Node for a tree.
 * Sources     : ide.c9.io/nofunever/csci21  github.com/nofunever/csci21
 */

#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>


class BSTNode {
 public:
  BSTNode(int contents = 0)
  : right_child_(NULL), left_child_(NULL),
    contents_(contents)
  {}

  ~BSTNode() {
    right_child_ = NULL;
    left_child_ = NULL;
}

void set_contents(int contents);

int contents() const;
int& contents();

void set_left_child(BSTNode* SetLeft);
void set_right_child(BSTNode* SetRight);

BSTNode* left_child() const;
BSTNode*& left_child();

BSTNode* right_child() const;
BSTNode*& right_child();

 private:
  BSTNode* right_child_;
  BSTNode* left_child_;
  int contents_;
};


#endif /* BST_NODE_H */










