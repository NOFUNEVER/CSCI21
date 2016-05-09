#include "Box.h"
#include "Prize.h"


int main()
{
  Prize p;
  Box b;
  std::string word;
  unsigned int integer;
  unsigned int choice;
  unsigned int choice2;  
  
  while(choice != 6) //runs unntil user quits
  {
    std::cout<<"-Prize Box Menu-"<<std::endl; //main menu with options 
    std::cout<<"(1)Construct Your Box"<<std::endl;
    std::cout<<"(2)Add Prize, Get Prize, Remove Prize"<<std::endl;
    std::cout<<"(3)List Prize & Box Data"<<std::endl;
    std::cout<<"(4)Compare two Prizes"<<std::endl;
    std::cout<<"(5)Reset(clear data)"<<std::endl;
    std::cout<<"(6)Quit"<<std::endl;
    std::cout<<"Enter Choice: ";
    std::cin>>choice;
    if(choice == 2)
    {
      std::cout<<"Add Prize(1), Get Prize(2), Remove Prize(3), Enter Choice: ";
      std::cin>>choice2;
      if(choice2 == 1)
      {
        std::cout<<"Enter Prize Name: ";
        std::cin>>word;
        p.setPrizeName(word); //sets input as prize name
        std::cout<<"Enter Prize Value: ";
        std::cin>>integer;
        p.setPrizeValue(integer); //sets input as prize value
        if(b.getPrizeCount() < b.getPrizeCapacity()) //checks to make sure there is room
        {
          b.addPrize(Prize(word, integer)); //adds prize
          std::cout<<"You have added your prize."<<std::endl;
        }
        else
        {
          std::cout<<"Box Capacity FULL. Not Added."<<std::endl;
        }
        std::cout<<"Continue?(y/n): "; //allows user to continue or quit
        std::cin>>word;
        if(word == "y" || word == "Y")
        {
          //goes back to main menu, calling main overwrites all current data
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
        std::cin>>word;
        if(word == "y" || word == "Y") //allows user to continure or quit
        {
          //goes back to main menu, calling main overwrites all current data
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
        std::cin>>word;
        if(word == "y" || word == "Y")
        {
          //goes back to main menu, calling main overwrites all current data
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
      b.setBoxNumber(integer); //sets the number of the box
      std::cout<<"Enter Box Color: ";
      std::cin>>word;
      b.setBoxColor(word); //sets the color of the box
      std::cout<<"Your Box has been constructed."<<std::endl;
      std::cout<<"Continue?(y/n): ";
      std::cin>>word;
      if(word == "y" || word == "Y")
      {
        //goes back to main menu, calling main overwrites all current data
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
      std::cin>>word;
      if(word == "y" || word == "Y")
      {
        //goes back to main menu, calling main overwrites all current data
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
      std::cout<<"Enter the index of the first Prize to compare: ";
      std::cin>>first;
      std::cout<<"Enter the index of the second Prize to compare: ";
      std::cin>>second;
      
      b.getPrize(first);
      Prize at = b.getPrize(first); //sets at, at first index selected
      b.getPrize(second);
      Prize at2 = b.getPrize(second); //sets at2, at second index selected
      
      if(at.getPrizeName() == at2.getPrizeName() && at.getPrizeValue() == at2.getPrizeValue()) //compares prize names and values
      {
        std::cout<<"These prizes are the same."<<std::endl;
      }
      else
      {
        std::cout<<"These prizes are different."<<std::endl;
      }
      std::cout<<"Continue?(y/n): ";
      std::cin>>word;
      if(word == "y" || word == "Y")
      {
        //goes back to main menu, calling main overwrites all current data  
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
      std::cout<<"Enter a valid choice 1-5: ";
      std::cin>>integer;
    }
  }
  return 0;
}