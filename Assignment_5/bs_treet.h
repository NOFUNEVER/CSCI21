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

template <class T>
  class BSTreeT {
    
    public:
    
      BSTreeT(int value =0 )
      : root_(NULL),
      size_(value){}

      ~BSTreeT(){
      Clear();
      }
  
      void Clear(){   //clears node
       Clear(root_);
      }
  
      int GetSize() const {
      return size_;
      }

      string ToStringForwards(){
      return ToStringForwards(root_);
      } 

      string ToStringBackwards(){
      return ToStringBackwards(root_);
      }

      BSTNodeT<T>* Get(const T& value){
      Get(value, root_);
      }

      bool Insert(T value){ //insert function for a tree
      return Insert(value, root_);
      }

      bool Remove(T value){ //remove function for our tree
      return Remove(value, root_);
      }

      T FindMin(){       //finds the min value 
        if (root_ == NULL){
        return 0;
        }
        return FindMin(root_);
      }

      unsigned int size() const {   //gets size without allowing it to change
      return size_;
      }
      
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

      BSTNodeT<T>* root_;
      unsigned int size_;
  
      string InOrder(BSTNodeT<T>* root){  //lists tree inorder from root
        stringstream ss;
        if (root != NULL){
          ss << InOrder(root->GetLeft());
          ss << root->GetContents() << " ";
          ss << InOrder(root->GetRight());
        }
        return ss.str();
        }
    
      bool Insert(T value, BSTNodeT<T>*& root){  //our actual insert function
        if (root == NULL){
          root = new BSTNodeT<T>(value);
          size_++;
          return true;
        }
        else if(value == root->GetContents()){
        return true;
        }
        else if (value < root->GetContents()){
        return Insert(value, root->GetLeft());
        } else if (value > root->GetContents()){
        return Insert(value, root->GetRight());
        }
        return false;
        }
      
      T FindMin(BSTNodeT<T>* root) const {  //find min wihtout modifying
        if (root->GetLeft() != NULL){
      return FindMin(root->GetLeft());
    }
          return root->GetContents();
        }
    
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
     }
  
      BSTNodeT<T>* Get(const T& value, BSTNodeT<T>*& root){
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
      }
  
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
      }
    
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
        }
    
};

#endif /* BS_TREE_H */























