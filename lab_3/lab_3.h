/*
 * Name        : lab_3.cpp
 * Author      : Luke Sathrum
 * Description : Header File for Lab #3. Do NOT Alter this file.
 */

#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>  //tried using ss to return instead of just a string at one point....didn't work either. left it in just incase I wanted to try again.
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// Function Prototypes (DO NOT ALTER)
string Goldilocks(string item, int number);
int RockScissorPaper(char player_one, char player_two);
string ToLower(string input);
string ToUpper(string input);

#endif