/*
 * Author : Jason Lamphere
 * CSCI22 : Assignment4 
 * Desc.  : Discrete Math Algorithm
   github.com/nofunever/csci21      ide.c9.io/nofunever/csci21
 *
 */
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;


int euclid(int a, int b){
	int t;
  cout<<"OurGCD("<<a<<", "<<b<<") is ";
	while(b != 0){
	  t = b;
		b = a%b;
		a = t;
	}
	cout<<a<<endl;
}

int main(){  
   int a;
   int b;
   string foward;
   ifstream infile;
   int count = 0;

   infile.open("GCDinput.txt");
   if(infile.fail()){
      cout<<"Failed to open."<<endl;
   }
   cout<<"Welcome to Euclids Algorithm"<<endl;
   while(infile >> foward){
      if(count == 0){
     	  a =atoi(foward.c_str());
      }
      else if(count == 1){
     	  b =atoi(foward.c_str());
        euclid(a, b);
     	}
      else if(count == 2){ 
     	  a =atoi(foward.c_str());
      }
     	else if(count == 3){
     		b =atoi(foward.c_str());
      	euclid(a, b);
     	}
      else if(count == 4){
     	  a =atoi(foward.c_str());
      }
      else	if(count == 5){
     		b =atoi(foward.c_str());
      	euclid(a, b);
     	}
     	count++;
    }
    infile.close();
    return 0;
}