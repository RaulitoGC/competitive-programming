#include <vector>
using namespace std;

static bool comp(pair<int,int> p1, pair<int,int> p2){
	return p1.first < p2.first;
}

vector<vector<int>> taskAssignment(int k, vector<int> tasks) {
  
	int n = tasks.size();
	vector<pair<int,int>> v;
	
	for(int i = 0 ; i < n ; i++){
		v.push_back(make_pair(tasks[i], i));	
	}
	
	sort(v.begin(), v.end(), comp);
	vector<vector<int>> res;
	
	for(int i = 0 ; i < n/2 ; i++){
		res.push_back({v[i].second, v[n - i - 1].second});	
	}
	
  return res;
}

