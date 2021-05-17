#include <vector>
using namespace std;

int waterArea(vector<int> heights) {
  
	if(heights.empty()){
		return 0;
	}
	
	int n = heights.size();
	
	vector<int> minLeftRight(n);
	
	int currentLocalMax = heights[0];
	minLeftRight[0] = 0;
	for(int i = 1 ; i < n ; i++){
		int height = heights[i];
		minLeftRight[i] = currentLocalMax;
		if(height > currentLocalMax){
			currentLocalMax = height;
		}
	}

	currentLocalMax = heights[n - 1];
	minLeftRight[n - 1] = 0;
	for(int i = n - 2 ; i >= 0 ; i--){
		int height = heights[i];
		minLeftRight[i] = min(minLeftRight[i], currentLocalMax);
		if(height > currentLocalMax){
			currentLocalMax = height;
		}
	}
	
	int dots = 0;
	for(int i = 0 ; i < n ; i++){
		int height = heights[i];
		if(height < minLeftRight[i]){
			dots += (minLeftRight[i] - height);
		}
	}
	
  return dots;
}

