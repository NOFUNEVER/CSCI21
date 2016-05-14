/*
 * Name        : word.cpp
 * Author      : Jason K Lamphere
 * Links       : 
 * Description : Word class for use with a bstree
 */
#ifndef WORD_H
#define WORD_H
 
#include "bst_node.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cstring>
using std::cout;
using std::ifstream;
using std::endl;
using std::string;
using std::map;
using std::stringstream;
using std::ios_base;

class Word 
{
    public:
        Word(){
            word = "";            //default constructor
        }                     
        Word(string word_){
            word = word_
        }   
        ~Word() {}
        
        unisigned int count() const {
            
            
        }
        string word_() const;
        void get_count(unsigned int count);
        void get_word_(string wor);
    private:
        string word;            
        unsigned int count;     
                                  
};
    
#endif
