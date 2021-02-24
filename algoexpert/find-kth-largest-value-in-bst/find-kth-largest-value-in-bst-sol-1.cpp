using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

void findKthLargestValueInBstHelper(BST* tree, int k, vector<int> &v){
	if(tree != nullptr){
		findKthLargestValueInBstHelper(tree->left, k, v);
		v.push_back(tree->value);
		findKthLargestValueInBstHelper(tree->right, k, v);
	}
}

int findKthLargestValueInBst(BST *tree, int k) {
  vector<int> v;
	findKthLargestValueInBstHelper(tree, k, v);
	int size = v.size();
	for(int num: v){
		cout << num <<" ";
	}
  return v[size - k];
}

