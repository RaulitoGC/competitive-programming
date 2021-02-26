#include <vector>
using namespace std;

// Time : O(n + m)
// Space : O(1)
vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
  
	int row = matrix.size() - 1;
	int col = 0;
	
	while( col < matrix[0].size() && row >= 0){
		if(matrix[row][col] > target){
			row--;
		}else if(matrix[row][col] < target){
			col++;
		}else{
			return {row,col};
		}
	}
	
  return {-1,-1};
}

