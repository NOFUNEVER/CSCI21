gi/*
 * Name        : Assignment_2.h
 * Author      : Jason K Lamphere
 * Description : Assignment2 
 * 
 * We have a class bnkAcct and 3 sub classes checking credit and savings.
 * Checking and savings can transfer between each other, Credit can only accept payments.
 * This demonstrates object orient and inheritence concepts.
 * 
 * 
 */
 
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using std::stringstream;
using std::string;

#ifndef bnkAcct_H
#define bnkAcct_H

class bnkAcct //base class
{
    public:
        bnkAcct(string f_name = "", string l_name = "", int pin = 0, double bal = 0); //constructor
        int getPin();      //accessor and mutators "setsgets" for our pin
        void setPin(int pin);
        string getfName();  //sets and gets for the account owners  name
        void setfName(string f_name);
        string getlName();
        void setlName(string l_name);
        string showAcct();
       
    protected:    
        string f_name_;
        string l_name_;
        int pin_;
        double bal_;

};

class Checking : public bnkAcct //sub class checking
{
    public:
        Checking(string f_name = "", string l_name = "", int pin = 0, double bal = 0, double deposit = 0, double withdraw = 0);
        double getChBal();  //gets and sets bal
        void setChBal(double bal);
        double getChDeposit();  //gets and sets deposit
        double setChDeposit(double deposit);
        double getChWithdraw(); // gets and sets withdraw
        double setChWithdraw(double withdraw);
        string showAcct(); //shows account into
    
    protected:
        double ch_deposit_; //variable to be used for this account
        double ch_withdraw_;
                
};

class Savings : public bnkAcct //sub class savings
{
  public:
    Savings(string f_name = "", string l_name = "", int pin = 0, double bal = 0, double deposit = 0, double withdraw = 0);
    double getSaBal(); //these funcion the same as checking but are new functions
    void setSaBal(double bal);
    double getSaDeposit();
    double setSaDeposit(double deposit);
    double getSaWithdraw();
    double setSaWithdraw(double withdraw);
    
    string showAcct();
    
  protected:
    double sa_deposit_; //variables to be used with this account
    double sa_withdraw_;
};

class Credit : public bnkAcct //sub class credit
{
  public:
    Credit(string f_name = "", string l_name = "", int pin = 0, double bal = 2009.43, double interest = 0.23, int limit = 4000, double payment = 0);
    double getInterest(); //gets and sets interest rate
    void setInterest(double interest);
    double getCrBal(); //gets and sets bal
    void setCrBal(double bal, double interest);
    double getCrPayment();  //gets and sets payment
    void setCrPayment(double payment);
    string showAcct();
  
  protected:
    double interest_; //variables to be used for this sub class
    double payment_;
    double bal_;
    int limit_;
};

#endif // bnkAcct_H
