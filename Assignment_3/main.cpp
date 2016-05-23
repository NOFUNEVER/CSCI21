/*
 * Name        : Assignment 3
 * Author      : Jason Lamphere
 * Description : Assignment3'
 * Links       : ide.c9.io./nofunever/csci21 github.com/nofunever/csci21
 */

#include "Box.h"
#include "Prize.h"
using std::cout;
using std::cin;
using std:endl;


int main(){
  Prize prize;
  Box box;
  std::string yn;
  unsigned int intg;
  unsigned int decision;
  unsigned int decision2;  
  
  while(decision != 6){ //runs unntil user inputs to exit
    cout<<"*****Menu******"<<endl; //main menu  
    cout<<"1:Make Your Box"<<endl;
    cout<<"2:Add Prize, Get Prize, Remove Prize"<<endl;
    cout<<"3:List Prize & Box Info"<<endl;
    cout<<"4:Compare the Prizes"<<endl;
    cout<<"5:Reset & start from the begining"<<endl;
    cout<<"6:Quit the Program"<<endl;
    cout<<"Please make a decision: ";
    cin>>decision;
    if(decision<1 | decision>6){
    cout<<"Please make a decision: ";
    cin>>decision;
    }
    
    if(decision == 2){
      cout<<"Add Prize:1, Get Prize:2, Remove Prize:3, Make Your Decision: ";
      cin>>decision2;
      if(decision2 == 1){
        cout<<"Enter Name of Prize: ";
        cin>>yn;
        prize.setPrizeName(yn); //sets input as prize name
        cout<<"Enter Value of Prize: ";
        cin>>intg;
        prize.setPrizeValue(intg); //sets input as prize value
        if(box.getPrizeCount() < box.getPrizeCapacity()){ //checks to make sure there is room inside our box
          box.addPrize(Prize(yn, intg)); //adds prize
          cout<<"You have added your prize."<<endl;
        }
        else
          cout<<"Box has reached maximum volume.. Nothing Added."<<endl;
        }
        cout<<"Continue y/n: "; //allows user to continue or quit
        cin>>yn;
        if(yn == "y" || yn == "Y"){   //goes back to main menu, starting over
        }
        else{
          break;
        }
      }
      else if(decision2 == 2){
        cout<<"Enter the position number of the prize to retreive : ";
        cin>>intg;
        box.getPrize(intg); //assigns selection to get prize
        Prize at = box.getPrize(intg); //pointer set to current position
        cout<<"Prize at position "<<intg<<": "<<endl; //displays position at current position
        cout<<"Name: "<<at.getPrizeName()<<endl;
        cout<<"Value: "<<at.getPrizeValue()<<endl;
        cout<<"Box Number: "<<box.getBoxNumber()<<endl;
        cout<<"Box Color: "<<box.getBoxColor()<<endl;
        cout<<"Continue? y/n: ";
        cin>>yn;
        if(yn == "y" || yn == "Y"){ //allows user to continure or quit
        }
        else{
          break;
        }
      }
      else if(decision2 == 3){
        cout<<"Enter the position value of the prize to remove: ";
        cin>>intg;
        box.removePrize(intg); //removes prize
        cout<<"Prize at position "<<intg<<" removed."<<endl;
        cout<<"Continue? y/n: ";
        cin>>yn;
        if(yn == "y" || yn == "Y"){
        }
        else{
          break;
        }
      }
    
    else if(decision == 1){
      int volume;
      cout<<"***Edit Box***"<<endl;
      cout<<"Enter Box Number: ";
      cin>>intg;
      box.setBoxNumber(intg); //mutator sets the  number of the box
      cout<<"Enter Box Color: ";
      cin>>yn;
      box.setBoxColor(yn); //mutator sets the  color of the box
      cout<<"Your Box has been made."<<endl;
      cout<<"Continue? y/n: ";
      cin>>yn;
      if(yn == "y" || yn == "Y"){
      }
      else{
        break;
      }
    }
    else if(decision == 3){ 
      intg = 0;
      box.getPrize(intg); //sets position to one
      Prize at = box.getPrize(intg); //pointer assigned to position
        
      cout<<"Box Number: "<<box.getBoxNumber(); //displays box info
      cout<<"  Box Color: "<<box.getBoxColor();
      cout<<"  Prize Volume: "<<box.getPrizeCapacity();
      cout<<"  Prize Count: "<<box.getPrizeCount()<<endl;

      while(intg < box.getPrizeCount()){ //while position is less than our prizecount
        cout<<"Prize at position "<<intg<<": ";
        cout<<"  Name: "<<at.getPrizeName(); //displays prize info at position
        cout<<"  Value: "<<at.getPrizeValue()<<endl;
        intg++; //increments position
        box.getPrize(intg); //assigns position to next position
        at = box.getPrize(intg); //assigns pointer to new position position
      }
      cout<<"Continue? y/n: ";
      cin>>yn;
      if(yn == "y" || yn == "Y"){
      }
      else{
        break;
      }
    }
    else if(decision == 4){ 
      int one;
      int two;
      
      cout<<"-Compare Two Prizes-"<<endl;
      cout<<"Enter the First Prize position to compare: ";
      cin>>one;
      cout<<"Enter the Second Prize position for comparison: ";
      cin>>two;
      
      box.getPrize(one);
      Prize at = box.getPrize(one); //sets at, at one position selected
      box.getPrize(two);
      Prize at2 = box.getPrize(two); //sets at2, at two position selected
      
      if(at.getPrizeName() == at2.getPrizeName() && at.getPrizeValue() == at2.getPrizeValue()){ //compares prize names and values
       cout<<"These prizes are the exactly the same."<<endl;
      }
      else{
        cout<<"These prizes are completely different."<<endl;
      }
      cout<<"Continue? y/n: ";
      cin>>yn;
      if(yn == "y" || yn == "Y"){
        //goes back to main menu, calling main stars us over
      }
      else
      {
        break;
      }
    }
    else if(decision == 5){
      main();
    }
    else if(decision == 6){
      break;
    }
    else{
      cout<<"Please enter a decision beween 1-5: ";
      cin>>intg;
    }
  }
  return 0;
}