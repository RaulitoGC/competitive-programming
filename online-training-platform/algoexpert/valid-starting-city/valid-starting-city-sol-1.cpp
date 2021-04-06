#include <vector>
using namespace std;



int validStartingCity(vector<int> distances, vector<int> fuel, int mpg) {
  int n = distances.size();
	int remaining = 0;
	
	int res = 0;
	int totalMilesRemaining = 0;
	
	for(int i = 1 ; i < n ; i++){
		int currentDistance = distances[i - 1];
		int currentFuel = fuel[i - 1];
		remaining += currentFuel*mpg - currentDistance;
		if(remaining < totalMilesRemaining){
			totalMilesRemaining = remaining;
			res = i;
		}
	}
	
  return res;
}

