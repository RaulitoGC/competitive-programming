#include <bits/stdc++.h>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  sort(arrayOne.begin(), arrayOne.end());
	sort(arrayTwo.begin(), arrayTwo.end());
	vector<int> res(2);
	int minValue = INT_MAX;
	
	int i = 0,j = 0;
	
	while(i < arrayOne.size() && j < arrayTwo.size()){
		int x = arrayOne[i];
		int y = arrayTwo[j];
		
		if( abs(x - y) <= minValue){
			minValue = abs(x-y);
			res[0] = x;
			res[1] = y;
		}
		
		if(x < y){
			i++;
		}else{
			j++;	
		}		
	}
	
	
	
  return res;
}

