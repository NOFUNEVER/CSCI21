/*
 * Name        : Lab_24
 * Author      : Jason K Lamphere
 * 
 * Sources     :ide.c9.io/nofunever/csci21   github.com/nofunever/csci21
 */

#include "bs_tree.h"

bool BSTree::Insert(int value) {  //calls insert command and uses default root
  return Insert(value, root_);
}

void BSTree::Clear() { // clears tree
  Clear(root_);
}

unsigned int BSTree::size() const { //returns size of tree
  return size_;
}

string BSTree::InOrder() {       //returns in order
  return InOrder(root_);
}

bool BSTree::Insert(int value, BSTNode*& root) {  //allows us to insert a node into our tree
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

void BSTree::Clear(BSTNode*& root) { //clears the specified root
  if (root != NULL) {
  Clear(root->left_child());
  Clear(root->right_child());
  delete root;
  root = NULL;
  size_--;
  }
}

string BSTree::InOrder(BSTNode* root) {  //outputs tree in order
stringstream ss;
  if (root != NULL) {
    ss << InOrder(root->left_child());
    ss << root->contents() << " ";
    ss << InOrder(root->right_child());
  }
  return ss.str();
}























