/*
 * Name        : Assignment_2.cpp
 * Author      : Jason K Lamphere
 * Description : Assignment2
 * https://github.com/nofunever/CSCI21 https://ide.c9.io/nofunever/csci21
 */
 
 
#include "Assignment_2.h"

int main() //driver for bnkAcct and subclasses
{

  bnkAcct bnkacct;  //for calling the classes and sub classes
  Checking che;
  Credit cre;
  Savings sav;
  unsigned int tempInt; //main scope variables
  unsigned int decision= 0;
  unsigned int decision2 = 0;
  using std::cout;
  using std::cin;
  using std::string;
  string temp;

while(decision!= 3) //runs until user decides they want to exits
{
  if(decision== 0)
  {
    cout<<"Welcome, thanks for supporting our oligarchy!"<<std::endl; //main menu menu options
    cout<<"1:Set up new account(do this first)"<<std::endl;
    cout<<"2:Access your accounts!"<<std::endl;
    cout<<"3:Exit" <<std::endl;
    cout<<"Please Make a decision:) : "<<std::endl;
    cin>>decision;
    cout << "\033[2J\033[1;1H";// clears screen
  }
  if(decision== 1) //runs through the account setup
  {
    cout<<"Great let us get started!!"<<std::endl;
    cout<<"Please enter your legal first name: "<<std::endl;
    cin>>temp;
    bnkacct.setfName(temp); //sets first name
    cout << "\033[2J\033[1;1H";
    cout<<"Enter the last name of the account holder: "<<std::endl;
    cin>>temp;
    bnkacct.setlName(temp); //sets last name
    cout << "\033[2J\033[1;1H";
    cout<<"Enter your desired 4 digit pin number: "<<std::endl;
    cin>>tempInt;
    bnkacct.setPin(tempInt); //sets pin
    cout << "\033[2J\033[1;1H";
    cout<<"Thanks for joining us!!"<<std::endl;
    cout<<"0:Return to Main Menu"<<std::endl; 
    cout<<"2:Use the ATM"<<std::endl;
    cin>>decision;
    cout << "\033[2J\033[1;1H";// clears screen
  }
  else if(decision== 2)
  {
    cout<<" Please enter your pin: "<<std::endl;
    cin>>tempInt;
    cout << "\033[2J\033[1;1H";
    if(tempInt == bnkacct.getPin()) //checks to make sure pin is the corrrect one
    {
      cout<<"Account: "<<bnkacct.showAcct()<<std::endl; //displayes account holder info from bnkacct class
      cout<<"1:View Checking Account"<<std::endl;
      cout<<"2:View Credit Account"<<std::endl;
      cout<<"3:View Savings Account"<<std::endl;
      cout<<"Enter your selection: ";
      cin>>decision2;
      cout << "\033[2J\033[1;1H";
      if(decision2 == 1)
      {
      cout<<bnkacct.showAcct()<<che.showAcct()<<std::endl; //shows account holder with their checking account data
      cout<<"0:Make Transfer"<<std::endl;
      cout<<"1:Make Deposit"<<std::endl;
      cout<<"2:Make Withdraw"<<std::endl;
      cout<<"3:Return Home"<<std::endl;
      cin>>tempInt;
      cout << "\033[2J\033[1;1H";
        
        if(tempInt == 0)  // allows transfering between savings and checking
        { int amt;
          cout<< "How much do you want to transfer to savings?"<<std::endl;
          cin >> amt;
          if(amt < che.getChBal())
          {
           che.setChWithdraw(amt);
           sav.setSaDeposit(amt);
          cout<<"Transfer Success!!";
          cin.get();
          decision= 0;
          }
          else std::cout<< "Not enough funds to make transfer"<<std::endl;
          
          cin.get();
          decision= 0;
        }
        
        if(tempInt == 1)
        {
          cout<<"Enter Deposit integer: ";
          cin>>tempInt;
          che.setChDeposit(tempInt); //inputs to set deposit function
          cout<<tempInt<<" Deposit Success returning returning to main menu shortly..."<<std::endl;
          cin.get();
          decision= 0;
          cout << "\033[2J\033[1;1H";
        }
        else if(tempInt == 2)
        {
          cout<<"Enter Withdraw: only in increments of $20: "<<std::endl;
          cin>>tempInt;
          cout << "\033[2J\033[1;1H";
          if(che.getChBal() >= tempInt && tempInt%20 == 0) //ensures there are sufficient funds and its a increment of 20
          {
            che.setChWithdraw(tempInt); //inputs to set withdraw function
            std::cout<<tempInt<<" Withdraw Success returning returning to main menu shortly..."<<std::endl;
            cin.get();
            decision= 0;
            std::cout << "\033[2J\033[1;1H";
          }
          else //exits if there are insufficient funds
          {
            cout<<tempInt<<"You either did not enter an increment of $20 or you have insufficient funds returning to main menu."<<std::endl;
           cin.get();
            decision= 0;
            cout << "\033[2J\033[1;1H";
          }
        }
        else
        {
          cout<<tempInt<<" Exiting returning to main menu shortly..."<<std::endl;
          cin.get();
          decision= 0;
          cout << "\033[2J\033[1;1H";
        }
      }
      else if(decision2 == 2)
      {
        cout<<bnkacct.showAcct()<<cre.showAcct()<<std::endl; //shows account holder and credit data
        cout<<"1:Make Payment"<<std::endl;
        cout<<"0:Exit"<<std::endl;
        cin>>tempInt;
        cout << "\033[2J\033[1;1H";
        if(tempInt == 1)
        {
        cout<<"Enter the payment for the payment amount: ";
        cin>>tempInt;
          cre.setCrPayment(tempInt); //sets payment input
          cout<<tempInt<<" Payment Success returning to main menu shortly..."<<std::endl;
          cin.get();
          decision= 0;
          cout << "\033[2J\033[1;1H";
        }
      }
      else if(decision2 == 3)
      {
        cout<<bnkacct.showAcct()<<sav.showAcct()<<std::endl; //displays savings account info
        cout<<"0:Transfer"<<std::endl;
        cout<<"1:Make Deposit"<<std::endl;
        cout<<"2:Make Withdraw"<<std::endl;
        cout<<"3:Return Home"<<std::endl;
        cin>>tempInt;
        cout << "\033[2J\033[1;1H";
        
        if(tempInt == 0) //transfers between checking and savings
        { int amt;
          std::cout<< "How much do you want to transfer to checking"<<std::endl;
          std::cin >> amt;
          if(amt < sav.getSaBal())
          {
           che.setChDeposit(amt);
           sav.setSaWithdraw(amt);
          std::cout<<"Transfer Success!!";
        cin.get();
          decision= 0;
          }
          else std::cout<< "Not enough funds to make transfer"<<std::endl;
          
          cin.get(); 
          decision= 0;
        }
        
        if(tempInt == 1)
        {
          std::cout<<"Enter Deposit in whole dollars: ";
          std::cin>>tempInt;
          sav.setSaDeposit(tempInt); //sets deposit function
          std::cout<<tempInt<<" Deposit Success, returning to main menu shortly..."<<std::endl;
          cin.get();
          decision= 0;
          std::cout << "\033[2J\033[1;1H";
        }
        else if(tempInt == 2)
        {
          std::cout<<"Enter Withdraw amount only in increments of $20: ";
          std::cin>>tempInt;
          std::cout << "\033[2J\033[1;1H";
          if(sav.getSaBal() >= tempInt  && tempInt%20 == 0) //ensures sufficient funds
          {
            sav.setSaWithdraw(tempInt);
            std::cout<<tempInt<<" Withdraw Success returning returning to main menu shortly..."<<std::endl;
            cin.get();
            decision= 0;
            std::cout << "\033[2J\033[1;1H";
          }
          else //eexits if insufficient funds
          {
            std::cout<<tempInt<<" Insufficient Funds returning returning to main menu shortly..."<<std::endl;
           cin.get();
            decision= 0;
            std::cout << "\033[2J\033[1;1H";
          }
        }
        else
        {
          std::cout<<tempInt<<" Exiting returning returning to main menu shortly..."<<std::endl;
          cin.get();
          decision= 0;
          std::cout << "\033[2J\033[1;1H";
        }
      }
    }
    else
    {
      std::cout<<"Incorrect!"<<std::endl;
      std::cout<<"Enter 2 to try again, or 0 to return to main menu: "<<std::endl;
      std::cin>>decision;
      std::cout << "\033[2J\033[1;1H";
    }
  }
}
return 0;
}
