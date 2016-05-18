#include "bs_treet.h"

int main(int argc, const char* argv[]){
    
    string word;
    if (argv[1] == ""){
        cout<< "No File Specified from Console argument!"<<endl;
        cout<<"Please try to open the file again with a valid file name appended at the end"<<endl;

    }
    cout << "Lets GO!"<< endl;
  
    
    // Initialize and open InputFile
    ifstream InputFile;
    InputFile.open(argv[1]);
    BSTreeT<string> rootnode;
    BSTreeT<string> *root;
    
    if(InputFile.is_open()){
        while(!InputFile.eof()){
            char command = InputFile.get();
            
            if (command == 35){                 //ignores # line
                getline(InputFile, word);
               }
            
                else if(command == 'O' || command == 'o'){
                    cout << "Print out Tree in forwards direction!" << endl;
                    if(root->GetSize() == 0){
                        cout<< "Tree is empty!!" << endl;
                    }
                    else { 
                        cout << "Foward:" << root->ToStringForwards() << endl;
                    }
                }
                else if(command == 'X' || command == 'x'){
                    root->Clear();
                    cout << "All leaves cleared successfully!" << endl;
                }
                else if(command == 'R' || command == 'r'){
                    getline(InputFile, word);
                    cout << "Removing" << word << " from Tree!" << endl;
                    if(root->Exists(word)){
                        root->Remove(word);
                        cout << "Removal was successful!"<<endl;
                         cout<< "Size of: " << root->GetSize() << " returned" <<endl;
                    }
                    else {
                        cout << "Removal Failed!"<<endl;
                        cout<< word << " was not located." << endl;
                    }
                }
                else if(command == 'D' || command == 'd'){
                    cout << "Deleting all leaves/Tree" << endl;
                    root->~BSTreeT();
                    if(root->GetSize() != 0){
                        cout << "Removal failure size not 0!"<<endl;
                        cout<< "Size returned as: " << root->GetSize() << endl;
                    } else {
                        cout << "Removal successful! Size = 0" << endl;
                    }
                }
                else if(command == 'C' || command == 'c'){
                    cout << "Creating a new Tree!" << endl;
                    root = new BSTreeT<string>;
                    cout << "Tree Created, of Size = " << root->GetSize() << endl;
                }
                else if(command == 'F' || command == 'f'){
                    getline(InputFile, word);
                    cout << "Searching for: " << word << endl;
                    if(root->Exists(word) == true   ){
                        cout << " Search Value was found in our tree!" << endl;
                    }
                    else {
                        cout << "Value Not Found!" << endl;
                    };
                }
                else if(command == 'G' || command == 'g'){
                    getline(InputFile, word);
                    cout << "Retrieving: " << word << endl;
                    if(root->Get(word)!=NULL){
                        cout << word << " successfully returned from tree "  << endl;
                    }
                    else {
                        cout << "Not in Tree, return value is NULL" << endl;
                    }
                }
                else if(command == 'N' || command == 'n'){
                    cout << "Counting Nodes in Tree!" << endl;
                    cout << " Tree has " << root->GetSize() <<" nodes" << endl;
                }
                else if(command == 'I' || command == 'i'){
                    getline(InputFile, word);
                    cout << "Inserting: " << word << endl;
                    root->Insert(word);
                    cout << "Insertion Completed!"<<endl;
                    cout<< "Size of: " << root->GetSize() << " returned" <<endl;
                }
                else if(command == 'E' || command == 'e'){
                    cout << "Printing out Tree backwards!" << endl;
                    if(root->GetSize() == 0){
                        cout<< "        Tree is empty!!" << endl;
                    }
                    else { 
                        cout << "Backwards: " << root->ToStringBackwards() << endl;
                    }
                } else {
                    
                }
        }
    }
    
    InputFile.close();
}