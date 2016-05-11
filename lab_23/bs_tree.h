/*
 * Name        : BS_TREE header
 * Author      : JASON
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

bool Remove(int value);

int FindMin();

void Clear();

unsigned int size() const;

string InOrder();

 private:
  bool Insert(int value, BSTNode*& root);

  bool Remove(int value, BSTNode*& root);

  int FindMin(BSTNode* root) const;

  void Clear(BSTNode*& root);

  string InOrder(BSTNode* root);

    BSTNode* root_;
    unsigned int size_;
};

#endif /* BS_TREE_H */























