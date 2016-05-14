/*
 * Name        : Prize.h
 * Author      : Jason Lamphere
 * Description : Assignment3'
 * Links       : ide.c9.io./nofunever/csci21 github.com/nofunever/csci21
 */

#ifndef PRIZE_H
#define PRIZE_H
#include<string>
#include <iostream>

class Prize
{
  private:
    std::string prizeName; //stores name
    unsigned int prizeValue; //stores value
    
  public:
    Prize() : prizeName("NO NAME"), prizeValue(0){} //default constructor
    Prize(std::string itemName, unsigned int itemValue)//param set constructor
    {
      prizeName = itemName;
      prizeValue = itemValue;
    }
    ~Prize(){}//destructor
    friend bool operator ==(const Prize &ONE, const Prize &TWO); //operator overlaod
    void setPrizeName(std::string itemName); //mutator
    std::string getPrizeName() const;//accesor
    void setPrizeValue(unsigned int itemValue);//mutator
    unsigned int getPrizeValue() const;//accessor
};



#endif