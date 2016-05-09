/*
 * Name        : Assignment_2.cpp
 * Author      : Jason K Lamphere
 * Description : Assignment2ude "Assignment_2.h"
 *
 * https://github.com/nofunever/CSCI21 https://ide.c9.io/nofunever/csci21
 */

#incl

int bnkAcct::getPin() //gets private pin value
{
  return pin_;
}

void bnkAcct::setPin(int pin) //sets the pin value 
{
  pin_ = pin;
}

string bnkAcct::getfName() //returns first name
{
  return f_name_;
}

void bnkAcct::setfName(string f_name) //sets first name
{
  f_name_ = f_name;
}

string bnkAcct::getlName() //returns last name
{
  return l_name_;
}

void bnkAcct::setlName(string l_name) // sets last name
{
  l_name_ = l_name;
}

string bnkAcct::showAcct() //displays Acct and owner information 
{
  stringstream ss;
  ss.setf(std::ios::fixed|std::ios::showpoint);
  ss.precision(2);
  ss << getfName() << " " << getlName();
  return ss.str();
}

Checking::Checking(string f_name, string l_name, int pin, double bal, double deposit, double withdraw)
: bnkAcct(f_name, l_name, pin, bal), ch_deposit_(deposit), ch_withdraw_(withdraw)
{} //initializes variables and  our new sub class variables

double Checking::getChBal() //returns bal
{
  return bal_;
}

void Checking::setChBal(double bal) //sets bal
{
  bal_ = bal;
}

double Checking::getChDeposit() //returns deposit
{
  return ch_deposit_;
}

double Checking::setChDeposit(double deposit) //sets deposit
{
  ch_deposit_ = deposit;
  bal_ += deposit; //adds deposit to bal
}

double Checking::getChWithdraw() //gets withdraw
{
  return ch_withdraw_;
}

double Checking::setChWithdraw(double withdraw) //sets withdraw
{
  ch_withdraw_ = withdraw;
  bal_ -= withdraw; //decrements withdraw from bal
}

string Checking::showAcct() //shows all account info
{
  stringstream ss;
  ss.setf(std::ios::fixed|std::ios::showpoint);
  ss.precision(2);
  ss << "  Checking Bal: " << getChBal();
  return ss.str();
}



Savings::Savings(string f_name, string l_name, int pin, double bal, double deposit, double withdraw)
: bnkAcct(f_name, l_name, pin, bal), sa_deposit_(deposit), sa_withdraw_(withdraw)
{}//initializes variables and new variables for sub class

double Savings::getSaBal() //gets bal
{
  return bal_;
}

void Savings::setSaBal(double bal) //sets bal
{
  bal_ = bal;
}

double Savings::getSaDeposit() //gets deposit
{
  return sa_deposit_;
}

double Savings::setSaDeposit(double deposit) //sets deposit
{
  sa_deposit_= deposit;
  bal_ += deposit; //adds deposit to bal
}

double Savings::getSaWithdraw() //gets withdraw
{
  return sa_withdraw_;
}

double Savings::setSaWithdraw(double withdraw) //sets withdraw
{
  sa_withdraw_ = withdraw;
  bal_ -= withdraw; //decrements withdraw from bal
  
  
  
}

string Savings::showAcct() //shows account info
{
  stringstream ss;
  ss.setf(std::ios::fixed|std::ios::showpoint);
  ss.precision(2);
  ss << "  Savings Bal: " << getSaBal();
  return ss.str();
}

Credit::Credit(string f_name, string l_name, int pin, double bal, double interest, int limit, double payment)
: bnkAcct(f_name, l_name, pin), bal_(bal), interest_(interest), payment_(payment)
{}//initialize variables and new sub variables

double Credit::getInterest() //gets the interest rate
{
  return interest_* bal_;
}

void Credit::setInterest(double interest = 0.23) //sets the interest rate
{
  interest_ = interest;
}

double Credit::getCrBal()//gets the bal
{
  return bal_ + bal_*interest_;
}

void Credit::setCrBal(double bal = 2009.43, double interest = 0.23)//set bal by adding it to bal times interest rate
{
  bal_ = bal;
}

double Credit::getCrPayment() //gets payment
{
  return payment_;
}

void Credit::setCrPayment(double payment) //sets payment
{
  payment_ = payment;
  bal_ -= payment; //decrements payment from bal
}

string Credit::showAcct()//shows account info
{
  stringstream ss;
  ss.setf(std::ios::fixed|std::ios::showpoint);
  ss.precision(2);
  ss << "  Credit Balance: " << getCrBal() << " Interest This Month Will Be: " << getInterest() << " with a Credit Limit of $4000.00, You Have, "<< 4000-getCrBal() <<" remaining. " << std::endl;
  return ss.str();
}

