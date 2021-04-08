#include <vector>
using namespace std;

vector<vector<int>> powerset(vector<int> array) {
  vector<vector<int>> subsets = {{}};
	int n = array.size();
	for(int i = 0 ; i < n ; i++){
		int size = subsets.size();
		for(int j = 0 ; j < size ; j++){
			vector<int> current = subsets[j];
			current.push_back(array[i]);
			subsets.push_back(current);
		}
	}
  return subsets;
}

