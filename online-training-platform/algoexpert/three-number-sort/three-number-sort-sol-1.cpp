#include <vector>
using namespace std;

vector<int> threeNumberSort(vector<int> array, vector<int> order) {
  
	int firstValue = order[0];
	int thirdValue = order[2];
	
	int n = array.size();
	
	int firstIdx = 0;
	for(int i = 0 ; i < n ; i++){
		if(array[i] == firstValue){
			swap(array[firstIdx], array[i]);
			firstIdx++;
		}
	}
	
	int thirdIdx = n - 1;
	for(int i = n - 1 ; i >= 0 ; i--){
		if(array[i] == thirdValue){
			swap(array[thirdIdx], array[i]);
			thirdIdx--;
		}
	}

  return array;
}

