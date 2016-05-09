/*
 * Name        : lab_5.cpp
 * Author      : Jason K Lamphere
 * Description : Practicing Functions. Use this file to write your
 *               Function Definitions (what goes below main()).
 */

#include "lab_5.h"

// CODE HERE (FUNCTION DEFINITIONS)
void Hello() {                                        //prints hello world
  cout << "Hello world!";
}
void PrintMessage(const string &message) {            //makes input string equal to "message" and prints
  message == "message";
  cout << message;
}
int GetAnswer() {                           //An accessor that gets a variable
  int x = 42;
  return x;
}
int FindLarger(const int &x, const int &y) {              //compares two values and returnsthe larger of the two
  if (x >= y)
    return x;
  else
    return y;
}

string BuildMessage(const string &strTwo , const bool &param  ) {     // has default argument for second parameter in prototype that assumes false.
  string temp = strTwo;                                               // if parameter is set to true  and parameer 1 is lower it will convert to upper case. 
  if (param == true && !strTwo.empty())                               // if paramter 2 is left alone to intentionally set false it won't convert  
  {   for (unsigned int i = 0; i < strTwo.length(); i++)              // if parameter 1 is empty, it will report empty
  {
      temp.at(i) = toupper(strTwo.at(i));
  }
      return "Message: " + temp;
  } else if (!strTwo.empty()) {
      return "Message: " + strTwo;
  } else {
  return "Message: empty";
  }
}