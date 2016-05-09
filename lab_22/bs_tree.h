/*
 * Name        : BS_TREE header
 * Author      : Cory Joseph
 * Description : creating a BST Node for a tree.
 * Sources     : 
 */

#ifndef BS_TREE_H
#define BS_TREE_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "bst_node.h"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class BSTree {
 public:
  BSTree(int size = 0)
  : root_(NULL),
    size_(size)
  {}

~BSTree() {
  Clear();
}

bool Insert(int value);

void Clear();

unsigned int size() const;

string InOrder();

 private:
  bool Insert(int value, BSTNode*& root);

  void Clear(BSTNode*& root);

  string InOrder(BSTNode* root);

    BSTNode* root_;
    unsigned int size_;
};

#endif /* BS_TREE_H */























