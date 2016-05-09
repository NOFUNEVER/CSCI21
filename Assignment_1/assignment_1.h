/*
 * Name        : FILL IN
 * Author      : FILL IN
 * Description : FILL IN
 * Sources     : FILL IN
 */

#ifndef ASSIGNMENT_1_H
#define ASSIGNMENT_1_H

// Add any includes and using statements Here
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <clocale>
using namespace std;

// Declare Function Prototypes Here (What goes above main)
// Checks a string to see if all the characters are alphabetic
bool CheckAlphabetic(const string &my_string);

// Encrypts a string using the Caesar Cipher method
bool EncryptString(string &my_string, int shift_num);

// Reverses the Encrypt function above
bool DecryptString(string &my_string, int shift_num);

// Computes the average value in an array
double ComputeAverage(double d_array[], unsigned int array_size);

// Finds the minimum value in an array of numbers
double FindMinValue(double d_array[], unsigned int array_size);

// Finds the maximum value in an array of numbers
double FindMaxValue(double d_array[], unsigned int array_size);

int CountWords( const string &my_string );
#endif /* ASSIGNMENT_1_H */


