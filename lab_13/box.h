/*
 * Name        : box.h
 * Author      : Jason Lamphere
 * Description : Templates 
 * https://github.com/NOFUNEVER/CSCI21 https://ide.c9.io/NOFUNEVER/CSCI21
 */

#ifndef LAB_H
#define LAB_H

#include <iostream>
using std::ostringstream;
using std::string;

template <class T> //decalre template param
class Box { //declare class box

  private:
    T dat_t_; //sets param var to template type
  
  public:
    Box(T newDat_t):dat_t_(newDat_t){ //constructor initializes dat_t_ to newDat_t
    
    }
    
    void setDat_t(T newDat_t){ //set function for dat_t_ to newDat_t
    
      dat_t_ = newDat_t;
    }
    
    T getDat_t(){ //get function returns dat_t_
    
      return dat_t_;
    }
    
    friend ostringstream+ operator <<(ostringstream+ out, Box<T> get){ //friend function with stringstream
    
      out << get.dat_t_; //puts dat_t_ into stream
      return out;
    }
    
    T Sum(T array[], int size){//template variable  used to provide sum of an array that can contain any data type
    
      T sum = T();
      
      for(int i = 0; i < size; i++){
        sum += array[i];
      }
      return sum;
    }
}

#endif