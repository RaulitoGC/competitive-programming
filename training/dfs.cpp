#include <bits/stdc++.h>
using namespace std;

struct Node{
  int val;
  Node* left;
  Node* right;
  Node(int _val): val(_val), left(nullptr), right(nullptr){};
  Node(int _val, Node* _left, Node* _right): val(_val), left(_left), right(_right){};
};

class Tree{
  public :
    Tree(){}

    // VAL - LEFT - RIGHT
    // Time complexity = O(n): traverse all the nodes
    // Space complexity = O(n): The function stack
    void dfs_preorder(Node* root){
      if(root != NULL){
        cout << root->val << " ";
        dfs_preorder(root->left);
        dfs_preorder(root->right);
      }
    }

    // LEFT - VAL - RIGHT
    // Time complexity = O(n): traverse all the nodes
    // Space complexity = O(n): The function stack
    void dfs_inorder(Node* root){
      if(root != NULL){
        dfs_inorder(root->left);
        cout << root->val << " ";
        dfs_inorder(root->right);
      }
    }

    // LEFT RIGHT VAL
    // Time complexity = O(n): traverse all the nodes
    // Space complexity = O(n): The function stack
    void dfs_postorder(Node* root){
      if(root != NULL){
        dfs_postorder(root->left);
        dfs_postorder(root->right);
        cout << root->val << " ";
      }
    }

    void dfs_iterative(Node* node){
      stack<Node*> s;
      s.push(node);
      while(!s.empty()){
        Node* current = s.top();
        s.pop();
        

        if(current->right != NULL){
          s.push(current->right);
        }
        cout << current->val <<" ";
        if(current->left != NULL){
          s.push(current->left);
        }
      }
    }
};



int32_t main(){
  Tree* tree = new Tree();
  
  Node* node = new Node(10, new Node(5, new Node(2), new Node(6)), new Node(12, new Node(11), new Node(14)));
  tree->dfs_preorder(node);
  cout << endl;
  tree->dfs_inorder(node);
  cout << endl;
  tree->dfs_postorder(node);
  cout << endl;
  tree->dfs_iterative(node);
}