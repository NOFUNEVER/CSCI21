/*
 * Name        : bst_nodet header file
 * Author      : Jason K Lamphere
 * Description : the header file where we will declare our nodes
 * for our tree
 * Sources     : 
 */

#ifndef BST_TREET_H
#define BST_TREET_H

// Add any includes and using statements Here
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>


template <class T>
class BSTreeT {
  public:
  BSTreeT() : root(NULL),size_(0) {}

~BSTreeT() {
  Clear();
};

T GetSize() const {
  return size_;
};



T BSTNodeT<T>::Insert(T value) {
  if (root == NULL) {
    root = new BSTNodeT(value);
    size_++;
  return true;
  } else if (value < root->GetContents()) {
    return Insert(value, root->GetLeft());
  } else if (value > root->GetContents()) {
    return Insert(value, root->GetRight());
  } else if (value == root->GetContents()) {
    size_++;
  }
    return size_;
};

bool BSTNodeT<T>::Exists(T value) {
  if (value == root->GetContents()) {
	return true;
  }
  if (root != NULL) {
      Exists(root->GetLeft());
      root->GetContents();
      Exists(root->GetRight());
  }
  return false;
};

T BSTNodeT<T>::Remove(T value) {
  if (value == root->GetContents()) {
	if (root->GetCount() == 1) {
      delete root;
	  root = NULL;
	  return 0;
	} else {
	  size_--;
	  return -1;
	}
  }
  if (root != NULL) {
      Remove(root->GetLeft());
      root->GetContents();
      Remove(root->GetRight());
  }
  return -1;
};

BSTNodeT* BSTNodeT<T>::Get(T value) {
  if (value == root->GetContents()) {
    return root;
  }
    Get(root->GetLeft());
    root->GetContents();
    Get(root->GetRight());
};

void Clear(BSTNodeT*& root) {
  if (root != NULL) {
  Clear(root->GetLeft());
  Clear(root->GetRight());
  delete root;
  root = NULL;
  size_--;
  }
};

string BSTNodeT<T>::ToStringForwards() {
stringstream ss;
  if (root != NULL) {
    ss << ToStringForwards(root->GetLeftChild());
    ss << root->GetContents() << ", ";
    ss << ToStringForwards(root->GetRightChild());
  }
  return ss.str();
};

string BSTNodeT<T>::ToStringBackwards() {
stringstream ss;
  if (root != NULL) {
    ss << ToStringBackwards(root->GetRightChild());
    ss << root->GetContents() << ", ";
    ss << ToStringBackwards(root->GetLeftChild());
  }
  return ss.str();
};

  private:

T BSTNodeT<T>::Clear() {
  Clear(root);
};

T BSTNodeT<T>::Insert() {
  return Insert();
};

    BSTreeT* root;
	unsigned int size_;
};


#endif /* BST_TREET_H */













