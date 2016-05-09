/*
 * Name        : food_item.h
 * Author      : Jason K Lamphere
 * Description : Inheritence practice
 */

#ifndef FOOD_ITEM_H_
#define FOOD_ITEM_H_

#include "item.h"
#include <iostream>
#include <sstream>

class FoodItem : public Item {
 public:
    FoodItem(string name = "fooditem", unsigned int value = 0,
    unsigned int calories = 0,
    string unit_of_measure = "nounits", double units = 0)
    : Item(name, value),
      calories_(calories), unit_of_measure_(unit_of_measure),
    units_(units) {
    }

~FoodItem() {}

unsigned int calories() {
  return calories_;
}

string unit_of_measure() {
  return unit_of_measure_;
}

double units() {
  return units_;
}

void set_calories(unsigned int calories) {
  calories_ = calories;
}

void set_unit_of_measure(string unit_of_measure) {
  unit_of_measure_ = unit_of_measure;
}

void set_units(double units) {
  units_ = units;
}

string ToString();

 private:
    unsigned int calories_;
  string unit_of_measure_;
  double units_;
};

#endif /* FOOD_ITEM_H_ */












