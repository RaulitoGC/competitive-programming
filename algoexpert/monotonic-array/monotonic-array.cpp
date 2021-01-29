#include <bits/stdc++.h>

using namespace std;

bool isMonotonic(vector<int> array) {
	int size = array.size();
	if(size <= 1) return true;
	int current = array[0];
	bool increasing = false, decreasing = false;
	for(int i = 1 ; i < size ; i++){
		if(array[i] > current){
			increasing = true;
		}else if(array[i] < current){
			decreasing = true;
		}else{
			continue;
		}
		current = array[i];
	}
	return !increasing || !decreasing;
}

