/*
 * Name        : dl_node header
 * Author      : Jason Lamphere
 * Description : the header file where we will declare our nodes
 * for our linked list
 * Sources     : 
 */

#ifndef DL_NODE_H
#define DL_NODE_H

// Add any includes and using statements Here
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;
class DLNode {
  public:
  DLNode() : contents_(""), next_node_(NULL), previous_node_(NULL){}
  DLNode(string newContents) : next_node_(NULL), previous_node_(NULL), contents_(newContents){}
 // DLNode(string newContents) : contents_(newContents), prev_node_(NULL), next_node_(NULL){}


~DLNode() {}
  
void SetContents(string newContents);

void SetNext(DLNode* newNext);

void SetPrevious(DLNode* newPrevious);

string GetContents() const;

DLNode* GetNext() const;

DLNode* GetPrevious() const;
  
  private:
    DLNode* next_node_;
    DLNode* previous_node_;
    string contents_;
};


#endif /* DL_NODE_H */







