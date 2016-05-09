/*
 * Name        : magic_item.h
 * Author      : Jason K Lamphere
 * Description : Inheritence practice
 */

#ifndef MAGIC_ITEM_H_
#define MAGIC_ITEM_H_

#include "item.h"
#include <iostream>
#include <sstream>

class MagicItem : public Item {
 public:
    MagicItem(string name = "magicitem", unsigned int value = 0,
  string description = "no description", unsigned int mana_required = 0)
    : Item(name, value),
      description_(description), mana_required_(mana_required) {
    }

~MagicItem() {}

string description() {
  return description_;
}

unsigned int mana_required() {
  return mana_required_;
}

void set_description(string description) {
  description_ = description;
}

void set_mana_required(unsigned int mana_required) {
  mana_required_ = mana_required;
}

string ToString();

 private:
    string description_;
  unsigned int mana_required_;
};

#endif /* MAGIC_ITEM_H_ */





