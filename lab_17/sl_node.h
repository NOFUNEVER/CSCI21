/*
 * Name        : SL_NODE header
 * Lab 17
 * Author      : Jason Lamphere
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
    SLNode(int contents = 0)
  : next_node_(NULL),
     contents_(contents)
  {}

  ~SLNode() {}

  void set_contents(int contents);
  int contents() const;
  void set_next_node(SLNode* next_node);
  SLNode* next_node() const;

 private:
  SLNode* next_node_;
  int contents_;
};


#endif /* SL_NODE_H */

