/*
 * Name        : bst_nodet header file
 * Author      : Jason K Lamphere
 * Description : the header file where we will declare our nodes
 * for our tree
 * Sources     : 
 */

#ifndef BST_NODET_H
#define BST_NODET_H

// Add any includes and using statements Here
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "bs_treet.h"

using namespace std;

template <class T> 
class BSTNodeT {
  public:
  BSTNodeT()
    : contents_(T()), right_child_(NULL), left_child_(NULL),
	   count_(0)
  {}

  BSTNodeT(T contents)
    : contents_(contents), right_child_(NULL), left_child_(NULL),
       count_(0)
  {}
  
~BSTNodeT() {
	right_child_ = NULL;
	left_child_ = NULL;
}
    
void SetContents(T contents) {
    contents_ = contents;
};

void SetLeft(BSTNodeT* left_child) {
  left_child_ = left_child;
};
    
void SetRight(BSTNodeT* right_child) {
  right_child_ = right_child;
};
    
void IncrementCount() {
  count_++;
};
    
void DecrementCount() {
  count_--;
};
    
T GetContents() const {
  return contents_;
};
    
BSTNodeT*& GetLeft() {
  return left_child_;
};
    
BSTNodeT*& GetRight() {
  return right_child_;
};
    
unsigned int GetCount() {
  return count_;
};
  
  private:
    T contents_;
    unsigned int count_;
	BSTNodeT* right_child_;
    BSTNodeT* left_child_;
};


#endif /* BST_NODET_H */














