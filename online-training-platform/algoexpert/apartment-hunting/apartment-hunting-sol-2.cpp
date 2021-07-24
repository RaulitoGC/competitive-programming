#include <vector>
#include <unordered_map>

using namespace std;


int getMinDistance(
									int b,
									unordered_map<string, vector<int>> distances,
									vector<string> reqs){
	
	int r = reqs.size();
	int res = INT_MAX;
	int resIdx = -1;
	
	for(auto it = distances.begin(); it != distances.end() ; it++){
		cout << it->first << endl;
		for(int idx = 0; idx < (it->second).size() ; idx++){
			cout << (it->second)[idx] << " ";
		}
		cout << endl;
	}
	
	for(int i = 0 ; i < b ; i++){
		int maxDistance = INT_MIN;
		
		for(int k = 0 ;  k < r ; k++){
			if(distances[reqs[k]][i] != INT_MAX){
				maxDistance = max(maxDistance, distances[reqs[k]][i]);	
			}
		}
		
		if(maxDistance < res){
			res = maxDistance;
			resIdx = i;
		}
	}
	
	return resIdx;
}

// Time : O(br)
// Space: O(br)
int apartmentHunting(vector<unordered_map<string, bool>> blocks,
                     vector<string> reqs) {
  
	int b = blocks.size();
	int r =reqs.size();
	
	unordered_map<string, vector<int> > distances;
	
	for(int k = 0 ; k < r ; k++){
		vector<int> distance(b);
		int lastIdxFound = -1;
		
		for(int i = 0 ; i < b ; i++){
			if(blocks[i][reqs[k]]){
				distance[i] = 0;
				lastIdxFound = i;
			}else if( lastIdxFound != -1){
				distance[i] = abs(i - lastIdxFound);
			}else{
				distance[i] = INT_MAX;
			}
		}
		
		lastIdxFound = -1;
		
		for(int i = b - 1 ; i >= 0 ; i--){apa
			if(blocks[i][reqs[k]]){
				distance[i] = 0;
				lastIdxFound = i;
			}else if( lastIdxFound != -1){
				distance[i] = min(distance[i], abs(lastIdxFound - i));
			}else{
				distance[i] = min(INT_MAX, distance[i]);
			}
		}
		
		distances[reqs[k]] = distance;
	}
	
  return getMinDistance(b, distances, reqs);
}

