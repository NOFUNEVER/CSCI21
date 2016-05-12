/*
 * Name        : BS_TREE 
 * Author      : Jason K Lamphere
 * Description : creating a BST Node for a tree.
 * Sources     : ide.c9.io/nofunever/csci21   github.com/nofunever/csci21
 */

#include "bs_tree.h"

bool BSTree::Insert(int value) { //insert function for a tree
  return Insert(value, root_);
}

bool BSTree::Remove(int value) { //remove function for our tree
  return Remove(value, root_);
}

int BSTree::FindMin() {       //finds the min value 
  if (root_ == NULL) {
    return 0;
  }
  return FindMin(root_);
}

void BSTree::Clear() {   //clears node
  Clear(root_);
}

unsigned int BSTree::size() const {   //gets size without allowing it to change
  return size_;
}

string BSTree::InOrder() {  //lists tree nodes in order
  return InOrder(root_);
}

bool BSTree::Insert(int value, BSTNode*& root) {  //our actual insert function
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

bool BSTree::Remove(int value, BSTNode*& root) {  //our actual remove function
if (root == NULL) {
  return false;
} else if (root->contents() == value) {
    if (root->left_child() == NULL && root->right_child() == NULL) {
      delete root;
      root = NULL;
      size_--;
    } else if (root->left_child() != NULL && root->right_child() != NULL) {
        int temp = FindMin(root->right_child());
        root->set_contents(temp);
        Remove(temp, root->right_child());
    } else {
        BSTNode* temp = root;
      if (root->left_child() != NULL) {
        root = root->left_child();
        delete temp;
      } else if (root->right_child() != NULL) {
        root = root->right_child();
        delete temp;
      }
      size_--;
    }
    return true;
} else if (value > root->contents()) {
  return Remove(value, root->right_child());
} else {
  return Remove(value, root->left_child());
}
}

int BSTree::FindMin(BSTNode* root) const {  //find min wihtout modifying
  if (root->left_child() != NULL) {
    return FindMin(root->left_child());
  }
  return root->contents();
}

void BSTree::Clear(BSTNode*& root) {  //full clear function
  if (root != NULL) {
    Clear(root->left_child());
    Clear(root->right_child());
    delete root;
    root = NULL;
    size_--;
  }
}

string BSTree::InOrder(BSTNode* root) {  //lists tree inorder from root
stringstream ss;
  if (root != NULL) {
    ss << InOrder(root->left_child());
    ss << root->contents() << " ";
    ss << InOrder(root->right_child());
  }
  return ss.str();
}























