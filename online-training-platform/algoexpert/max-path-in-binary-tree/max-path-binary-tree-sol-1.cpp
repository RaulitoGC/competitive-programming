#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};

pair<int,int> maxPathSumHelper(BinaryTree* tree){
	if(tree == nullptr){
		return make_pair(0, INT_MIN);
	}
	
	pair<int, int> leftMaxSumArray = maxPathSumHelper(tree->left);
	int leftMaxSumAsBranch = leftMaxSumArray.first;
	int leftMaxPathSum = leftMaxSumArray.second;
	
	pair<int, int> rightMaxSumArray = maxPathSumHelper(tree->right);
	int rightMaxSumAsBranch = rightMaxSumArray.first;
	int rightMaxPathSum = rightMaxSumArray.second;
	
	int maxChildSumAsBranch = max(leftMaxSumAsBranch, rightMaxSumAsBranch);
	int maxSumAsBranch = max(maxChildSumAsBranch + tree->value, tree->value);
	int maxSumAsRootNoode = max(
		leftMaxSumAsBranch + tree->value + rightMaxSumAsBranch,
		maxSumAsBranch
	);
	int maxPathSum = max(leftMaxPathSum, max(rightMaxPathSum, maxSumAsRootNoode));
	
	return make_pair(maxSumAsBranch, maxPathSum);
}


// Time :  O(n) : n -> number of nodes
// Space: O(Log(n)) Average / O(n) worst : n -> number of nodes
int maxPathSum(BinaryTree tree) {
	pair<int, int> maxSumArray = maxPathSumHelper(&tree);
  return maxSumArray.second;
}

