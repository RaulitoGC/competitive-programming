#include <vector>
using namespace std;

int laptopRentals(vector<vector<int>> times) {
	
	if(times.empty()) return 0;
	
  int maxTime = INT_MIN;
	int n = times.size();
	for(int i = 0 ; i < n ; i++){
		if(maxTime < times[i][1]){
			maxTime = times[i][1];
		}
	}
	
	vector<int> hours(maxTime, 0);
	int maxParallelLaptops = 0;
	
	for(int i = 0 ; i < n ; i++){
		for(int start = times[i][0]; start < times[i][1] ; start++){
			hours[start]++;
			if(maxParallelLaptops < hours[start]){
				maxParallelLaptops = hours[start];
			}
		}
	}
	
  return maxParallelLaptops;
}

