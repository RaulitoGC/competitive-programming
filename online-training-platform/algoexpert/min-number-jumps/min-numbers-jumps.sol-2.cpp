#include <vector>
using namespace std;

int minNumberOfJumps(vector<int> array) {
  
	pair<int,int> interval = {0,0};
	int n = array.size();
	int jumps = 0;
	while(true){
		
		int maxReach = -1;
		for(int i = interval.first ; i <= interval.second ; i++){
			maxReach = max(maxReach, i + array[i]);
		}		
				
		if(interval.second >= n - 1){
			break;
		}
		
		interval = make_pair(interval.second + 1, maxReach);
			jumps++;
	}
  return jumps;
}

