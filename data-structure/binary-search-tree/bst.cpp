#include <bits/stdc++.h>
using namespace std;

class BST{
  public :

    int value;
    BST* left;
    BST* right;

    BST(int _value){
      value = _value;
    }

    // Average : Time -> O(log(n)), Space -> O(1)
    // Worst Case: Time -> O(n), space -> O(1)
    void insert(int newValue){
      if(newValue < value){
        if(left != NULL){
          left->insert(newValue);
        }else{
          left = new BST(newValue);
        }
      }else if(value < newValue){
        if(right != NULL){
          right->insert(newValue);
        }else{
          right = new BST(newValue);
        }
      }else{
        // do not nothing if the value exist
      }
    }

    // Average : Time -> O(log(n)), Space -> O(1)
    // Worst Case: Time -> O(n), space -> O(1)
    bool search(int value){
      if(value < this->value){
        if(left != NULL){
          return left->search(value);
        }else{
          return false;
        }
      }else if(this->value < value){
        if(right != NULL){
          return right->search(value);
        }else{
          return false;
        }
      }else{
        return true;
      }
      return false;
    }

    int getMinValue(){
      if(left != NULL){
        return left->getMinValue();
      }else{
        return value;
      }
    }

    void remove(int value, BST* parent){
      if(value < this->value){
        if(right != NULL){
          right->remove(value, this);
        }
      }else if( this->value < value){
        if(left != NULL){
          left->remove(value, this);
        }
      }else{
        if(left != NULL && right != NULL){
          value = right->getMinValue();
          right->remove(value, this);
        }
      }
    }    
};


int32_t main(){

  BST* bst = new BST(10);
  bst->left = new BST(8);
  
}