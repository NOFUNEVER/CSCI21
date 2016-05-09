/*
 * Name        : lab_14.cpp
 * Author      : Jason K Lamphere
 * Description : Working with Pointers and Dynamic Variables / Arrays
 */
#include "lab_14.h"

// CODE HERE -- FUNCTION DEFINITIONS
int* MakeDynoIntArray(unsigned int size) {  //makes a dyanmic array
  return new int[size];
}

int Sum(int* the_array, unsigned int array_size) {  //sums the array
  if (the_array == NULL) {
    throw "NULL ARRAY REFERENCE";
  }
  int sum = 0;
  for (unsigned int i = 0; i < array_size; i++) {
    sum = sum + the_array[i];
  }
  return sum;
}

int Max(int* the_array, unsigned int array_size) {  // finds the max value of dynamic array
  if (the_array == NULL) {
    throw "NULL ARRAY REFERENCE";
  }
  int max = the_array[0];
  for (unsigned int i = 1; i < array_size; i++) {
    if (the_array[i] > max) {
      max = the_array[i];
    }
  }
  return max;
}

int Min(int* the_array, unsigned int array_size) {   //finds min value of dynamic array
if (the_array == NULL) {
    throw "NULL ARRAY REFERENCE";
}
  int min = the_array[0];
  for (unsigned int i = 1; i < array_size; i++) {
    if (the_array[i] < min) {
      min = the_array[i];
    }
  }
  return min;
}
