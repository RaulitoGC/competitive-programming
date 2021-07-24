#include <vector>
#include <unordered_map>

using namespace std;


int getMaxDistance(unordered_map<string, int> distances){
	int maxDistance = INT_MIN;
	for(auto it = distances.begin() ; it != distances.end() ; it++){
		if(it->second != INT_MAX){
			maxDistance = max(maxDistance, it->second);	
		}
	}
	return maxDistance;
}


// Time : O(b^2*r)
// Space: O(r)
int apartmentHunting(vector<unordered_map<string, bool>> blocks,
                     vector<string> reqs) {
	
	int res = INT_MAX;
	int resIdx = -1;
	int b = blocks.size();
	int r = reqs.size();
	for(int i = 0 ; i < b ; i++){
		unordered_map<string, int> distances;
		for(int k = 0 ; k < r ; k++){
			distances[reqs[k]] = INT_MAX;
			for(int j = 0 ;  j < b ; j++){
				if(blocks[j][reqs[k]]){
					distances[reqs[k]] = min(distances[reqs[k]], abs(i - j));
				}
			}
		}
		
		int maxDistance = getMaxDistance(distances);
		if(maxDistance < res){
			res = maxDistance;
			resIdx = i;
		}
		
	}

  return resIdx;
}

