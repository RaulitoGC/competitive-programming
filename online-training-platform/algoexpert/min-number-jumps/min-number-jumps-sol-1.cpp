#include <vector>
using namespace std;

//Time: O(n^2)
// Space: O(n)
int minNumberOfJumps(vector<int> array) {
  
	int n = array.size();
	vector<int> jumps(n, INT_MAX);
	jumps[0] = 0;
	
	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j < i ; j++){
			if(array[j] + j >= i){
				jumps[i] = min(jumps[i], jumps[j] + 1);
			}
		}
	}
	
  return jumps[n - 1];
}

