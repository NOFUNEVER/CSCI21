/*
 * Name        : Lab_24
 * Author      : Jason
 * 
 * Sources     :
 */

#include "bs_tree.h"

bool BSTree::Insert(int value) {
  return Insert(value, root_);
}

bool BSTree::Remove(int value) {
  return Remove(value, root_);
}

int BSTree::FindMin() {
  if (root_ == NULL) {
    return 0;
  }
  return FindMin(root_);
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

bool BSTree::Remove(int value, BSTNode*& root) {
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

int BSTree::FindMin(BSTNode* root) const {
  if (root->left_child() != NULL) {
    return FindMin(root->left_child());
  }
  return root->contents();
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























