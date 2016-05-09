/*
 * Name        : lab_1.cpp
 * Author      : Jason K Lamphere
 * Date        : 1/27/16
 * Description : Our First Lab of the Semester!
 * https://ide.c9.io/nofunever/csci21
 * https://github.com/NOFUNEVER/CSCI21
 */
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;



string checkExperience (char hasExperience)
{
  if(hasExperience =='y' || hasExperience == 'Y') {
    cout << "Welcome Back"<<endl;

  } else if (hasExperience =='n' || hasExperience =='n') {
    cout << "Get Ready for someon fun" << endl;
  }

  return string("");
}

void FirstLab()
{
  string first_name;

  char programmed_before = 'z';
  char my_character = 'z';

  cout << "Welcome to the LAB!"<< endl;
  cout << "What is your first name?" << endl;
  cin >> first_name;
  cout << "Nice to meet you " << first_name << endl;
  cout << "have you ever programmed before??? (y/n)";
  cin >> programmed_before;
  checkExperience(programmed_before);



}




int main()
{
  FirstLab();
  return 0;
}