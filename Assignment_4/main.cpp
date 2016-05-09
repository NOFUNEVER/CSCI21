/*
 * Name        : Assignment_4
 * Author      : Jason K Lamphere
 * Description : the main file for our doubly linked list which will include
 * our dl_list header file.
 * Sources https://ide.c9.io/nofunever/csci21 github.com/nofunever/csci21
 */

 

#include "dl_node.h"
#include "dl_list.h"
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;


bool is_number(const std::string& s) //checks to make sure its a name before adding to list
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}



int main (int argc, const char* argv[]){ // accepts arguement from command line to open a file

DLNode node;
    DLList list;
    ifstream instream;
    ofstream outstream;
    stringstream stream;
    string next;
    int next2=0;
    int count = 0;
    int temp = 0;
    string temphead="";

    cout << "It's Time for Musical Chairs!"<<endl; 
    cout << "Who will be eliminated first?"<<endl <<endl;
    
   
    instream.open(argv[1]);  //opens file stream from console argument
    if(instream.fail()){     //if it fails it tells you 
        cout<<"Failed to open file."<<endl;
        return 0;
    }
    
    while(instream >> next){ //while its reading in from the file it will put the line into next and count
      count++;
      
        if(!is_number(next) && count < 2){
              
           list.PushFront(next);   // pushes line to front and returns it to be viewed the first time
           cout << list.GetFront()<<endl;
        }
    
        else if(!is_number(next) && count > 1){
              
           list.PushBack(next);
           cout<<list.GetBack()<<endl;
              
          }
     
    }
          
          cout<<endl;
          instream.close();
          instream.open("a3input.txt");
          
           while(instream >> next){   //if it is a number 
                if(is_number(next)){
                  next2 = atoi(next.c_str());//dumpsd  numerical value stored in string into an int varialbe
                  temp = next2%list.GetSize()-1; //figures out eliminated player using modulo
                     
                cout<<"Player "<<temp+1<<": "<<list.Traverse(temp)<<" lost the round and has been eliminated." <<endl<<endl;//traverses to the proper player 
                list.RemoveFirst(list.Traverse(temp)); //removes and reaaranges our list.
                temphead = list.Traverse(temp);
                list.RemoveFirst(list.Traverse(temp)); 
                 list.PushFront(temphead);
                
                cout<<list<< endl;
         
          }
        }
        
          return 0;
              
   }
        
      
  
    
 
   
    
    
   
        
        
      
    
 
