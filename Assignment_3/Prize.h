/*
 * Name        : Prize.h
 * Author      : Jason Lamphere
 * Description : Assignment3
 */

#ifndef PRIZE_H
#define PRIZE_H
#include<string>
#include <iostream>

class Prize
{
  private:
    std::string prizeName;
    unsigned int prizeValue;
    
  public:
    Prize() : prizeName("NO NAME"), prizeValue(0){}
    Prize(std::string itemName, unsigned int itemValue)
    {
      prizeName = itemName;
      prizeValue = itemValue;
    }
    ~Prize(){}
    friend bool operator ==(const Prize &ONE, const Prize &TWO);
    void setPrizeName(std::string itemName);
    std::string getPrizeName() const;
    void setPrizeValue(unsigned int itemValue);
    unsigned int getPrizeValue() const;
};



#endif