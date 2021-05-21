#include <vector>
using namespace std;

int maximumSumSubmatrix(vector<vector<int>> matrix, int size) {
  
	int n = matrix.size();
	int m = matrix[0].size();
	
	vector<vector<int>> matrixSum(n , vector<int>(m, 0));
	
	matrixSum[0][0] = matrix[0][0];
	for( int j = 1 ; j < m ; j++){
		matrixSum[0][j] = matrix[0][j] + matrixSum[0][j-1];
	}
	
	for( int i = 1 ; i < n ; i++){
		matrixSum[i][0] = matrix[i][0] + matrixSum[i - 1][0];
	}
	
	for( int i = 1 ; i < n ; i++){
		for(int j = 1 ; j < m ; j++){
			matrixSum[i][j] = matrixSum[i-1][j] + matrixSum[i][j-1] - matrixSum[i - 1][j - 1] + matrix[i][j];
		}
	}
	
	int maxSum = INT_MIN;
	
	for( int i = size - 1 ; i < n ; i++){
		for(int j = size - 1 ; j < m ; j++){
			
			int currentSum = matrixSum[i][j];
			
			if(i - size >= 0){
				currentSum -= matrixSum[i-size][j];
			}
			
			if(j - size >= 0){
				currentSum -= matrixSum[i][j-size];
			}
			
			if(j-size >=0 && i-size >=0){
				currentSum += matrixSum[i-size][j-size];
			}
			cout << currentSum << endl;
			maxSum = max(maxSum, currentSum); 
		}
	}
	
  return maxSum;
}

