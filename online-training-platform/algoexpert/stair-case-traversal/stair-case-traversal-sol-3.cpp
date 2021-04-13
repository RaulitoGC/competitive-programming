using namespace std;

//Time : O(n) | Space: o (n)
int staircaseTraversal(int height, int maxSteps) {
  int currentNumberOfWays = 0;
	vector<int> waysToTop = {1};
	for(int currentHeight = 1 ; currentHeight < height + 1 ; currentHeight++){
		int startWindowIdx = currentHeight - maxSteps - 1;
		int endWindowIdx = currentHeight - 1;
		
		if(startWindowIdx >= 0){
			currentNumberOfWays -= waysToTop[startWindowIdx];
		}
		
		currentNumberOfWays += waysToTop[endWindowIdx];
		
		waysToTop.push_back(currentNumberOfWays);
	}
  return waysToTop[height];
}

