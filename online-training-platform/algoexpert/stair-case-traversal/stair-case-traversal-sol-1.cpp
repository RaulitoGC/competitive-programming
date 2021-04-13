using namespace std;

// Time : O(n^k) | Space: O(n)
int staircaseTraversalHelper(int height, int maxSteps){
	if(height <= 1) return 1;
	
	int total = 0;
	for(int i = 1 ; i <= min(maxSteps, height) ; i++){
		total += staircaseTraversalHelper(height - i, maxSteps);
	}
	return total;
}

int staircaseTraversal(int height, int maxSteps) {
  
  return staircaseTraversalHelper(height, maxSteps);
}

