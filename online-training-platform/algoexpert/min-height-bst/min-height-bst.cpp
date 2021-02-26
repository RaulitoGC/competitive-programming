using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == NULL) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == NULL) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

//Time : O(n)
// Space: O(n), 
BST* minHeightBstHelper(vector<int> array, int start, int end){
	if(start > end) return NULL;
	int mid = start + (end - start)/2;
	BST* root = new BST(array[mid]);
	BST* left = minHeightBstHelper(array, start, mid - 1);
	BST* right = minHeightBstHelper(array, mid + 1, end);
	root->left = left;
	root->right = right;
	return root;
}

BST *minHeightBst(vector<int> array) {
  int size = array.size() - 1;
  return minHeightBstHelper(array, 0, size);
}

