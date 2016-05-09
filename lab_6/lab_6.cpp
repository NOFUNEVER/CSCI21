/*
 * Name        : lab_6.cpp
 * Author      : Jason K Lamphere
 * Description : Working with Arrays
 */

#include "lab_6.h"

// CODE HERE (FUNCTION DEFINITIONS)
string PrepareForDisplay(int values[], int size, char separator) {
  stringstream displayss;
  for (int i = 0; i < size - 1; i++)
    displayss << values[i] << separator;
  displayss << values[size - 1];
  return displayss.str();
  }

bool HasValue(int values[], int size, int value) {
  for (int i = 0; i < size; i++) {
    if (values[i] == value) {
    return true;
  } 
}
return false;
}

int ValueAt(int values[], int size, int index, bool& error) {
  if (index < size && index >= 0) {
  error = false;
    return values[index];
  } else {
  error = true;
    return 0;
  }
}

int Sum(int values[], int size) {
  int Sum = 0;
    for (int i = 0; i < size; i++) {
       Sum += values[i];
    }
  return Sum;
}

bool SwapValues(int values[], int size, int index1, int index2) {
  if (index1 < size && index1 >= 0 && index2 < size && index2 >= 0) {
  int temp = 0;
  temp = values[index1];
  values[index1] = values[index2];
  values[index2] = temp;
  return true;
  } else {
  return false;
  }
}
