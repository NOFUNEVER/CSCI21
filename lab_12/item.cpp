/*
 * Name        : item.cpp
 * Author      : Jason K Lamphere
 * Description : Inheritence practice
 */

#include "item.h"

//stores input containing name and dollar value into a string.
string Item::ToString() {
stringstream ss;
  ss << name_ << ", $" << value_;
  return ss.str();
}



