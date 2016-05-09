/*
 * Name        : SL_LIST header
 * Author      : Jason Lamphere
 * Description : creating a node
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

class SLList {             //constructor
 public:
    SLList(unsigned int size = 0)
  : head_(NULL),
     size_(size)
  {}

  ~SLList() {           // destructor
    Clear();
  }

  void InsertHead(int contents); // checks for head and creates if not present
  void RemoveHead();            // checks for head and removes it
  void Clear();                 // wipes all contents from linked list
  unsigned int size() const;   //returns size
  string ToString() const;   //outputs to a string

 private:
  SLNode* head_; //points to the very first node in linked list
  unsigned int size_; // stores the number of nodes currently in list
};
#endif /* SL_LIST_H */

