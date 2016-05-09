/*
 * Name        : food_item.cpp
 * Author      : Jason K Lamphere
 * Description : Inheritence practice
 */

#include "food_item.h"

// takes in additional information relevant to food and stores in a string
string FoodItem::ToString() {
stringstream ss;
  ss.setf(std::ios::showpoint|std::ios::fixed);
  ss.precision(2);
  ss << Item::ToString();
  ss << ", " << units_ << " " << unit_of_measure_ << ", ";
  ss << calories_ << " calories";
  return ss.str();
}

