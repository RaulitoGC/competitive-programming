class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

bool validateBstHelper(BST* tree, int minValue, int maxValue){
	if( tree->value < minValue || tree->value >= maxValue){
		return false;
	}
	
	if(tree->left != NULL && !validateBstHelper(tree->left, minValue, tree->value)){
		return false;
	}
	
	if(tree->right != NULL && !validateBstHelper(tree->right, tree->value, maxValue)){
		return false;
	}
	
	return true;
}

bool validateBst(BST *tree) {
  // Write your code here.
  return validateBstHelper(tree, INT_MIN, INT_MAX);
}

