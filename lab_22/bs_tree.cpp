/*
 * Name        : Lab_24
 * Author      : Jason K Lamphere
 * 
 * Sources     :ide.c9.io/nofunever/csci21   github.com/nofunever/csci21
 */

#include "bs_tree.h"

bool BSTree::Insert(int value) {
  return Insert(value, root_);
}

void BSTree::Clear() {
  Clear(root_);
}

unsigned int BSTree::size() const {
  return size_;
}

string BSTree::InOrder() {
  return InOrder(root_);
}

bool BSTree::Insert(int value, BSTNode*& root) {
  if (root == NULL) {
    root = new BSTNode(value);
  size_++;
  return true;
  } else if (value < root->contents()) {
    return Insert(value, root->left_child());
  } else if (value > root->contents()) {
    return Insert(value, root->right_child());
  }
    return false;
}

void BSTree::Clear(BSTNode*& root) {
  if (root != NULL) {
  Clear(root->left_child());
  Clear(root->right_child());
  delete root;
  root = NULL;
  size_--;
  }
}

string BSTree::InOrder(BSTNode* root) {
stringstream ss;
  if (root != NULL) {
    ss << InOrder(root->left_child());
    ss << root->contents() << " ";
    ss << InOrder(root->right_child());
  }
  return ss.str();
}























