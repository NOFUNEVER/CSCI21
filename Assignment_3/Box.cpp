/*
 * Name        : Box.cpp
 * Author      : Jason Lamphere
 * Description : Assignment3
 */
#include<iostream>
#include<string>

#include "Box.h"
#include "Prize.h"


//o Box
// private data members: boxNumber (unsigned int), boxColor (string),
//scratch (Prize), prizes (Prize*, for dynamic array), prizeCapacity
//(unsigned int), prizeCount (unsigned int)
// public default constructor: initial values boxNumber (0), boxColor ("NO
//COLOR"), prizeCapacity (5), prizeCount(0); in the definition, prizes
//array must be initialized to match prizeCapacity
// public overloaded constructor: parameters for boxNumber, boxColor,
//prizeCapacity; in the definition, prizes array must be initialized to
//match prizeCapacity
// public destructor: free memory associated with prizes
// public accessors/gets AND mutators/sets for boxNumber, boxColor
// public accessor/get ONLY for data members prizeCapacity, prizeCount
// public addPrize: parameters prize (Prize), return value (bool); place
//prize in prizes array if there is space and return true, else return false
// public getPrize: parameters index (unsigned int), return value Prize&;
//return a Prize if index is valid, else return scratch (data member
//declared in class header)

Box::Box() : boxNumber(0), boxColor("NO COLOR"), prizeCapacity(5),prizeCount(0)
{
  prizes = new Prize[prizeCapacity];
  scratch = Prize();
}

Box::Box(unsigned int number, std::string color, unsigned int capacity){
  
  boxNumber = number;
  boxColor = color;
  prizeCapacity = capacity;
  prizeCount = 0;
  prizes = new Prize[capacity];
}

Box::~Box(){
  
  delete [] prizes;
  prizes = NULL;
}

unsigned int Box::getBoxNumber() const{
  
  return boxNumber;
}

void Box::setBoxNumber(unsigned int number){
  
  boxNumber = number;
}

void Box::setBoxColor(std::string color){  
  boxColor = color;
}

std::string Box::getBoxColor(){
  
  return boxColor;
}
    
unsigned int Box::getPrizeCapacity() const{
  
  return prizeCapacity;
}

unsigned int Box::getPrizeCount() const{
  
  return prizeCount;
}
   
bool Box::addPrize(const Prize& prize){
  
  if(prizeCount >= prizeCapacity)
  {
    return false;
  }
  else
  {
    prizes[prizeCount++] = prize;
    return true;
  }
}

Prize Box::getPrize(unsigned int index){
  
  if(index >= prizeCount)
  {
    return scratch;
  }
  else
  {
    return prizes[index];
  }
}
        
Prize Box::removePrize(unsigned int index){
  
  if (index >= prizeCount)
  {
    return scratch;
  }
  else 
  { Prize tmp = prizes[index];

  for (int i = index; i < prizeCount - 1; i++)
  {
    prizes[i] = prizes[i - 1];
  }
  prizeCount--;
  return tmp;
  }
}    