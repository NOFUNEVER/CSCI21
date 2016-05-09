/*
 * Name        : Prize.cpp
 * Author      : Jason Lamphere
 * Description : Assignment3
 */
#include<iostream>
#include<string>
#include "Prize.h"

//Prize
// private data members: prizeName (string), prizeValue (unsigned int)
// public default constructor: initial values itemName ("NO NAME"),
//itemValue (0)
// public overloaded constructor: parameters for all data members
// public destructor: empty
// friend overloaded operator==: returns true if the prizeName and
//prizeValue of the two Prizes being compared are equivalent, else return
//false
// public accessors/gets and mutators/sets for all data members

bool operator ==(const Prize &ONE, const Prize &TWO){
  
  return (ONE.getPrizeName() == TWO.getPrizeName() && ONE.getPrizeValue() == TWO.getPrizeValue());
}
    
void Prize::setPrizeName(std::string itemName){
  
  prizeName = itemName;
}
    
std::string Prize::getPrizeName() const{
  
  return prizeName;
}
    
void Prize::setPrizeValue(unsigned int itemValue){
  
  prizeValue = itemValue;
}
    
unsigned int Prize::getPrizeValue() const{
  
  return prizeValue;
    
}
    