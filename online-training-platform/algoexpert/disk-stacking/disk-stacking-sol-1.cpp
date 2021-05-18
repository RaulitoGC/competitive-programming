#include <vector>
using namespace std;


vector<vector<int>> buildSequence(vector<vector<int>> disks, 
																	vector<int> sequence, int lastIdxInserted){
	
	vector<vector<int>> result;
	
	while(lastIdxInserted != -1){
		result.insert(result.begin(), disks[lastIdxInserted]);
		lastIdxInserted = sequence[lastIdxInserted];
	}
	
	return result;
}

vector<vector<int>> diskStacking(vector<vector<int>> disks) {
  
	sort(disks.begin(), disks.end(),
			[](vector<int> &a, vector<int> &b){ return a[2] < b[2];});
	
	int n = disks.size();
	
	vector<int> heights;
	for(int i = 0 ; i < n ; i++){
		heights.push_back(disks[i][2]);
	}
	
	vector<int> sequence(n, -1);
	
	int maxHeightIdx = 0;
	for(int i = 1 ; i < n ; i++){
		
		int currentWidth = disks[i][0];
		int currentDepth = disks[i][1];
		int currentHeight = disks[i][2];
		
		for(int j = 0 ; j < i ; j++){
			
			int width = disks[j][0];
			int depth = disks[j][1];
			int height = disks[j][2];
			
			if(width < currentWidth && depth < currentDepth && height < currentHeight){
				
				if(heights[i] <= currentHeight + heights[j]){
					heights[i] = currentHeight + heights[j];	
					sequence[i] = j;
				}
			}
		}
		
		if(heights[i] >= heights[maxHeightIdx]){
			maxHeightIdx = i;
		}
	}
	
  return buildSequence(
		disks,
		sequence,
		maxHeightIdx
	);
}

