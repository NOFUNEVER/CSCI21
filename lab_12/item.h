/*
 * Name        : item.h
 * Author      : Jason K Lamphere
 * Description : Inheritence practice
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::stringstream;
using std::string;


class Item {
 public:
    Item(string name = "item", unsigned int value = 0)
    : value_(value),
      name_(name) {
  }

~Item() {}

string name() {
  return name_;
}

unsigned int value() {
  return value_;
}

void set_name(string name) {
  name_ = name;
}

void set_value(unsigned int value) {
  value_ = value;
}

string ToString();

 private:
  unsigned int value_;
  string name_;
};

#endif /* ITEM_H_ */












