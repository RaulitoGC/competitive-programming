#include <bits/stdc++.h>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  unordered_set<int> us;
	for(int i = 0 ; i < array.size() ; i++){
		us.insert(array[i]);
	}
	
	for(int i = 0 ; i < array.size() ; i++){
		auto t = us.find(targetSum - array[i]);
		if(t != us.end() && *t != array[i]){
			return {array[i], targetSum - array[i]};
		}
	}

  return {};
}

