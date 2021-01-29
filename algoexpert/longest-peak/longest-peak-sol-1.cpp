#include <bits/stdc++.h>

using namespace std;

// Time : O(n*k), k : number of posible peeks
// Space: O(N)
int longestPeak(vector<int> array) {
	
	if(array.empty()) return 0;
	
	int size = array.size();
  vector<bool> v1(size, true);
	vector<bool> v2(size, true);
	
	for(int i = 0 ; i < size - 1 ; i++){
		v1[i] = (array[i] < array[i+1]);
	}
	
	for(int i = size - 1; i > 0 ; i--){
		v2[i] = (array[i] < array[i-1]);
	}
	
// 	for(int i = 0 ; i < size ; i++){
// 		cout << v1[i] << " ";
// 	}
	
	// cout<<endl;
	int res = 0;
	for(int i = 0 ; i < size ; i++){
		if(!v1[i] && !v2[i]){
			int prev = i - 1;
			int next = i + 1;
			
			while( prev >= 0  && v1[prev]){
				prev--;
			}
			
			while(next < size && v2[next]){
				next++;
			}
			if(prev != i - 1 && next != i + 1){
				res = max(res, next - prev - 1);
			}
		}
	}
	
	return (res < 3)? 0 : res;
}

