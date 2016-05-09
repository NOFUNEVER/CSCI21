/*
 * Name        : SL_NODE header
 * Author      : Jason K Lamphere
 * Description : creating a node
 * Sources     : 
 */

#ifndef SL_NODE_H
#define SL_NODE_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

class SLNode {
 public:
    SLNode(int contents = 0)    //default and potentially overloaded constructor
  : next_node_(NULL),
     contents_(contents)
  {}                           

  ~SLNode() {}              //destructor

  void set_contents(int contents);    //mutator for contents
  int contents() const;               //accessor for contents
  void set_next_node(SLNode* next_node); //mutator for next node
  SLNode* next_node() const;             // 

 private:
  SLNode* next_node_;  //pointer for next node
  int contents_;       // stores contents of node
};


#endif /* ASSIGNMENT_3_H */

