#include <vector>
using namespace std;

int leftAreasLessOrEquals(vector<int> buildings, int currentHeight, int position);
int rightAreasLessOrEquals(vector<int> buildings, int currentHeight, int position);


// Time : O(n^2)
// Space: O(1)
int largestRectangleUnderSkyline(vector<int> buildings) {
	
	if(buildings.empty()){
		return 0;
	}
	
  int maxValue = INT_MIN;
	int n = buildings.size();
	
	for(int i = 0 ; i < n ; i++){
		int leftAreas = leftAreasLessOrEquals(buildings, buildings[i], i);
		int rightAreas = rightAreasLessOrEquals(buildings, buildings[i], i);
		cout << buildings[i] << " -- " << leftAreas << " -- " << rightAreas << endl;
		maxValue = max(maxValue, leftAreas + buildings[i] + rightAreas);
	}
  return maxValue;
}

int leftAreasLessOrEquals(vector<int> buildings, int currentHeight, int position){
	int totalArea = 0;
	
	for(int i = position - 1 ; i >= 0; i--){
		if( currentHeight <= buildings[i]){
			totalArea += currentHeight;
		}else{
			break;
		}
	}

	
	return totalArea;
}

int rightAreasLessOrEquals(vector<int> buildings, int currentHeight, int position){
	int totalArea = 0;
	
	for(int i = position + 1 ; i < buildings.size() ; i++){
		if( currentHeight <= buildings[i]){
			totalArea += currentHeight;
		}else{
			break;
		}
	}
	
	return totalArea;
}

