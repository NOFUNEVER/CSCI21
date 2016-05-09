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

  void Insert(int value);//allows you to to insert node 
  bool RemoveFirstOccurence(int value); //self explanitory
  int GetHead() const;
  int GetTail() const;
  void Clear();
  unsigned int size() const;
  string ToString() const;

 private:
  SLNode* head_;
  SLNode* tail_;
  unsigned int size_;
  void InsertHead(int contents);
  void InsertTail(int contents);
  void RemoveHead();
  void RemoveTail();
};
#endif /* SL_LIST_H */

