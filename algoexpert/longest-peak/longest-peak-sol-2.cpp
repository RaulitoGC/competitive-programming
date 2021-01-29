#include <bits/stdc++.h>

using namespace std;

// Time : O(n)
// Space: O(1)
int longestPeak(vector<int> array) {
  if(array.empty()) return 0;
	
	int idx = 1;
	int res = 0;
	int size = array.size();
	while(idx < size - 1){
		bool isPeak = (array[idx] > array[idx - 1]) && (array[idx] > array[idx + 1]);
		
		if(!isPeak){
			idx++;
			continue;
		}
		
		int prev = idx;
		int next = idx;
		while( prev > 0 && array[prev - 1] < array[prev]){
			prev--;
		}
		
		while(next < size - 1 && array[next] > array[next + 1]){
			next++;
		}
		cout << prev << " "<< next << endl;
		int peakSize = next - prev + 1;
		res = max(res, peakSize);
		
		idx = next;
	}
	
	
  return res;
}

