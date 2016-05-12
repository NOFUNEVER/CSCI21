
/*
 * Name        : lab_27
 * Author      : Jason
 * Description : the last lab in programming and algorithms 2 where we use built
 * in functions to work with vectors.
 * Sources     :
 */

#include "lab_27.h"

void TreasureChest::AddItem(const Item& item_to_add) {
  chest_.push_back(item_to_add);
}

void TreasureChest::InsertItem(const Item& item_to_add, unsigned int position) {
  if (position < chest_.size()) {
    chest_.insert(chest_.begin() + position, item_to_add);
  } else {
    chest_.push_back(item_to_add);
  }
}

const Item* TreasureChest::GetItem(unsigned int position) {
  if (position >= chest_.size()) {
    return NULL;
  }
  return &chest_.at(position);
}

Item TreasureChest::RemoveItem(unsigned int position) {
  if (position >= chest_.size()) {
    throw string("ERROR: Remove at invalid position");
  }
    Item temp = chest_.at(position);
    chest_.erase(chest_.begin() + position);
    return temp;
}

void TreasureChest::Clear() {
  chest_.clear();
}

bool TreasureChest::Empty() const {
  if (chest_.size() == 0) {
    return true;
  }
  return false;
}

unsigned int TreasureChest::GetSize() const {
  return chest_.size();
}

void TreasureChest::SortByName() {
  sort(chest_.begin(), chest_.end(), CompareItemsByName);
}

void TreasureChest::SortByValue() {
  sort(chest_.begin(), chest_.end(), CompareItemsByValue);
}

void TreasureChest::SortByQuantity() {
  sort(chest_.begin(), chest_.end(), CompareItemsByQuantity);
}

ostream& operator<<(ostream& outs, const TreasureChest& src) {
  if (src.chest_.size() == 0) {
    outs << "Chest Empty!";
  } else {
  for (unsigned int i = 0; i < (src.chest_.size() - 1); i++) {
    outs << src.chest_.at(i) << ", ";
  }
    outs << src.chest_.at(src.chest_.size() - 1);
  }
  return outs;
}

string TreasureChest::ToString() {
stringstream ss;
  ss << *this;
  return ss.str();
}

bool CompareItemsByName(const Item& lsrc, const Item& rsrc) {
  if (lsrc.name_ < rsrc.name_) {
    return true;
  }
  return false;
}

bool CompareItemsByValue(const Item& lsrc, const Item& rsrc) {
  if (lsrc.value_ < rsrc.value_) {
    return true;
  }
  return false;
}

bool CompareItemsByQuantity(const Item& lsrc, const Item& rsrc) {
  if (lsrc.quantity_ < rsrc.quantity_) {
    return true;
  }
  return false;
}












