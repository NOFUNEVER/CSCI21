/*
 * Name        : lab_22.cpp
 * Author      : Xavier Winsor
 * Description : Recursive Functions
 */

#include "lab_22.h"

// CODE FUNCTION DEFINITIONS HERE

unsigned int Factorial(unsigned int value){
    int end = value;
    if (value >= 1){
        value = value * Factorial(value-1);
        
    }else{
        return 1;
    }
    
    return value;
    
    //return 0;
}

unsigned int Fibonacci(unsigned int fib_value){
    
    if(fib_value < 2){
         return fib_value;
    }else {
        fib_value = Fibonacci(fib_value - 1)+Fibonacci(fib_value-2);
    }
    return fib_value;
    
    //return 0;
}

bool WordIsPalindrome(string word){
    int length = word.length();
    bool end;
    if(length <= 1){
        end = true;
    }else if (word.at(0)==word.at(length-1)){
        word = word.substr(1, (length - 2));
        WordIsPalindrome(word);
    }else{
        end = false;
    }
    return end;
}

string ArrayForwardsAsString(int array[], unsigned int start, unsigned int size){
    stringstream ss;
    
    if(start!=(size)){
        ss<<array[start];
        ss<<" ";
        ss<<ArrayForwardsAsString(array, start+1, size);
    }
    return ss.str();
    
}

string ArrayBackwardsAsString(int array[], int start, unsigned int size){
    stringstream ss; 
    if(start>=0){
        ss<<array[start];
        ss<<" ";
        ss<<ArrayBackwardsAsString(array, start-1, size);
    }
    return ss.str();
}