


#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;


int recursive(int a, int n) {
	    if(n == 0) {  // base case
	      return a;
	    }
	      else{
	          
	   return recursive(a, n-1) * recursive(a,n-1);
	   
	      }
}
	      


int main(){
int a;
int n;

cout << "input a"<<endl;    
cin >> a;
cout <<"input b"<<endl;
cin >>n;

cout << recursive(a,n);
    
    
    
    
    
}