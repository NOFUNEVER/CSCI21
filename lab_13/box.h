/*
 * Name        : box.h
 * Author      : Jason Lamphere
 * Description : Templates 
 * https://github.com/NOFUNEVER/CSCI21 https://ide.c9.io/NOFUNEVER/CSCI21
 */

#ifndef BOX_H
#define BOX_H

#include <string>
#include <ostream>
using std::string;
using std::ostream;



template<class T>
class Box{ 

public:
   
Box(){   //default constructor
    contents = 0;
}

Box(T newContents){ //overloaded constructor
    contents = newContents;
}

void setContents(T newContents){//mutator
    contents = newContents;
}


T getContents() const{//accessor
    return contents;
}

friend ostream& operator <<(ostream& output, const Box<T> &newContents){//output
    output << newContents.contents;
    return output;
}



protected:
  T contents; //protected templated variables
};

template<class T>
T Sum(T values[], unsigned int size){  // sums  up thevalues in array
    T sum = T();
    for( int i = 0; i < size; i++){
        sum+=values[i];
    }
 return sum;   
 }


#endif