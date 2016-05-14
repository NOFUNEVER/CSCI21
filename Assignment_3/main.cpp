/*
 * Name        : Assignment 3
 * Author      : Jason Lamphere
 * Description : Assignment3'
 * Links       : ide.c9.io./nofunever/csci21 github.com/nofunever/csci21
 */

#include "Box.h"
#include "Prize.h"


int main(){
  Prize p;
  Box b;
  std::string yn;
  unsigned int integer;
  unsigned int choice;
  unsigned int choice2;  
  
  while(choice != 6){ //runs unntil user inputs to exit
    std::cout<<"-Prize Box Menu-"<<std::endl; //main menu  
    std::cout<<"1:Construct Your Box"<<std::endl;
    std::cout<<"2:Add Prize, Get Prize, Remove Prize"<<std::endl;
    std::cout<<"3:List Prize & Box Data"<<std::endl;
    std::cout<<"4:Compare Prizes"<<std::endl;
    std::cout<<"5:Reset(start over)"<<std::endl;
    std::cout<<"6:Quit"<<std::endl;
    std::cout<<"Please make a Choice: ";
    std::cin>>choice;
    if(choice == 2){
      std::cout<<"Add Prize:1, Get Prize:2, Remove Prize:3, Make Your Choice: ";
      std::cin>>choice2;
      if(choice2 == 1){
        std::cout<<"Enter Name of Prize: ";
        std::cin>>yn;
        p.setPrizeName(yn); //sets input as prize name
        std::cout<<"Enter Value of Prize: ";
        std::cin>>integer;
        p.setPrizeValue(integer); //sets input as prize value
        if(b.getPrizeCount() < b.getPrizeCapacity()){ //checks to make sure there is room inside the box
          b.addPrize(Prize(yn, integer)); //adds prize
          std::cout<<"You have added your prize."<<std::endl;
        }
        else
          std::cout<<"Box has reached maximum capacity.. Not Added."<<std::endl;
        }
        std::cout<<"Continue y/n: "; //allows user to continue or quit
        std::cin>>yn;
        if(yn == "y" || yn == "Y")
        {
          //goes back to main menu, starting over
        }
        else
        {
          break;
        }
      }
      else if(choice2 == 2)
      {
        std::cout<<"Enter the index integer of the prize to get: ";
        std::cin>>integer;
        b.getPrize(integer); //assigns selection to get prize
        Prize at = b.getPrize(integer); //pointer set to current index
        std::cout<<"Prize at index "<<integer<<": "<<std::endl; //displays index at current position
        std::cout<<"Name: "<<at.getPrizeName()<<std::endl;
        std::cout<<"Value: "<<at.getPrizeValue()<<std::endl;
        std::cout<<"Box Number: "<<b.getBoxNumber()<<std::endl;
        std::cout<<"Box Color: "<<b.getBoxColor()<<std::endl;
        std::cout<<"Continue?(y/n): ";
        std::cin>>yn;
        if(yn == "y" || yn == "Y") //allows user to continure or quit
        {
          //goes back to main menu, starting over
        }
        else
        {
          break;
        }
      }
      else if(choice2 == 3)
      {
        std::cout<<"Enter the index integer of the prize to remove(cannot remove index 0): ";
        std::cin>>integer;
        b.removePrize(integer); //removes prize
        std::cout<<"Prize at index "<<integer<<" remove."<<std::endl;
        std::cout<<"Continue?(y/n): ";
        std::cin>>yn;
        if(yn == "y" || yn == "Y")
        {
          //goes back to main menu, starting over
        }
        else
        {
          break;
        }
      }
    }
    else if(choice == 1)
    {
      int capacity;
      std::cout<<"-Edit Box-"<<std::endl;
      std::cout<<"Enter Box Number: ";
      std::cin>>integer;
      b.setBoxNumber(integer); //mutator sets the  number of the box
      std::cout<<"Enter Box Color: ";
      std::cin>>yn;
      b.setBoxColor(yn); //mutator sets the  color of the box
      std::cout<<"Your Box has been constructed."<<std::endl;
      std::cout<<"Continue?(y/n): ";
      std::cin>>yn;
      if(yn == "y" || yn == "Y")
      {
        //goes back to main menu, starting over
      }
      else
      {
        break;
      }
    }
    else if(choice == 3)
    { 
      integer = 0;
      b.getPrize(integer); //sets index to first
      Prize at = b.getPrize(integer); //pointer assigned to index
        
      std::cout<<"Box Number: "<<b.getBoxNumber(); //displays box info
      std::cout<<"  Box Color: "<<b.getBoxColor();
      std::cout<<"  Prize Capacity: "<<b.getPrizeCapacity();
      std::cout<<"  Prize Count: "<<b.getPrizeCount()<<std::endl;

      while(integer < b.getPrizeCount()) //while index is less than prozecount
      {
        std::cout<<"Prize at index "<<integer<<": ";
        std::cout<<"  Name: "<<at.getPrizeName(); //displays prize info at index
        std::cout<<"  Value: "<<at.getPrizeValue()<<std::endl;
        integer++; //increments index
        b.getPrize(integer); //assigns index to next position
        at = b.getPrize(integer); //assigns pointer to new index position
      }
      std::cout<<"Continue?(y/n): ";
      std::cin>>yn;
      if(yn == "y" || yn == "Y")
      {
        //goes back to main menu, starting over
      }
      else
      {
        break;
      }
    }
    else if(choice == 4)
    { 
      int first;
      int second;
      
      std::cout<<"-Compare Two Prizes-"<<std::endl;
      std::cout<<"Enter the first Prize position to compare: ";
      std::cin>>first;
      std::cout<<"Enter the second Prize position for comparison: ";
      std::cin>>second;
      
      b.getPrize(first);
      Prize at = b.getPrize(first); //sets at, at first index selected
      b.getPrize(second);
      Prize at2 = b.getPrize(second); //sets at2, at second index selected
      
      if(at.getPrizeName() == at2.getPrizeName() && at.getPrizeValue() == at2.getPrizeValue()) //compares prize names and values
      {
        std::cout<<"These prizes are the exactly the same."<<std::endl;
      }
      else
      {
        std::cout<<"These prizes are completely different."<<std::endl;
      }
      std::cout<<"Continue? y/n: ";
      std::cin>>yn;
      if(yn == "y" || yn == "Y")
      {
        //goes back to main menu, calling main stars us over
      }
      else
      {
        break;
      }
    }
    else if(choice == 5)
    {
      main();
    }
    else if(choice == 6)
    {
      break;
    }
    else
    {
      std::cout<<"Please enter a choice beween 1-5: ";
      std::cin>>integer;
    }
  }
  return 0;
}