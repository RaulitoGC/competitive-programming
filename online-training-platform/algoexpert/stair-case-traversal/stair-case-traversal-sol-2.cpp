using namespace std;

// Time : O(n*k) | Space: O(n)
int staircaseTraversalHelper(int height, int maxSteps, unordered_map<int,int> &memoize){
	if(memoize.find(height) != memoize.end()) return memoize[height];
	
	int total = 0;
	for(int i = 1 ; i <= min(maxSteps, height) ; i++){
		total += staircaseTraversalHelper(height - i, maxSteps, memoize);
	}
	return memoize[height] = total;
}

int staircaseTraversal(int height, int maxSteps) {
  unordered_map<int,int> memoize = {{0,1}, {1,1}};
  return staircaseTraversalHelper(height, maxSteps, memoize);
}

