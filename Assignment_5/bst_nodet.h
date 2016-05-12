/*
 * Name        : BST_NODE header
 * Author      : Jason K Lamphere
 * Description : creating a BST Node for a tree.
 * Sources     : ide.c9.io/nofunever/csci21    github.com/nofunever/csci21
 */

#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

template <class T>
class BSTNodeT {
 public:
  BSTNodeT(const T &contents = T())
  : right_child_(NULL), left_child_(NULL),
    contents_(contents)
  {}

  ~BSTNodeT() {
    right_child_ = NULL;
    left_child_ = NULL;
}

void SetContents(T contents) { // sets node contents
  contents_ = contents;
}

T GetContents() const {      //gets node contents not allowing it to be changed
 return contents_;
}

T& GetContents() {        //gets address of contets
  return contents_;
}

void SetLeft(BSTNodeT<T>* SetLeft) { //sets child contents
  left_child_ = SetLeft;
}

void SetRight(BSTNodeT<T>* SetRight) {
  right_child_ = SetRight;
}

BSTNodeT<T>* GetLeft() const {  //get left child
return left_child_;
}

BSTNodeT<T>*& GetLeft() {  //get left child 
return left_child_;
}

BSTNodeT<T>* GetRight() const { //get right child
return right_child_;
}

BSTNodeT<T>*& GetRight() { //get right child
  return right_child_;
}

void IncrementCount() {
  count_++;
}
    
void DecrementCount() {
  count_--;
}

 private:
    T contents_;
    unsigned int count_;
	BSTNodeT<T>* right_child_;
    BSTNodeT<T>* left_child_;
};


#endif /* BST_NODE_H */











