#include <vector>
using namespace std;

int laptopRentals(vector<vector<int>> times) {
  // Write your code here.
	if(times.empty()){
		return 0;
	}
	
	vector<int> startTimes, endTimes;
	int n = times.size();
	
	for(int i = 0 ; i < n ; i++){
		startTimes.push_back(times[i][0]);
		endTimes.push_back(times[i][1]);
	}
	
	sort(startTimes.begin(), startTimes.end());
	sort(endTimes.begin(), endTimes.end());
	
	int startIterator = 0, endIterator = 0, usedLaptops = 0;
	
	while(startIterator < n) {
		if(startTimes[startIterator] >= endTimes[endIterator]){
			usedLaptops--;
			endIterator++;
		}
		
		usedLaptops++;
		startIterator++;
	}
	
  return usedLaptops;
}

