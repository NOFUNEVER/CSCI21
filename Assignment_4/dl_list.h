/*
 * Name        : dl_list header
 * Author      : Jason K Lamphere
 * Description : This is the header file for our linked list file.
 * This will include our dl_node files.
 * Sources ide.c9.io/nofunever/csci21,  github.com/NOFUNEVER/CSCI21
 */

#ifndef DL_LIST_H
#define DL_LIST_H

// Add any includes and using statements Here
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "dl_node.h"

using namespace std;

class DLList {
  public:
    DLList(unsigned int size = 0)
  : head_(NULL),
     tail_(NULL),
    size_(size)
  {}

~DLList() {
  Clear();
}

int GetSize() const;

void PushFront(string newContents);

void PushBack(string newContents);

void insert(string newContents);

string GetFront() const;

string GetBack() const;

void PopFront();

void PopBack();

void RemoveFirst(string target);

void RemoveAll(string target);

bool get(string target);

void Clear();

string Traverse(int x);


friend ostream& operator<< (ostream& out, const DLList& src);


  
  private:
  DLNode* head_;
  DLNode* tail_;
    unsigned int size_;
};


#endif /* DL_LIST_H */






