/*
 * Name        : Box.h
 * Author      : Jason Lamphere
 * Description : Assignment3
 * Links       : https://ide.c9.io/nofunever/csci21
 */
#ifndef BOX_H
#include <string>
#include <iostream>
#include "Prize.h"


class Box : public Prize
{
  private:
    unsigned int boxNumber;
    unsigned int prizeCapacity;
    unsigned int prizeCount;
    std::string boxColor;
    Prize scratch;
    Prize* prizes;

  public:
    Box();  
    Box(unsigned int number, std::string color, unsigned int capacity);
    ~Box();
    void setBoxNumber(unsigned int number);
    unsigned int getBoxNumber() const;
    void setBoxColor(std::string color);
    std::string getBoxColor();
    unsigned int getPrizeCapacity() const;
    unsigned int getPrizeCount() const;
    bool addPrize(const Prize& prize);
    Prize getPrize(unsigned int index);
    Prize removePrize(unsigned int index);
};



#endif