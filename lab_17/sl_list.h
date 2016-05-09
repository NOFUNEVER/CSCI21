/*
 * Name        : SL_LIST header
 * Author      : Jason Lamphere
 * Description : creating a linked list
 * Sources     : 
 */

#ifndef SL_LIST_H
#define SL_LIST_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using std::string;
using std::stringstream;

#include "sl_node.h"

class SLList {
 public:
    SLList(unsigned int size = 0)
  : head_(NULL),
     tail_(NULL),
      size_(size)
  {}

  ~SLList() {
    Clear();
  }

  void InsertHead(int contents); // adds head to list
  void InsertTail(int contents); // adds tail to list
  void RemoveHead(); // removes head
  void RemoveTail();// removes tail
  int GetHead() const; //returns value stored in head
  int GetTail() const;// returns value in tail
  void Clear(); // clears list
  unsigned int size() const;// know size of list
  string ToString() const; // stores for out put

 private:
  SLNode* head_;
  SLNode* tail_;
  unsigned int size_;
};
#endif /* SL_LIST_H */

