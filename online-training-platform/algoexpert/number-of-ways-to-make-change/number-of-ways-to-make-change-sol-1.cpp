#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {

	vector<int> ways(n + 1,0);
	ways[0] = 1;
	
	for(int i = 0 ; i < denoms.size() ; i++){
		for(int j = denoms[i] ; j < n + 1 ; j++){
			ways[j] += ways[j - denoms[i]];
		}
	}
	
  return ways[n];
}

