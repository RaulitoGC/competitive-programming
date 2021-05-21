#include <vector>
using namespace std;

int maximizeExpression(vector<int> array) {
	int n = array.size();
	if(n < 4){
		return 0;
	}
	int maxSum = INT_MIN;
  for(int i = 0 ; i < n ; i++){
		for(int j = i + 1 ; j < n ; j++){
			for(int k = j + 1 ; k < n ; k++){
				for(int l = k + 1 ; l < n ; l++){
					maxSum = max(maxSum, array[i] - array[j] + array[k] - array[l]);
				}
			}
		}
	}
  return maxSum;
}

