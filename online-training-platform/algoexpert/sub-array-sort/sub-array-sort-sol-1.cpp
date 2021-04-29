#include <vector>
using namespace std;

bool isOutOfOrder(int index, int number, vector<int> array){
	if(index == 0) return number > array[index + 1];
	else if(index == array.size() - 1) return number < array[index - 1];
	else return array[index - 1] > number || number > array[index + 1];
}

vector<int> subarraySort(vector<int> array) {
  
	int n = array.size();
	
	int maxOutOfOrder = INT_MIN, minOutOfOrder = INT_MAX, number;
	
	for(int i = 0 ; i < n ;i++){
			number = array[i];
			if(isOutOfOrder(i, number, array)){
				minOutOfOrder = min(minOutOfOrder, number);
				maxOutOfOrder = max(maxOutOfOrder, number);
			}
	}
	
	if(maxOutOfOrder == INT_MIN && minOutOfOrder == INT_MAX){
		return {-1, -1};
	}
	
	int subArrayLeftIndex = 0;
	while(minOutOfOrder >= array[subArrayLeftIndex]){
		subArrayLeftIndex++;
	}
	
	int subArrayRightIndex = n - 1;
	while(maxOutOfOrder <= array[subArrayRightIndex]){
		subArrayRightIndex--;
	}
	
  return {subArrayLeftIndex, subArrayRightIndex};
}

