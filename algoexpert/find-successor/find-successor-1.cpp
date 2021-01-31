#include <bits/stdc++.h>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

void findSuccessorHelper(BinaryTree* root, BinaryTree* node, bool &found, BinaryTree* &res) {
  if(root != NULL){
		findSuccessorHelper(root->left, node, found, res);
		if(found){
			res = root;
			found = false;
			return;
		}
		if(root->value == node->value){
			found = true;
		}
		
		findSuccessorHelper(root->right, node, found, res);
	}
}


BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
	BinaryTree* res = nullptr;
	bool found = false;
  findSuccessorHelper(tree, node, found, res);
	return res;
}

