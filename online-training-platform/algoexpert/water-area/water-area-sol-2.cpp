#include <vector>
using namespace std;

int waterArea(vector<int> heights) {
  
	int n = heights.size();
	
	if(n == 0){
		return 0;
	}
	
	int leftIdx = 0, left = heights[leftIdx];
	int rightIdx = n - 1, right = heights[rightIdx];
	
	int dots = 0;
	
	while(leftIdx < rightIdx){
		if(heights[leftIdx] < heights[rightIdx]){
			leftIdx++;
			left = max(left, heights[leftIdx]);
			dots += (left - heights[leftIdx]);
		}else{
			rightIdx--;
			right = max(right, heights[rightIdx]);
			dots += (right - heights[rightIdx]);
		}
		cout << " dotst : " << dots << endl;
	}
	
  return dots;
}

