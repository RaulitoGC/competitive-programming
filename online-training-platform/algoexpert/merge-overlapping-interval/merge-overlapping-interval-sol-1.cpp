#include <vector>
using namespace std;


//Time: O(nLogn)
// Space: O(n)
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  vector<vector<int>> res;
	if(intervals.empty()) return res;
	
	sort(intervals.begin(), intervals.end(), [](vector<int> v1, vector<int> v2) {
        return (v1[0] == v2[0])? v1[1] <= v2[1] : v1[0] <= v2[0];
    });
	
	int n = intervals.size();
	int init = intervals[0][0];
	int end = intervals[0][1];
	for(int i = 1 ; i < n ; i++){
		if(intervals[i][0] > end){
			res.push_back({init, end});
			init = intervals[i][0];
			end = intervals[i][1];
		}else{
			end = max(end, intervals[i][1]);
		}
	}
	
	res.push_back({init,end});
	
  return res;
}

