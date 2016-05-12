/*
 * Name        : sorting.cpp
 * Author      : Jason Lamphere
 * Description : Working with Insertion and Shell Sort
 * Sources     : ide.c9.io/nofunever/csci21   github.com/nofunever/csci21
 */
#include "sorting.h"

// CODE HERE -- FUNCTION DEFINITIONS

void SwapValues(int &value_1, int &value_2) {  //swaps node values by ref
  // DO NOT ALTER THE NEXT 3 LINES!!!
  if (GRADER) {
    cout << value_1 << " " << value_2 << endl;
  }
  // Code SWAP Algorithm Here
   int temp = 0;
  temp = value_1;
  value_1 = value_2;
  value_2 = temp;
}




int InsertionSort(int the_array[], unsigned int size) {  // goes through list one at a time and moves contents to proper location
  int passes = 0;
  for (unsigned int i = 0; i <= (size - 1); i++) {
  passes++;
    unsigned int j = i;
  while (j > 0 && the_array[j] < the_array[j - 1]) {
    SwapValues(the_array[j], the_array[j - 1]);
    j = j - 1;
  }
  }
  return passes;
}

int ShellSort(int the_array[], unsigned int size) {   //insertion sort that an swap values farther apart making really unorganized lists be sorted faster
  int passes = 0;
  unsigned int gap = size / 2;
    while (gap > 0) {
  passes++;
    for (unsigned int i = gap; i <= (size - 1); i++) {
      int temp = the_array[i];
    unsigned int j = i;
    while (j >= gap && the_array[j - gap] > temp) {
      the_array[j] = the_array[j - gap];
      j = j - gap;
    }
    the_array[j] = temp;
    DisplayArray(the_array);
    }
    gap = gap / 2;
  }
  return passes;
}

int BubbleSort(int the_array[], unsigned int size){  //inefficient bubble sort passes through list swapping values if they are in wrong order cycling through list till its complete
  
  int passes = 0;
  for (unsigned int i = (size - 1); i >= 1; i--) {
  passes++;
    for (unsigned int j = 0; j < i; j++) {
      if (the_array[j] > the_array[j + 1]) {
        SwapValues(the_array[j], the_array[j + 1]);
      }
    }
  }
  return passes;
  
}


int OptimizedBubbleSort(int the_array[], unsigned int size){ //bubble sort that doesn't recheck previously sorted items
  int passes = 0;
  for (unsigned int i = (size - 1); i >= 1; i--) {
  bool swapped = false;
  passes++;
    for (unsigned int j = 0; j < i; j++) {
      if (the_array[j] > the_array[j + 1]) {
        SwapValues(the_array[j], the_array[j + 1]);
        swapped = true;
      }
    }
    if (swapped == false)
      break;
  }
  return passes;
  
}


int SelectionSort(int the_array[], unsigned int size){ //each passs moves the smallest unsorted element. 
unsigned int smallest = 0;
int passes = 0;
  for (unsigned int i = 0; i < size; i++) {
      passes++;
      smallest = i; //set smallest to the current index of array
    for (unsigned int j = (i + 1); j < size; j++) {
      if (the_array[j] < the_array[smallest])
        smallest = j;
    }
    if (smallest != i) {
      SwapValues(the_array[i], the_array[smallest]);
    }
  }
  return passes;
  
}  
  
  
 
 