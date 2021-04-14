using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

// Time O(V)
// Space O(  V)
void helper(BinaryTree* root, int acum, vector<int> *res){
	if(root != NULL){
		if(root->left == NULL && root->right == NULL){
			res->push_back(root->value + acum);
			return;
		}
		helper(root->left, acum + root->value, res);
		helper(root->right, acum + root->value, res);
	}
}

vector<int> branchSums(BinaryTree *root) {
	vector<int> res;
  helper(root, 0, &res);
  return res;
}

