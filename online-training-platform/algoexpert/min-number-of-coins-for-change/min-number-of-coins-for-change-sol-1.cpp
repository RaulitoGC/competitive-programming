#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
	
	int maxNumber = INT_MAX - n - 1;
	vector<int> minWays(n + 1, maxNumber);
	minWays[0] = 0;
	
  for(int i = 0 ; i < denoms.size() ; i++){
		for(int j = denoms[i] ; j < n + 1 ; j++){
			minWays[j] = min(minWays[j], minWays[j - denoms[i]] + 1);
		}
	}
  return (minWays[n] >= maxNumber)? -1 : minWays[n];
}

