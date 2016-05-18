/*
 * Name        : Driver/Main
 * Author      : Jason K Lamphere
 * Description : creating a BST Node for a tree.
 * Sources     : ide.c9.io/nofunever/csci21    github.com/nofunever/csci21
 */

#include "bs_treet.h"

int main(int argc, const char* argv[]){
    
    string word;
    if (argv[1] == ""){
        cout<< "No File Specified from Console argument! Or no"<<endl;
        cout<<"Please try to open the file again with a valid file name appended at the end"<<endl;
    }
    cout << "It's time to make a tree from our file."<<endl;
    cout << "Lets GO!"<< endl<<endl<<endl;

    // Initialize and open In
    ifstream In;
    In.open(argv[1]);
    BSTreeT<string> *root;
    
    if(In.is_open()){                            //starts loop if file opens succesfully.
        while(!In.eof()){                       //untill we get to the end
            char command = In.get();               //reads in our commands variable
            if (command == 35){                 //ignores # line
                getline(In, word);              //jump to next line instead of taking in the empty space after it
               }
                else if(!('O'||'o'||'X'||'x'||'R'||'r'||'D'||'d'||'C'||
                'c'||'F'||'f'||'G'||'g'||'N'||'n'||'I'||'i'||'E'||'e')){ //even though we have a comment filter this filters out garbage commands
                 cout << "unrecognized input" <<endl;
                }
                else if(command == 'O' || command == 'o'){                                      //Standard output
                    cout << "Print out Tree in forwards direction!" << endl;
                    if(root->GetSize() == 0){
                        cout<< "Tree is empty!!" << endl;
                    }
                    else { 
                        cout << "Foward:" << root->ToStringForwards() << endl;
                    }
                }
                else if(command == 'X' || command == 'x'){                                      //clears all leaves
                    root->Clear();
                    cout << "All leaves cleared successfully!" << endl;
                }
                else if(command == 'R' || command == 'r'){
                    getline(In, word);
                    cout << "Removing" << word << " from Tree!" << endl;
                    if(root->Exists(word)){                                         //solves exesetential existential problems..jk it finds our our value in our tree.
                        root->Remove(word);
                        cout << "Removal was successful!"<<endl;
                        cout<< "Size of: " << root->GetSize() << " returned" <<endl;
                    }
                    else {
                        cout << "Removal Failed!"<<endl;
                        cout<< word << " was not located." << endl;
                    }
                }
                else if(command == 'D' || command == 'd'){            //deltes all leaves and tree itself
                    cout << "Deleting all leaves/Tree" << endl;
                    root->~BSTreeT();
                    if(root->GetSize() != 0){
                        cout << "Removal failure size not 0!"<<endl;
                        cout<< "Size returned as: " << root->GetSize() << endl;
                    } else {
                        cout << "Removal successful! Size = 0" << endl;
                    }
                }
                else if(command == 'C' || command == 'c'){                            //creates a tree with a empty node
                    cout << "Creating a new Tree!" << endl;
                    root = new BSTreeT<string>;
                    cout << "Tree Created, of Size = " << root->GetSize() << endl;
                }
                else if(command == 'F' || command == 'f'){                  //checks if in bst and responds t or f
                    getline(In, word);
                    cout << "Searching for: " << word << endl;
                    if(root->Exists(word) == true   ){
                        cout << " Search Value was found in our tree!" << endl;
                    }
                    else {
                        cout << "Value Not Found!" << endl;
                    };
                }
                else if(command == 'G' || command == 'g'){                      //checks for value in bst and if it does returns that value;
                    getline(In, word);
                    cout << "Retrieving: " << word << endl;
                    if(root->Get(word)!=NULL){
                        cout << word << " successfully returned from tree "  << endl;
                    }
                    else {
                        cout << "Not in Tree, return value is NULL" << endl;     //error message
                    }
                }
                else if(command == 'N' || command == 'n'){      //node counter
                    cout << "Counting Nodes in Tree!" << endl;   
                    cout << " Tree has " << root->GetSize() <<" nodes" << endl;
                }
                else if(command == 'I' || command == 'i'){     //inserts
                    getline(In, word);
                    cout << "Inserting: " << word << endl;
                    root->Insert(word);
                    cout << "Insertion Completed!"<<endl;   //happy affirmation message
                    cout<< "Size of: " << root->GetSize() << " returned" <<endl;
                }
                else if(command == 'E' || command == 'e'){
                    cout << "Printing out Tree backwards!" << endl;
                    if(root->GetSize() == 0){
                        cout<< "        Tree is empty!!" << endl;
                    }
                    else { 
                        cout << "Backwards: " << root->ToStringBackwards() << endl;
                    }    //prints out nodes in reverse /post order.
                } else {
                    
                }
        }
    }
    
    In.close(); //we gotta close our file before we leave duhhhhhh.
}