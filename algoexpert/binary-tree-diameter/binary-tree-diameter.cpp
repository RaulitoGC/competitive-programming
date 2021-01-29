using namespace std;

// This is an input class. Do not edit.
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

// Time : O(n)
// Space: O(d), longest child
int binaryTreeDiameterHelper(BinaryTree* tree, int height, int &res){
	if(tree != NULL){
		if(tree->left == NULL && tree->right == NULL){
			return height;
		}
		
		int left = (tree->left != NULL)?binaryTreeDiameterHelper(tree->left, height + 1, res) : height;
		int right = (tree->right != NULL)?binaryTreeDiameterHelper(tree->right, height + 1, res) : height;
		
		res = max(res, (right - height) + (left - height));
		return max(right,left);
	}
	
	return height;
}

int binaryTreeDiameter(BinaryTree *tree) {
  int res = 0;
	binaryTreeDiameterHelper(tree, 0, res);
  return res;
}