#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  set<vector<int>> res;
	int size = array.size();
	unordered_set<int> us;
	for(int i = 0 ; i < size ;i++){
		us.insert(array[i]); // O(N)
	}
	
	int newTarget;
	for(int i = 0 ; i < size ; i++){
		for(int j = i + 1; j < size ; j++){
			newTarget = targetSum - (array[i] + array[j]);
			if(newTarget != array[i] && newTarget != array[j] && us.find(newTarget) != us.end()){
				vector<int> triplet = {array[i], array[j], newTarget};
				sort(triplet.begin(), triplet.end());
				res.insert(triplet);
			}
		}
	}

  return vector<vector<int>>(res.begin(), res.end());
}

