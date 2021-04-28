#include <vector>
using namespace std;

// Time : O(n^4)
// Space : O(k), k = #quadruplets
vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
	
	vector<vector<int>> quadruplets;
	
	int n = array.size();
	
  for(int i = 0 ; i < n ; i++){
		for(int j = i + 1 ; j < n ; j++){
			for(int k = j + 1 ; k < n  ; k++){
				for(int l = k + 1 ; l < n ; l++){
					if(array[i] + array[j] + array[k] + array[l] == targetSum){
						quadruplets.push_back({array[i], array[j], array[k], array[l]});
					}
				}
			}
		}
	}
  return quadruplets;
}

