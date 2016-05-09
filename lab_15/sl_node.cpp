/*
 * Name        : lab_15.cpp
 * Author      : Jason Lamphere
 * Description : practice creating nodes for use with linked lists later on.
 *               
 */

#include "sl_node.h"

void SLNode::set_contents(int contents) {
  contents_ = contents;
}

int SLNode::contents() const {
  return contents_;
}

void SLNode::set_next_node(SLNode* next_node) {
  next_node_ = next_node;
}

SLNode* SLNode::next_node() const {
  return next_node_;
}
