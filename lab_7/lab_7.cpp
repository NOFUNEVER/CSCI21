/*
 * Name        : lab_7.cpp
 * Author      :Jason K Lamphere
 * Description : Working with File I/O
 */
#include "lab_7.h"

// CODE HERE -- FUNCTION DEFINITION FOR ProcessFile()
// checks file for multiples of ten and executes appropriate function.
 bool ProcessFile(string filename) {
  ifstream fin;
  filename == "lab_7_input.txt";
  fin.open(filename.c_str());
  if (!fin)
    return false;
  int number;
  while (!fin.eof()) {
    fin >> number;
    if (fin) {
      if (number == 10) {
        OnTen();
      } else if (number == 20) {
        OnTwenty();
      } else if (number == 30) {
        OnThirty();
      } else if (number == 40) {
        OnForty();
      } else if (number == 50) {
        OnFifty();
      } else {
      OnError();
      }
    }
  }
  fin.close();
  return true;
}

 void ProcessArguments(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
  string temp = argv[i];
  if (temp == "10") {
     OnTen();
  } else if (temp == "20") {
     OnTwenty();
  } else if (temp == "30") {
     OnThirty();
  } else if (temp == "40") {
     OnForty();
  } else if (temp == "50") {
     OnFifty();
  } else {
     OnError();
  }
  }
}