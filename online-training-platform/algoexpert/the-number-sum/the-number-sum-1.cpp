#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
	vector<vector<int>> res;
  for(int i = 0 ; i < array.size() ; i++){
		for(int j = i + 1 ; j < array.size() ; j++){
			for(int k = j+1 ; k < array.size()  ; k++){
				if(array[i] + array[j] + array[k] == targetSum){
					vector<int> current = {array[i], array[j], array[k]};
					sort(current.begin(), current.end());
					res.push_back(current);
				}
			}
		}
	}
	sort(res.begin(), res.end());
	return res;
}

