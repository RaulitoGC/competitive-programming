#include <vector>
#include<bits/stdc++.h>

using namespace std;

//Time : O(N)
// Space : O(n)
vector<int> arrayOfProducts(vector<int> array) {
	int size = array.size();
  vector<int> prev(size);
	vector<int> next(size);
	vector<int> res(size);
	
	prev[0] = array[0];
	for(int i = 1 ; i < size ; i++){
			prev[i] = prev[i-1]*array[i];
	}
	
	next[size - 1] = array[size - 1];
	for(int i = size - 2 ; i >= 0 ; i--){
			next[i] = next[i+1]*array[i];
	}
	
	for(int i = 0 ; i < size ; i++){
		int m1 = (i - 1 >= 0)? prev[i - 1] : 1;
		int m2 = (i + 1 < size)? next[i + 1] : 1;
		
		res[i] = m1*m2;
	}
	
	return res;
}