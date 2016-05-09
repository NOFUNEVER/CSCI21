/*
 * Name        : magic_item.cpp
 * Author      :Jason K Lamphere
 * Description : Inheritence practice
 */

#include "magic_item.h"
// collects extra information outside of item need for a magic item and puts it in a string
string MagicItem::ToString() {
stringstream ss;
  ss << Item::ToString();
  ss << ", " << description_ << ", requires " << mana_required_ << " mana";
  return ss.str();
}

