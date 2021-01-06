#include <bits/stdc++.h>
using namespace std;

struct Node{
  int val;
  Node* left;
  Node* right;
  Node(int _val): val(_val), left(nullptr), right(nullptr){};
  Node(int _val, Node* _left, Node* _right): val(_val), left(_left), right(_right){};
};

class BST{
  private:
    Node* root;

    void print_preorder(Node* root){
      if(root != NULL){
        cout << root->val << endl;
        print_preorder(root->left);
        print_preorder(root->right);
      }
    }

    void print_inorder(Node* root){
      if(root != NULL){
        print_inorder(root->left);
        cout << root->val << " ";
        print_inorder(root->right);
      }
    }

    void print_post_order(){

    }

    void print_bfs(){

    }

  public :
    BST(){}

    void insert(Node* root, int val){
      if(val < root->val){
        if(root->left != NULL){
          insert(root->left, val);
        }else{
          root->left = new Node(val);
        }
      }else if(root->val < val){
        if(root->right != NULL){
          insert(root->right, val);
        }else{
          root->right = new Node(val);
        }
      }else{
        // do not nothing if the value exist
      }
    }

    bool search(Node* root, int val){
      if(val < root->val){
        if(root->left != NULL){
          return search(root->left, val);
        }else{
          return false;
        }
      }else if(root->val < val){
        if(root->right != NULL){
          return search(root->right, val);
        }else{
          return false;
        }
      }else{
        return true;
      }
      return false;
    }

    void remove(Node* root, int val){

    }

    void print(Node* root){
      print_inorder(root);
    }
    
};


int32_t main(){

  Node* root = new Node(10, new Node(8, new Node(7), nullptr), new Node(12));
  BST* bst = new BST();
  //bst->print(root);
  cout << bst->search(root, 9) << endl;
  bst->insert(root, 9);
  cout << endl;
  cout << bst->search(root, 9) << endl;
  //bst->print(root);
}