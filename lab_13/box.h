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
using std::stringstream;
using std::endl;


template<class T>
class Box{ 

  public:
   
Box(){
    contents = 0;
}


Box(T newContents){
    contents = newContents;
}


void setContents(T newContents){
    contents = newContents;
}



T getContents() const{
    return contents;
}


friend ostream& operator <<(ostream& output, const Box<T> &newContents){
    output << newContents.contents;
    return output;
}





T Sum(T values, unsigned int size){
    T sum = "zero";
    for( int i = 0; i < size; i++){
        sum+=values[i];
    }
 return sum;   
}
 protected:
    T contents; 
};

#endif