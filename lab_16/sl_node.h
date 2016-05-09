/*
 * Name        : SL_NODE header
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
    SLNode(int contents = 0) : next_node_(NULL), contents_(contents) {} //node constructor
   ~SLNode() {}  // node destructor

  void set_contents(int contents);   //sets contents of node
  int contents() const;       // returns contents
  void set_next_node(SLNode* next_node); // sets the next node
  SLNode* next_node() const;    //returns the next node

 private:
  SLNode* next_node_; //creates next node
  int contents_;   //contents variable
};


#endif /* SL_NODE_H */

