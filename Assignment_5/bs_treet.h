/*
 * Name        : BS_TREE header
 * Author      : Jason K Lamphere
 * Description : creating a BST Node for a tree.
 * Sources     : ide.c9.io/nofunever/csci21   github.com/nofunever/csci21
 */

#ifndef BS_TREE_H
#define BS_TREE_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <istream>
#include "bst_nodet.h"


using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

template <class T>                                            //templated bst can accept any data type
  class BSTreeT {
    
    public:
    
      BSTreeT(int value =0 )   //default contructor
      : root_(NULL),
      size_(value){}

      ~BSTreeT(){
      Clear();
      }           // destructor
  
      void Clear(){   //clears node
       Clear(root_);
      }         // clear function/for destructor
  
      int GetSize() const {
      return size_;
      } //size accessor

      string ToStringForwards(){
      return ToStringForwards(root_);
      }    //prints leaves in order

      string ToStringBackwards(){
      return ToStringBackwards(root_);
      }   //prints leaves backwards

      BSTNodeT<T>* Get(const T& value){
      Get(value, root_);
      } //searches for a node with a value and returns said value if found.

      bool Insert(T value){ //insert function for a tree
      return Insert(value, root_);
      }    //inserts a node into the properly sorted location

      bool Remove(T value){ //remove function for our tree
      return Remove(value, root_);
      }   //removes a node and from our tree

      T FindMin(){       //finds the min value 
        if (root_ == NULL){
        return 0;
        }
        return FindMin(root_);
      }     //finds our smallest node

      string InOrder(){  //lists tree nodes in order
      return InOrder(root_);
      }

      bool Exists(T value){
        if(Get(value) == NULL ){
        return false;
        }else if(Get(value) !=NULL){
        return true;
        }
      }

      

    protected:

      BSTNodeT<T>* root_;      //root node pointer
      unsigned int size_;      //size varaible
  
      string InOrder(BSTNodeT<T>* root){  //lists tree inorder from root
        stringstream ss;
        if (root != NULL){                //if its not empty
          ss << InOrder(root->GetLeft());  //check left
          ss << root->GetContents() << " "; 
          ss << InOrder(root->GetRight()); //check right
        }
        return ss.str(); //return ss
        }
    
      bool Insert(T value, BSTNodeT<T>*& root){  //our actual insert function
        if (root == NULL){                  //root is emtpy make node add size and return true
          root = new BSTNodeT<T>(value);
          size_++;
          return true;
        }
        else if(value == root->GetContents()){                        //if its already in the bst return true and do nothing... bst by definition can't have repeat enteries.
        return true;
        }
        else if (value < root->GetContents()){                                    //if its smaller go left
        return Insert(value, root->GetLeft());
        } else if (value > root->GetContents()){
        return Insert(value, root->GetRight());                                 //larger go right
        }
        return false;
        }    
      
      T FindMin(BSTNodeT<T>* root) const {  //find min wihtout modifying
        if (root->GetLeft() != NULL){
      return FindMin(root->GetLeft());
    }
          return root->GetContents();
        }                               //finds our min value
    
      bool Remove(const T& value, BSTNodeT<T>*& root){  //our actual remove function
        if (root == NULL){
          return false;
        } else if (root->GetContents() == value){
            if (root->GetLeft() == NULL && root->GetRight()== NULL){
              delete root;
              root = NULL;
              size_--;
            } else if (root->GetLeft() != NULL && root->GetRight() != NULL){
              T temp = FindMin(root->GetRight());
              root->SetContents(temp);
              Remove(temp, root->GetRight());
              } else{
                BSTNodeT<T>* temp = root;
                if (root->GetLeft() != NULL){
                  root = root->GetLeft();
                  delete temp;
                } else if (root->GetRight() != NULL){
                  root = root->GetRight();
                  delete temp;
                  }
              }
          return true;
        } else if (value > root->GetContents()){
          return Remove(value, root->GetRight());
          } else {
            return Remove(value, root->GetLeft());
            }
     }                         //removal function
  
      BSTNodeT<T>* Get(const T& value, BSTNodeT<T>*& root){                                    //looks for a ndoe with a value and then returns the value of the node to confirm for testing
        if(value == root->GetContents()||  root== NULL ){
          return root;
        } else if(root->GetLeft()!=NULL && value < root->GetContents()  ){
          return Get(value,root->GetLeft());
          } else if(root->GetRight()!=NULL&&value > root->GetContents() ){
            return Get(value,root->GetRight());
            }
      }
      
      string ToStringForwards(BSTNodeT<T>*& root){
        stringstream ss;
      
        if (root != NULL){
          if (root->GetLeft() == NULL && root->GetRight() == NULL){
            ss<<root->GetContents();
            return ss.str();
          }
          if(root->GetLeft() != NULL){
            ss << ToStringForwards(root->GetLeft()) << ", ";
          }
          ss <<  root->GetContents();               
            if(root->GetRight() != NULL){                                               
              ss << ", "<< ToStringForwards(root->GetRight());      
            }                                                   
          return ss.str();                                    
        } else{    
          return "";
          }
      }                                  //reads our bst pre order
  
      string ToStringBackwards(BSTNodeT<T>*& root){
        stringstream ss;
        if (root != NULL){
          if (root->GetLeft() == NULL && root->GetRight() == NULL){
            ss<<root->GetContents();
            return ss.str();
          }
          if(root->GetRight() != NULL){
          ss  << ToStringBackwards(root->GetRight())<< ", ";
          }
          ss << root->GetContents();
          if(root->GetLeft() != NULL){     
            ss << ", "<< ToStringBackwards(root->GetLeft()) ;     
          }                                           
          return ss.str();                          
        } else{    
          return "";
          }
      }                                 //post order
    
      void Clear(BSTNodeT<T>*& root){  //full clear function
        if (root != NULL){
          Clear(root->GetLeft());
          Clear(root->GetRight());
          delete root;
          root = NULL;
          size_--;
        } else if(root_== NULL&&size_>0){
            size_--;
          }  
        }                                                 //clears the tree
    
};

#endif /* BS_TREE_H */























